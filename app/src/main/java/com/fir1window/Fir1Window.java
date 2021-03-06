/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.fir1window;

public class Fir1Window {
  public static void fir1_window(double[] input, double low, double high) {
    Fir1WindowJNI.fir1_window(input, low, high);
  }

  public static SWIGTYPE_p_double new_doubleArray(int nelements) {
    long cPtr = Fir1WindowJNI.new_doubleArray(nelements);
    return (cPtr == 0) ? null : new SWIGTYPE_p_double(cPtr, false);
  }

  public static void delete_doubleArray(SWIGTYPE_p_double ary) {
    Fir1WindowJNI.delete_doubleArray(SWIGTYPE_p_double.getCPtr(ary));
  }

  public static double doubleArray_getitem(SWIGTYPE_p_double ary, int index) {
    return Fir1WindowJNI.doubleArray_getitem(SWIGTYPE_p_double.getCPtr(ary), index);
  }

  public static void doubleArray_setitem(SWIGTYPE_p_double ary, int index, double value) {
    Fir1WindowJNI.doubleArray_setitem(SWIGTYPE_p_double.getCPtr(ary), index, value);
  }

}
