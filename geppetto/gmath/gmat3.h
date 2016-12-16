#ifndef _GMAT3_H_
#define _GMAT3_H_

#include "gvec3.h"

class GMat4;

const float identity3x3[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
};

class GMat3
{
public:
	GMat3();
	GMat3(const GMat3 &m);
	GMat3(const GMat4 &m);
	GMat3(const float *a);
	GMat3(const GVec3 x, const GVec3 y, const GVec3 z);
	
	const GVec3 &operator[](const int i)   const;
	GVec3 &operator[](const int i);
	GMat3 &operator=(const GMat3 &m);
	GMat3 &operator+=(GMat3 &m);
	GMat3 &operator-=(const GMat3 &m);
	GMat3 &operator*=(const float s);
	GMat3 &operator*=(const GMat3 &m);
	GMat3  operator+(const GMat3 &m)  const;
	GMat3  operator-(const GMat3 &m)  const;
	GMat3  operator*(const GMat3 &m)  const;
	GVec3  operator*(const GVec3 &v)  const;
	GMat3  operator*(const float s)  const;
	bool  operator==(const GMat3 &m) const;
	bool  operator!=(const GMat3 &m) const;
	
	void debug();
	void identity();
	void inverse();
	const float *toArray() const;
	void transpose();
	void zero();
private:
	GVec3 mat[3];
};

#endif
