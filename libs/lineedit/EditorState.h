#ifndef EDITORSTATE_H
#define	EDITORSTATE_H

#include <string>
#include <vector>
#include <algorithm>

#include "lineeditUtils.h"


typedef std::vector<std::string> StringVector;

enum StateType {
    ST_IDLE, ST_STRING, ST_BRACKET, ST_ASSIGNMENT, ST_LISTMEMBERS
};

class EditorState {
public:

    EditorState() {
    }

    std::string getDescription() {
        return description;
    }

    StateType getType() {
        return type;
    }

    /**
     * Indicates if the cmd input should release this state
     * @param cmd
     * @param type
     * @return 
     */
    virtual bool tryRelease(std::string cmd, StateType type) = 0;

    /**
     * Indicates if the cmd input triggers this state
     * @param cmd
     * @param type
     * @return 
     */
    virtual bool tryHook(std::string cmd, StateType type) = 0;

    StringVector getCompletions() {
        return completions;
    }

    void setCompletions(StringVector completions) {
        this->completions.clear();
        for (unsigned int i = 0; i < completions.size(); i++) {
            this->completions.push_back(completions[i]);
        }
    }

    void addCompletion(std::string completion) {
        completions.push_back(completion);
    }

    void setSubject(std::string subject) {
        this->subject = subject;
    }

    std::string getSubject() const {
        return subject;
    }

protected:

    StringVector completions;
    std::string hookChars; /** any of these triggers this state **/
    char hookChar; // actual trigger
    std::string releaseChars; /** release for this state **/
    std::string subject; /** for example the function name **/
    std::string description;
    StateType type;
};

class StateIdle : public EditorState {
public:

    StateIdle() : EditorState() {
        description = "inIdle";
        type = ST_IDLE;
    }

    virtual bool tryHook(std::string cmd, StateType type) {
        return false; // cannot be triggered
    }

    virtual bool tryRelease(std::string cmd, StateType type) {
        return false; // cannot be released
    }

    virtual bool tryCancel(const char c, StateType type) {
        return false; // cannot be canceled
    }

};

class StateInString : public EditorState {
public:

    StateInString() : EditorState() {
        hookChars = "\"";
        releaseChars = "\"";
        description = "inString";
        type = ST_STRING;
    }

    virtual bool tryHook(std::string cmd, StateType type) {
        if (type == this->type) { // cannot nest strings
            return false;
        }
        if (LineEditUtils().lastCharContains(cmd, hookChars.c_str())) {
            return true;
        }
        return false;
    }

    virtual bool tryRelease(std::string cmd, StateType type) {
        if (type != this->type) { // cannot release unless current state is same type
            return false;
        }
        if (LineEditUtils().lastCharContains(cmd, releaseChars.c_str())) {
            return true;
        }
        return false;
    }
};

class StateInBrackets : public EditorState {
public:

    StateInBrackets() : EditorState() {
        hookChars = "(";
        releaseChars = ")";
        description = "inBrackets";
        type = ST_BRACKET;
    }

    virtual bool tryHook(std::string cmd, StateType type) {
        // brackets can be nested, but not triggered in middle of a string
        if (type == ST_STRING) {
            return false;
        }
        if (LineEditUtils().lastCharContains(cmd, hookChars.c_str())) {
            return true;
        }
        return false;
    }

    virtual bool tryRelease(std::string cmd, StateType type) {
        if (type != this->type) { // cannot release unless current state is same type
            return false;
        }
        if (LineEditUtils().lastCharContains(cmd, releaseChars.c_str())) {
            return true;
        }
        return false;
    }
};

class StateInAssignment : public EditorState {
public:

    StateInAssignment() : EditorState() {
        hookChars = "=";
        releaseChars = "any command releases this state";
        description = "inAssignment";
        type = ST_ASSIGNMENT;
    }

    virtual bool tryHook(std::string cmd, StateType type) {
        if (type == this->type // cannot nest this state
                || type == ST_STRING // don't trigger if in middle of a string
                ) {
            return false;
        }
        if (LineEditUtils().lastCharContains(cmd, hookChars.c_str())) {
            return true;
        }
        return false;
    }

    virtual bool tryRelease(std::string cmd, StateType type) {
        if (type != this->type) { // cannot release unless current state is same type
            return false;
        }
        return true;
    }
};

class StateListingMembers : public EditorState {
public:

    StateListingMembers() : EditorState() {
        hookChars = ".";
        releaseChars = "any command releases this state";
        description = "inListingMembers";
        type = ST_LISTMEMBERS;
    }

    virtual bool tryHook(std::string cmd, StateType type) {
        if (type == this->type // cannot nest this state
                || type == ST_STRING // don't trigger if in middle of a string
                ) {
            return false;
        }

        if (LineEditUtils().lastCharContains(cmd, hookChars.c_str())) {
            return true;
        }
        return false;
    }

    virtual bool tryRelease(std::string cmd, StateType type) {
        if (type != this->type) { // cannot release unless current state is same type
            return false;
        }
        return true;
    }
};


#endif	/* EDITORSTATE_H */

