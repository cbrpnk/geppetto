#include <cassert>
#include <cmath>

#include "gmat3.h"
#include "gmat4.h"
#include "gvec4.h"
#include "gmath.h"

GMat4::GMat4()
{}


GMat4::GMat4(const GMat4 &m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	mat[3] = m[3];
}


GMat4::GMat4(const GMat3 &m)
{
	mat[0] = GVec4(m[0]);
	mat[1] = GVec4(m[1]);
	mat[2] = GVec4(m[2]);
	mat[3] = GVec4(0.0f, 0.0f, 0.0f, 1.0f);
}


GMat4::GMat4(const float *a)
{
	for(int i=0; i<4; ++i) {
		mat[i] = GVec4(a[i*4+0], a[i*4+1], a[i*4+2], a[i*4+3]);
	}
}


GMat4::GMat4(const GVec4 x, const GVec4 y, const GVec4 z, const GVec4 w)
{
	mat[0] = x;
	mat[1] = y;
	mat[2] = z;
	mat[3] = w;
}


GMat4 &GMat4::operator=(const GMat4 &m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	mat[3] = m[3];
	
	return *this;
}


const GVec4 &GMat4::operator[](const int i) const
{
	assert(i>=0 && i<4);
	return mat[i];
}


GVec4 &GMat4::operator[](const int i)
{
	assert(i>=0 && i<4);
	return mat[i];
}


GMat4 &GMat4::operator+=(GMat4 &m)
{
	*this = *this + m;
	return *this;
}


GMat4 &GMat4::operator-=(const GMat4 &m)
{
	*this = *this - m;
	return *this;
}


GMat4 &GMat4::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


GMat4 &GMat4::operator*=(const GMat4 &m)
{
	*this = *this * m;
	return *this;
}


GMat4 GMat4::operator+(const GMat4 &m) const
{
	GMat4 tmp = *this;
	
	for(int i=0; i<4; ++i) {
		tmp[i] += m[i];
	}
	
	return GMat4(tmp);
}


GMat4 GMat4::operator-(const GMat4 &m) const
{
	GMat4 tmp = *this;
	
	for(int i=0; i<4; ++i) {
		tmp[i] -= m[i];
	}
	
	return GMat4(tmp);
}


GMat4 GMat4::operator*(const GMat4 &m) const
{
	return GMat4(*this*m[0], *this*m[1], *this*m[2], *this*m[3]);
}


GVec4 GMat4::operator*(const GVec4 &v) const
{
	GMat4 tmp = *this;
	tmp.transpose();
	
	return GVec4(tmp[0]*v, tmp[1]*v, tmp[2]*v, tmp[3]*v);
}


GMat4 GMat4::operator*(const float s) const
{
	return GMat4(mat[0]*s, mat[1]*s, mat[2]*s, mat[3]*s);
}


bool GMat4::operator==(const GMat4 &m) const
{
	return mat[0] == m[0] && mat[1] == m[1] && mat[2] == m[2] && mat[3] == m[3];
}


bool GMat4::operator!=(const GMat4 &m) const
{
	return mat[0] != m[0] || mat[1] != m[1] || mat[2] != m[2] || mat[3] != m[3];
}


void GMat4::debug()
{
	mat[0].debug();
	mat[1].debug();
	mat[2].debug();
	mat[3].debug();
}


void GMat4::identity()
{
	*this = GMat4(identity4x4);
}


void GMat4::inverse()
{}


void GMat4::rotate(const float x, const float y, const float z)
{
	GMat4 tmp;
	float rad_x = Gmath::degToRad(x);
	float rad_y = Gmath::degToRad(y);
	float rad_z = Gmath::degToRad(z);
	
	// X rotation
	tmp.identity();
	tmp[1].y = cos(rad_x);
	tmp[1].z = sin(rad_x);
	tmp[2].y = -sin(rad_x);
	tmp[2].z = cos(rad_x);
	
	*this *= tmp;
	
	// Y rotation
	tmp.identity();
	tmp[0].x = cos(rad_y);
	tmp[0].z = -sin(rad_y);
	tmp[2].x = sin(rad_y);
	tmp[2].z = cos(rad_y);
	
	*this *= tmp;
	
	// Z rotation
	tmp.identity();
	tmp[0].x = cos(rad_z);
	tmp[0].y = sin(rad_z);
	tmp[1].x = -sin(rad_z);
	tmp[1].y = cos(rad_z);
	
	*this *= tmp;
}


const float *GMat4::toArray() const
{
	return &(mat[0][0]);
}


void GMat4::translate(const float x, const float y, const float z)
{
	mat[3].x = x;
	mat[3].y = y;
	mat[3].z = z;
}


void GMat4::transpose()
{
	GMat4 tmp;
	
	for(int i=0; i<4; ++i) {
		for(int j=0; j<4; ++j) {
			tmp[i][j] = mat[j][i];
		}
	}
	
	*this = tmp;
}


void GMat4::zero()
{
	for(int i=0; i<4; ++i) {
		mat[i].zero();
	}
}


