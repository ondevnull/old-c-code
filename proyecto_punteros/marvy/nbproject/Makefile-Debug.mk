#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Debug/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/media/MANUEL/marvy_2.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Debug/GNU-Linux-x86/marvy

dist/Debug/GNU-Linux-x86/marvy: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o dist/Debug/GNU-Linux-x86/marvy ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/media/MANUEL/marvy_2.o: /media/MANUEL/marvy_2.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/media/MANUEL
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/media/MANUEL/marvy_2.o /media/MANUEL/marvy_2.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/marvy

# Subprojects
.clean-subprojects:
