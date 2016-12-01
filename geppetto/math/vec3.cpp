#include <cmath>
#include <iostream>
#include <cassert>

#include "mat3.h"
#include "vec3.h"
#include "vec4.h"


Vec3::Vec3()
{}


Vec3::Vec3(const Vec3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}


Vec3::Vec3(const Vec4 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}


Vec3::Vec3(const float *a)
{
	x = a[0];
	y = a[1];
	z = a[2];
}


Vec3::Vec3(const float x, const float y, const float z) : x(x), y(y), z(z)
{}


Vec3 &Vec3::operator=(const Vec3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	
	return *this;
}


const float &Vec3::operator[](const int i) const
{
	assert(i>=0 && i<3);
	
	switch(i) {
	case 0:
		return x;
	case 1:
		return y;
	}
	return z;
}


float &Vec3::operator[](const int i)
{
	assert(i>=0 && i<3);
	
	switch(i) {
	case 0:
		return x;
	case 1:
		return y;
	}
	return z;
}


Vec3 &Vec3::operator+=(const Vec3 &v)
{
	*this = *this + v;
	return *this;
}


Vec3 &Vec3::operator-=(const Vec3 &v)
{
	*this = *this - v;
	return *this;
}


Vec3 &Vec3::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


Vec3 &Vec3::operator*=(const Mat3 &m)
{
	*this = m * *this;
	return *this;
}


Vec3 &Vec3::operator/=(const float s)
{
	*this *= 1.0f/s;
	return *this;
}


Vec3 Vec3::operator+(const Vec3 &v) const
{
	return Vec3(x + v.x, y + v.y, z + v.z);
}


Vec3 Vec3::operator-(const Vec3 &v) const
{
	return Vec3(x - v.x, y - v.y, z - v.z);
}


float Vec3::operator*(const Vec3 &v) const
{
	return x*v.x + y*v.y + z*v.z;
}


Vec3 Vec3::operator*(const Mat3 &m) const
{
	return m * *this;
}


Vec3 Vec3::operator*(const float s) const
{
	return Vec3(x*s, y*s, z*s);
}


Vec3 Vec3::operator/(const float s) const
{
	return Vec3(x/s, y/x, z/s);
}


bool Vec3::operator==(const Vec3 &v) const
{
	return (x == v.x) && (y == v.y) && (z == v.z);
}


bool Vec3::operator!=(const Vec3 &v) const
{
	return (x != v.x) || (y != v.y) || (z != v.z);
}


Vec3 Vec3::cross(const Vec3 &v) const
{
	return Vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}


void Vec3::debug()
{
	std::cout << "[" << x << ", " << y << ", " << z << "]\n";
}


float Vec3::length() const
{
	return sqrt(x*x + y*y + z*z);
}


void Vec3::normalize()
{
	float l = length();
	x /= l;
	y /= l;
	z /= l;
}


void Vec3::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

