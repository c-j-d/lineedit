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
#include "Observer.h"

#define ctrl(C) ((C) - '@')

bool debug = true;

enum modeOption {
    MODE_DEFAULT, MODE_CHOOSE, MODE_NEW_FILE, MODE_EDIT_FILE
};
modeOption mode = MODE_DEFAULT;

const char* nl = (char*) "\n\r";
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

    return 0;
}

/* callback for '(' and ')' */
int bracketCallback(const char *buf, size_t len, char c) {

    if (em.processInput(buf)) {
       
        if (em.getCurrentState()->getSubject() == "funcX") {
            em.getCurrentState()->addCompletion("param1");
            em.getCurrentState()->addCompletion("param2");
            em.getCurrentState()->addCompletion("param3");
        }
    }


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

    return 0;

}

int escapeCallback(const char *buf, size_t len, char c) {

    linenoiseClearScreen();

    linenoiceSetCursorPos(0);



    std::cout << nl << "Editor state" << nl;
    std::cout.flush();
    std::cout << em.getMessage() << nl;
    std::cout.flush();


    // restore prompt
    linenoiceSetCursorPos(0);
    std::cout << nl << nl << prompt << buf;
    std::cout.flush();

    return 0;
}

/* callback for 'Ctrl + L' */
int clrCallback(const char *buf, size_t len, char c) {

    printf("\r\n%s\r\n", "in clear screen callback");
    prompt = default_prompt;
    linenoiseClearScreen();
    return 0;

}

/* callback for back space */
int backspaceCallback(const char *buf, size_t len, char c) {
    em.deleteChar();
    return 0;

}

int quotationCallback(const char *buf, size_t len, char c) {

    if (em.processInput(buf)) {


    }
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
    
    EditorMachineObserver *observer = new Observer();
    em.setObserver(observer);

    // add default completions to default state
    em.getCurrentState()->addCompletion("objX");
    em.getCurrentState()->addCompletion("funcX");

    char *prgname = argv[0];

    /* Set tab completion callback */
    linenoiseSetCompletionCallback(completion);

    /* Set character callback functions*/
    linenoiseSetCharacterCallback(dotCallback, '.');
    linenoiseSetCharacterCallback(bracketCallback, ')');
    linenoiseSetCharacterCallback(bracketCallback, '(');
    linenoiseSetCharacterCallback(assignCallback, '=');
    linenoiseSetCharacterCallback(quotationCallback, '"');
    //linenoiseSetCharacterCallback(listSeparatorCallback, ',');

    linenoiseSetCharacterCallback(escapeCallback, 27);
    linenoiseSetCharacterCallback(backspaceCallback, '\b');
    linenoiseSetCharacterCallback(backspaceCallback, 8);
    linenoiseSetCharacterCallback(backspaceCallback, (char)8);


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
            std::cout << line << nl;
            std::cout.flush();
        }

        em.reset();
        free(line);
    }
    return 0;
}

