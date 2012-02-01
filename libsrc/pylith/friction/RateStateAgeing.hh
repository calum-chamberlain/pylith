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
// Copyright (c) 2010-2011 University of California, Davis
//
// See COPYING for license information.
//
// ----------------------------------------------------------------------
//

/** @file libsrc/friction/RateStateAgeing.hh
 *
 * @brief C++ Rate and State fault constitutive model with ageing law.
 *
 * Implementation comes from "Kaneko, Y., N. Lapusta, and J.-P. Ampuero 
 * (2008), Spectral element modeling of spontaneous earthquake rupture on
 * rate and state faults: Effect of velocity-strengthening friction at 
 * shallow depths, J. Geophys. Res., 113, B09317" 
 *
 * Regularized Rate & State equation : Eqn(15) of Kaneko et. al. (2008)
 *
 * Ageing Law : Eqn (19), of Kaneko et. al. (2008) added separate expression
 * if (slipRate * dt / L) < = 0.00001 by using Taylor series expansion of
 * exp(slipRate * dt / L) for the term (1 - exp(slipRate * dt / L))
 */

#if !defined(pylith_friction_ratestateageing_hh)
#define pylith_friction_rateStateAgeing_hh

// Include directives ---------------------------------------------------
#include "FrictionModel.hh" // ISA FrictionModel

// RateStateAgeing -------------------------------------------------------
/** @brief C++ Rate and State fault constitutive model with ageing law.
 *
 * Friction is equal to the product of a coefficient of friction (function
 * of slip rate and state variable) and the normal traction.
 */

class pylith::friction::RateStateAgeing : public FrictionModel
{ // class RateStateAgeing
  friend class TestRateStateAgeing; // unit testing

  // PUBLIC METHODS /////////////////////////////////////////////////////
public :

  /// Default constructor.
  RateStateAgeing(void);

  /// Destructor.
  ~RateStateAgeing(void);

  /** Set floor for slip rate used in computing friction. Used to
   *  avoid zero friction at zero slip rate.
   *
   * @param value Floor for slip rate.
   */
  void minSlipRate(const double value);

  // PROTECTED METHODS //////////////////////////////////////////////////
protected :

  /// These methods should be implemented by every constitutive model.

  /** Compute properties from values in spatial database.
   *
   * @param propValues Array of property values.
   * @param dbValues Array of database values.
   */
  void _dbToProperties(double* const propValues,
		       const double_array& dbValues) const;

  /** Nondimensionalize properties.
   *
   * @param values Array of property values.
   * @param nvalues Number of values.
   */
  void _nondimProperties(double* const values,
			 const int nvalues) const;

  /** Dimensionalize properties.
   *
   * @param values Array of property values.
   * @param nvalues Number of values.
   */
  void _dimProperties(double* const values,
		      const int nvalues) const;

  /** Compute friction from properties and state variables.
   *
   * @param slip Current slip at location.
   * @param slipRate Current slip rate at location.
   * @param normalTraction Normal traction at location.
   * @param properties Properties at location.
   * @param numProperties Number of properties.
   * @param stateVars State variables at location.
   * @param numStateVars Number of state variables.
   */
  void _dbToStateVars(double* const stateValues,
		      const double_array& dbValues) const;

  /** Nondimensionalize state variables.
   *
   * @param values Array of initial state values.
   * @param nvalues Number of values.
   */
  void _nondimStateVars(double* const values,
			   const int nvalues) const;
  
  /** Dimensionalize state variables.
   *
   * @param values Array of initial state values.
   * @param nvalues Number of values.
   */
  void _dimStateVars(double* const values,
			const int nvalues) const;

  /** Compute friction from properties and state variables.
   *
   * @param slip Current slip at location.
   * @param slipRate Current slip rate at location.
   * @param normalTraction Normal traction at location.
   * @param properties Properties at location.
   * @param numProperties Number of properties.
   * @param stateVars State variables at location.
   * @param numStateVars Number of state variables.
   */
  double _calcFriction(const double slip,
		       const double slipRate,
		       const double normalTraction,
		       const double* properties,
		       const int numProperties,
		       const double* stateVars,
		       const int numStateVars);

  /** Compute change in friction for a change in slip (Jacobian).
   *
   * @param slip Current slip at location.
   * @param slipRate Current slip rate at location.
   * @param normalTraction Normal traction at location.
   * @param properties Properties at location.
   * @param numProperties Number of properties.
   * @param stateVars State variables at location.
   * @param numStateVars Number of state variables.
   *
   * @returns Change in friction for a chance in slip (dT/dD).
   */
  double _calcFrictionSlope(const double slip,
			    const double slipRate,
			    const double normalTraction,
			    const double* properties,
			    const int numProperties,
			    const double* stateVars,
			    const int numStateVars);
  
  /** Update state variables (for next time step).
   *
   * @param slip Current slip at location.
   * @param slipRate Current slip rate at location.
   * @param normalTraction Normal traction at location.
   * @param stateVars State variables at location.
   * @param numStateVars Number of state variables.
   * @param properties Properties at location.
   * @param numProperties Number of properties.
   */
  void _updateStateVars(const double slip,
			const double slipRate,
			const double normalTraction,
			double* const stateVars,
			const int numStateVars,
			const double* properties,
			const int numProperties);

  // PRIVATE MEMBERS ////////////////////////////////////////////////////
private :

  /// Floor for slip rate used in friction calculation.
  double _minSlipRate;

  /// Indices for properties in section and spatial database.
  static const int p_coef;
  static const int p_slipRate0;
  static const int p_L;
  static const int p_a;
  static const int p_b;
  static const int p_cohesion;

  static const int db_coef;
  static const int db_slipRate0;
  static const int db_L;
  static const int db_a;
  static const int db_b;
  static const int db_cohesion;

  /// Indices for state variables in section and spatial database.
  static const int s_state;

  static const int db_state;

  // NOT IMPLEMENTED ////////////////////////////////////////////////////
private :

  RateStateAgeing(const RateStateAgeing&); ///< Not implemented.
  const RateStateAgeing& operator=(const RateStateAgeing&); ///< Not implemented

}; // class RateStateAgeing

#endif // pylith_friction_ratestateageing_hh


// End of file 
