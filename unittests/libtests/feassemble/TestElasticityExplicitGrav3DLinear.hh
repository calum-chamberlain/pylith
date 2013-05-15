// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
// Brad T. Aagaard, U.S. Geological Survey
// Charles A. Williams, GNS Science
// Matthew G. Knepley, University of Chicago
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010-2012 University of California, Davis
//
// See COPYING for license information.
//
// ----------------------------------------------------------------------
//

/**
 * @file unittests/libtests/feassemble/TestElasticityExplicitGrav3DLinear.hh
 *
 * @brief C++ TestElasticityExplicit object
 *
 * C++ unit testing for ElasticityExplicit with 1-D linear cells and gravity.
 */

#if !defined(pylith_feassemble_testelasticityexplicitgrav3dlinear_hh)
#define pylith_feassemble_testelasticityexplicitgrav3dlinear_hh

#include "TestElasticityExplicit.hh" // ISA TestElasticityExplicit

/// Namespace for pylith package
namespace pylith {
  namespace feassemble {
    class TestElasticityExplicitGrav3DLinear;
  } // feassemble
} // pylith

/// C++ unit testing for ElasticityExplicit
class pylith::feassemble::TestElasticityExplicitGrav3DLinear :
  public TestElasticityExplicit
{ // class TestElasticityExplicit3DLinear

  // CPPUNIT TEST SUITE /////////////////////////////////////////////////
  CPPUNIT_TEST_SUITE( TestElasticityExplicitGrav3DLinear );

  CPPUNIT_TEST( testInitialize );
  CPPUNIT_TEST( testIntegrateResidual );
  CPPUNIT_TEST( testIntegrateJacobian );
  CPPUNIT_TEST( testUpdateStateVars );

  CPPUNIT_TEST_SUITE_END();

  // PUBLIC METHODS /////////////////////////////////////////////////////
public :

  /// Setup testing data.
  void setUp(void);

}; // class TestElasticityExplicitGrav3DLinear

#endif // pylith_feassemble_testelasticityexplicitgrav3dlinear_hh


// End of file 