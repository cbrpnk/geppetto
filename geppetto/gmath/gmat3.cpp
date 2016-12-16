#include <cassert>
#include <cmath>

#include "gmat3.h"
#include "gmat4.h"
#include "gvec3.h"
#include "gmath.h"

GMat3::GMat3()
{}


GMat3::GMat3(const GMat3 &m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
}


GMat3::GMat3(const GMat4 &m)
{
	mat[0] = GVec3(m[0]);
	mat[1] = GVec3(m[1]);
	mat[2] = GVec3(m[2]);
}


GMat3::GMat3(const float *a)
{
	for(int i=0; i<3; ++i) {
		mat[i] = GVec3(a[i*3+0], a[i*3+1], a[i*3+2]);
	}
}


GMat3::GMat3(const GVec3 x, const GVec3 y, const GVec3 z)
{
	mat[0] = x;
	mat[1] = y;
	mat[2] = z;
}


GMat3 &GMat3::operator=(const GMat3 &m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	
	return *this;
}


const GVec3 &GMat3::operator[](const int i) const
{
	assert(i>=0 && i<3);
	return mat[i];
}


GVec3 &GMat3::operator[](const int i)
{
	assert(i>=0 && i<3);
	return mat[i];
}


GMat3 &GMat3::operator+=(GMat3 &m)
{
	*this = *this + m;
	return *this;
}


GMat3 &GMat3::operator-=(const GMat3 &m)
{
	*this = *this - m;
	return *this;
}


GMat3 &GMat3::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


GMat3 &GMat3::operator*=(const GMat3 &m)
{
	*this = *this * m;
	return *this;
}


GMat3 GMat3::operator+(const GMat3 &m) const
{
	GMat3 tmp = *this;
	
	for(int i=0; i<3; ++i) {
		tmp[i] += m[i];
	}
	
	return GMat3(tmp);
}


GMat3 GMat3::operator-(const GMat3 &m) const
{
	GMat3 tmp = *this;
	
	for(int i=0; i<3; ++i) {
		tmp[i] -= m[i];
	}
	
	return GMat3(tmp);
}


GMat3 GMat3::operator*(const GMat3 &m) const
{
	return GMat3(*this*m[0], *this*m[1], *this*m[2]);
}


GVec3 GMat3::operator*(const GVec3 &v) const
{
	GMat3 tmp = *this;
	tmp.transpose();
	
	return GVec3(tmp[0]*v, tmp[1]*v, tmp[2]*v);
}


GMat3 GMat3::operator*(const float s) const
{
	return GMat3(mat[0]*s, mat[1]*s, mat[2]*s);
}


bool GMat3::operator==(const GMat3 &m) const
{
	return mat[0] == m[0] && mat[1] == m[1] && mat[2] == m[2];
}


bool GMat3::operator!=(const GMat3 &m) const
{
	return mat[0] != m[0] || mat[1] != m[1] || mat[2] != m[2];
}


void GMat3::debug()
{
	mat[0].debug();
	mat[1].debug();
	mat[2].debug();
}


void GMat3::identity()
{
	*this = GMat3(identity3x3);
}


void GMat3::inverse()
{}


const float *GMat3::toArray() const
{
	return &(mat[0][0]);
}


void GMat3::transpose()
{
	GMat3 tmp;
	
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			tmp[i][j] = mat[j][i];
		}
	}
	
	*this = tmp;
}


void GMat3::zero()
{
	for(int i=0; i<3; ++i) {
		mat[i].zero();
	}
}


