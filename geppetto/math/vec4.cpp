#include <cmath>
#include <iostream>
#include <cassert>

#include "mat4.h"
#include "vec3.h"
#include "vec4.h"


namespace Geppetto {
namespace Math {

Vec4::Vec4()
{}


Vec4::Vec4(const Vec4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}


Vec4::Vec4(const Vec3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}


Vec4::Vec4(const float* a)
{
	x = a[0];
	y = a[1];
	z = a[2];
	w = a[3];
}


Vec4::Vec4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w)
{}


Vec4& Vec4::operator=(const Vec4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	
	return *this;
}


const float& Vec4::operator[](const int i) const
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


float& Vec4::operator[](const int i)
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


Vec4& Vec4::operator+=(const Vec4& v)
{
	*this = *this + v;
	return *this;
}


Vec4& Vec4::operator-=(const Vec4& v)
{
	*this = *this - v;
	return *this;
}


Vec4& Vec4::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


Vec4& Vec4::operator*=(const Mat4& m)
{
	*this = m * *this;
	return *this;
}


Vec4& Vec4::operator/=(const float s)
{
	*this *= 1.0f/s;
	return *this;
}


Vec4 Vec4::operator+(const Vec4& v) const
{
	return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}


Vec4 Vec4::operator-(const Vec4& v) const
{
	return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}


float Vec4::operator*(const Vec4& v) const
{
	return x*v.x + y*v.y + z*v.z + w*v.w;
}


Vec4 Vec4::operator*(const Mat4& m) const
{
	return m * *this;
}


Vec4 Vec4::operator*(const float s) const
{
	return Vec4(x*s, y*s, z*s, w*s);
}


Vec4 Vec4::operator/(const float s) const
{
	return Vec4(x/s, y/x, z/s, w/s);
}


bool Vec4::operator==(const Vec4& v) const
{
	return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
}


bool Vec4::operator!=(const Vec4& v) const
{
	return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
}


Vec4 Vec4::Cross(const Vec4& v) const
{
	return Vec4(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x, 0.0f);
}


void Vec4::Debug()
{
	std::cout << "[" << x << ", " << y << ", " << z << ", " << w << "]\n";
}


float Vec4::Length() const
{
	return sqrt(x*x + y*y + z*z + w*w);
}


void Vec4::Normalize()
{
	float l = Length();
	x /= l;
	y /= l;
	z /= l;
	w /= l;	
}


void Vec4::Zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

} // namespace Math
} // namespace Geppetto
