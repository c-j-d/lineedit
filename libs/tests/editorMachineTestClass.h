/*
 * File:   editorMachineTestClass.h
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 5:22:59 PM
 */

#ifndef EDITORMACHINETESTCLASS_H
#define	EDITORMACHINETESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class editorMachineTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(editorMachineTestClass);

    CPPUNIT_TEST(testGetCmd);
    CPPUNIT_TEST(testGetLinePos);
    CPPUNIT_TEST(testGetStateQueue);
    CPPUNIT_TEST(testProcessInput);
    CPPUNIT_TEST(testReset);
    CPPUNIT_TEST(testDeleteChar);

    CPPUNIT_TEST_SUITE_END();

public:
    editorMachineTestClass();
    virtual ~editorMachineTestClass();
    void setUp();
    void tearDown();

private:
    void testGetCmd();
    void testGetLinePos();
    void testGetStateQueue();
    void testProcessInput();
    void testReset();
    void testDeleteChar();

};

#endif	/* EDITORMACHINETESTCLASS_H */

