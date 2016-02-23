/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fft.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 22-Feb-2016 20:51:15
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "fft_bandpower_calculate.h"
#include "fft.h"

/* Function Definitions */

/*
 * Arguments    : const double x[256]
 *                creal_T y[256]
 * Return Type  : void
 */
void fft(const double x[256], creal_T y[256])
{
  creal_T b_y1[256];
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iheight;
  int istart;
  int j;
  static const double dv1[129] = { 1.0, 0.99969881869620425, 0.99879545620517241,
    0.99729045667869021, 0.99518472667219693, 0.99247953459871,
    0.989176509964781, 0.98527764238894122, 0.98078528040323043,
    0.97570213003852857, 0.970031253194544, 0.96377606579543984,
    0.95694033573220882, 0.94952818059303667, 0.94154406518302081,
    0.932992798834739, 0.92387953251128674, 0.91420975570353069,
    0.90398929312344334, 0.89322430119551532, 0.881921264348355,
    0.87008699110871146, 0.85772861000027212, 0.84485356524970712,
    0.83146961230254524, 0.81758481315158371, 0.80320753148064494,
    0.78834642762660634, 0.773010453362737, 0.75720884650648457,
    0.74095112535495922, 0.724247082951467, 0.70710678118654757,
    0.68954054473706683, 0.67155895484701833, 0.65317284295377676,
    0.63439328416364549, 0.61523159058062682, 0.59569930449243336,
    0.57580819141784534, 0.55557023301960218, 0.53499761988709715,
    0.51410274419322166, 0.49289819222978404, 0.47139673682599764,
    0.44961132965460654, 0.42755509343028208, 0.40524131400498986,
    0.38268343236508978, 0.35989503653498811, 0.33688985339222005,
    0.31368174039889152, 0.29028467725446233, 0.26671275747489837,
    0.24298017990326387, 0.2191012401568698, 0.19509032201612825,
    0.17096188876030122, 0.14673047445536175, 0.1224106751992162,
    0.0980171403295606, 0.073564563599667426, 0.049067674327418015,
    0.024541228522912288, 0.0, -0.024541228522912288, -0.049067674327418015,
    -0.073564563599667426, -0.0980171403295606, -0.1224106751992162,
    -0.14673047445536175, -0.17096188876030122, -0.19509032201612825,
    -0.2191012401568698, -0.24298017990326387, -0.26671275747489837,
    -0.29028467725446233, -0.31368174039889152, -0.33688985339222005,
    -0.35989503653498811, -0.38268343236508978, -0.40524131400498986,
    -0.42755509343028208, -0.44961132965460654, -0.47139673682599764,
    -0.49289819222978404, -0.51410274419322166, -0.53499761988709715,
    -0.55557023301960218, -0.57580819141784534, -0.59569930449243336,
    -0.61523159058062682, -0.63439328416364549, -0.65317284295377676,
    -0.67155895484701833, -0.68954054473706683, -0.70710678118654757,
    -0.724247082951467, -0.74095112535495922, -0.75720884650648457,
    -0.773010453362737, -0.78834642762660634, -0.80320753148064494,
    -0.81758481315158371, -0.83146961230254524, -0.84485356524970712,
    -0.85772861000027212, -0.87008699110871146, -0.881921264348355,
    -0.89322430119551532, -0.90398929312344334, -0.91420975570353069,
    -0.92387953251128674, -0.932992798834739, -0.94154406518302081,
    -0.94952818059303667, -0.95694033573220882, -0.96377606579543984,
    -0.970031253194544, -0.97570213003852857, -0.98078528040323043,
    -0.98527764238894122, -0.989176509964781, -0.99247953459871,
    -0.99518472667219693, -0.99729045667869021, -0.99879545620517241,
    -0.99969881869620425, -1.0 };

  double twid_re;
  static const double dv2[129] = { 0.0, -0.024541228522912288,
    -0.049067674327418015, -0.073564563599667426, -0.0980171403295606,
    -0.1224106751992162, -0.14673047445536175, -0.17096188876030122,
    -0.19509032201612825, -0.2191012401568698, -0.24298017990326387,
    -0.26671275747489837, -0.29028467725446233, -0.31368174039889152,
    -0.33688985339222005, -0.35989503653498811, -0.38268343236508978,
    -0.40524131400498986, -0.42755509343028208, -0.44961132965460654,
    -0.47139673682599764, -0.49289819222978404, -0.51410274419322166,
    -0.53499761988709715, -0.55557023301960218, -0.57580819141784534,
    -0.59569930449243336, -0.61523159058062682, -0.63439328416364549,
    -0.65317284295377676, -0.67155895484701833, -0.68954054473706683,
    -0.70710678118654757, -0.724247082951467, -0.74095112535495922,
    -0.75720884650648457, -0.773010453362737, -0.78834642762660634,
    -0.80320753148064494, -0.81758481315158371, -0.83146961230254524,
    -0.84485356524970712, -0.85772861000027212, -0.87008699110871146,
    -0.881921264348355, -0.89322430119551532, -0.90398929312344334,
    -0.91420975570353069, -0.92387953251128674, -0.932992798834739,
    -0.94154406518302081, -0.94952818059303667, -0.95694033573220882,
    -0.96377606579543984, -0.970031253194544, -0.97570213003852857,
    -0.98078528040323043, -0.98527764238894122, -0.989176509964781,
    -0.99247953459871, -0.99518472667219693, -0.99729045667869021,
    -0.99879545620517241, -0.99969881869620425, -1.0, -0.99969881869620425,
    -0.99879545620517241, -0.99729045667869021, -0.99518472667219693,
    -0.99247953459871, -0.989176509964781, -0.98527764238894122,
    -0.98078528040323043, -0.97570213003852857, -0.970031253194544,
    -0.96377606579543984, -0.95694033573220882, -0.94952818059303667,
    -0.94154406518302081, -0.932992798834739, -0.92387953251128674,
    -0.91420975570353069, -0.90398929312344334, -0.89322430119551532,
    -0.881921264348355, -0.87008699110871146, -0.85772861000027212,
    -0.84485356524970712, -0.83146961230254524, -0.81758481315158371,
    -0.80320753148064494, -0.78834642762660634, -0.773010453362737,
    -0.75720884650648457, -0.74095112535495922, -0.724247082951467,
    -0.70710678118654757, -0.68954054473706683, -0.67155895484701833,
    -0.65317284295377676, -0.63439328416364549, -0.61523159058062682,
    -0.59569930449243336, -0.57580819141784534, -0.55557023301960218,
    -0.53499761988709715, -0.51410274419322166, -0.49289819222978404,
    -0.47139673682599764, -0.44961132965460654, -0.42755509343028208,
    -0.40524131400498986, -0.38268343236508978, -0.35989503653498811,
    -0.33688985339222005, -0.31368174039889152, -0.29028467725446233,
    -0.26671275747489837, -0.24298017990326387, -0.2191012401568698,
    -0.19509032201612825, -0.17096188876030122, -0.14673047445536175,
    -0.1224106751992162, -0.0980171403295606, -0.073564563599667426,
    -0.049067674327418015, -0.024541228522912288, -0.0 };

  double twid_im;
  int ihi;
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 255; i++) {
    b_y1[iy].re = x[ix];
    b_y1[iy].im = 0.0;
    iy = 256;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  b_y1[iy].re = x[ix];
  b_y1[iy].im = 0.0;
  for (i = 0; i <= 255; i += 2) {
    temp_re = b_y1[i + 1].re;
    temp_im = b_y1[i + 1].im;
    b_y1[i + 1].re = b_y1[i].re - b_y1[i + 1].re;
    b_y1[i + 1].im = b_y1[i].im - b_y1[i + 1].im;
    b_y1[i].re += temp_re;
    b_y1[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 64;
  iheight = 253;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re = b_y1[i + iy].re;
      temp_im = b_y1[i + iy].im;
      b_y1[i + iy].re = b_y1[i].re - temp_re;
      b_y1[i + iy].im = b_y1[i].im - temp_im;
      b_y1[i].re += temp_re;
      b_y1[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 128; j += ju) {
      twid_re = dv1[j];
      twid_im = dv2[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * b_y1[i + iy].re - twid_im * b_y1[i + iy].im;
        temp_im = twid_re * b_y1[i + iy].im + twid_im * b_y1[i + iy].re;
        b_y1[i + iy].re = b_y1[i].re - temp_re;
        b_y1[i + iy].im = b_y1[i].im - temp_im;
        b_y1[i].re += temp_re;
        b_y1[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix <<= 1;
    iheight -= iy;
  }

  memcpy(&y[0], &b_y1[0], sizeof(creal_T) << 8);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
