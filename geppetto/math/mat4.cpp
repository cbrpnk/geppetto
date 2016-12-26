#include <cassert>
#include <cmath>

#include "mat3.h"
#include "mat4.h"
#include "vec4.h"
#include "math.h"


namespace Geppetto {
namespace Math {


Mat4::Mat4()
{}


Mat4::Mat4(const Mat4& m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	mat[3] = m[3];
}


Mat4::Mat4(const Mat3& m)
{
	mat[0] = Vec4(m[0]);
	mat[1] = Vec4(m[1]);
	mat[2] = Vec4(m[2]);
	mat[3] = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
}


Mat4::Mat4(const float* a)
{
	for(int i=0; i<4; ++i) {
		mat[i] = Vec4(a[i*4+0], a[i*4+1], a[i*4+2], a[i*4+3]);
	}
}


Mat4::Mat4(const Vec4 x, const Vec4 y, const Vec4 z, const Vec4 w)
{
	mat[0] = x;
	mat[1] = y;
	mat[2] = z;
	mat[3] = w;
}


Mat4& Mat4::operator=(const Mat4& m)
{
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	mat[3] = m[3];
	
	return *this;
}


const Vec4& Mat4::operator[](const int i) const
{
	assert(i>=0 && i<4);
	return mat[i];
}


Vec4& Mat4::operator[](const int i)
{
	assert(i>=0 && i<4);
	return mat[i];
}


Mat4& Mat4::operator+=(Mat4& m)
{
	*this = *this + m;
	return *this;
}


Mat4& Mat4::operator-=(const Mat4& m)
{
	*this = *this - m;
	return *this;
}


Mat4& Mat4::operator*=(const float s)
{
	*this = *this * s;
	return *this;
}


Mat4& Mat4::operator*=(const Mat4& m)
{
	*this = *this * m;
	return *this;
}


Mat4 Mat4::operator+(const Mat4& m) const
{
	Mat4 tmp = *this;
	
	for(int i=0; i<4; ++i) {
		tmp[i] += m[i];
	}
	
	return Mat4(tmp);
}


Mat4 Mat4::operator-(const Mat4& m) const
{
	Mat4 tmp = *this;
	
	for(int i=0; i<4; ++i) {
		tmp[i] -= m[i];
	}
	
	return Mat4(tmp);
}


Mat4 Mat4::operator*(const Mat4& m) const
{
	return Mat4(*this*m[0], *this*m[1], *this*m[2], *this*m[3]);
}


Vec4 Mat4::operator*(const Vec4& v) const
{
	Mat4 tmp = *this;
	tmp.Transpose();
	
	return Vec4(tmp[0]*v, tmp[1]*v, tmp[2]*v, tmp[3]*v);
}


Mat4 Mat4::operator*(const float s) const
{
	return Mat4(mat[0]*s, mat[1]*s, mat[2]*s, mat[3]*s);
}


bool Mat4::operator==(const Mat4& m) const
{
	return mat[0] == m[0] && mat[1] == m[1] && mat[2] == m[2] && mat[3] == m[3];
}


bool Mat4::operator!=(const Mat4& m) const
{
	return mat[0] != m[0] || mat[1] != m[1] || mat[2] != m[2] || mat[3] != m[3];
}


void Mat4::Debug()
{
	mat[0].Debug();
	mat[1].Debug();
	mat[2].Debug();
	mat[3].Debug();
}


void Mat4::Identity()
{
	*this = Mat4(identity4x4);
}


void Mat4::Inverse()
{}


void Mat4::Rotate(const float x, const float y, const float z)
{
	Mat4 tmp;
	float radX = DegToRad(x);
	float radY = DegToRad(y);
	float radZ = DegToRad(z);
	
	// X rotation
	tmp.Identity();
	tmp[1].y = cos(radX);
	tmp[1].z = sin(radX);
	tmp[2].y = -sin(radX);
	tmp[2].z = cos(radX);
	
	*this *= tmp;
	
	// Y rotation
	tmp.Identity();
	tmp[0].x = cos(radY);
	tmp[0].z = -sin(radY);
	tmp[2].x = sin(radY);
	tmp[2].z = cos(radY);
	
	*this *= tmp;
	
	// Z rotation
	tmp.Identity();
	tmp[0].x = cos(radZ);
	tmp[0].y = sin(radZ);
	tmp[1].x = -sin(radZ);
	tmp[1].y = cos(radZ);
	
	*this *= tmp;
}


const float* Mat4::ToArray() const
{
	return &(mat[0][0]);
}


void Mat4::Translate(const float x, const float y, const float z)
{
	mat[3].x = x;
	mat[3].y = y;
	mat[3].z = z;
}


void Mat4::Transpose()
{
	Mat4 tmp;
	
	for(int i=0; i<4; ++i) {
		for(int j=0; j<4; ++j) {
			tmp[i][j] = mat[j][i];
		}
	}
	
	*this = tmp;
}


void Mat4::Zero()
{
	for(int i=0; i<4; ++i) {
		mat[i].Zero();
	}
}

} // namespace Math
} // namespace Geppetto
