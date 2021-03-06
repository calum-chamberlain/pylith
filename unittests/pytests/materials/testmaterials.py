#!/usr/bin/env nemesis
#
# ======================================================================
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
# ======================================================================
#

## @file unittests/materials/testmaterials.py

## @brief Python application for testing materials code.

from pyre.applications.Script import Script

import unittest

class TestApp(Script):
  """
  Test application.
  """

  # PUBLIC METHODS /////////////////////////////////////////////////////

  def __init__(self, name="testapp"):
    """
    Constructor.
    """
    Script.__init__(self, name)
    return


  def main(self):
    """
    Run the application.
    """
    from pylith.utils.PetscManager import PetscManager
    petsc = PetscManager()
    petsc.options = [("malloc_dump", "true")]
    petsc.initialize()

    unittest.TextTestRunner(verbosity=2).run(self._suite())

    petsc.finalize()
    return


  # PRIVATE METHODS ////////////////////////////////////////////////////

  def _suite(self):
    """
    Setup the test suite.
    """

    suite = unittest.TestSuite()

    from TestElasticPlaneStrain import TestElasticPlaneStrain
    suite.addTest(unittest.makeSuite(TestElasticPlaneStrain))

    from TestElasticPlaneStress import TestElasticPlaneStress
    suite.addTest(unittest.makeSuite(TestElasticPlaneStress))

    from TestElasticIsotropic3D import TestElasticIsotropic3D
    suite.addTest(unittest.makeSuite(TestElasticIsotropic3D))

    from TestMaxwellIsotropic3D import TestMaxwellIsotropic3D
    suite.addTest(unittest.makeSuite(TestMaxwellIsotropic3D))

    from TestMaxwellPlaneStrain import TestMaxwellPlaneStrain
    suite.addTest(unittest.makeSuite(TestMaxwellPlaneStrain))

    from TestGenMaxwellIsotropic3D import TestGenMaxwellIsotropic3D
    suite.addTest(unittest.makeSuite(TestGenMaxwellIsotropic3D))

    from TestGenMaxwellPlaneStrain import TestGenMaxwellPlaneStrain
    suite.addTest(unittest.makeSuite(TestGenMaxwellPlaneStrain))

    from TestGenMaxwellQpQsIsotropic3D import TestGenMaxwellQpQsIsotropic3D
    suite.addTest(unittest.makeSuite(TestGenMaxwellQpQsIsotropic3D))

    from TestPowerLaw3D import TestPowerLaw3D
    suite.addTest(unittest.makeSuite(TestPowerLaw3D))

    from TestPowerLawPlaneStrain import TestPowerLawPlaneStrain
    suite.addTest(unittest.makeSuite(TestPowerLawPlaneStrain))

    from TestDruckerPrager3D import TestDruckerPrager3D
    suite.addTest(unittest.makeSuite(TestDruckerPrager3D))

    from TestDruckerPragerPlaneStrain import TestDruckerPragerPlaneStrain
    suite.addTest(unittest.makeSuite(TestDruckerPragerPlaneStrain))

    from TestMaterial import TestMaterial
    suite.addTest(unittest.makeSuite(TestMaterial))

    from TestElasticMaterial import TestElasticMaterial
    suite.addTest(unittest.makeSuite(TestElasticMaterial))

    from TestHomogeneous import TestHomogeneous
    suite.addTest(unittest.makeSuite(TestHomogeneous))

    return suite


# ----------------------------------------------------------------------
if __name__ == '__main__':
  app = TestApp()
  app.run()


# End of file 
