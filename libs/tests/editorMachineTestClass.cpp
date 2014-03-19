/*
 * File:   editorMachineTestClass.cpp
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 5:22:59 PM
 */

#include "editorMachineTestClass.h"
#include "../editor/EditorMachine.h"
#include <string>
#include "../editor/EditorState.h"


CPPUNIT_TEST_SUITE_REGISTRATION(editorMachineTestClass);

editorMachineTestClass::editorMachineTestClass() {
}

editorMachineTestClass::~editorMachineTestClass() {
}

void editorMachineTestClass::setUp() {
}

void editorMachineTestClass::tearDown() {
}

void editorMachineTestClass::testGetCmd() {
    EditorMachine editorMachine;

    editorMachine.processInput("12345");
    std::string result = editorMachine.getCmd();
    std::string expected = "12345";
    CPPUNIT_ASSERT_EQUAL(expected, result);

    editorMachine.processInput("12345abc");
    result = editorMachine.getCmd();
    expected = "abc";
    CPPUNIT_ASSERT_EQUAL(expected, result);

    editorMachine.processInput(""); // should never happen, still... 
    result = editorMachine.getCmd();
    expected = "abc";
    CPPUNIT_ASSERT_EQUAL(expected, result);

}

void editorMachineTestClass::testGetLinePos() {
    EditorMachine editorMachine;
    unsigned int result = editorMachine.getLinePos();
    CPPUNIT_ASSERT(true);
}

void editorMachineTestClass::testGetStateQueue() {
    EditorMachine editorMachine;
    StatePointer result = editorMachine.getStateQueue();
    CPPUNIT_ASSERT(true);

}

void editorMachineTestClass::testProcessInput() {
    EditorMachine editorMachine;
    std::string buf;
    
    /***************** bogus test **********************************/
    buf = "bogus";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf.c_str())); // shouldn't change state
    StateType st = ST_IDLE;
    StateType rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    

    /***************** function test *******************************/
    // input a function
    buf += " funcX(";
    CPPUNIT_ASSERT(editorMachine.processInput(buf.c_str())); // should change state
    st = ST_BRACKET;
    rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    std::string subject = "funcX";
    std::string rSubject = (editorMachine.getStateQueue().back())->getSubject();
    CPPUNIT_ASSERT_EQUAL(subject, rSubject);

    // simulate end of function
    buf += " parameterValue )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf.c_str())); // should release state back to idle
    st = ST_IDLE;
    rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    
    /***************** plain brackets test *********************/
    // just input a plain bracket.
    buf += " (";
    CPPUNIT_ASSERT(editorMachine.processInput(buf.c_str())); // should change state
    st = ST_BRACKET;
    rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    subject = "";
    rSubject = (editorMachine.getStateQueue().back())->getSubject();
    CPPUNIT_ASSERT_EQUAL(subject, rSubject);
    
    
    /****************** nested brackets test *****************************************/    
    buf += " (";
    CPPUNIT_ASSERT(editorMachine.processInput(buf.c_str())); // should change state, should be two levels of bracket state now
    
    st = ST_BRACKET;
    rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);    
    
    buf += " foo )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf.c_str())); // exit first parenthesis
    st = ST_BRACKET;
    rSt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    buf += " foo )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf.c_str())); // exit second parenthesis
    st = ST_IDLE;
    rSt = (editorMachine.getStateQueue().back())->getType();  // should have gotten back to idle state
    CPPUNIT_ASSERT_EQUAL(st, rSt);

}

void editorMachineTestClass::testReset() {
    EditorMachine editorMachine;
    editorMachine.processInput("func(");
    editorMachine.reset();

    StateType t = ST_IDLE;
    StateType rt = (editorMachine.getStateQueue().back())->getType();
    CPPUNIT_ASSERT_EQUAL(t, rt);


    //        std::string empty = "";
    //        std::string result = editorMachine.getCmd();
    //        CPPUNIT_ASSERT_EQUAL(empty, result);

    unsigned int z = 0;
    unsigned int r = editorMachine.getLinePos();
    CPPUNIT_ASSERT_EQUAL(z, r);
}
