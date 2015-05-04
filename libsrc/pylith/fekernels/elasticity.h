/* -*- C -*-
 *
 * ----------------------------------------------------------------------
 *
 * Brad T. Aagaard, U.S. Geological Survey
 * Charles A. Williams, GNS Science
 * Matthew G. Knepley, University of Chicago
 *
 * This code was developed as part of the Computational Infrastructure
 * for Geodynamics (http:*geodynamics.org).
 *
 * Copyright (c) 2010-2015 University of California, Davis
 *
 * See COPYING for license information.
 *
 * ----------------------------------------------------------------------
 */

/** @file libsrc/fekernels/elasticity.h
 *
 */

#if !defined(pylith_fekernels_elasticity_h)
#define pylith_fekernels_elasticity_h

// Include directives ---------------------------------------------------
#include <portinfo>

#include "pylith/utils/types.hh" 
#include "pylith/utils/error.h" 

/** f0 entry function for disp/vel time evolution.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [2].
 * @param numA Number of registered subfields in auxiliary field [0].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim), vel(dim)]
 *
 * Auxiliary fields: None
 */
PetscErrorCode
pylith_fekernels_f0_EvolutionDispVel(const PylithInt dim,
				     const PylithInt numS,
				     const PylithInt numA,
				     const PylithInt sOff[],
				     const PylithInt aOff[],
				     const PylithScalar s[],
				     const PylithScalar s_t[],
				     const PylithScalar s_x[],
				     const PylithScalar a[],
				     const PylithScalar a_t[],
				     const PylithScalar a_x[],
				     const PylithScalar x[],
				     PylithScalar f0[]);


/** f0 entry function for inertia and body forces.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [2].
 * @param numA Number of registered subfields in auxiliary field [2].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim), vel(dim)]
 *
 * Auxiliary fields: [density(1), body force(dim)]
 */
PetscErrorCode
pylith_fekernels_f0_ElasticityInertiaBodyForce(const PylithInt dim,
					       const PylithInt numS,
					       const PylithInt numA,
					       const PylithInt sOff[],
					       const PylithInt aOff[],
					       const PylithScalar s[],
					       const PylithScalar s_t[],
					       const PylithScalar s_x[],
					       const PylithScalar a[],
					       const PylithScalar a_t[],
					       const PylithScalar a_x[],
					       const PylithScalar x[],
					       PylithScalar f0[]);


/** f0 entry function for inertia (no body force).
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [2].
 * @param numA Number of registered subfields in auxiliary field [2].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim), vel(dim)]
 *
 * Auxiliary fields: [density(1)]
 */
PetscErrorCode
pylith_fekernels_f0_ElasticityInertia(const PylithInt dim,
				      const PylithInt numS,
				      const PylithInt numA,
				      const PylithInt sOff[],
				      const PylithInt aOff[],
				      const PylithScalar s[],
				      const PylithScalar s_t[],
				      const PylithScalar s_x[],
				      const PylithScalar a[],
				      const PylithScalar a_t[],
				      const PylithScalar a_x[],
				      const PylithScalar x[],
				      PylithScalar f0[]);


/** f0 entry function for body forces (no inertia).
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [2].
 * @param numA Number of registered subfields in auxiliary field [2].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim), vel(dim)]
 *
 * Auxiliary fields: [body force(dim)]
 */
PetscErrorCode
pylith_fekernels_f0_ElasticityBodyForce(const PylithInt dim,
					const PylithInt numS,
					const PylithInt numA,
					const PylithInt sOff[],
					const PylithInt aOff[],
					const PylithScalar s[],
					const PylithScalar s_t[],
					const PylithScalar s_x[],
					const PylithScalar a[],
					const PylithScalar a_t[],
					const PylithScalar a_x[],
					const PylithScalar x[],
					PylithScalar f0[]);


/** Function for inertia.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim), vel(dim)]
 *
 * Auxiliary fields: [density]
 */
PetscErrorCode
pylith_fekernels_Inertia(const PylithInt dim,
			 const PylithInt numS,
			 const PylithInt numA,
			 const PylithInt sOff[],
			 const PylithInt aOff[],
			 const PylithScalar s[],
			 const PylithScalar s_t[],
			 const PylithScalar s_x[],
			 const PylithScalar a[],
			 const PylithScalar a_t[],
			 const PylithScalar a_x[],
			 const PylithScalar x[],
			 PylithScalar f0[]);
					      

/** Function for body force.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [0].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f0 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: NONE
 *
 * Auxiliary fields: [body force(dim)]
 */
PetscErrorCode
pylith_fekernels_BodyForce(const PylithInt dim,
			   const PylithInt numS,
			   const PylithInt numA,
			   const PylithInt sOff[],
			   const PylithInt aOff[],
			   const PylithScalar s[],
			   const PylithScalar s_t[],
			   const PylithScalar s_tt[],
			   const PylithScalar s_x[],
			   const PylithScalar a[],
			   const PylithScalar a_x[],
			   const PylithScalar x[],
			   PylithScalar f0[]);


