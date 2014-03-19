/*
 * File:   newtestclass.h
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 2:27:34 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testGetDescription);
    CPPUNIT_TEST(testTryHook);
    CPPUNIT_TEST(testTryRelease);
    CPPUNIT_TEST(testGetDescription2);
    CPPUNIT_TEST(testTryHook2);
    CPPUNIT_TEST(testTryRelease2);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testGetDescription();
    void testTryHook();
    void testTryRelease();
    void testGetDescription2();
    void testTryHook2();
    void testTryRelease2();

};

#endif	/* NEWTESTCLASS_H */

