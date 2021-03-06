/* Include files */

#include "blascompat32.h"
#include "robot_diff_sfun.h"
#include "c1_robot_diff.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_diff_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[18] = { "l", "v", "w", "u", "J",
  "d_estado", "nargin", "nargout", "clock", "dt", "vl", "vr", "X_old", "Y_old",
  "theta_old", "X", "Y", "theta" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "x",
  "theta" };

/* Function Declarations */
static void initialize_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static void initialize_params_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static void enable_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance);
static void disable_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static void ext_mode_exec_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_robot_diff(SFc1_robot_diffInstanceStruct *
  chartInstance);
static void set_sim_state_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance);
static void sf_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance);
static void c1_chartstep_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static void initSimStructsc1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_theta, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[13]);
static void c1_eml_scalar_eg(SFc1_robot_diffInstanceStruct *chartInstance);
static real_T c1_get_ang(SFc1_robot_diffInstanceStruct *chartInstance, real_T
  c1_x);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_robot_diff, const char_T
  *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_robot_diffInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_robot_diff;
  c1_is_active_c1_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_robot_diff = 0U;
}

static void initialize_params_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
}

static void enable_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
  c1_update_debugger_state_c1_robot_diff(chartInstance);
}

static const mxArray *get_sim_state_c1_robot_diff(SFc1_robot_diffInstanceStruct *
  chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_X;
  real_T *c1_Y;
  real_T *c1_theta;
  uint8_T *c1_is_active_c1_robot_diff;
  c1_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_X = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_X;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_Y;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_theta;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_is_active_c1_robot_diff;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_doneDoubleBufferReInit;
  real_T *c1_X;
  real_T *c1_Y;
  real_T *c1_theta;
  uint8_T *c1_is_active_c1_robot_diff;
  c1_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_X = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_X = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "X");
  *c1_Y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "Y");
  *c1_theta = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "theta");
  *c1_is_active_c1_robot_diff = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "is_active_c1_robot_diff");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_robot_diff(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance)
{
}

