#include <cmath>
#include <iostream>
#include <cassert>

#include "gmat3.h"
#include "gvec3.h"
#include "gvec4.h"


GVec3::GVec3()
{}


GVec3::GVec3(const GVec3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}


GVec3::GVec3(const GVec4 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}


GVec3::GVec3(const float *a)
{
	x = a[0];
	y = a[1];
	z = a[2];
}


GVec3::GVec3(const float x, const float y, const float z) : x(x), y(y), z(z)
{}


GVec3 &GVec3::operator=(const GVec3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	
	return *this;
}


const float &GVec3::operator[](const int i) const
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


float &GVec3::operator[](const int i)
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


GVec3 &GVec3::operator+=(const GVec3 &v)
{
	*this = *this + v;
	return *this;
}


GVec3 &GVec3::operator-=(const GVec3 &v)
{
	*this = *this - v;
	return *this;
}


GVec3 &GVec3::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


GVec3 &GVec3::operator*=(const GMat3 &m)
{
	*this = m * *this;
	return *this;
}


GVec3 &GVec3::operator/=(const float s)
{
	*this *= 1.0f/s;
	return *this;
}


GVec3 GVec3::operator+(const GVec3 &v) const
{
	return GVec3(x + v.x, y + v.y, z + v.z);
}


GVec3 GVec3::operator-(const GVec3 &v) const
{
	return GVec3(x - v.x, y - v.y, z - v.z);
}


float GVec3::operator*(const GVec3 &v) const
{
	return x*v.x + y*v.y + z*v.z;
}


GVec3 GVec3::operator*(const GMat3 &m) const
{
	return m * *this;
}


GVec3 GVec3::operator*(const float s) const
{
	return GVec3(x*s, y*s, z*s);
}


GVec3 GVec3::operator/(const float s) const
{
	return GVec3(x/s, y/x, z/s);
}


bool GVec3::operator==(const GVec3 &v) const
{
	return (x == v.x) && (y == v.y) && (z == v.z);
}


bool GVec3::operator!=(const GVec3 &v) const
{
	return (x != v.x) || (y != v.y) || (z != v.z);
}


GVec3 GVec3::cross(const GVec3 &v) const
{
	return GVec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}


void GVec3::debug()
{
	std::cout << "[" << x << ", " << y << ", " << z << "]\n";
}


float GVec3::length() const
{
	return sqrt(x*x + y*y + z*z);
}


void GVec3::normalize()
{
	float l = length();
	x /= l;
	y /= l;
	z /= l;
}


void GVec3::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

