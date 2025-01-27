#ifndef __MYVECTOR2_H_

#define __MYVECTOR2_H_

#include <cmath>
#include <Vector2i.hpp>
#include <string>

using std::string;

class Vector2{

public:

    #define CMP_EPSILON 0.00001

    #define sgn(x) x > 0 ? 1.0 :(x < 0 ? -1.0 : 0.0)
    #define is_equal_approx_f(a, b) fabs(a - b) < fmin(1.0, fabs(a))*CMP_EPSILON
    #define snap(x,d) roundf(x/d)*d
    #define deg2rad(x) x*3.1415926535897932384626433832795/180.0

    float x = 0.0;
    float y = 0.0;
    Vector2();
    Vector2(float _x, float _y);
    ~Vector2();

    Vector2 abs() const;
    float angle() const {return atan2f(y, x);}
    float angle_to(const Vector2 & to) const;
    float angle_to_point(const Vector2 & to) const;
    float aspect() const {return (!!y) ? x/y : .0f;}
    Vector2 bounce(const Vector2 &n) const;
    Vector2 ceil() const;
    Vector2 clampmin(const float & length) const;
    Vector2 clampmax(const float & length) const;
    Vector2 clamp(const float & min, const float & max) const;
    float cross(const Vector2 & with) const;
    float dot(const Vector2 & with) const;
    Vector2 dir_to(const Vector2 & b) const;
    float dist_to(const Vector2 & b) const;
    float dist_squared_to(const Vector2 & b) const;
    Vector2 floor() const;
    bool is_equal_approx(const Vector2 & v) const;
    bool is_normalized() const {return (fabs(x*x + y*y - 1.0) <= CMP_EPSILON);}
    float length() const {return sqrt(x*x + y*y);}
    float length_squared() const {return (x*x + y*y);}
    Vector2 lerp(const Vector2 & b, const float & t) const;
    Vector2 move_toward(const Vector2 & to, const float & delta) const;
    Vector2 normalized() const;
    Vector2 posmod(const float & mod) const;
    Vector2 posmodv(const Vector2 & modv) const;
    Vector2 project(const Vector2 & b) const;
    Vector2 reflect(const Vector2 & n) const;
    Vector2 round() const;
    Vector2 sign() const;
    Vector2 slerp(const Vector2 & b, const float & t) const;
    Vector2 slide(const Vector2  & n) const;
    Vector2 snapped(const Vector2 & by) const;
    Vector2 improduct(const Vector2 & b) const;
    Vector2 rotate(const float & r)const;

    Vector2 operator+(const Vector2 & b) const;
    Vector2 operator-(const Vector2 & b) const;
    Vector2 operator-() const;
    Vector2 operator*(const float & n) const;
    Vector2 operator/(const float & n) const;
    // string toString() const;
	bool operator==(const Vector2 &b) const { return ((x == b.x) && (y == b.y));}
	bool operator!=(const Vector2 &b) const { return ((x != b.x) || (y != b.y));}

	bool operator<(const Vector2 &b) const { return x == b.x ? (y < b.y) : (x < b.x); }
	bool operator>(const Vector2 &b) const { return x == b.x ? (y > b.y) : (x > b.x); }
	bool operator<=(const Vector2 &b) const { return x == b.x ? (y <= b.y) : (x < b.x); }
	bool operator>=(const Vector2 &b) const { return x == b.x ? (y >= b.y) : (x > b.x); }

    friend Vector2 operator*(const float & n, const Vector2 & a){return Vector2(n*a.x, n*a.y);};
    // operator Vector2i() const {return Vector2i((uint32_t)x, (uint32_t)y);} 
};

inline Vector2::Vector2()
{
    x = 0.0;
    y = 0.0;
}

inline Vector2::Vector2(float _x, float _y){
    x = _x;
    y = _y;
}

inline Vector2::~Vector2()
{
}

inline Vector2 Vector2::operator+(const Vector2 & b) const{
    return Vector2(x+b.x, y+b.y);
}

inline Vector2 Vector2::operator-(const Vector2 & b) const{
    return Vector2(x-b.x, y-b.y);
}

