
#include <string>
#include "editorMachineTestClass.h"

#include "../lineedit/EditorMachine.h"
#include "../lineedit/EditorState.h"


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

    editorMachine.processInput("12345("); // triger bracket state
    editorMachine.processInput("12345(abc"); // append some chars that will not trigger new state
    result = editorMachine.getCmd();
    expected = "abc"; // check that only chars entered after a state change is processed
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
//    EditorMachine editorMachine;
//    StatePointer result = editorMachine.getStateQueue();
//    CPPUNIT_ASSERT(true);

}

void editorMachineTestClass::testProcessInput() {
    EditorMachine editorMachine;
    std::string buf;
    
    /***************** bogus test **********************************/
    buf = "bogus";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf)); // shouldn't change state
    StateType st = ST_IDLE;
    StateType rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    

    /***************** function test *******************************/
    // input a function
    buf += " funcX(";
    CPPUNIT_ASSERT(editorMachine.processInput(buf)); // should change state
    st = ST_BRACKET;
    rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    std::string subject = "funcX";
    std::string rSubject = (editorMachine.getCurrentState())->getSubject();
    CPPUNIT_ASSERT_EQUAL(subject, rSubject);

    // simulate end of function
    buf += " parameterValue )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf)); // should release state back to idle
    st = ST_IDLE;
    rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    
    /***************** plain brackets test *********************/
    // just input a plain bracket.
    buf += " (";
    CPPUNIT_ASSERT(editorMachine.processInput(buf)); // should change state
    st = ST_BRACKET;
    rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    subject = "";
    rSubject = (editorMachine.getCurrentState())->getSubject();
    CPPUNIT_ASSERT_EQUAL(subject, rSubject);
    
    
    /****************** nested brackets test *****************************************/    
    buf += " (";
    CPPUNIT_ASSERT(editorMachine.processInput(buf)); // should change state, should be two levels of bracket state now
    
    st = ST_BRACKET;
    rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);    
    
    buf += " foo )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf)); // exit first parenthesis
    st = ST_BRACKET;
    rSt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(st, rSt);
    
    buf += " foo )";
    CPPUNIT_ASSERT(!editorMachine.processInput(buf)); // exit second parenthesis
    st = ST_IDLE;
    rSt = (editorMachine.getCurrentState())->getType();  // should have gotten back to idle state
    CPPUNIT_ASSERT_EQUAL(st, rSt);

}

void editorMachineTestClass::testReset() {
    EditorMachine editorMachine;
    editorMachine.processInput("func(");
    editorMachine.reset();

    StateType t = ST_IDLE;
    StateType rt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(t, rt);


    //        std::string empty = "";
    //        std::string result = editorMachine.getCmd();
    //        CPPUNIT_ASSERT_EQUAL(empty, result);

    unsigned int z = 0;
    unsigned int r = editorMachine.getLinePos();
    CPPUNIT_ASSERT_EQUAL(z, r);
}

void editorMachineTestClass::testDeleteChar() {
    EditorMachine editorMachine;
    StateType t;
    StateType rt;
    std::string cmd; 
    
    editorMachine.processInput("func(");
    
    t = ST_BRACKET;
    rt = editorMachine.getCurrentState()->getType();
    CPPUNIT_ASSERT_EQUAL(t, rt);
    unsigned int linePos = 0;
    
    // test delete
    editorMachine.deleteChar("func");
    t = ST_IDLE;
    rt = (editorMachine.getCurrentState())->getType();
    CPPUNIT_ASSERT_EQUAL(t, rt);    
    CPPUNIT_ASSERT_EQUAL(linePos, editorMachine.getLinePos());
    cmd  = "func";
    CPPUNIT_ASSERT_EQUAL(cmd, editorMachine.getCmd());
    
}

