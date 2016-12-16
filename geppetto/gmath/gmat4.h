#ifndef _GMAT4_H_
#define _GMAT4_H_

#include "gvec4.h"

class GMat3;

const float identity4x4[] = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f,
};

class GMat4
{
public:
	GMat4();
	GMat4(const GMat4 &m);
	GMat4(const GMat3 &m);
	GMat4(const float *a);
	GMat4(const GVec4 x, const GVec4 y, const GVec4 z, const GVec4 w);
	
	const GVec4 &operator[](const int i)   const;
	GVec4 &operator[](const int i);
	GMat4 &operator=(const GMat4 &m);
	GMat4 &operator+=(GMat4 &m);
	GMat4 &operator-=(const GMat4 &m);
	GMat4 &operator*=(const float s);
	GMat4 &operator*=(const GMat4 &m);
	GMat4  operator+(const GMat4 &m)  const;
	GMat4  operator-(const GMat4 &m)  const;
	GMat4  operator*(const GMat4 &m)  const;
	GVec4  operator*(const GVec4 &v)  const;
	GMat4  operator*(const float s)  const;
	bool  operator==(const GMat4 &m) const;
	bool  operator!=(const GMat4 &m) const;
	
	void debug();
	void identity();
	void inverse();
	void rotate(const float x, const float y, const float z);
	const float *toArray() const;
	void translate(const float x, const float y, const float z);
	void transpose();
	void zero();
private:
	GVec4 mat[4];
};

#endif
