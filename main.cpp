#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <typeinfo> 

extern "C" {
#include "libs/linenoise/linenoise.h"
}
#include "libs/editor/EditorMachine.h"
#include "libs/editor/EditorState.h"

typedef std::vector<std::string> StringVector;


StringVector completions;
StringVector currentFunction;

/* callback for '.' */
int dotCallback(const char *buf, size_t len, char c) {

    return 0;
}

/* callback for '(' */
int bracketCallback(const char *buf, size_t len, char c) {

    return 0;
}

/* tab completion callback */
// todo: list object members when input of . operator
// todo: list possible values for function parameters

void completion(const char *buf, linenoiseCompletions *lc) {



}

int main(int argc, char **argv) {

    EditorMachine m;

    printf("term: %s", getenv("term"));

    char *line;
    char *prgname = argv[0];


    /* Set the completion callback. This will be called every time the
     * user uses the <tab> key. */
     /* Set callback functions*/
    linenoiseSetCompletionCallback(completion);
    linenoiseSetCharacterCallback(dotCallback, '.');
    linenoiseSetCharacterCallback(bracketCallback, '(');

    /* Load history from file. The history file is just a plain text file
     * where entries are separated by newlines. */
    linenoiseHistoryLoad("history.txt"); /* Load the history at startup */

    /* Now this is the main loop of the typical linenoise-based application.
     * The call to linenoise() will block as long as the user types something
     * and presses enter.
     *
     * The typed string is returned as a malloc() allocated string by
     * linenoise, so the user needs to free() it. */
    while ((line = linenoise("hello cpp> ")) != NULL) {

        linenoiseHistoryAdd(line); /* Add to the history. */
        linenoiseHistorySave("history.txt"); /* Save the history on disk. */



        free(line);
    }
    return 0;
}

