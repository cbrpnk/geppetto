#ifndef _VEC4_H_
#define _VEC4_H_

class Mat4;
class Vec3;

class Vec4 {
public:
	float x;
	float y;
	float z;
	float w;
	
	Vec4();
	Vec4(const Vec4 &v);
	Vec4(const Vec3 &v);
	Vec4(const float *a);
	Vec4(const float x, const float y, const float z, const float w);
	
	const float &operator[](const int i)   const;
	float &operator[](const int i);
	Vec4  &operator=(const Vec4 &v);
	Vec4  &operator+=(const Vec4 &v);
	Vec4  &operator-=(const Vec4 &v);
	Vec4  &operator*=(const float s);
	Vec4  &operator*=(const Mat4 &m);
	Vec4  &operator/=(const float s);
	Vec4   operator+(const Vec4 &v)  const;
	Vec4   operator-(const Vec4 &v)  const;
	float  operator*(const Vec4 &v)  const;
	Vec4   operator*(const Mat4 &m)  const;
	Vec4   operator*(const float s)  const;
	Vec4   operator/(const float s)  const;
	bool   operator==(const Vec4 &v) const;
	bool   operator!=(const Vec4 &v) const;
	
	Vec4 cross(const Vec4 &v) const;
	void debug();
	float length() const;
	void normalize();
	void zero();
};

#endif
