# -*- Makefile -*-
#
# ----------------------------------------------------------------------
#
# Brad T. Aagaard, U.S. Geological Survey
# Charles A. Williams, GNS Science
# Matthew G. Knepley, University of Chicago
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2015 University of California, Davis
#
# See COPYING for license information.
#
# ----------------------------------------------------------------------
#

subpackage = faults
include $(top_srcdir)/subpackage.am
include $(top_srcdir)/check.am

SUBDIRS = data

TESTS = testfaults

check_PROGRAMS = testfaults

# Primary source files
testfaults_SOURCES = \
	TestFault.cc \
	TestFaultCohesive.cc \
	TestFaultMesh.cc \
	TestSlipFn.cc \
	TestStepSlipFn.cc \
	TestConstRateSlipFn.cc \
	TestBruneSlipFn.cc \
	TestLiuCosSlipFn.cc \
	TestTimeHistorySlipFn.cc \
	TestEqKinSrc.cc \
	TestFaultCohesiveKin.cc \
	TestFaultCohesiveKinCases.cc \
	TestFaultCohesiveKinSrcs.cc \
	TestFaultCohesiveKinSrcsCases.cc \
	TestFaultCohesiveDyn.cc \
	TestFaultCohesiveDynCases.cc \
	TestTractPerturbation.cc \
	TestFaultCohesiveImpulses.cc \
	TestFaultCohesiveImpulsesCases.cc \
	test_faults.cc


noinst_HEADERS = \
	TestSlipFn.hh \
	TestBruneSlipFn.hh \
	TestLiuCosSlipFn.hh \
	TestTimeHistorySlipFn.hh \
	TestConstRateSlipFn.hh \
	TestStepSlipFn.hh \
	TestEqKinSrc.hh \
	TestFault.hh \
	TestFaultCohesive.hh \
	TestFaultCohesiveKin.hh \
	TestFaultCohesiveKinCases.hh \
	TestFaultCohesiveKinSrcs.hh \
	TestFaultCohesiveKinSrcsCases.hh \
	TestFaultCohesiveDyn.hh \
	TestFaultCohesiveDynCases.hh \
	TestTractPerturbation.hh \
	TestFaultCohesiveImpulses.hh \
	TestFaultCohesiveImpulsesCases.hh \
	TestFaultMesh.hh

# Source files associated with testing data
testfaults_SOURCES += \
	data/CohesiveData.cc \
	data/CohesiveDataTri3.cc \
	data/CohesiveDataTri3b.cc \
	data/CohesiveDataTri3c.cc \
	data/CohesiveDataTri3d.cc \
	data/CohesiveDataTri3e.cc \
	data/CohesiveDataTri3f.cc \
	data/CohesiveDataTri3g.cc \
	data/CohesiveDataTri3h.cc \
	data/CohesiveDataTri3Lagrange.cc \
	data/CohesiveDataQuad4.cc \
	data/CohesiveDataQuad4b.cc \
	data/CohesiveDataQuad4c.cc \
	data/CohesiveDataQuad4d.cc \
	data/CohesiveDataQuad4e.cc \
	data/CohesiveDataQuad4f.cc \
	data/CohesiveDataQuad4g.cc \
	data/CohesiveDataQuad4h.cc \
	data/CohesiveDataQuad4i.cc \
	data/CohesiveDataQuad4Lagrange.cc \
	data/CohesiveDataTet4.cc \
	data/CohesiveDataTet4b.cc \
	data/CohesiveDataTet4c.cc \
	data/CohesiveDataTet4d.cc \
	data/CohesiveDataTet4f.cc \
	data/CohesiveDataTet4g.cc \
	data/CohesiveDataTet4h.cc \
	data/CohesiveDataTet4i.cc \
	data/CohesiveDataTet4j.cc \
	data/CohesiveDataTet4k.cc \
	data/CohesiveDataTet4Lagrange.cc \
	data/CohesiveDataHex8.cc \
	data/CohesiveDataHex8b.cc \
	data/CohesiveDataHex8c.cc \
	data/CohesiveDataHex8d.cc \
	data/CohesiveDataHex8e.cc \
	data/CohesiveDataHex8f.cc \
	data/CohesiveDataHex8g.cc \
	data/CohesiveDataHex8h.cc \
	data/CohesiveDataHex8i.cc \
	data/CohesiveDataHex8j.cc \
	data/CohesiveDataHex8Lagrange.cc \
	data/CohesiveKinData.cc \
	data/CohesiveKinDataTri3.cc \
	data/CohesiveKinDataTri3d.cc \
	data/CohesiveKinDataTri3g.cc \
	data/CohesiveKinDataQuad4.cc \
	data/CohesiveKinDataQuad4e.cc \
	data/CohesiveKinDataQuad4i.cc \
	data/CohesiveKinDataTet4.cc \
	data/CohesiveKinDataTet4e.cc \
	data/CohesiveKinDataTet4f.cc \
	data/CohesiveKinDataHex8.cc \
	data/CohesiveKinSrcsDataTri3.cc \
	data/CohesiveKinSrcsDataQuad4.cc \
	data/CohesiveKinSrcsDataTet4.cc \
	data/CohesiveKinSrcsDataHex8.cc \
	data/CohesiveDynData.cc \
	data/CohesiveDynDataTri3.cc \
	data/CohesiveDynDataTri3d.cc \
	data/CohesiveDynDataQuad4.cc \
	data/CohesiveDynDataTet4.cc \
	data/CohesiveDynDataHex8.cc \
	data/CohesiveImpulsesData.cc \
	data/CohesiveImpulsesDataTri3.cc \
	data/CohesiveImpulsesDataQuad4.cc \
	data/CohesiveImpulsesDataTet4.cc \
	data/CohesiveImpulsesDataHex8.cc

