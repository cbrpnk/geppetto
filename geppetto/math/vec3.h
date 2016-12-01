#ifndef _VEC3_H_
#define _VEC3_H_

class Mat3;
class Vec4;

class Vec3
{
public:
	float x;
	float y;
	float z;
	
	Vec3();
	Vec3(const Vec3 &v);
	Vec3(const Vec4 &v);
	Vec3(const float *a);
	Vec3(const float x, const float y, const float z);
	
	const float &operator[](const int i)   const;
	float &operator[](const int i);
	Vec3  &operator=(const Vec3 &v);
	Vec3  &operator+=(const Vec3 &v);
	Vec3  &operator-=(const Vec3 &v);
	Vec3  &operator*=(const float s);
	Vec3  &operator*=(const Mat3 &m);
	Vec3  &operator/=(const float s);
	Vec3   operator+(const Vec3 &v)  const;
	Vec3   operator-(const Vec3 &v)  const;
	float  operator*(const Vec3 &v)  const;
	Vec3   operator*(const Mat3 &m)  const;
	Vec3   operator*(const float s)  const;
	Vec3   operator/(const float s)  const;
	bool   operator==(const Vec3 &v) const;
	bool   operator!=(const Vec3 &v) const;
	
	Vec3 cross(const Vec3 &v) const;
	void debug();
	float length() const;
	void normalize();
	void zero();
};

#endif