inline Vector2 Vector2::operator-() const{
    return Vector2(-x, -y);
}

inline Vector2 Vector2::operator*(const float & n) const{
    return Vector2(x*n, y*n);
}

inline Vector2 Vector2::operator/(const float & n) const{
    return Vector2(x/n, y/n);
}

inline Vector2 Vector2::normalized() const{
    return *this/this->length();
}

inline float Vector2::dot(const Vector2 & with) const{
    return (x*with.x + y*with.y);
}

inline float Vector2::cross(const Vector2 & with) const{
    return (x*with.y - y*with.x);
}

inline Vector2 Vector2::abs() const{
    return Vector2(fabs(x), fabs(y));
}


inline Vector2 Vector2::ceil() const{

    return Vector2(ceilf(x), ceilf(y));
}

inline Vector2 Vector2::floor() const{

    return Vector2(floorf(x), floorf(y));
}

inline Vector2 Vector2::round() const{

    return Vector2(roundf(x), roundf(y));
}

inline Vector2 Vector2::clampmin(const float & length) const{
    float l = this->length();
    if (l < length){
        return *this * length / l;
    }
    return *this;
}

inline Vector2 Vector2::clampmax(const float & length) const{
    float l = this->length();
    if (l > length){
        return *this * length / l;
    }
    return *this;
}

inline Vector2 Vector2::clamp(const float & min, const float & max) const {
    float l = this->length();
    if (l > max){
        return *this * max / l;
    }
    else if(l < min){
        return *this * min / l;
    }
    return *this;
}
inline Vector2 Vector2::dir_to(const Vector2 & b) const{
    return (b - *this).normalized();
}
inline float Vector2::dist_to(const Vector2 & b) const{
    return (b - *this).length();
}

inline float Vector2::dist_squared_to(const Vector2 & b) const{
    return (b - *this).length_squared();
}

inline float Vector2::angle_to(const Vector2 & to) const {
    return (to.angle() - angle());
}

inline float Vector2::angle_to_point(const Vector2 & to) const {
    return (to - *this).angle();
}

inline Vector2 Vector2::reflect(const Vector2 & n) const {
    return 2.0f * n * this->dot(n) - *this;
}

inline Vector2 Vector2::bounce(const Vector2 & n) const {
    return -reflect(n);
}

inline Vector2 Vector2::lerp(const Vector2 & b, const float & t) const{
    return *this * (1-t)+b * t;
}

inline Vector2 Vector2::slerp(const Vector2 & b, const float & t) const{
    return lerp(b, sin(1.5707963267948966192313216916398f*t));
}

inline Vector2 Vector2::posmod(const float & mod) const{
    return Vector2(fmod(x, mod), fmod(y, mod));
}

inline Vector2 Vector2::posmodv(const Vector2 & b) const{
    return Vector2(fmod(x, b.x), fmod(y, b.y));
}

inline Vector2 Vector2::project(const Vector2 & b) const{
    return b * (dot(b) / b.length_squared());
}

inline bool Vector2::is_equal_approx(const Vector2 & b) const{
    return is_equal_approx_f(x, b.x) && is_equal_approx_f(y, b.y);
}

inline Vector2 Vector2::move_toward(const Vector2 & b, const float & delta) const{
    if (!is_equal_approx(b)){
        Vector2 d = b - *this; 
        return *this + d.clampmax(delta);
    }
}

inline Vector2 Vector2::slide(const Vector2 & n) const {
    return *this - n * this->dot(n);
}

inline Vector2 Vector2::sign() const{
    return Vector2(sgn(x), sgn(y));
}

inline Vector2 Vector2::snapped(const Vector2 &by) const{
    return Vector2(snap(x, by.x), snap(y, by.y));
}

inline Vector2 Vector2::improduct(const Vector2 & b) const{
    return Vector2(x*b.x - y*b.y, x*b.y + y*b.x);
}

inline Vector2 Vector2::rotate(const float & r) const{
    return this->improduct(Vector2(cos(r), sin(r)));
}

// inline string Vector2::toString() const{
//     // return util::Format("({0},{1})", this->x, this->y);

// }
#endif
