#ifndef _GVEC4_H_
#define _GVEC4_H_

class GMat4;
class GVec3;

class GVec4
{
public:
	float x;
	float y;
	float z;
	float w;
	
	GVec4();
	GVec4(const GVec4 &v);
	GVec4(const GVec3 &v);
	GVec4(const float *a);
	GVec4(const float x, const float y, const float z, const float w);
	
	const float &operator[](const int i)   const;
	float &operator[](const int i);
	GVec4  &operator=(const GVec4 &v);
	GVec4  &operator+=(const GVec4 &v);
	GVec4  &operator-=(const GVec4 &v);
	GVec4  &operator*=(const float s);
	GVec4  &operator*=(const GMat4 &m);
	GVec4  &operator/=(const float s);
	GVec4   operator+(const GVec4 &v)  const;
	GVec4   operator-(const GVec4 &v)  const;
	float  operator*(const GVec4 &v)  const;
	GVec4   operator*(const GMat4 &m)  const;
	GVec4   operator*(const float s)  const;
	GVec4   operator/(const float s)  const;
	bool   operator==(const GVec4 &v) const;
	bool   operator!=(const GVec4 &v) const;
	
	GVec4 cross(const GVec4 &v) const;
	void debug();
	float length() const;
	void normalize();
	void zero();
};

#endif
