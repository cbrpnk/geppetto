#ifndef _GVEC3_H_
#define _GVEC3_H_

class GMat3;
class GVec4;

class GVec3
{
public:
	float x;
	float y;
	float z;
	
	GVec3();
	GVec3(const GVec3 &v);
	GVec3(const GVec4 &v);
	GVec3(const float *a);
	GVec3(const float x, const float y, const float z);
	
	const float &operator[](const int i)   const;
	float &operator[](const int i);
	GVec3  &operator=(const GVec3 &v);
	GVec3  &operator+=(const GVec3 &v);
	GVec3  &operator-=(const GVec3 &v);
	GVec3  &operator*=(const float s);
	GVec3  &operator*=(const GMat3 &m);
	GVec3  &operator/=(const float s);
	GVec3   operator+(const GVec3 &v)  const;
	GVec3   operator-(const GVec3 &v)  const;
	float  operator*(const GVec3 &v)  const;
	GVec3   operator*(const GMat3 &m)  const;
	GVec3   operator*(const float s)  const;
	GVec3   operator/(const float s)  const;
	bool   operator==(const GVec3 &v) const;
	bool   operator!=(const GVec3 &v) const;
	
	GVec3 cross(const GVec3 &v) const;
	void debug();
	float length() const;
	void normalize();
	void zero();
};

#endif