noinst_HEADERS += \
	data/CohesiveData.hh \
	data/CohesiveDataTri3.hh \
	data/CohesiveDataTri3b.hh \
	data/CohesiveDataTri3c.hh \
	data/CohesiveDataTri3d.hh \
	data/CohesiveDataTri3e.hh \
	data/CohesiveDataTri3f.hh \
	data/CohesiveDataTri3g.hh \
	data/CohesiveDataTri3h.hh \
	data/CohesiveDataTri3Lagrange.hh \
	data/CohesiveDataQuad4.hh \
	data/CohesiveDataQuad4b.hh \
	data/CohesiveDataQuad4c.hh \
	data/CohesiveDataQuad4d.hh \
	data/CohesiveDataQuad4e.hh \
	data/CohesiveDataQuad4f.hh \
	data/CohesiveDataQuad4g.hh \
	data/CohesiveDataQuad4h.hh \
	data/CohesiveDataQuad4i.hh \
	data/CohesiveDataQuad4Lagrange.hh \
	data/CohesiveDataTet4.hh \
	data/CohesiveDataTet4b.hh \
	data/CohesiveDataTet4c.hh \
	data/CohesiveDataTet4d.hh \
	data/CohesiveDataTet4f.hh \
	data/CohesiveDataTet4g.hh \
	data/CohesiveDataTet4h.hh \
	data/CohesiveDataTet4i.hh \
	data/CohesiveDataTet4j.hh \
	data/CohesiveDataTet4k.hh \
	data/CohesiveDataTet4Lagrange.hh \
	data/CohesiveDataHex8.hh \
	data/CohesiveDataHex8b.hh \
	data/CohesiveDataHex8c.hh \
	data/CohesiveDataHex8d.hh \
	data/CohesiveDataHex8e.hh \
	data/CohesiveDataHex8f.hh \
	data/CohesiveDataHex8g.hh \
	data/CohesiveDataHex8h.hh \
	data/CohesiveDataHex8i.hh \
	data/CohesiveDataHex8j.hh \
	data/CohesiveDataHex8Lagrange.hh \
	data/CohesiveKinData.hh \
	data/CohesiveKinDataTri3.hh \
	data/CohesiveKinDataTri3d.hh \
	data/CohesiveKinDataTri3g.hh \
	data/CohesiveKinDataQuad4.hh \
	data/CohesiveKinDataQuad4e.hh \
	data/CohesiveKinDataQuad4i.hh \
	data/CohesiveKinDataTet4.hh \
	data/CohesiveKinDataTet4e.hh \
	data/CohesiveKinDataTet4f.hh \
	data/CohesiveKinDataHex8.hh \
	data/CohesiveKinSrcsDataTri3.hh \
	data/CohesiveKinSrcsDataQuad4.hh \
	data/CohesiveKinSrcsDataTet4.hh \
	data/CohesiveKinSrcsDataHex8.hh \
	data/CohesiveDynData.hh \
	data/CohesiveDynDataTri3.hh \
	data/CohesiveDynDataTri3d.hh \
	data/CohesiveDynDataQuad4.hh \
	data/CohesiveDynDataTet4.hh \
	data/CohesiveDynDataHex8.hh \
	data/CohesiveImpulsesData.hh \
	data/CohesiveImpulsesDataTri3.hh \
	data/CohesiveImpulsesDataQuad4.hh \
	data/CohesiveImpulsesDataTet4.hh \
	data/CohesiveImpulsesDataHex8.hh

AM_CPPFLAGS += \
	$(PYTHON_EGG_CPPFLAGS) -I$(PYTHON_INCDIR) \
	$(PETSC_SIEVE_FLAGS) $(PETSC_CC_INCLUDES)

testfaults_LDFLAGS = \
	$(AM_LDFLAGS) $(PYTHON_LA_LDFLAGS)

testfaults_LDADD = \
	-lcppunit -ldl \
	$(top_builddir)/libsrc/pylith/libpylith.la \
	-lspatialdata \
	$(PETSC_LIB) $(PYTHON_BLDLIBRARY) $(PYTHON_LIBS) $(PYTHON_SYSLIBS)

if ENABLE_CUBIT
  testfaults_LDADD += -lnetcdf_c++ -lnetcdf
endif


leakcheck: testfaults
	valgrind --log-file=valgrind_faults.log --leak-check=full --suppressions=$(top_srcdir)/share/valgrind-python.supp .libs/testfaults


# End of file 
