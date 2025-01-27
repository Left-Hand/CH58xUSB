#ifndef __PID_H__

#define __PID_H__

class PID{
    private:
        float _prev_error = 0.0;
        float _integral = 0.0;

        float _dt = 0.1;
        float err = 0.0;       
        float err_next = 0.0;  
        float err_last = 0.0;   
    public:
        float _Kp = 100.0;
        float _Ki = 4.0;
        float _Kd = 0.01;
        float _max = 4.0;
        PID(){};
        PID(float kp, float ki, float kd):_Kp(kp), _Ki(ki),_Kd(kd){;}
        ~PID(){;}
        float update(const float & setpoint, const float & pv);
        void reset_integral(){_integral = 0.0;}
    // void fallat(const float & _value);
};

#endif