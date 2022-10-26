//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: roboticArm_loadCell.cpp
//
// Code generated for Simulink model 'roboticArm_loadCell'.
//
// Model version                  : 2.64
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Oct 26 10:45:37 2022
//
// Target selection: franka_emika_panda.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#include "roboticArm_loadCell.h"
#include "roboticArm_loadCell_private.h"
#include "roboticArm_loadCell_dt.h"

SimulinkPandaRobot simulinkPandaRobot_1721602;

// Block signals (default storage)
B_roboticArm_loadCell_T roboticArm_loadCell_B;

// Block states (default storage)
DW_roboticArm_loadCell_T roboticArm_loadCell_DW;

// Real-time model
RT_MODEL_roboticArm_loadCell_T roboticArm_loadCell_M_ =
  RT_MODEL_roboticArm_loadCell_T();
RT_MODEL_roboticArm_loadCell_T *const roboticArm_loadCell_M =
  &roboticArm_loadCell_M_;

// Forward declaration for local functions
static real_T roboticArm_loadCell_xnrm2(int32_T n, const real_T x[42], int32_T
  ix0);
static void roboticArm_loadCell_xscal(int32_T n, real_T a, real_T x[42], int32_T
  ix0);
static real_T roboticArm_loadCell_xnrm2_k(int32_T n, const real_T x[7], int32_T
  ix0);
static void roboticArm_loadCell_xscal_a(int32_T n, real_T a, real_T x[7],
  int32_T ix0);
static void roboticArm_loadCell_xaxpy_od(int32_T n, real_T a, const real_T x[6],
  int32_T ix0, real_T y[42], int32_T iy0);
static void roboticArm_loadCell_xaxpy_o(int32_T n, real_T a, const real_T x[42],
  int32_T ix0, real_T y[6], int32_T iy0);
static real_T roboticArm_loadCell_xdotc(int32_T n, const real_T x[42], int32_T
  ix0, const real_T y[42], int32_T iy0);
