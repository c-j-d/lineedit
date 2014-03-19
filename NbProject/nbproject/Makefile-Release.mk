#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/414208620/linenoise.o \
	${OBJECTDIR}/_ext/414208620/utf8.o \
	${OBJECTDIR}/_ext/1200001932/pugixml.o \
	${OBJECTDIR}/_ext/1472/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/editor

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/editor: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/editor ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/414208620/linenoise.o: ../libs/linenoise/linenoise.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/414208620
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/414208620/linenoise.o ../libs/linenoise/linenoise.c

${OBJECTDIR}/_ext/414208620/utf8.o: ../libs/linenoise/utf8.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/414208620
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/414208620/utf8.o ../libs/linenoise/utf8.c

${OBJECTDIR}/_ext/1200001932/pugixml.o: ../libs/pugixml_1.2/pugixml.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1200001932
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1200001932/pugixml.o ../libs/pugixml_1.2/pugixml.cpp

${OBJECTDIR}/_ext/1472/main.o: ../main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1472
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/_ext/1357304591/editorMachineTestClass.o ${TESTDIR}/_ext/1357304591/editorMachineTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1357304591/newtestclass1.o ${TESTDIR}/_ext/1357304591/newtestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/_ext/1357304591/utilsTestClass.o ${TESTDIR}/_ext/1357304591/utilsTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/_ext/1357304591/editorMachineTestClass.o: ../libs/tests/editorMachineTestClass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/editorMachineTestClass.o ../libs/tests/editorMachineTestClass.cpp


${TESTDIR}/_ext/1357304591/editorMachineTestRunner.o: ../libs/tests/editorMachineTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/editorMachineTestRunner.o ../libs/tests/editorMachineTestRunner.cpp


${TESTDIR}/_ext/1357304591/newtestclass1.o: ../libs/tests/newtestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/newtestclass1.o ../libs/tests/newtestclass1.cpp


${TESTDIR}/_ext/1357304591/newtestrunner1.o: ../libs/tests/newtestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/newtestrunner1.o ../libs/tests/newtestrunner1.cpp


${TESTDIR}/_ext/1357304591/utilsTestClass.o: ../libs/tests/utilsTestClass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/utilsTestClass.o ../libs/tests/utilsTestClass.cpp


${TESTDIR}/_ext/1357304591/utilsTestRunner.o: ../libs/tests/utilsTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1357304591
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1357304591/utilsTestRunner.o ../libs/tests/utilsTestRunner.cpp


${OBJECTDIR}/_ext/414208620/linenoise_nomain.o: ${OBJECTDIR}/_ext/414208620/linenoise.o ../libs/linenoise/linenoise.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/414208620
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/414208620/linenoise.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/414208620/linenoise_nomain.o ../libs/linenoise/linenoise.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/414208620/linenoise.o ${OBJECTDIR}/_ext/414208620/linenoise_nomain.o;\
	fi

${OBJECTDIR}/_ext/414208620/utf8_nomain.o: ${OBJECTDIR}/_ext/414208620/utf8.o ../libs/linenoise/utf8.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/414208620
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/414208620/utf8.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/414208620/utf8_nomain.o ../libs/linenoise/utf8.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/414208620/utf8.o ${OBJECTDIR}/_ext/414208620/utf8_nomain.o;\
	fi

${OBJECTDIR}/_ext/1200001932/pugixml_nomain.o: ${OBJECTDIR}/_ext/1200001932/pugixml.o ../libs/pugixml_1.2/pugixml.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1200001932
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1200001932/pugixml.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1200001932/pugixml_nomain.o ../libs/pugixml_1.2/pugixml.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1200001932/pugixml.o ${OBJECTDIR}/_ext/1200001932/pugixml_nomain.o;\
	fi

${OBJECTDIR}/_ext/1472/main_nomain.o: ${OBJECTDIR}/_ext/1472/main.o ../main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1472
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1472/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1472/main_nomain.o ../main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/editor

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