static void sf_c1_robot_diff(SFc1_robot_diffInstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  real_T *c1_clock;
  real_T *c1_dt;
  real_T *c1_vl;
  real_T *c1_vr;
  real_T *c1_X;
  real_T *c1_X_old;
  real_T *c1_Y_old;
  real_T *c1_theta_old;
  real_T *c1_Y;
  real_T *c1_theta;
  c1_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_theta_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_Y_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_X_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_X = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_vr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_vl = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_clock, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_dt, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_vl, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_vr, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_X, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_X_old, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_Y_old, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_theta_old, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_Y, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_theta, 9U);
  *c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_robot_diff(chartInstance);
  sf_debug_check_for_state_inconsistency(_robot_diffMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_clock;
  real_T c1_dt;
  real_T c1_vl;
  real_T c1_vr;
  real_T c1_X_old;
  real_T c1_Y_old;
  real_T c1_theta_old;
  uint32_T c1_debug_family_var_map[18];
  real_T c1_l;
  real_T c1_v;
  real_T c1_w;
  real_T c1_u[2];
  real_T c1_J[6];
  real_T c1_d_estado[3];
  real_T c1_nargin = 7.0;
  real_T c1_nargout = 3.0;
  real_T c1_X;
  real_T c1_Y;
  real_T c1_theta;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_v[2];
  int32_T c1_i0;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_a[6];
  int32_T c1_i4;
  real_T c1_b[2];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_C[3];
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_c_y;
  real_T *c1_b_clock;
  real_T *c1_b_dt;
  real_T *c1_b_vl;
  real_T *c1_b_vr;
  real_T *c1_b_X_old;
  real_T *c1_b_Y_old;
  real_T *c1_b_theta_old;
  real_T *c1_b_X;
  real_T *c1_b_Y;
  real_T *c1_b_theta;
  int32_T *c1_sfEvent;
  c1_b_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_Y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_theta_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_Y_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_X_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_X = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_vr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_vl = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  c1_hoistedGlobal = *c1_b_clock;
  c1_b_hoistedGlobal = *c1_b_dt;
  c1_c_hoistedGlobal = *c1_b_vl;
  c1_d_hoistedGlobal = *c1_b_vr;
  c1_e_hoistedGlobal = *c1_b_X_old;
  c1_f_hoistedGlobal = *c1_b_Y_old;
  c1_g_hoistedGlobal = *c1_b_theta_old;
  c1_clock = c1_hoistedGlobal;
  c1_dt = c1_b_hoistedGlobal;
  c1_vl = c1_c_hoistedGlobal;
  c1_vr = c1_d_hoistedGlobal;
  c1_X_old = c1_e_hoistedGlobal;
  c1_Y_old = c1_f_hoistedGlobal;
  c1_theta_old = c1_g_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_l, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_v, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_w, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 3U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_J, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_d_estado, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_clock, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_dt, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_vl, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_vr, 11U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_X_old, 12U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Y_old, 13U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_theta_old, 14U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_X, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Y, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 17);
  c1_l = 252.5;
  _SFD_EML_CALL(0U, *c1_sfEvent, 19);
  c1_A = c1_vr + c1_vl;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_v = c1_b_x / 2.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 20);
  c1_b_A = c1_vr - c1_vl;
  c1_c_x = c1_b_A;
  c1_d_x = c1_c_x;
  c1_w = c1_d_x / 252.5;
  _SFD_EML_CALL(0U, *c1_sfEvent, 23);
  c1_b_v[0] = c1_v;
  c1_b_v[1] = c1_w;
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_u[c1_i0] = c1_b_v[c1_i0];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 25);
  c1_e_x = c1_theta_old;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_theta_old;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_J[0] = -c1_f_x;
  c1_J[3] = 0.0;
  c1_J[1] = c1_h_x;
  c1_J[4] = 0.0;
  c1_i1 = 0;
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_J[c1_i1 + 2] = (real_T)c1_i2;
    c1_i1 += 3;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 29);
  for (c1_i3 = 0; c1_i3 < 6; c1_i3++) {
    c1_a[c1_i3] = c1_J[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_b[c1_i4] = c1_u[c1_i4];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_d_estado[c1_i5] = 0.0;
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_d_estado[c1_i6] = 0.0;
  }

  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_C[c1_i7] = c1_d_estado[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_d_estado[c1_i8] = c1_C[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_C[c1_i9] = c1_d_estado[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_d_estado[c1_i10] = c1_C[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_d_estado[c1_i11] = 0.0;
    c1_i12 = 0;
    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_d_estado[c1_i11] += c1_a[c1_i12 + c1_i11] * c1_b[c1_i13];
      c1_i12 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 31);
  c1_b_a = c1_d_estado[0];
  c1_b_b = c1_dt;
  c1_y = c1_b_a * c1_b_b;
  c1_X = c1_X_old + c1_y;
  _SFD_EML_CALL(0U, *c1_sfEvent, 32);
  c1_c_a = c1_d_estado[1];
  c1_c_b = c1_dt;
  c1_b_y = c1_c_a * c1_c_b;
  c1_Y = c1_Y_old + c1_b_y;
  _SFD_EML_CALL(0U, *c1_sfEvent, 33);
  c1_d_a = c1_d_estado[2];
  c1_d_b = c1_dt;
  c1_c_y = c1_d_a * c1_d_b;
  c1_theta = c1_get_ang(chartInstance, c1_theta_old + c1_get_ang(chartInstance,
    c1_c_y));
  _SFD_EML_CALL(0U, *c1_sfEvent, -33);
  sf_debug_symbol_scope_pop();
  *c1_b_X = c1_X;
  *c1_b_Y = c1_Y;
  *c1_b_theta = c1_theta;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_robot_diff(SFc1_robot_diffInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_theta, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_theta), &c1_thisId);
  sf_mex_destroy(&c1_theta);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_theta;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_theta = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_theta), &c1_thisId);
  sf_mex_destroy(&c1_theta);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  real_T c1_b_inData[3];
  int32_T c1_i15;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_b_inData[c1_i14] = (*(real_T (*)[3])c1_inData)[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_u[c1_i15] = c1_b_inData[c1_i15];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv0[3];
  int32_T c1_i16;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_y[c1_i16] = c1_dv0[c1_i16];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d_estado;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i17;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_d_estado = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_estado), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_estado);
  for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
    (*(real_T (*)[3])c1_outData)[c1_i17] = c1_y[c1_i17];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  real_T c1_b_inData[6];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
      c1_b_inData[c1_i20 + c1_i18] = (*(real_T (*)[6])c1_inData)[c1_i20 + c1_i18];
    }

    c1_i18 += 3;
  }

  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      c1_u[c1_i23 + c1_i21] = c1_b_inData[c1_i23 + c1_i21];
    }

    c1_i21 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6])
{
  real_T c1_dv1[6];
  int32_T c1_i24;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c1_i24 = 0; c1_i24 < 6; c1_i24++) {
    c1_y[c1_i24] = c1_dv1[c1_i24];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_J;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_J = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_J), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_J);
  c1_i25 = 0;
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
      (*(real_T (*)[6])c1_outData)[c1_i27 + c1_i25] = c1_y[c1_i27 + c1_i25];
    }

    c1_i25 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i28;
  real_T c1_b_inData[2];
  int32_T c1_i29;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    c1_b_inData[c1_i28] = (*(real_T (*)[2])c1_inData)[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
    c1_u[c1_i29] = c1_b_inData[c1_i29];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_robot_diffInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv2[2];
  int32_T c1_i30;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
    c1_y[c1_i30] = c1_dv2[c1_i30];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i31;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_u), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_u);
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    (*(real_T (*)[2])c1_outData)[c1_i31] = c1_y[c1_i31];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_robot_diff_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[13];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i32;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c1_i32 = 0; c1_i32 < 13; c1_i32++) {
    c1_r0 = &c1_info[c1_i32];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i32);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i32);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[13])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 1310162656U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 1289541292U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1286844044U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_div";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[2].fileTimeLo = 1305343200U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "sin";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[3].fileTimeLo = 1286843950U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[4].name = "eml_scalar_sin";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[4].fileTimeLo = 1286843936U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "";
  c1_info[5].name = "cos";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[5].fileTimeLo = 1286843906U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[6].name = "eml_scalar_cos";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[6].fileTimeLo = 1286843922U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "";
  c1_info[7].name = "mtimes";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].fileTimeLo = 1289541292U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "eml_index_class";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[8].fileTimeLo = 1286843978U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eml_scalar_eg";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[9].fileTimeLo = 1286843996U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "eml_xgemm";
  c1_info[10].dominantType = "int32";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[10].fileTimeLo = 1299098372U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[11].name = "eml_blas_inline";
  c1_info[11].dominantType = "";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[11].fileTimeLo = 1299098368U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[12].name = "eml_refblas_xgemm";
  c1_info[12].dominantType = "int32";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[12].fileTimeLo = 1299098374U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_robot_diffInstanceStruct *chartInstance)
{
}