static void roboticArm_loadCell_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[42], int32_T iy0);
static real_T roboticArm_loadCell_xdotc_d(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0);
static void roboticArm_loadCell_xaxpy_odx(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T roboticArm_loadCell_xdotc_dh(int32_T n, const real_T x[49],
  int32_T ix0, const real_T y[49], int32_T iy0);
static void roboticArm_loadCell_xaxpy_odxo(int32_T n, real_T a, int32_T ix0,
  real_T y[49], int32_T iy0);
static void roboticArm_loadCell_xscal_ar(real_T a, real_T x[36], int32_T ix0);
static void roboticArm_loadCell_xscal_arg(real_T a, real_T x[49], int32_T ix0);
static void roboticArm_loadCell_xswap(real_T x[49], int32_T ix0, int32_T iy0);
static void roboticArm_loadCell_xswap_o(real_T x[36], int32_T ix0, int32_T iy0);
static void roboticArm_loadCell_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void roboticArm_loadCell_xrot(real_T x[49], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void roboticArm_loadCell_xrot_c(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void roboticArm_loadCell_svd(const real_T A[42], real_T U[36], real_T s[6],
  real_T V[49]);
pthread_t rtExtModeServerStepThr;
static sem_t ext_mode_main_step_sem;
boolean_T extModeServerStepFinished= true;
void* rtExtModeServerStepThread(void *argv)
{
  for (;;) {
    sem_wait(&ext_mode_main_step_sem);
    extModeServerStepFinished = false;

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(roboticArm_loadCell_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(roboticArm_loadCell_M, true);
      }
    }

    rtExtModeCheckEndTrigger();
    extModeServerStepFinished = true;
  }
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static real_T roboticArm_loadCell_xnrm2(int32_T n, const real_T x[42], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xscal(int32_T n, real_T a, real_T x[42], int32_T
  ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static real_T roboticArm_loadCell_xnrm2_k(int32_T n, const real_T x[7], int32_T
  ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xscal_a(int32_T n, real_T a, real_T x[7],
  int32_T ix0)
{
  int32_T b;
  int32_T k;
  b = (ix0 + n) - 1;
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xaxpy_od(int32_T n, real_T a, const real_T x[6],
  int32_T ix0, real_T y[42], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xaxpy_o(int32_T n, real_T a, const real_T x[42],
  int32_T ix0, real_T y[6], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static real_T roboticArm_loadCell_xdotc(int32_T n, const real_T x[42], int32_T
  ix0, const real_T y[42], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[42], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static real_T roboticArm_loadCell_xdotc_d(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xaxpy_odx(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static real_T roboticArm_loadCell_xdotc_dh(int32_T n, const real_T x[49],
  int32_T ix0, const real_T y[49], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xaxpy_odxo(int32_T n, real_T a, int32_T ix0,
  real_T y[49], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xscal_ar(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xscal_arg(real_T a, real_T x[49], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 6; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xswap(real_T x[49], int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T k;
  int32_T temp_tmp;
  int32_T tmp;
  for (k = 0; k < 7; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xswap_o(real_T x[36], int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T k;
  int32_T temp_tmp;
  int32_T tmp;
  for (k = 0; k < 6; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T ads;
  real_T bds;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    scale = 0.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }
  }

  *a = scale;
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xrot(real_T x[49], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  real_T temp_tmp_0;
  real_T temp_tmp_2;
  int32_T k;
  int32_T temp_tmp;
  int32_T temp_tmp_1;
  for (k = 0; k < 7; k++) {
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_xrot_c(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  real_T temp_tmp_0;
  real_T temp_tmp_2;
  int32_T k;
  int32_T temp_tmp;
  int32_T temp_tmp_1;
  for (k = 0; k < 6; k++) {
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

// Function for MATLAB Function: '<S2>/JT2J_star'
static void roboticArm_loadCell_svd(const real_T A[42], real_T U[36], real_T s[6],
  real_T V[49])
{
  real_T b_A[42];
  real_T b_s[7];
  real_T e[7];
  real_T work[6];
  real_T emm1;
  real_T nrm;
  real_T r;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  int32_T i;
  int32_T qjj;
  int32_T qp1jj;
  int32_T qp1q;
  int32_T qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  memcpy(&b_A[0], &A[0], 42U * sizeof(real_T));
  for (i = 0; i < 7; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  memset(&U[0], 0, 36U * sizeof(real_T));
  memset(&V[0], 0, 49U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    qq = 6 * i + i;
    apply_transform = false;
    nrm = roboticArm_loadCell_xnrm2(6 - i, b_A, qq + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq] < 0.0) {
        b_s[i] = -nrm;
      } else {
        b_s[i] = nrm;
      }

      if (fabs(b_s[i]) >= 1.0020841800044864E-292) {
        roboticArm_loadCell_xscal(6 - i, 1.0 / b_s[i], b_A, qq + 1);
      } else {
        qp1q = (qq - i) + 6;
        for (qjj = qq; qjj < qp1q; qjj++) {
          b_A[qjj] /= b_s[i];
        }
      }

      b_A[qq]++;
      b_s[i] = -b_s[i];
    } else {
      b_s[i] = 0.0;
    }

    for (qp1q = i + 1; qp1q + 1 < 8; qp1q++) {
      qjj = 6 * qp1q + i;
      if (apply_transform) {
        roboticArm_loadCell_xaxpy(6 - i, -(roboticArm_loadCell_xdotc(6 - i, b_A,
          qq + 1, b_A, qjj + 1) / b_A[i + 6 * i]), qq + 1, b_A, qjj + 1);
      }

      e[qp1q] = b_A[qjj];
    }

    for (qq = i; qq + 1 < 7; qq++) {
      U[qq + 6 * i] = b_A[6 * i + qq];
    }

    nrm = roboticArm_loadCell_xnrm2_k(6 - i, e, i + 2);
    if (nrm == 0.0) {
      e[i] = 0.0;
    } else {
      if (e[i + 1] < 0.0) {
        e[i] = -nrm;
      } else {
        e[i] = nrm;
      }

      nrm = e[i];
      if (fabs(e[i]) >= 1.0020841800044864E-292) {
        roboticArm_loadCell_xscal_a(6 - i, 1.0 / e[i], e, i + 2);
      } else {
        for (qq = i + 1; qq < 7; qq++) {
          e[qq] /= nrm;
        }
      }

      e[i + 1]++;
      e[i] = -e[i];
      for (qq = i + 1; qq + 1 < 7; qq++) {
        work[qq] = 0.0;
      }

      for (qq = i + 1; qq + 1 < 8; qq++) {
        roboticArm_loadCell_xaxpy_o(5 - i, e[qq], b_A, (i + 6 * qq) + 2, work, i
          + 2);
      }

      for (qq = i + 1; qq + 1 < 8; qq++) {
        roboticArm_loadCell_xaxpy_od(5 - i, -e[qq] / e[i + 1], work, i + 2, b_A,
          (i + 6 * qq) + 2);
      }
    }

    for (qq = i + 1; qq + 1 < 8; qq++) {
      V[qq + 7 * i] = e[qq];
    }
  }

  i = 5;
  b_s[5] = b_A[35];
  b_s[6] = 0.0;
  e[5] = b_A[41];
  e[6] = 0.0;
  for (qq = 0; qq < 6; qq++) {
    U[qq + 30] = 0.0;
  }

  U[35] = 1.0;
  for (qp1q = 4; qp1q >= 0; qp1q--) {
    qq = 6 * qp1q + qp1q;
    if (b_s[qp1q] != 0.0) {
      for (qp1jj = qp1q + 1; qp1jj + 1 < 7; qp1jj++) {
        qjj = (6 * qp1jj + qp1q) + 1;
        roboticArm_loadCell_xaxpy_odx(6 - qp1q, -(roboticArm_loadCell_xdotc_d(6
          - qp1q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (qjj = qp1q; qjj + 1 < 7; qjj++) {
        qp1jj = 6 * qp1q + qjj;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (qq = 0; qq < qp1q; qq++) {
        U[qq + 6 * qp1q] = 0.0;
      }
    } else {
      for (qjj = 0; qjj < 6; qjj++) {
        U[qjj + 6 * qp1q] = 0.0;
      }

      U[qq] = 1.0;
    }
  }

  for (qq = 6; qq >= 0; qq--) {
    if ((qq + 1 <= 5) && (e[qq] != 0.0)) {
      qp1q = (7 * qq + qq) + 2;
      for (qjj = qq + 1; qjj + 1 < 8; qjj++) {
        qp1jj = (7 * qjj + qq) + 2;
        roboticArm_loadCell_xaxpy_odxo(6 - qq, -(roboticArm_loadCell_xdotc_dh(6
          - qq, V, qp1q, V, qp1jj) / V[qp1q - 1]), qp1q, V, qp1jj);
      }
    }

    for (qp1q = 0; qp1q < 7; qp1q++) {
      V[qp1q + 7 * qq] = 0.0;
    }

    V[qq + 7 * qq] = 1.0;
  }

  for (qq = 0; qq < 7; qq++) {
    nrm = e[qq];
    if (b_s[qq] != 0.0) {
      rt = fabs(b_s[qq]);
      r = b_s[qq] / rt;
      b_s[qq] = rt;
      if (qq + 1 < 7) {
        nrm /= r;
      }

      if (qq + 1 <= 6) {
        roboticArm_loadCell_xscal_ar(r, U, 6 * qq + 1);
      }
    }

    if ((qq + 1 < 7) && (nrm != 0.0)) {
      rt = fabs(nrm);
      r = rt / nrm;
      nrm = rt;
      b_s[qq + 1] *= r;
      roboticArm_loadCell_xscal_arg(r, V, 7 * (qq + 1) + 1);
    }

    e[qq] = nrm;
  }

  qq = 0;
  nrm = 0.0;
  for (qp1q = 0; qp1q < 7; qp1q++) {
    nrm = fmax(nrm, fmax(fabs(b_s[qp1q]), fabs(e[qp1q])));
  }

  while ((i + 2 > 0) && (qq < 75)) {
    qp1q = i + 1;
    exitg1 = false;
    while (!(exitg1 || (qp1q == 0))) {
      rt = fabs(e[qp1q - 1]);
      if (rt <= (fabs(b_s[qp1q - 1]) + fabs(b_s[qp1q])) * 2.2204460492503131E-16)
      {
        e[qp1q - 1] = 0.0;
        exitg1 = true;
      } else if ((rt <= 1.0020841800044864E-292) || ((qq > 20) && (rt <=
                   2.2204460492503131E-16 * nrm))) {
        e[qp1q - 1] = 0.0;
        exitg1 = true;
      } else {
        qp1q--;
      }
    }

    if (i + 1 == qp1q) {
      qp1jj = 4;
    } else {
      qjj = i + 2;
      qp1jj = i + 2;
      exitg1 = false;
      while ((!exitg1) && (qp1jj >= qp1q)) {
        qjj = qp1jj;
        if (qp1jj == qp1q) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (qp1jj < i + 2) {
            rt = fabs(e[qp1jj - 1]);
          }

          if (qp1jj > qp1q + 1) {
            rt += fabs(e[qp1jj - 2]);
          }

          r = fabs(b_s[qp1jj - 1]);
          if ((r <= 2.2204460492503131E-16 * rt) || (r <=
               1.0020841800044864E-292)) {
            b_s[qp1jj - 1] = 0.0;
            exitg1 = true;
          } else {
            qp1jj--;
          }
        }
      }

      if (qjj == qp1q) {
        qp1jj = 3;
      } else if (i + 2 == qjj) {
        qp1jj = 1;
      } else {
        qp1jj = 2;
        qp1q = qjj;
      }
    }

    switch (qp1jj) {
     case 1:
      rt = e[i];
      e[i] = 0.0;
      for (qjj = i; qjj + 1 >= qp1q + 1; qjj--) {
        roboticArm_loadCell_xrotg(&b_s[qjj], &rt, &r, &sqds);
        if (qjj + 1 > qp1q + 1) {
          smm1 = e[qjj - 1];
          rt = smm1 * -sqds;
          e[qjj - 1] = smm1 * r;
        }

        roboticArm_loadCell_xrot(V, 7 * qjj + 1, 7 * (i + 1) + 1, r, sqds);
      }
      break;

     case 2:
      rt = e[qp1q - 1];
      e[qp1q - 1] = 0.0;
      for (qjj = qp1q; qjj < i + 2; qjj++) {
        roboticArm_loadCell_xrotg(&b_s[qjj], &rt, &r, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= r;
        roboticArm_loadCell_xrot_c(U, 6 * qjj + 1, 6 * (qp1q - 1) + 1, r, sqds);
      }
      break;

     case 3:
      rt = b_s[i + 1];
      r = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[i])), fabs(e[i])), fabs
                    (b_s[qp1q])), fabs(e[qp1q]));
      rt /= r;
      smm1 = b_s[i] / r;
      emm1 = e[i] / r;
      sqds = b_s[qp1q] / r;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      smm1 = e[qp1q] / r * sqds;
      for (qjj = qp1q + 1; qjj <= i + 1; qjj++) {
        roboticArm_loadCell_xrotg(&rt, &smm1, &r, &sqds);
        if (qjj > qp1q + 1) {
          e[qjj - 2] = rt;
        }

        smm1 = e[qjj - 1];
        emm1 = b_s[qjj - 1];
        rt = emm1 * r + smm1 * sqds;
        e[qjj - 1] = smm1 * r - emm1 * sqds;
        smm1 = sqds * b_s[qjj];
        b_s[qjj] *= r;
        roboticArm_loadCell_xrot(V, 7 * (qjj - 1) + 1, 7 * qjj + 1, r, sqds);
        roboticArm_loadCell_xrotg(&rt, &smm1, &r, &sqds);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * r + sqds * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -sqds + r * b_s[qjj];
        smm1 = sqds * e[qjj];
        e[qjj] *= r;
        if (qjj < 6) {
          roboticArm_loadCell_xrot_c(U, 6 * (qjj - 1) + 1, 6 * qjj + 1, r, sqds);
        }
      }

      e[i] = rt;
      qq++;
      break;

     default:
      if (b_s[qp1q] < 0.0) {
        b_s[qp1q] = -b_s[qp1q];
        roboticArm_loadCell_xscal_arg(-1.0, V, 7 * qp1q + 1);
      }

      qq = qp1q + 1;
      while ((qp1q + 1 < 7) && (b_s[qp1q] < b_s[qq])) {
        rt = b_s[qp1q];
        b_s[qp1q] = b_s[qq];
        b_s[qq] = rt;
        roboticArm_loadCell_xswap(V, 7 * qp1q + 1, 7 * (qp1q + 1) + 1);
        if (qp1q + 1 < 6) {
          roboticArm_loadCell_xswap_o(U, 6 * qp1q + 1, 6 * (qp1q + 1) + 1);
        }

        qp1q = qq;
        qq++;
      }

      qq = 0;
      i--;
      break;
    }
  }

  for (i = 0; i < 6; i++) {
    s[i] = b_s[i];
  }
}

// Model step function
void roboticArm_loadCell_step(void)
{
  real_T V[49];
  real_T J[42];
  real_T rtb_MathFunction1_tmp[42];
  real_T rtb_MathFunction1_tmp_0[42];
  real_T U[36];
  real_T b[36];
  real_T rtb_TSamp[6];
  real_T rtb_TSamp_0[6];
  real_T rtb_VectorConcatenate[6];
  real_T rtb_VectorConcatenate_0[6];
  real_T s[6];
  real_T tmp[6];
  real_T J_0;
  real_T rtb_Sum;
  real_T rtb_TSamp_g;
  int32_T b_k;
  int32_T i;
  int32_T i_0;
  int32_T rtb_MathFunction1_tmp_tmp;
  char_T *sErr;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator1;

  // Reset subsysRan breadcrumbs
  srClearBC(roboticArm_loadCell_DW.FFFBPIcntrl_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(roboticArm_loadCell_DW.Subsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(roboticArm_loadCell_DW.TorqueBias_SubsysRanBC);

  // S-Function (get_duration_period): '<S3>/Get Duration Period1'
  {
    if (simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      // Wait for the control thread signal
      if ((bool)roboticArm_loadCell_DW.GetDurationPeriod1_DWORK1) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();
      roboticArm_loadCell_B.GetDurationPeriod1 =
        simulinkPandaRobot_1721602.getSampleTime();
    }
  }

  // S-Function (get_model): '<S2>/Get Model'
  {
    if (simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      // Wait for the control thread signal
      if ((bool)roboticArm_loadCell_DW.GetModel_DWORK1) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();

      // robot pose
      simulinkPandaRobot_1721602.copyRobotPose
        (&roboticArm_loadCell_B.GetModel_o1[0]);

      // bodyJacobian
      simulinkPandaRobot_1721602.copyBodyJacobian
        (&roboticArm_loadCell_B.GetModel_o2[0]);

      // zeroJacobian
      simulinkPandaRobot_1721602.copyZeroJacobian
        (&roboticArm_loadCell_B.GetModel_o3[0]);

      // mass
      simulinkPandaRobot_1721602.copyMass(&roboticArm_loadCell_B.GetModel_o4[0]);

      // coriolis
      simulinkPandaRobot_1721602.copyCoriolis
        (&roboticArm_loadCell_B.GetModel_o5[0]);

      // gravity
      simulinkPandaRobot_1721602.copyGravity(&roboticArm_loadCell_B.GetModel_o6
        [0]);
    }
  }

  // S-Function (get_robot_state): '<S2>/Get Robot State'
  {
    // Wait for the control thread signal
    if ((bool)roboticArm_loadCell_DW.GetRobotState_DWORK1 &&
        simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      simulinkPandaRobot_1721602.waitForControlThreadStep();
    }

    // If control loop threw exeption terminate execution
    simulinkPandaRobot_1721602.checkIfAndHandleException();
    if (!simulinkPandaRobot_1721602.getCurrentlyInFirstControlStep()) {
      std::vector<std::string> output_signals;
      signalsStringToSignalsVector(output_signals,"tau_J");

      //copy outputs
      simulinkPandaRobot_1721602.copyOutputSignal(output_signals, 0,
        &roboticArm_loadCell_B.GetRobotState[0]);
    }
  }

  // S-Function (get_duration_period): '<S2>/Duration Period'
  {
    if (simulinkPandaRobot_1721602.getcontrolThreadHasBeendSpawned()) {
      // Wait for the control thread signal
      if ((bool)roboticArm_loadCell_DW.DurationPeriod_DWORK1) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();
      roboticArm_loadCell_B.DurationPeriod =
        simulinkPandaRobot_1721602.getSampleTime();
    }
  }

  // Sum: '<S10>/Sum' incorporates:
  //   Delay: '<S10>/Delay'

  rtb_Sum = roboticArm_loadCell_B.GetDurationPeriod1 +
    roboticArm_loadCell_DW.Delay_DSTATE;

  // Lookup_n-D: '<S3>/1-D Lookup Table1' incorporates:
  //   Lookup_n-D: '<S3>/1-D Lookup Table2'
  //   Lookup_n-D: '<S3>/1-D Lookup Table3'
  //   Lookup_n-D: '<S3>/1-D Lookup Table4'
  //   Lookup_n-D: '<S3>/1-D Lookup Table5'
  //   Lookup_n-D: '<S3>/1-D Lookup Table6'
  //   Switch: '<S10>/Switch'

  roboticArm_loadCell_B.uDLookupTable1 = look1_binlxpw(rtb_Sum,
    roboticArm_loadCell_ConstP.pooled5, roboticArm_loadCell_ConstP.pooled4,
    9999U);

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[0] = roboticArm_loadCell_B.uDLookupTable1;

  // Lookup_n-D: '<S3>/1-D Lookup Table2'
  roboticArm_loadCell_B.uDLookupTable2 = roboticArm_loadCell_B.uDLookupTable1;

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[1] = roboticArm_loadCell_B.uDLookupTable2;

  // Lookup_n-D: '<S3>/1-D Lookup Table5'
  roboticArm_loadCell_B.uDLookupTable5 = roboticArm_loadCell_B.uDLookupTable1;

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[2] = roboticArm_loadCell_B.uDLookupTable5;

  // Lookup_n-D: '<S3>/1-D Lookup Table3'
  roboticArm_loadCell_B.uDLookupTable3 = roboticArm_loadCell_B.uDLookupTable1;

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[3] = roboticArm_loadCell_B.uDLookupTable3;

  // Lookup_n-D: '<S3>/1-D Lookup Table4'
  roboticArm_loadCell_B.uDLookupTable4 = roboticArm_loadCell_B.uDLookupTable1;

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[4] = roboticArm_loadCell_B.uDLookupTable4;

  // Lookup_n-D: '<S3>/1-D Lookup Table6'
  roboticArm_loadCell_B.uDLookupTable6 = roboticArm_loadCell_B.uDLookupTable1;

  // SignalConversion generated from: '<S3>/Vector Concatenate'
  rtb_VectorConcatenate[5] = roboticArm_loadCell_B.uDLookupTable6;

  // RelationalOperator: '<S2>/Relational Operator' incorporates:
  //   Constant: '<S2>/Constant'
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

  rtb_RelationalOperator = (roboticArm_loadCell_DW.DiscreteTimeIntegrator_DSTATE
    > 0.1);

  // Outputs for Enabled SubSystem: '<S1>/FF + FB (PI)  cntrl' incorporates:
  //   EnablePort: '<S4>/Enable'

  for (b_k = 0; b_k < 6; b_k++) {
    for (i = 0; i < 7; i++) {
      // Math: '<S2>/Math Function1' incorporates:
      //   Math: '<S4>/Math Function1'
      //   S-Function (get_model): '<S2>/Get Model'

      rtb_MathFunction1_tmp[i + 7 * b_k] = roboticArm_loadCell_B.GetModel_o3[6 *
        i + b_k];

      // MATLAB Function: '<S2>/JT2J_star' incorporates:
      //   Math: '<S2>/Math Function1'

      J[b_k + 6 * i] = rtb_MathFunction1_tmp[7 * b_k + i];
    }
  }

  // End of Outputs for SubSystem: '<S1>/FF + FB (PI)  cntrl'

  // MATLAB Function: '<S2>/JT2J_star'
  rtb_RelationalOperator1 = true;
  for (b_k = 0; b_k < 42; b_k++) {
    J_0 = J[b_k];
    if (rtb_RelationalOperator1 && (rtIsInf(J_0) || rtIsNaN(J_0))) {
      rtb_RelationalOperator1 = false;
    }
  }

  if (rtb_RelationalOperator1) {
    roboticArm_loadCell_svd(J, U, s, V);
  } else {
    for (b_k = 0; b_k < 36; b_k++) {
      U[b_k] = (rtNaN);
    }

    for (i = 0; i < 6; i++) {
      s[i] = (rtNaN);
    }
  }

  for (b_k = 0; b_k < 42; b_k++) {
    J[b_k] = 0.0;
  }

  for (b_k = 0; b_k < 6; b_k++) {
    i = b_k + 6 * b_k;
    J[i] = s[b_k];
    J_0 = J[i];
    rtb_TSamp[b_k] = 1.0 / (J_0 * J_0);
    s[b_k] = J_0;
  }

  for (b_k = 0; b_k < 36; b_k++) {
    b[b_k] = 0.0;
  }

  for (b_k = 0; b_k < 6; b_k++) {
    b[b_k + 6 * b_k] = rtb_TSamp[b_k];
  }

  // RelationalOperator: '<S2>/Relational Operator1' incorporates:
  //   Constant: '<S2>/Constant3'
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

  rtb_RelationalOperator1 =
    (roboticArm_loadCell_DW.DiscreteTimeIntegrator_DSTATE > 0.05);

  // Outputs for Enabled SubSystem: '<S2>/Torque Bias' incorporates:
  //   EnablePort: '<S9>/Enable'

  // RelationalOperator: '<S6>/FixPt Relational Operator' incorporates:
  //   UnitDelay: '<S6>/Delay Input1'
  //
  //  Block description for '<S6>/Delay Input1':
  //
  //   Store in Global RAM

  if (static_cast<int32_T>(rtb_RelationalOperator1) > static_cast<int32_T>
      (roboticArm_loadCell_DW.DelayInput1_DSTATE)) {
    for (i = 0; i < 7; i++) {
      // Sum: '<S9>/Add'
      roboticArm_loadCell_B.Add[i] = roboticArm_loadCell_B.GetRobotState[i] -
        roboticArm_loadCell_B.GetModel_o6[i];
    }

    srUpdateBC(roboticArm_loadCell_DW.TorqueBias_SubsysRanBC);
  }

  // End of RelationalOperator: '<S6>/FixPt Relational Operator'
  // End of Outputs for SubSystem: '<S2>/Torque Bias'

  // Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (rtb_RelationalOperator) {
    for (i = 0; i < 7; i++) {
      // Inport: '<S8>/tau_im_in' incorporates:
      //   Sum: '<S2>/Add'

      roboticArm_loadCell_B.tau_im_in[i] =
        (roboticArm_loadCell_B.GetRobotState[i] -
         roboticArm_loadCell_B.GetModel_o6[i]) - roboticArm_loadCell_B.Add[i];
    }

    srUpdateBC(roboticArm_loadCell_DW.Subsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S2>/Subsystem'

  // MATLAB Function: '<S2>/JT2J_star' incorporates:
  //   Math: '<S2>/Math Function1'

  for (b_k = 0; b_k < 6; b_k++) {
    for (i = 0; i < 7; i++) {
      J[i + 7 * b_k] = 0.0;
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      for (i = 0; i < 7; i++) {
        rtb_MathFunction1_tmp_tmp = 7 * b_k + i;
        J[rtb_MathFunction1_tmp_tmp] += rtb_MathFunction1_tmp[7 * i_0 + i] * U[6
          * b_k + i_0];
      }
    }

    for (i = 0; i < 7; i++) {
      rtb_MathFunction1_tmp_0[i + 7 * b_k] = 0.0;
    }
  }

  for (b_k = 0; b_k < 6; b_k++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      for (i = 0; i < 7; i++) {
        rtb_MathFunction1_tmp_tmp = 7 * b_k + i;
        rtb_MathFunction1_tmp_0[rtb_MathFunction1_tmp_tmp] += J[7 * i_0 + i] *
          b[6 * b_k + i_0];
      }
    }
  }

  // Math: '<S2>/Math Function2' incorporates:
  //   MATLAB Function: '<S2>/JT2J_star'

  for (b_k = 0; b_k < 7; b_k++) {
    for (i = 0; i < 6; i++) {
      J[i + 6 * b_k] = 0.0;
    }
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    for (b_k = 0; b_k < 7; b_k++) {
      for (i = 0; i < 6; i++) {
        rtb_MathFunction1_tmp_tmp = 6 * b_k + i;
        J[rtb_MathFunction1_tmp_tmp] += rtb_MathFunction1_tmp_0[7 * i_0 + b_k] *
          U[6 * i_0 + i];
      }
    }

    // Product: '<S2>/Product' incorporates:
    //   MATLAB Function: '<S2>/JT2J_star'

    roboticArm_loadCell_B.Product[i_0] = 0.0;
  }

  // End of Math: '<S2>/Math Function2'
  for (b_k = 0; b_k < 7; b_k++) {
    for (i = 0; i < 6; i++) {
      // Product: '<S2>/Product'
      roboticArm_loadCell_B.Product[i] += J[6 * b_k + i] *
        roboticArm_loadCell_B.tau_im_in[b_k];
    }
  }

  // Outputs for Enabled SubSystem: '<S1>/FF + FB (PI)  cntrl' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (rtb_RelationalOperator) {
    roboticArm_loadCell_DW.FFFBPIcntrl_MODE = true;
    for (i = 0; i < 6; i++) {
      // Sum: '<S4>/Add1'
      J_0 = rtb_VectorConcatenate[i] - roboticArm_loadCell_B.Product[i];

      // SampleTimeMath: '<S5>/TSamp'
      //
      //  About '<S5>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )

      rtb_TSamp_g = J_0 * 1000.0;

      // DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
      roboticArm_loadCell_B.DiscreteTimeIntegrator1[i] =
        roboticArm_loadCell_DW.DiscreteTimeIntegrator1_DSTATE[i];

      // Sum: '<S5>/Diff' incorporates:
      //   UnitDelay: '<S5>/UD'
      //
      //  Block description for '<S5>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S5>/UD':
      //
      //   Store in Global RAM

      rtb_TSamp_0[i] = rtb_TSamp_g - roboticArm_loadCell_DW.UD_DSTATE[i];

      // Sum: '<S4>/Add1'
      s[i] = J_0;

      // SampleTimeMath: '<S5>/TSamp'
      //
      //  About '<S5>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )

      rtb_TSamp[i] = rtb_TSamp_g;
    }

    for (b_k = 0; b_k < 6; b_k++) {
      // Sum: '<S4>/Add2' incorporates:
      //   Gain: '<S4>/Kd'

      J_0 = 0.0;
      for (i = 0; i < 6; i++) {
        J_0 += roboticArm_loadCell_ConstP.Kd_Gain[6 * i + b_k] * rtb_TSamp_0[i];
      }

      rtb_VectorConcatenate_0[b_k] = rtb_VectorConcatenate[b_k] + J_0;

      // Gain: '<S4>/Kp'
      tmp[b_k] = 0.0;
    }

    // Gain: '<S4>/Kp'
    for (b_k = 0; b_k < 6; b_k++) {
      for (i = 0; i < 6; i++) {
        tmp[i] += roboticArm_loadCell_ConstP.Kp_Gain[6 * b_k + i] * s[b_k];
      }
    }

    // Sum: '<S4>/Add2' incorporates:
    //   Gain: '<S4>/Ki'
    //   Gain: '<S4>/time_sample_correction'

    for (b_k = 0; b_k < 6; b_k++) {
      J_0 = 0.0;
      for (i = 0; i < 6; i++) {
        J_0 += roboticArm_loadCell_ConstP.Ki_Gain[6 * i + b_k] * (1000.0 *
          roboticArm_loadCell_B.DiscreteTimeIntegrator1[i]);
      }

      rtb_VectorConcatenate[b_k] = (rtb_VectorConcatenate_0[b_k] + tmp[b_k]) +
        J_0;
    }

    for (b_k = 0; b_k < 7; b_k++) {
      // Product: '<S4>/Product' incorporates:
      //   Math: '<S4>/Math Function1'

      roboticArm_loadCell_B.Product_i[b_k] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      for (b_k = 0; b_k < 7; b_k++) {
        // Product: '<S4>/Product' incorporates:
        //   Math: '<S4>/Math Function1'

        roboticArm_loadCell_B.Product_i[b_k] += rtb_MathFunction1_tmp[7 * i +
          b_k] * rtb_VectorConcatenate[i];
      }

      // Update for UnitDelay: '<S5>/UD'
      //
      //  Block description for '<S5>/UD':
      //
      //   Store in Global RAM

      roboticArm_loadCell_DW.UD_DSTATE[i] = rtb_TSamp[i];

      // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
      //   Product: '<S4>/Product1'

      roboticArm_loadCell_DW.DiscreteTimeIntegrator1_DSTATE[i] += s[i] *
        roboticArm_loadCell_B.DurationPeriod * 0.001;
    }

    srUpdateBC(roboticArm_loadCell_DW.FFFBPIcntrl_SubsysRanBC);
  } else if (roboticArm_loadCell_DW.FFFBPIcntrl_MODE) {
    // Disable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
    for (i = 0; i < 6; i++) {
      roboticArm_loadCell_DW.DiscreteTimeIntegrator1_DSTATE[i] =
        roboticArm_loadCell_B.DiscreteTimeIntegrator1[i];
    }

    // End of Disable for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
    roboticArm_loadCell_DW.FFFBPIcntrl_MODE = false;
  }

  // End of Outputs for SubSystem: '<S1>/FF + FB (PI)  cntrl'

  // S-Function (apply_control): '<Root>/Apply Control'
  {
    // S-Function Block: <Root>/Apply Control
    if ((bool)roboticArm_loadCell_DW.ApplyControl_DWORK1) {
      // Wait for the control thread signal
      if ((bool)roboticArm_loadCell_DW.ApplyControl_DWORK2) {
        simulinkPandaRobot_1721602.waitForControlThreadStep();
      }

      // If control loop threw exeption terminate execution
      simulinkPandaRobot_1721602.checkIfAndHandleException();

      // copy inputs
      simulinkPandaRobot_1721602.copyInputSignal
        (&roboticArm_loadCell_B.Product_i[0], 0);

      // notify control thread that the inputs have been read
      simulinkPandaRobot_1721602.notifyControlThreadToContinue();
    } else if (!(bool)roboticArm_loadCell_DW.ApplyControl_DWORK1) {
      // Its the first time _step() function is called -->
      // Initialize according to settings parsed from the mask
      // and spawn control thread
      simulinkPandaRobot_1721602.applyRobotSettings();
      simulinkPandaRobot_1721602.spawnControlThread();
      roboticArm_loadCell_DW.ApplyControl_DWORK1 = 1;
    }
  }

  // S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
  b_k = 48;
  LibOutputs_Network(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U],
                     &roboticArm_loadCell_B.UDPReceive_o1[0U], &b_k);
  if (*sErr != 0) {
    rtmSetErrorStatus(roboticArm_loadCell_M, sErr);
    rtmSetStopRequested(roboticArm_loadCell_M, 1);
  }

  // End of S-Function (sdspFromNetwork): '<Root>/UDP Receive'

  // S-Function (byte2any): '<Root>/Byte Unpack'

  // Unpack: <Root>/Byte Unpack
  (void) memcpy(&roboticArm_loadCell_B.ByteUnpack[0],
                &roboticArm_loadCell_B.UDPReceive_o1[0],
                48);

  // Switch: '<S10>/Switch1' incorporates:
  //   Delay: '<S10>/Delay'
  //   Switch: '<S10>/Switch'

  roboticArm_loadCell_DW.Delay_DSTATE = rtb_Sum;

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S2>/KP1'

  roboticArm_loadCell_DW.DiscreteTimeIntegrator_DSTATE += 1000.0 *
    roboticArm_loadCell_B.DurationPeriod * 0.001;

  // Update for UnitDelay: '<S6>/Delay Input1'
  //
  //  Block description for '<S6>/Delay Input1':
  //
  //   Store in Global RAM

  roboticArm_loadCell_DW.DelayInput1_DSTATE = rtb_RelationalOperator1;

  // External mode
  if (extModeServerStepFinished) {
    rtExtModeUploadCheckTrigger(1);

    {                                  // Sample time: [0.001s, 0.0s]
      rtExtModeUpload(0, (real_T)roboticArm_loadCell_M->Timing.taskTime0);
    }

    sem_post(&ext_mode_main_step_sem);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(roboticArm_loadCell_M)!=-1) &&
        !((rtmGetTFinal(roboticArm_loadCell_M)-
           roboticArm_loadCell_M->Timing.taskTime0) >
          roboticArm_loadCell_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(roboticArm_loadCell_M, "Simulation finished");
    }

    if (rtmGetStopRequested(roboticArm_loadCell_M)) {
      rtmSetErrorStatus(roboticArm_loadCell_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  roboticArm_loadCell_M->Timing.taskTime0 =
    ((time_T)(++roboticArm_loadCell_M->Timing.clockTick0)) *
    roboticArm_loadCell_M->Timing.stepSize0;
}

// Model initialize function
void roboticArm_loadCell_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(roboticArm_loadCell_M, -1);
  roboticArm_loadCell_M->Timing.stepSize0 = 0.001;

  // External mode info
  rtParseArgsForExtMode(0,NULL);
  roboticArm_loadCell_M->Sizes.checksums[0] = (2619475441U);
  roboticArm_loadCell_M->Sizes.checksums[1] = (3075703303U);
  roboticArm_loadCell_M->Sizes.checksums[2] = (768819640U);
  roboticArm_loadCell_M->Sizes.checksums[3] = (1712712277U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    roboticArm_loadCell_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &roboticArm_loadCell_DW.FFFBPIcntrl_SubsysRanBC;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&roboticArm_loadCell_DW.Subsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&roboticArm_loadCell_DW.TorqueBias_SubsysRanBC;
    rteiSetModelMappingInfoPtr(roboticArm_loadCell_M->extModeInfo,
      &roboticArm_loadCell_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(roboticArm_loadCell_M->extModeInfo,
                        roboticArm_loadCell_M->Sizes.checksums);
    rteiSetTPtr(roboticArm_loadCell_M->extModeInfo, rtmGetTPtr
                (roboticArm_loadCell_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    roboticArm_loadCell_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;
  }

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(roboticArm_loadCell_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(roboticArm_loadCell_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(roboticArm_loadCell_M, true);
    }
  }

  rtERTExtModeStartMsg();
  sem_init(&ext_mode_main_step_sem, 0, 0);
  pthread_create( &rtExtModeServerStepThr, NULL, &rtExtModeServerStepThread,
                 (void*) NULL);

  // block instance data
  {
    {
      simulinkPandaRobot_1721602 = SimulinkPandaRobot( "172.16.0.2",
        0,
        0,
        0,
        roboticArm_loadCell_ConstP.ApplyControl_P1,
        roboticArm_loadCell_ConstP.ApplyControl_P2,
        roboticArm_loadCell_ConstP.ApplyControl_P3,
        roboticArm_loadCell_ConstP.ApplyControl_P4,
        roboticArm_loadCell_ConstP.ApplyControl_P5,
        0,
        roboticArm_loadCell_ConstP.ApplyControl_P6,
        1);
    }
  }

  {
    char_T *sErr;

    // Start for S-Function (get_duration_period): '<S3>/Get Duration Period1'
    {
      roboticArm_loadCell_DW.GetDurationPeriod1_DWORK1 = (double)
        simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
    }

    // Start for S-Function (get_model): '<S2>/Get Model'
    {
      roboticArm_loadCell_DW.GetModel_DWORK1 = (double)
        simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
    }

    // Start for S-Function (get_robot_state): '<S2>/Get Robot State'
    {
      roboticArm_loadCell_DW.GetRobotState_DWORK1 = (double)
        simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
    }

    // Start for S-Function (get_duration_period): '<S2>/Duration Period'
    {
      roboticArm_loadCell_DW.DurationPeriod_DWORK1 = (double)
        simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
    }

    // Start for S-Function (apply_control): '<Root>/Apply Control'
    {
      //Flag for performing initialization in first run of main _step();
      roboticArm_loadCell_DW.ApplyControl_DWORK1 = 0;
      roboticArm_loadCell_DW.ApplyControl_DWORK2 = (double)
        simulinkPandaRobot_1721602.establishIfCurrentBlockFirstToBeComputed();
    }

    // Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
    sErr = GetErrorBuffer(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U], 0,
                        "0.0.0.0", 8002, "10.10.10.15", -1, 8192, 1, MIN_int32_T);
    }

    if (*sErr == 0) {
      LibStart(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(roboticArm_loadCell_M, sErr);
        rtmSetStopRequested(roboticArm_loadCell_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  }
}

// Model terminate function
void roboticArm_loadCell_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (apply_control): '<Root>/Apply Control'
  {
    // S-Function Block: <Root>/Apply Control
  }

  // Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
  sErr = GetErrorBuffer(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(roboticArm_loadCell_M, sErr);
    rtmSetStopRequested(roboticArm_loadCell_M, 1);
  }

  LibDestroy(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&roboticArm_loadCell_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive'
}

//
// File trailer for generated code.
//
// [EOF]
//
