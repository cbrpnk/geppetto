#include <cmath>

#include "test.h"
#include "../math/vec3.h"
#include "../math/mat3.h"


namespace TEST_VEC3 {
using namespace Geppetto::Math;

    void OPERATOR_SUBSCRIPT() {
        Vec3 v(0.0f, 1.0f, 2.0f);
        
        ASSERT_EQUAL(v[0], 0.0f);
        ASSERT_EQUAL(v[1], 1.0f);
        ASSERT_EQUAL(v[2], 2.0f);
            
        // Test the const version of the operator
        const Vec3 cv(0.0f, 1.0f, 2.0f);
        
        ASSERT_EQUAL(cv[0], 0.0f);
        ASSERT_EQUAL(cv[1], 1.0f);
        ASSERT_EQUAL(cv[2], 2.0f);
    }
    
    
    void OPERATOR_ASSIGNMENT() {
        Vec3 v(0.0f, 1.0f, 2.0f);
        Vec3 v2 = v;
        v.x = 9.9f;
        v.y = 9.9f;
        v.z = 9.9f;
        
        ASSERT_EQUAL(v2[0], 0.0f);
        ASSERT_EQUAL(v2[1], 1.0f);
        ASSERT_EQUAL(v2[2], 2.0f);
    }
    
    
    void OPERATOR_PLUS_ASSIGN() {
        Vec3 v(1.0f, 2.0f, 3.0f);
        Vec3 v2(0.1f, 0.2f, 0.3f);
        v += v2;
        
        ASSERT_EQUAL(v.x, 1.1f);
        ASSERT_EQUAL(v.y, 2.2f);
        ASSERT_EQUAL(v.z, 3.3f);
        
        // Check that v2 has not been modified
        ASSERT_EQUAL(v2.x, 0.1f);
        ASSERT_EQUAL(v2.y, 0.2f);
        ASSERT_EQUAL(v2.z, 0.3f);
    }
    
    
    void OPERATOR_MINUS_ASSIGN() {
        Vec3 v(1.1f, 2.2f, 3.3f);
        Vec3 v2(0.1f, 0.2f, 0.3f);
        v -= v2;
        
        ASSERT_EQUAL(v.x, 1.0f);
        ASSERT_EQUAL(v.y, 2.0f);
        ASSERT_EQUAL(v.z, 3.0f);
        
        // Check that v2 has not been modified
        ASSERT_EQUAL(v2.x, 0.1f);
        ASSERT_EQUAL(v2.y, 0.2f);
        ASSERT_EQUAL(v2.z, 0.3f);
    }
    
    
    void OPERATOR_TIMES_ASSIGN() {
        // Scalar multiplication
        Vec3 v(1.0f, 2.0f, 3.0f);
        float s = 10.0f;
        v *= s;
        
        ASSERT_EQUAL(v.x, 10.0f);
        ASSERT_EQUAL(v.y, 20.0f);
        ASSERT_EQUAL(v.z, 30.0f);
        
        // Matrix multiplication
        Vec3 v2(1.0f, 2.0f, 3.0f);
        Mat3 m(v2, v2, v2);
        v2 *= m;
        ASSERT_EQUAL(v2, m * Vec3(1.0f, 2.0f, 3.0f));
    }
    
    
    void OPERATOR_DIVIDE_ASSIGN() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        float s = 10.0f;
        
