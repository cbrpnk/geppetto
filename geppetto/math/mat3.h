#ifndef _MAT3_H_
#define _MAT3_H_

#include "vec3.h"

namespace Geppetto {
namespace Math {

class Mat4;

const float identity3x3[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
};

class Mat3
{
public:
    Mat3();
    Mat3(const Mat3& m);
    Mat3(const Mat4& m);
    Mat3(const float* a);
    Mat3(const Vec3 x, const Vec3 y, const Vec3 z);
    
    const Vec3& operator[](const int i)    const;
    Vec3&       operator[](const int i);
    Mat3&       operator=(const Mat3& m);
    Mat3&       operator+=(Mat3& m);
    Mat3&       operator-=(const Mat3& m);
    Mat3&       operator*=(const float s);
    Mat3&       operator*=(const Mat3& m);
    Mat3        operator+(const Mat3& m)  const;
    Mat3        operator-(const Mat3& m)  const;
    Mat3        operator*(const Mat3& m)  const;
    Vec3        operator*(const Vec3& v)  const;
    Mat3        operator*(const float s)   const;
    bool         operator==(const Mat3& m) const;
    bool         operator!=(const Mat3& m) const;
    
    void         Debug();
    void         Identity();
    void         Inverse();
    const float* ToArray() const;
    void         Transpose();
    void         Zero();
private:
    Vec3 mat[3];
};

} // namespace Math
} // namespace Geppetto

#endif
