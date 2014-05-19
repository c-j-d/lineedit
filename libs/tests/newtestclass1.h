/*
 * File:   newtestclass1.h
 * Author: johadunf
 *
 * Created on Mar 18, 2014, 3:16:57 PM
 */

#ifndef NEWTESTCLASS1_H
#define	NEWTESTCLASS1_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass1);

    CPPUNIT_TEST(testTryHookAssignment);
    CPPUNIT_TEST(testTryReleaseAssignment);
    CPPUNIT_TEST(testTryCancelAssignment);
    
    CPPUNIT_TEST(testTryHookIdle);
    CPPUNIT_TEST(testTryReleaseIdle);
    CPPUNIT_TEST(testTryCancelIdle);
    
    CPPUNIT_TEST(testTryHookString);
    CPPUNIT_TEST(testTryReleaseString);
    CPPUNIT_TEST(testTryCancelString);
    
    CPPUNIT_TEST(testTryHookBrackets);
    CPPUNIT_TEST(testTryReleaseBrackets);
    CPPUNIT_TEST(testTryCancelBrackets);
    
    CPPUNIT_TEST(testTryHookListMembers);
    CPPUNIT_TEST(testTryReleaseListMembers);
    CPPUNIT_TEST(testTryCancelListMembers);
    
    CPPUNIT_TEST(testSetGetSubject);
    

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass1();
    virtual ~newtestclass1();
    void setUp();
    void tearDown();

private:
    void testTryHookAssignment();
    void testTryReleaseAssignment();
    void testTryCancelAssignment();
    
    void testTryHookIdle();
    void testTryReleaseIdle();
    void testTryCancelIdle();
    
    void testTryHookString();
    void testTryReleaseString();
    void testTryCancelString();
    
    void testTryHookBrackets();
    void testTryReleaseBrackets();
    void testTryCancelBrackets();
    
    void testTryHookListMembers();
    void testTryReleaseListMembers();
    void testTryCancelListMembers();
    
    void testSetGetSubject();

};

#endif	/* NEWTESTCLASS1_H */