        v /= s;
        ASSERT_EQUAL(v.x, 1.0f);
        ASSERT_EQUAL(v.y, 2.0f);
        ASSERT_EQUAL(v.z, 3.0f);
    }
    
    
    void OPERATOR_PLUS() {
        Vec3 v(1.0f, 2.0f, 3.0f);
        Vec3 v2(10.0f, 20.0f, 30.0f);
        Vec3 v3 = v + v2;
        
        ASSERT_EQUAL(v3.x, 11.0f);
        ASSERT_EQUAL(v3.y, 22.0f);
        ASSERT_EQUAL(v3.z, 33.0f);
    }
    
    
    void OPERATOR_MINUS() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        Vec3 v2(1.0f, 2.0f, 3.0f);
        Vec3 v3 = v - v2;
        
        ASSERT_EQUAL(v3.x, 9.0f);
        ASSERT_EQUAL(v3.y, 18.0f);
        ASSERT_EQUAL(v3.z, 27.0f);
    }
    
    
    void OPERATOR_TIMES() {
        // Test for vector multiplication
        Vec3 v(10.0f, 20.0f, 30.0f);
        Vec3 v2(1.0f, 2.0f, 3.0f);
        float s = v * v2;
        
        ASSERT_EQUAL(s, 140);
        
        // Test for scalar multiplication
        Vec3 v4 = v * 10;
        
        ASSERT_EQUAL(v4.x, 100.0f);
        ASSERT_EQUAL(v4.y, 200.0f);
        ASSERT_EQUAL(v4.z, 300.0f);
        
        // Test for matrix multiplication
        Vec3 v5(1.0f, 2.0f, 3.0f);
        Mat3 m(v5, v5, v5);
        Vec3 v6 = v5 * m;
        
        ASSERT_EQUAL(v6, m * v5);
        
    }
    
    
    void OPERATOR_DIVIDE() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        Vec3 v2 = v / 10;
        
        ASSERT_EQUAL(v2.x, 1.0f);
        ASSERT_EQUAL(v2.y, 2.0f);
        ASSERT_EQUAL(v2.z, 3.0f);
    }
    
    
    void OPERATOR_EQUAL() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        
        ASSERT_FALSE(v == Vec3(99.0f, 20.0f, 30.0f));
        ASSERT_FALSE(v == Vec3(10.0f, 99.0f, 30.0f));
        ASSERT_FALSE(v == Vec3(10.0f, 20.0f, 99.0f));
        
        ASSERT_TRUE(v == Vec3(10.0f, 20.0f, 30.0f));
    }
    
    
    void OPERATOR_NOT_EQUAL() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        
        ASSERT_TRUE(v != Vec3(99.0f, 20.0f, 30.0f));
        ASSERT_TRUE(v != Vec3(10.0f, 99.0f, 30.0f));
        ASSERT_TRUE(v != Vec3(10.0f, 20.0f, 99.0f));
        
        ASSERT_FALSE(v != Vec3(10.0f, 20.0f, 30.0f));
        
    }
    
    
    void CROSS() {
        Vec3 v(10.0f, 20.0f, 30.0f);
        Vec3 v2(2.0f, 3.0f, 4.0f);
        Vec3 v3 = v.Cross(v2);
        
        ASSERT_EQUAL(v3.x, -10);
        ASSERT_EQUAL(v3.y, 20);
        ASSERT_EQUAL(v3.z, -10);
    }
    
    
    void LENGTH() {
        Vec3 v(3.0f, 4.0f, 0.0f);
        ASSERT_EQUAL(v.Length(), 5.0f);
    }
    
    
    void NORMALIZE() {
        Vec3 v(1.0f, 2.0f, 3.0f);
        Vec3 xAxis(1.0f, 0.0f, 0.0f);
        Vec3 yAxis(0.0f, 1.0f, 0.0f);
        Vec3 zAxis(0.0f, 0.0f, 1.0f);
        float epsilon = 0.001f;
        float len = v.Length();
        float angleX = v*xAxis/len;
        float angleY = v*yAxis/len;
        float angleZ = v*zAxis/len;
        v.Normalize();
        len = v.Length();
        
        // Use an error margin of +/- epsilon
        ASSERT_LESS_THAN(std::abs(1-len), epsilon);
        ASSERT_LESS_THAN(std::abs(angleX-(v*xAxis/len)), epsilon);
        ASSERT_LESS_THAN(std::abs(angleY-(v*yAxis/len)), epsilon);
        ASSERT_LESS_THAN(std::abs(angleZ-(v*zAxis/len)), epsilon);
    }
    
    
    void ZERO() {
        Vec3 v(1.0, 1.0, 1.0);
        v.Zero();
        
        ASSERT_EQUAL(v.x, 0);
        ASSERT_EQUAL(v.y, 0);
        ASSERT_EQUAL(v.z, 0);
    }
    
    
    void TEST() {
        OPERATOR_SUBSCRIPT();
        OPERATOR_ASSIGNMENT();
        OPERATOR_PLUS_ASSIGN();
        OPERATOR_MINUS_ASSIGN();
        OPERATOR_TIMES_ASSIGN();
        OPERATOR_DIVIDE_ASSIGN();
        OPERATOR_PLUS();
        OPERATOR_MINUS();
        OPERATOR_TIMES();
        OPERATOR_DIVIDE();
        OPERATOR_EQUAL();
        OPERATOR_NOT_EQUAL();
        CROSS();
        LENGTH();
        NORMALIZE();
        ZERO();
    }
}
