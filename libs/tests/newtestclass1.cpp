/*
 * File:   newtestclass1.cpp
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 3:16:57 PM
 */

#include "newtestclass1.h"
#include "../lineedit/EditorState.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void newtestclass1::testTryHookAssignment() {
    const char* cmd = "hej =";
    StateInAssignment stateInAssignment;

    StateType type = ST_ASSIGNMENT;
    CPPUNIT_ASSERT(!stateInAssignment.tryHook(cmd, type));

    type = ST_BRACKET;
    CPPUNIT_ASSERT(stateInAssignment.tryHook(cmd, type));

}

void newtestclass1::testTryReleaseAssignment() {

    StateInAssignment stateInAssignment;

    CPPUNIT_ASSERT(stateInAssignment.tryRelease("any", ST_ASSIGNMENT));
    CPPUNIT_ASSERT(!stateInAssignment.tryRelease("any", ST_STRING));

}

void newtestclass1::testTryHookIdle() {
    StateIdle stateIdle;
    CPPUNIT_ASSERT(!stateIdle.tryHook("foo", ST_STRING));
}

void newtestclass1::testTryReleaseIdle() {
    StateIdle stateIdle;
    CPPUNIT_ASSERT(!stateIdle.tryRelease("foo", ST_STRING));
}

void newtestclass1::testTryHookString() {

    StateInString stateInString;

    CPPUNIT_ASSERT(!stateInString.tryHook("file=\"", ST_STRING));
    CPPUNIT_ASSERT(stateInString.tryHook("file=\"", ST_ASSIGNMENT));

}

void newtestclass1::testTryReleaseString() {
    StateInString stateInString;

    CPPUNIT_ASSERT(stateInString.tryRelease("filename\"", ST_STRING));
    CPPUNIT_ASSERT(!stateInString.tryRelease("filename\"", ST_IDLE));
}

void newtestclass1::testTryHookBrackets() {

    StateInBrackets stateInBrackets;

    CPPUNIT_ASSERT(stateInBrackets.tryHook("func(", ST_IDLE));
    CPPUNIT_ASSERT(stateInBrackets.tryHook("func(", ST_BRACKET)); // nested bracket states 

    CPPUNIT_ASSERT(!stateInBrackets.tryHook("func ", ST_IDLE));
    CPPUNIT_ASSERT(!stateInBrackets.tryHook("func ", ST_BRACKET));

    CPPUNIT_ASSERT(!stateInBrackets.tryHook("(", ST_STRING)); // do not trigger when in a string state

}

void newtestclass1::testTryReleaseBrackets() {
    StateInBrackets stateInBrackets;

    CPPUNIT_ASSERT(!stateInBrackets.tryRelease("param)", ST_IDLE));
    CPPUNIT_ASSERT(stateInBrackets.tryRelease(" param)", ST_BRACKET));
}

void newtestclass1::testTryHookListMembers() {
    StateListingMembers stateListingMembers;

    CPPUNIT_ASSERT(stateListingMembers.tryHook("obj.", ST_IDLE));
    CPPUNIT_ASSERT(!stateListingMembers.tryHook("obj", ST_LISTMEMBERS));
    
    CPPUNIT_ASSERT(!stateListingMembers.tryHook("obj.", ST_LISTMEMBERS)); // no nesting
    
    CPPUNIT_ASSERT(!stateListingMembers.tryHook(".", ST_STRING)); // do not trigger when in a string state
}

void newtestclass1::testTryReleaseListMembers() {
    StateListingMembers stateListingMembers;

    CPPUNIT_ASSERT(!stateListingMembers.tryRelease("any", ST_STRING));
    CPPUNIT_ASSERT(stateListingMembers.tryRelease("any", ST_LISTMEMBERS));
}

void newtestclass1::testSetGetSubject() {
    StateInBrackets stateInBrackets;
    stateInBrackets.setSubject("subject");
    CPPUNIT_ASSERT(stateInBrackets.getSubject() == "subject");
}