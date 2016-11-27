#include <cassert>
#include <cmath>

#include "mat3.h"
#include "mat4.h"
#include "vec3.h"
#include "gmath.h"

Mat3::Mat3() {}


Mat3::Mat3(const Mat3 &m) {
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
}


Mat3::Mat3(const Mat4 &m) {
	mat[0] = Vec3(m[0]);
	mat[1] = Vec3(m[1]);
	mat[2] = Vec3(m[2]);
}


Mat3::Mat3(const float *a) {
	for(int i=0; i<3; ++i) {
		mat[i] = Vec3(a[i*3+0], a[i*3+1], a[i*3+2]);
	}
}


Mat3::Mat3(const Vec3 x, const Vec3 y, const Vec3 z) {
	mat[0] = x;
	mat[1] = y;
	mat[2] = z;
}


Mat3 &Mat3::operator=(const Mat3 &m) {
	mat[0] = m[0];
	mat[1] = m[1];
	mat[2] = m[2];
	
	return *this;
}


const Vec3 &Mat3::operator[](const int i) const {
	assert(i>=0 && i<3);
	return mat[i];
}


Vec3 &Mat3::operator[](const int i) {
	assert(i>=0 && i<3);
	return mat[i];
}


Mat3 &Mat3::operator+=(Mat3 &m) {
	*this = *this + m;
	return *this;
}


Mat3 &Mat3::operator-=(const Mat3 &m) {
	*this = *this - m;
	return *this;
}


Mat3 &Mat3::operator*=(const float s) {
	*this = *this * s;
	return *this;
}


Mat3 &Mat3::operator*=(const Mat3 &m) {
	*this = *this * m;
	return *this;
}


Mat3 Mat3::operator+(const Mat3 &m) const {
	Mat3 tmp = *this;
	
	for(int i=0; i<3; ++i) {
		tmp[i] += m[i];
	}
	
	return Mat3(tmp);
}


Mat3 Mat3::operator-(const Mat3 &m) const {
	Mat3 tmp = *this;
	
	for(int i=0; i<3; ++i) {
		tmp[i] -= m[i];
	}
	
	return Mat3(tmp);
}


Mat3 Mat3::operator*(const Mat3 &m) const {
	return Mat3(*this*m[0], *this*m[1], *this*m[2]);
}


Vec3 Mat3::operator*(const Vec3 &v) const {
	Mat3 tmp = *this;
	tmp.transpose();
	
	return Vec3(tmp[0]*v, tmp[1]*v, tmp[2]*v);
}


Mat3 Mat3::operator*(const float s) const {
	return Mat3(mat[0]*s, mat[1]*s, mat[2]*s);
}


bool Mat3::operator==(const Mat3 &m) const {
	return mat[0] == m[0] && mat[1] == m[1] && mat[2] == m[2];
}


bool Mat3::operator!=(const Mat3 &m) const {
	return mat[0] != m[0] || mat[1] != m[1] || mat[2] != m[2];
}


void Mat3::debug() {
	mat[0].debug();
	mat[1].debug();
	mat[2].debug();
}


void Mat3::identity() {
	*this = Mat3(identity3x3);
}


void Mat3::inverse() {

}


const float *Mat3::toArray() const {
	return &(mat[0][0]);
}


void Mat3::transpose() {
	Mat3 tmp;
	
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			tmp[i][j] = mat[j][i];
		}
	}
	
	*this = tmp;
}


void Mat3::zero() {
	for(int i=0; i<3; ++i) {
		mat[i].zero();
	}
}