/** f1 entry function for isotropic linear elasticity in 3-D.
 *
 * @param dim Spatial dimension [3].
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [2].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [lambda(1), mu(1)]
 */
PetscErrorCode
pylith_fekernels_f1_IsotropicLinearElasticity3D(const PylithInt dim,
						const PylithInt numS,
						const PylithInt numA,
						const PylithInt sOff[],
						const PylithInt aOff[],
						const PylithScalar s[],
						const PylithScalar s_t[],
						const PylithScalar s_x[],
						const PylithScalar a[],
						const PylithScalar a_t[],
						const PylithScalar a_x[],
						const PylithScalar x[],
						PylithScalar f1[]);
					      

/** Calculate volumetic stress for 3-D isotropic linear elasticity.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim*dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [lambda(1), initialstress(dim*dim), initialstrain(dim*dim)]
 */
PetscErrorCode
pylith_fekernels_volumetricStress_IsotropicLinearElasticity3D(const PylithInt dim,
							      const PylithInt numS,
							      const PylithInt numA,
							      const PylithInt sOff[],
							      const PylithInt aOff[],
							      const PylithScalar s[],
							      const PylithScalar s_t[],
							      const PylithScalar s_x[],
							      const PylithScalar a[],
							      const PylithScalar a_t[],
							      const PylithScalar a_x[],
							      const PylithScalar x[],
							      PylithScalar stress[]);


/** Calculate deviatoric stress for 3-D isotropic linear elasticity.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim*dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [mu(1), initialstress(dim*dim), initialstrain(dim*dim)]
 */
PetscErrorCode
pylith_fekernels_deviatoricStress_IsotropicLinearElasticity3D(const PylithInt dim,
							      const PylithInt numS,
							      const PylithInt numA,
							      const PylithInt sOff[],
							      const PylithInt aOff[],
							      const PylithScalar s[],
							      const PylithScalar s_t[],
							      const PylithScalar s_x[],
							      const PylithScalar a[],
							      const PylithScalar a_t[],
							      const PylithScalar a_x[],
							      const PylithScalar x[],
							      PylithScalar stress[]);

/** f1 entry function for 2-D plane strain isotropic linear elasticity.
 *
 * @param dim Spatial dimension [3].
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [2].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [lambda(1), mu(1)]
 */
PetscErrorCode
pylith_fekernels_f1_IsotropicLinearElasticityPlaneStrain(const PylithInt dim,
							 const PylithInt numS,
							 const PylithInt numA,
							 const PylithInt sOff[],
							 const PylithInt aOff[],
							 const PylithScalar s[],
							 const PylithScalar s_t[],
							 const PylithScalar s_x[],
							 const PylithScalar a[],
							 const PylithScalar a_t[],
							 const PylithScalar a_x[],
							 const PylithScalar x[],
							 PylithScalar f1[]);
					      

/** Calculate volumetic stress for 2-D plane strain isotropic linear elasticity.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim*dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [lambda(1), initialstress(dim*dim), initialstrain(dim*dim)]
 */
PetscErrorCode
pylith_fekernels_volumetricStress_IsotropicLinearElasticityPlaneStrain(const PylithInt dim,
								       const PylithInt numS,
								       const PylithInt numA,
								       const PylithInt sOff[],
								       const PylithInt aOff[],
								       const PylithScalar s[],
								       const PylithScalar s_t[],
								       const PylithScalar s_x[],
								       const PylithScalar a[],
								       const PylithScalar a_t[],
								       const PylithScalar a_x[],
								       const PylithScalar x[],
								       PylithScalar stress[]);


/** Calculate deviatoric stress for 2-D plane strain isotropic linear elasticity.
 *
 * @param dim Spatial dimension.
 * @param numS Number of registered subfields in solution field [1].
 * @param numA Number of registered subfields in auxiliary field [1].
 * @param sOff Offset of registered subfields in solution field [numS].
 * @param aOff Offset of registered subfields in auxiliary field [numA]
 * @param s Solution field with all subfields.
 * @param s_t Time derivative of solution field.
 * @param s_x Gradient of solution field.
 * @param a Auxiliary field with all subfields.
 * @param a_t Time derivative of auxiliary field.
 * @param a_x Gradient of auxiliary field.
 * @param x Coordinates of point evaluation.
 * @param f1 Result [dim*dim].
 *
 * @returns 0 if no errors.
 * 
 * Solution fields: [disp(dim)]
 *
 * Auxiliary fields: [mu(1), initialstress(dim*dim), initialstrain(dim*dim)]
 */
PetscErrorCode
pylith_fekernels_deviatoricStress_IsotropicLinearElasticityPlaneStrain(const PylithInt dim,
								       const PylithInt numS,
								       const PylithInt numA,
								       const PylithInt sOff[],
								       const PylithInt aOff[],
								       const PylithScalar s[],
								       const PylithScalar s_t[],
								       const PylithScalar s_x[],
								       const PylithScalar a[],
								       const PylithScalar a_t[],
								       const PylithScalar a_x[],
								       const PylithScalar x[],
								       PylithScalar stress[]);

#endif // pylith_fekernels_elasticity_h


// End of file 