static real_T c1_get_ang(SFc1_robot_diffInstanceStruct *chartInstance, real_T
  c1_x)
{
  real_T c1_theta;
  uint32_T c1_debug_family_var_map[4];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T *c1_sfEvent;
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_x, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, *c1_sfEvent, 39);
  if (CV_EML_IF(0, 1, 0, c1_x > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, *c1_sfEvent, 40);
    c1_theta = c1_x - 6.2831853071795862;
  } else {
    _SFD_EML_CALL(0U, *c1_sfEvent, 41);
    if (CV_EML_IF(0, 1, 1, c1_x < -3.1415926535897931)) {
      _SFD_EML_CALL(0U, *c1_sfEvent, 42);
      c1_theta = c1_x + 6.2831853071795862;
    } else {
      _SFD_EML_CALL(0U, *c1_sfEvent, 44);
      c1_theta = c1_x;
    }
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, -44);
  sf_debug_symbol_scope_pop();
  return c1_theta;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i33;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i33, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i33;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_robot_diff, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_robot_diff), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_robot_diff);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_robot_diffInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_robot_diffInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_robot_diff_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(100549444U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3655895645U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3175689591U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4208114690U);
}

mxArray *sf_c1_robot_diff_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tBMzxDUxqGjPCDnNi9jroH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_robot_diff(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"X\",},{M[1],M[17],T\"Y\",},{M[1],M[18],T\"theta\",},{M[8],M[0],T\"is_active_c1_robot_diff\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_robot_diff_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_robot_diffInstanceStruct *chartInstance;
    chartInstance = (SFc1_robot_diffInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_diffMachineNumber_,
           1,
           1,
           1,
           10,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_robot_diffMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_robot_diffMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_robot_diffMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"vl");
          _SFD_SET_DATA_PROPS(3,1,1,0,"vr");
          _SFD_SET_DATA_PROPS(4,2,0,1,"X");
          _SFD_SET_DATA_PROPS(5,1,1,0,"X_old");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Y_old");
          _SFD_SET_DATA_PROPS(7,1,1,0,"theta_old");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Y");
          _SFD_SET_DATA_PROPS(9,2,0,1,"theta");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,910);
        _SFD_CV_INIT_EML_FCN(0,1,"get_ang",912,-1,1064);
        _SFD_CV_INIT_EML_IF(0,1,0,944,953,984,1060);
        _SFD_CV_INIT_EML_IF(0,1,1,984,998,1029,1060);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_clock;
          real_T *c1_dt;
          real_T *c1_vl;
          real_T *c1_vr;
          real_T *c1_X;
          real_T *c1_X_old;
          real_T *c1_Y_old;
          real_T *c1_theta_old;
          real_T *c1_Y;
          real_T *c1_theta;
          c1_theta = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_Y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_theta_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_Y_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_X_old = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_X = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_vr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_vl = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_clock);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_dt);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_vl);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_vr);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_X);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_X_old);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_Y_old);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_theta_old);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_Y);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_robot_diffMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_robot_diff_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_robot_diff(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_robot_diffInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc1_robot_diffInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_robot_diff((SFc1_robot_diffInstanceStruct*)
    chartInstanceVar);
  initialize_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_robot_diff(void *chartInstanceVar)
{
  enable_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_robot_diff(void *chartInstanceVar)
{
  disable_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_robot_diff(void *chartInstanceVar)
{
  sf_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_robot_diff(void *chartInstanceVar)
{
  ext_mode_exec_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_robot_diff(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_robot_diff
    ((SFc1_robot_diffInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_robot_diff(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_robot_diff((SFc1_robot_diffInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_robot_diff(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_robot_diff(S);
}

static void sf_opaque_set_sim_state_c1_robot_diff(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_robot_diff(S, st);
}

static void sf_opaque_terminate_c1_robot_diff(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_robot_diffInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_diff_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_robot_diff((SFc1_robot_diffInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_robot_diff(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_robot_diff((SFc1_robot_diffInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_robot_diff_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_robot_diff\",T\"is_active_c1_robot_diff\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c1_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_diff_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,1,7);
      sf_mark_chart_reusable_outputs(S,infoStruct,1,3);
    }

    sf_set_rtw_dwork_info(S,infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4043563614U));
  ssSetChecksum1(S,(2328762577U));
  ssSetChecksum2(S,(849857342U));
  ssSetChecksum3(S,(3919092980U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_robot_diff(SimStruct *S)
{
  SFc1_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc1_robot_diffInstanceStruct *)malloc(sizeof
    (SFc1_robot_diffInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_robot_diffInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_robot_diff;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_robot_diff;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_robot_diff;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_robot_diff;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_robot_diff;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_robot_diff;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_robot_diff;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_robot_diff;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_robot_diff;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_robot_diff;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_robot_diff;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c1_robot_diff;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_robot_diff_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_robot_diff(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_robot_diff(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_robot_diff(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_robot_diff_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
