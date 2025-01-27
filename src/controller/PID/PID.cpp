#include "PID.hpp"

float PID::update(const float & setpoint, const float & pv){
	float error = setpoint - pv;
	float Pout = _Kp * error;
	
	_integral += error * _dt;
	float Iout = _Ki * _integral;
	
	float derivative = (error - _prev_error) / _dt;
	float Dout = _Kd * derivative;
	
	float output = Pout + Iout + Dout;
	
	if (_integral > _max) _integral = _max;
	else if(_integral < - _max) _integral = - _max;
	_prev_error = error;
	return output;
}

// void fallat(const float & _value){
    
// }
	