/*
 * File:   utilsTestClass.h
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 4:10:31 PM
 */

#ifndef UTILSTESTCLASS_H
#define	UTILSTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class utilsTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(utilsTestClass);
    
    CPPUNIT_TEST(testReverseString);
    CPPUNIT_TEST(testCharLen);
    CPPUNIT_TEST(testContains);
    CPPUNIT_TEST(testGetTail);
    CPPUNIT_TEST(testLastCharContains);
    CPPUNIT_TEST(testExtractSubject);

    CPPUNIT_TEST_SUITE_END();

public:
    utilsTestClass();
    virtual ~utilsTestClass();
    void setUp();
    void tearDown();

private:
    void testReverseString();
    void testCharLen();
    void testContains();
    void testGetTail();
    void testLastCharContains();
    void testExtractSubject();

};

#endif	/* UTILSTESTCLASS_H */

