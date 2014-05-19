/*
 * File:   utilsTestClass.cpp
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 4:10:31 PM
 */

#include "utilsTestClass.h"
#include "../lineedit/lineeditUtils.h"
#include <string>


CPPUNIT_TEST_SUITE_REGISTRATION(utilsTestClass);

utilsTestClass::utilsTestClass() {
}

utilsTestClass::~utilsTestClass() {
}

void utilsTestClass::setUp() {
}

void utilsTestClass::tearDown() {
}

void utilsTestClass::testReverseString() {
    std::string result = LineEditUtils().reverseString("abc");
    CPPUNIT_ASSERT(result == "cba");
}

void utilsTestClass::testCharLen() {
    const char* buf = "12345";
    
    unsigned int result = LineEditUtils().charLen(buf);
    unsigned int test = 5;
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    std::string empty;
    unsigned int zero = 0;
    result = LineEditUtils().charLen(empty.c_str());
    CPPUNIT_ASSERT_EQUAL(zero, result);
    
    std::string spaces = "  ehj  ";
    unsigned int seven = 7;
    result = LineEditUtils().charLen(spaces.c_str());
    CPPUNIT_ASSERT_EQUAL(seven, result);
    

}

void utilsTestClass::testContains() {
    char c = '(';
    const char* buf = "func( ";
    bool result = LineEditUtils().contains(c, buf);

    CPPUNIT_ASSERT(result);

}

void utilsTestClass::testGetTail() {
    const char* buf = "01234";
    const char* test = "34";
    int fromPosition = 2;
    const char* result = LineEditUtils().getTail(buf, fromPosition);

    CPPUNIT_ASSERT_EQUAL(std::string(result), std::string(test));
    
    // test overloaded
    
    const char c = LineEditUtils().getTail(buf);
    const char t = '4';
    CPPUNIT_ASSERT_EQUAL(c, t);

}

void utilsTestClass::testPopChar() {
    const char* buf = "01234";
    const char* test = "0123";
    const char* result = LineEditUtils().popChar(buf);

    CPPUNIT_ASSERT_EQUAL(std::string(result), std::string(test));

}

void utilsTestClass::testLastCharContains() {

    std::string subject = "0123";
    std::string test = "3";    
    CPPUNIT_ASSERT(LineEditUtils().lastCharContains(subject.c_str(), test.c_str()));
    
    test = "12";
    CPPUNIT_ASSERT(!LineEditUtils().lastCharContains(subject.c_str(), test.c_str()));
    
    subject = " (";
    test = "(";
    CPPUNIT_ASSERT(LineEditUtils().lastCharContains(subject.c_str(), test.c_str()));

}

void utilsTestClass::testExtractSubject(){
    const char* cmd = ".,subject[][),";
    std::string result = LineEditUtils().extractSubject(cmd);
    std::string test = "subject";    
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    cmd = ", func(";
    result = LineEditUtils().extractSubject(cmd);
    test = "func";    
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    cmd = "object.objFunc(";
    result = LineEditUtils().extractSubject(cmd);
    test = "objFunc";    
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    cmd = "object.objFunc";
    result = LineEditUtils().extractSubject(cmd);
    test = "objFunc";    
    CPPUNIT_ASSERT_EQUAL(test, result);
}

