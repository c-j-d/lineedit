#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <typeinfo> 

extern "C" {
#include "libs/linenoise/linenoise.h"
}
#include "libs/lineedit/EditorMachine.h"
#include "libs/lineedit/EditorState.h"
#include "libs/lineedit/lineeditUtils.h"

#define ctrl(C) ((C) - '@')

bool debug = true;

enum modeOption {
    MODE_DEFAULT, MODE_CHOOSE, MODE_NEW_FILE, MODE_EDIT_FILE
};
modeOption mode = MODE_DEFAULT;

const char* default_prompt = (char*) "hello, enter some code > ";
const char* esc_prompt = (char*) "> ";
const char* prompt = default_prompt;
char *line; // what is entered at command line

typedef std::vector<std::string> StringVector;

EditorMachine em;

/* callback for '.' */
int dotCallback(const char *buf, size_t len, char c) {

    if (em.processInput(buf)) {
        if (em.getCurrentState()->getSubject() == "objX") {
            em.getCurrentState()->addCompletion("member1");
            em.getCurrentState()->addCompletion("member2");
            em.getCurrentState()->addCompletion("member3");
        }
    }
    if (debug) {
        std::cout << em.getCurrentState()->getDescription() << std::endl;
        linenoiceSetCursorPos(0);
        std::cout << em.getCurrentState()->getDescription() << std::endl;
    }
    return 0;
}

/* callback for '(' and ')' */
int bracketCallback(const char *buf, size_t len, char c) {

    if (em.processInput(buf)) {
        std::cout << "subject: " << em.getCurrentState()->getSubject() << std::endl;
        if (em.getCurrentState()->getSubject() == "funcX") {
            em.getCurrentState()->addCompletion("param1");
            em.getCurrentState()->addCompletion("param2");
            em.getCurrentState()->addCompletion("param3");
        }
    }
    if (debug) printf("\n\r%s\n\r", em.getCurrentState()->getDescription().c_str());

    return 0;
}

/* callback for '=' */
int assignCallback(const char *buf, size_t len, char c) {
    if (em.processInput(buf)) {
        if (em.getCurrentState()->getSubject() == "param1") {
            em.getCurrentState()->addCompletion("obj1");
            em.getCurrentState()->addCompletion("obj2");
            em.getCurrentState()->addCompletion("obj3");
        }
    }
    if (debug) printf("\n\r%s\n\r", em.getCurrentState()->getDescription().c_str());
    return 0;
}

/* callback for '"' */
int stringCallback(const char *buf, size_t len, char c) {

    if (em.processInput(buf)) {
        if (em.getCurrentState()->getSubject() == "param2") {
            em.getCurrentState()->addCompletion("file1");
            em.getCurrentState()->addCompletion("file2");
            em.getCurrentState()->addCompletion("file3");
        }
    }
    if (debug) printf("\r\n%s\n\r", em.getCurrentState()->getDescription().c_str());
    return 0;

}

/* callback for 'ESC' */
int escapeCallback(const char *buf, size_t len, char c) {

    if (mode == MODE_DEFAULT) {
        mode = MODE_CHOOSE;

        printf("\n\rEnter your choise, ESC again to exit this menu:\n\r%s", esc_prompt);
        printf("\n\r'n' : Create a new file\n\r%s", esc_prompt);

        char c = getchar();
        switch (c) {
            case 'n':
                mode = MODE_NEW_FILE;
                printf("\n\rPlease enter the name of new file: ");
        }

    } else {
        if (mode == MODE_EDIT_FILE) {
            fprintf(stdout, "\n\rSave: y/n\n\r");
            if (tolower(getchar()) == 'y') {
                fprintf(stdout, "Saving file...");
            } else {
                fprintf(stdout, "Discarding file ...");
            }
        }
    }

    fflush(stdout);

    return 0;

}

/* callback for 'Ctrl + S' */
int saveCallback(const char *buf, size_t len, char c) {

    printf("\r\n%s\r\n", "in save callback");
    printf("\r\n%s\r\n", "in save callback");
    linenoiceSetCursorPos(10);
    printf("%s\r\n", "in save callback");
    printf("\r\n%s\r\n", "in save callback");
    prompt = default_prompt;
    return 0;

}

/* callback for 'Ctrl + L' */
int clrCallback(const char *buf, size_t len, char c) {

    printf("\r\n%s\r\n", "in clear screen callback");
    prompt = default_prompt;
    linenoiseClearScreen();
    return 0;

}

/* tab completion callback */

void completion(const char *buf, linenoiseCompletions * lc) {
    int startPos = em.getLinePos();
    // discard extra spaces
    while (buf[startPos] == ' ') {
        startPos++;
    }
    int matchlen = std::strlen(buf + startPos);

    //pad previous complete commands
    std::string newBuffer;
    for (unsigned int i = 0; i < startPos; i++) {
        newBuffer += buf[i];
    }

    StringVector completions = em.getCurrentState()->getCompletions();
    if (debug) printf("\n\r%s\n\r", "Current completions:");
    for (unsigned int i = 0; i < completions.size(); i++) {
        if (debug) printf("\n\r\t%s", completions[i].c_str());
        if (strncasecmp(buf + startPos, completions[i].c_str(), matchlen) == 0) {
            linenoiseAddCompletion(lc, (newBuffer + completions[i]).c_str());
        }
    }
}

int main(int argc, char **argv) {

    // add default completions to default state
    em.getCurrentState()->addCompletion("objX");
    em.getCurrentState()->addCompletion("funcX");

    printf("term: %s", getenv("term"));

    char *prgname = argv[0];


    /* Set callback functions*/
    linenoiseSetCompletionCallback(completion);
    linenoiseSetCharacterCallback(dotCallback, '.');
    linenoiseSetCharacterCallback(bracketCallback, '(');
    linenoiseSetCharacterCallback(bracketCallback, ')');
    linenoiseSetCharacterCallback(assignCallback, '=');
    linenoiseSetCharacterCallback(stringCallback, '"');
    linenoiseSetCharacterCallback(saveCallback, ctrl('S'));
    linenoiseSetCharacterCallback(escapeCallback, 27);
    linenoiseSetCharacterCallback(clrCallback, ctrl('L'));

    /* Load history from file. The history file is just a plain text file
     * where entries are separated by newlines. */
    linenoiseHistoryLoad("history.txt"); /* Load the history at startup */

    /* The typed string is returned as a malloc() allocated string by
     * linenoise, so the user needs to free() it. */


    while ((line = linenoise(prompt)) != NULL) {

        linenoiseHistoryAdd(line); /* Add to the history. */
        linenoiseHistorySave("history.txt"); /* Save the history on disk. */


        // parse special commands        
        if (!strcmp(line, "clr")) {
            linenoiseClearScreen();
        } else {
            // send command to Rev parser
        }

        em.reset();
        free(line);
    }
    return 0;
}

