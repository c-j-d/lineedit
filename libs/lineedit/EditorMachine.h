#ifndef EDITORMACHINE_H
#define	EDITORMACHINE_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "EditorState.h"
#include "lineeditUtils.h"


typedef std::vector<EditorState*> StatePointer;
typedef std::vector<std::string> StringVector;

class EditorMachine {
    

public:

    EditorMachine() {
        defaultState = new StateIdle();
        queuedStates = new StatePointer();
        this->reset();
    }

    /**
     * Run this method for each new context
     */
    void reset(void) { // resets to default state (new line)
        linePos = 0;
        cmd = "";
        queuedStates->clear();
        queuedStates->push_back(defaultState);
    }

    void deleteChar(){
        if(linePos <= 0){
            return;
        }
        const char c = cmd.at(cmd.size() -1);
        StateType type = queuedStates->back()->getType();
        
        // cancel state
        if (queuedStates->back()->tryCancel(c, type)) {
            queuedStates->pop_back();            
        }
        
        cmd = cmd.substr(0, cmd.size() -1);
        
        linePos --;
        
    }
    /**
     * Processes the whole command buffer and changes the state of machine accordingly
     * @param buf user input, must be null terminated
     * @return boolean weather the input has added a new state
     */
    bool processInput(std::string buf) {
        
        if (buf.size() <= 0) {
            return false;
        }

        // extract the unprocessed string
        cmd = buf.substr(linePos, buf.size());
        std::string subject = LineEditUtils().extractSubject(cmd); 
        linePos = buf.size(); // update line position

        StateType type = (queuedStates->back())->getType();

        // release state
        if (queuedStates->back()->tryRelease(cmd, type)) {
            queuedStates->pop_back();
            //return false;  
        }

        // set new state
        if (stateInAssignment.tryHook(cmd, type)) {
            addState(new StateInAssignment(), subject);

        } else if (stateInBrackets.tryHook(cmd, type)) {
            addState(new StateInBrackets(), subject);

        } else if (stateInString.tryHook(cmd, type)) {
            addState(new StateInString(), subject);

        } else if (stateListingMembers.tryHook(cmd, type)) {
            addState(new StateListingMembers(), subject);

        } else {
            return false;
        }

        return true;
    }

    std::string getCmd() const {
        return cmd;
    }

    unsigned int getLinePos() const {
        return linePos;
    }

    StatePointer* getStateQueue() const {
        return queuedStates;
    }
    
    EditorState* getCurrentState(){
        return queuedStates->back();
    }

private:

    unsigned int linePos; // position on command line that was last processed
    std::string cmd; // the part of the command line that are currently being processed

    StatePointer *queuedStates; // states can overlap, and are stored in this queue

    EditorState* defaultState;

    // the states this machine can be in
    StateIdle stateIdle;
    StateInAssignment stateInAssignment;
    StateInBrackets stateInBrackets;
    StateInString stateInString;
    StateListingMembers stateListingMembers;
    
    void addState(EditorState* e, std::string subject) {
        e->setSubject(subject);
        queuedStates->push_back(e);
    }
};

#endif	/* EDITORMACHINE_H */

