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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Cedges.o \
	${OBJECTDIR}/Cedges_UNIT.o \
	${OBJECTDIR}/Cexception.o \
	${OBJECTDIR}/Cfile.o \
	${OBJECTDIR}/Cfile_UNIT.o \
	${OBJECTDIR}/Cfile_gvedit.o \
	${OBJECTDIR}/Cgraph.o \
	${OBJECTDIR}/Cgraph_UNIT.o \
	${OBJECTDIR}/Cgraph_table.o \
	${OBJECTDIR}/Cgraph_table_UNIT.o \
	${OBJECTDIR}/Cmax_inde_sets_table.o \
	${OBJECTDIR}/Cmax_inde_sets_table_UNIT.o \
	${OBJECTDIR}/Cvertex.o \
	${OBJECTDIR}/Cvertex_UNIT.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/stdafx.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-DDEBUG
CXXFLAGS=-DDEBUG

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetcpp_stable_linux

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetcpp_stable_linux: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetcpp_stable_linux ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Cedges.o: Cedges.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cedges.o Cedges.cpp

${OBJECTDIR}/Cedges_UNIT.o: Cedges_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cedges_UNIT.o Cedges_UNIT.cpp

${OBJECTDIR}/Cexception.o: Cexception.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cexception.o Cexception.cpp

${OBJECTDIR}/Cfile.o: Cfile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cfile.o Cfile.cpp

${OBJECTDIR}/Cfile_UNIT.o: Cfile_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cfile_UNIT.o Cfile_UNIT.cpp

${OBJECTDIR}/Cfile_gvedit.o: Cfile_gvedit.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cfile_gvedit.o Cfile_gvedit.cpp

${OBJECTDIR}/Cgraph.o: Cgraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cgraph.o Cgraph.cpp

${OBJECTDIR}/Cgraph_UNIT.o: Cgraph_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cgraph_UNIT.o Cgraph_UNIT.cpp

${OBJECTDIR}/Cgraph_table.o: Cgraph_table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cgraph_table.o Cgraph_table.cpp

${OBJECTDIR}/Cgraph_table_UNIT.o: Cgraph_table_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cgraph_table_UNIT.o Cgraph_table_UNIT.cpp

${OBJECTDIR}/Cmax_inde_sets_table.o: Cmax_inde_sets_table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cmax_inde_sets_table.o Cmax_inde_sets_table.cpp

${OBJECTDIR}/Cmax_inde_sets_table_UNIT.o: Cmax_inde_sets_table_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cmax_inde_sets_table_UNIT.o Cmax_inde_sets_table_UNIT.cpp

${OBJECTDIR}/Cvertex.o: Cvertex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cvertex.o Cvertex.cpp

${OBJECTDIR}/Cvertex_UNIT.o: Cvertex_UNIT.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cvertex_UNIT.o Cvertex_UNIT.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/stdafx.o: stdafx.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stdafx.o stdafx.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetcpp_stable_linux

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
