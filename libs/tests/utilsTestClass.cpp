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

void utilsTestClass::testCharLen() {
    const char* buf = "12345";
    
    Utils utils;
    unsigned int result = utils.charLen(buf);
    unsigned int test = 5;
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    std::string empty;
    unsigned int zero = 0;
    result = utils.charLen(empty.c_str());
    CPPUNIT_ASSERT_EQUAL(zero, result);
    
    std::string spaces = "  ehj  ";
    unsigned int seven = 7;
    result = utils.charLen(spaces.c_str());
    CPPUNIT_ASSERT_EQUAL(seven, result);
    

}

void utilsTestClass::testContains() {
    char c = '(';
    const char* buf = "func( ";
    Utils utils;
    bool result = utils.contains(c, buf);

    CPPUNIT_ASSERT(result);

}

void utilsTestClass::testGetTail() {
    const char* buf = "01234";
    int fromPosition = 2;
    Utils utils;
    const char* result = utils.getTail(buf, fromPosition);

    CPPUNIT_ASSERT(result = "34");

}

void utilsTestClass::testLastCharContains() {

    std::string subject = "0123";
    std::string test = "3";    
    CPPUNIT_ASSERT(Utils().lastCharContains(subject.c_str(), test.c_str()));
    
    test = "12";
    CPPUNIT_ASSERT(!Utils().lastCharContains(subject.c_str(), test.c_str()));
    
    subject = " (";
    test = "(";
    CPPUNIT_ASSERT(Utils().lastCharContains(subject.c_str(), test.c_str()));

}

void utilsTestClass::testExtractSubject(){
    const char* cmd = ".,123subject[][),";
    std::string result = Utils().extractSubject(cmd);
    std::string test = "subject";    
    CPPUNIT_ASSERT_EQUAL(test, result);
    
    cmd = ", func(";
    result = Utils().extractSubject(cmd);
    test = "func";    
    CPPUNIT_ASSERT_EQUAL(test, result);
}

