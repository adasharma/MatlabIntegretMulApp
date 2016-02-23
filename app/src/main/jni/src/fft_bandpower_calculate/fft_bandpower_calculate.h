/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fft_bandpower_calculate.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 22-Feb-2016 20:51:15
 */

#ifndef __FFT_BANDPOWER_CALCULATE_H__
#define __FFT_BANDPOWER_CALCULATE_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "fft_bandpower_calculate_types.h"

/* Function Declarations */
extern void fft_bandpower_calculate(const double data[256], double Fs, double
  band[2], double *totalpower, double *pband);

#endif

/*
 * File trailer for fft_bandpower_calculate.h
 *
 * [EOF]
 */
