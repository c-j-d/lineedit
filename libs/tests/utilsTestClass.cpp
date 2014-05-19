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

void utilsTestClass::testContains() {
    char c = '(';
    std::string buf = "func( ";
    bool result = LineEditUtils().contains(c, buf);

    CPPUNIT_ASSERT(result);

}

void utilsTestClass::testLastCharContains() {

    std::string subject = "0123";
    std::string test = "3";    
    CPPUNIT_ASSERT(LineEditUtils().lastCharContains(subject, test));
    
    test = "12";
    CPPUNIT_ASSERT(!LineEditUtils().lastCharContains(subject, test));
    
    subject = " (";
    test = "(";
    CPPUNIT_ASSERT(LineEditUtils().lastCharContains(subject, test));

}

void utilsTestClass::testExtractSubject(){
    std::string cmd = ".,subject[][),";
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

