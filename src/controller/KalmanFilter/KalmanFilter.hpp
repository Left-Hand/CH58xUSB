/*
  Copyright(C) 2019- White Noise Team

  One dimensional Kalman Filter implementation for
  use with BNO055 IMU to filter noisy gyro and
  accelerometer measurements.

  This software is distributed under the MIT License

  This file includes the headers of the Kalman Filter API
*/
#ifndef __KALMAN_H_

#define __KALMAN_H_


class KalmanFilter {
    public:
      float R = 1.0;
      float Q = 1.0;
      float A = 1.0;
      float B = 1.0;
      float C = 1.0;
      float cov;

      float x; // Signal without noise
      bool init;

      KalmanFilter();
      KalmanFilter(float r, float q, float a, float b, float c);

      float update(float z);

      float predict();

      float uncertainty();

      void offset(const float & ofs){x += ofs;}

};


#endif
