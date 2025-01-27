/*
  Copyright(C) 2019- White Noise Team

  One dimensional KalmanFilter Filter implementation for
  use with BNO055 IMU to filter noisy gyro and
  accelerometer measurements.

  This software is distributed under the MIT License

  This file includes the source of the KalmanFilter Filter API
*/

#include "KalmanFilter.hpp"

KalmanFilter::KalmanFilter(){
    init = false;
}

KalmanFilter::KalmanFilter(float r, float q, float a, float b, float c) {
  R = r;
  Q = q;
  A = a;
  B = b;
  C = c;
  init = false;
}

float KalmanFilter::update(float z) {
  if (!init) {
    x = 1.0 / C * z;
    cov = Q / (C * C);
    init = true;
  }

  else {
    float pred = predict();
    float p_cov = uncertainty();

    float K = p_cov * C / (C * C * p_cov + Q);

    x = pred + K * (z - C * pred);
    cov = p_cov - K * C * p_cov;

  }

  return x;

}

float KalmanFilter::predict() {
  return A * x;
}

float KalmanFilter::uncertainty() {
  return A * A * cov + R;
}
