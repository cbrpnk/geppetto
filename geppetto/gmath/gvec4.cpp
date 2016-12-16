#include <cmath>
#include <iostream>
#include <cassert>

#include "gmat4.h"
#include "gvec3.h"
#include "gvec4.h"


GVec4::GVec4()
{}


GVec4::GVec4(const GVec4 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}


GVec4::GVec4(const GVec3 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}


GVec4::GVec4(const float *a)
{
	x = a[0];
	y = a[1];
	z = a[2];
	w = a[3];
}


GVec4::GVec4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w)
{}


GVec4 &GVec4::operator=(const GVec4 &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	
	return *this;
}


const float &GVec4::operator[](const int i) const
{
	assert(i>=0 && i<4);
	
	switch(i) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	}
	return w;
}


float &GVec4::operator[](const int i)
{
	assert(i>=0 && i<4);
	
	switch(i) {
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	}
	return w;
}


GVec4 &GVec4::operator+=(const GVec4 &v)
{
	*this = *this + v;
	return *this;
}


GVec4 &GVec4::operator-=(const GVec4 &v)
{
	*this = *this - v;
	return *this;
}


GVec4 &GVec4::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


GVec4 &GVec4::operator*=(const GMat4 &m)
{
	*this = m * *this;
	return *this;
}


GVec4 &GVec4::operator/=(const float s)
{
	*this *= 1.0f/s;
	return *this;
}


GVec4 GVec4::operator+(const GVec4 &v) const
{
	return GVec4(x + v.x, y + v.y, z + v.z, w + v.w);
}


GVec4 GVec4::operator-(const GVec4 &v) const
{
	return GVec4(x - v.x, y - v.y, z - v.z, w - v.w);
}


float GVec4::operator*(const GVec4 &v) const
{
	return x*v.x + y*v.y + z*v.z + w*v.w;
}


GVec4 GVec4::operator*(const GMat4 &m) const
{
	return m * *this;
}


GVec4 GVec4::operator*(const float s) const
{
	return GVec4(x*s, y*s, z*s, w*s);
}


GVec4 GVec4::operator/(const float s) const
{
	return GVec4(x/s, y/x, z/s, w/s);
}


bool GVec4::operator==(const GVec4 &v) const
{
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}


bool GVec4::operator!=(const GVec4 &v) const
{
	return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
}


GVec4 GVec4::cross(const GVec4 &v) const
{
	return GVec4(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x, 0.0f);
}


void GVec4::debug()
{
	std::cout << "[" << x << ", " << y << ", " << z << ", " << w << "]\n";
}


float GVec4::length() const
{
	return sqrt(x*x + y*y + z*z + w*w);
}


void GVec4::normalize()
{
	float l = length();
	x /= l;
	y /= l;
	z /= l;
	w /= l;	
}


void GVec4::zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

