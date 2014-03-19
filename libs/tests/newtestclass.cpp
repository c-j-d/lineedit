/*
 * File:   newtestclass.cpp
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 2:27:34 PM
 */

#include "newtestclass.h"
#include "../editor/EditorState.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testGetDescription() {
    StateIdle stateIdle;
    std::string result = stateIdle.getDescription();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testTryHook() {
    const char* cmd;
    std::string state;
    StateIdle stateIdle;
    bool result = stateIdle.tryHook(cmd, state);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testTryRelease() {
    const char* cmd;
    std::string state;
    StateIdle stateIdle;
    bool result = stateIdle.tryRelease(cmd, state);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetDescription2() {
    StateInAssignment stateInAssignment;
    std::string result = stateInAssignment.getDescription();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testTryHook2() {
    const char* cmd;
    std::string state;
    StateInAssignment stateInAssignment;
    bool result = stateInAssignment.tryHook(cmd, state);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testTryRelease2() {
    const char* cmd;
    std::string state;
    StateInAssignment stateInAssignment;
    bool result = stateInAssignment.tryRelease(cmd, state);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

