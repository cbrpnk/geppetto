#include <cmath>

#include "test.h"
#include "../math/vec4.h"
#include "../math/mat4.h"


namespace TEST_VEC4 {
using namespace Geppetto::Math;

	void OPERATOR_SUBSCRIPT() {
		Vec4 v(0.0f, 1.0f, 2.0f, 3.0f);
		
		ASSERT_EQUAL(v[0], 0.0f);
		ASSERT_EQUAL(v[1], 1.0f);
		ASSERT_EQUAL(v[2], 2.0f);
		ASSERT_EQUAL(v[3], 3.0f);
			
		// Test the const version of the operator
		const Vec4 cv(0.0f, 1.0f, 2.0f, 3.0f);
		
		ASSERT_EQUAL(cv[0], 0.0f);
		ASSERT_EQUAL(cv[1], 1.0f);
		ASSERT_EQUAL(cv[2], 2.0f);
		ASSERT_EQUAL(cv[3], 3.0f);
	}
	
	
	void OPERATOR_ASSIGNMENT() {
		Vec4 v(0.0f, 1.0f, 2.0f, 3.0f);
		Vec4 v2 = v;
		v.x = 9.9f;
		v.y = 9.9f;
		v.z = 9.9f;
		v.w = 9.9f;
		
		ASSERT_EQUAL(v2[0], 0.0f);
		ASSERT_EQUAL(v2[1], 1.0f);
		ASSERT_EQUAL(v2[2], 2.0f);
		ASSERT_EQUAL(v2[3], 3.0f);
	}
	
	
	void OPERATOR_PLUS_ASSIGN() {
		Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4 v2(0.1f, 0.2f, 0.3f, 0.4f);
		v += v2;
		
		ASSERT_EQUAL(v.x, 1.1f);
		ASSERT_EQUAL(v.y, 2.2f);
		ASSERT_EQUAL(v.z, 3.3f);
		ASSERT_EQUAL(v.w, 4.4f);
		
		// Check that v2 has not been modified
		ASSERT_EQUAL(v2.x, 0.1f);
		ASSERT_EQUAL(v2.y, 0.2f);
		ASSERT_EQUAL(v2.z, 0.3f);
		ASSERT_EQUAL(v2.w, 0.4f);
	}
	
	
	void OPERATOR_MINUS_ASSIGN() {
		Vec4 v(1.1f, 2.2f, 3.3f, 4.4f);
		Vec4 v2(0.1f, 0.2f, 0.3f, 0.4f);
		v -= v2;
		
		ASSERT_EQUAL(v.x, 1.0f);
		ASSERT_EQUAL(v.y, 2.0f);
		ASSERT_EQUAL(v.z, 3.0f);
		ASSERT_EQUAL(v.w, 4.0f);
		
		// Check that v2 has not been modified
		ASSERT_EQUAL(v2.x, 0.1f);
		ASSERT_EQUAL(v2.y, 0.2f);
		ASSERT_EQUAL(v2.z, 0.3f);
		ASSERT_EQUAL(v2.w, 0.4f);
		
	}
	
	
	void OPERATOR_TIMES_ASSIGN() {
		// Scalar multiplication
		Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		float s = 10.0f;
		v *= s;
		
		ASSERT_EQUAL(v.x, 10.0f);
		ASSERT_EQUAL(v.y, 20.0f);
		ASSERT_EQUAL(v.z, 30.0f);
		ASSERT_EQUAL(v.w, 40.0f);
		
		// Matrix multiplication
		Vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		Mat4 m(v2, v2, v2, v2);
		v2 *= m;
		ASSERT_EQUAL(v2, m * Vec4(1.0f, 2.0f, 3.0f, 4.0f));
	}
	
	
	void OPERATOR_DIVIDE_ASSIGN() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		float s = 10.0f;
		
		v /= s;
		ASSERT_EQUAL(v.x, 1.0f);
		ASSERT_EQUAL(v.y, 2.0f);
		ASSERT_EQUAL(v.z, 3.0f);
		ASSERT_EQUAL(v.w, 4.0f);
		
	}
	
	
	void OPERATOR_PLUS() {
		Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4 v2(10.0f, 20.0f, 30.0f, 40.0f);
		Vec4 v3 = v + v2;
		
		ASSERT_EQUAL(v3.x, 11.0f);
		ASSERT_EQUAL(v3.y, 22.0f);
		ASSERT_EQUAL(v3.z, 33.0f);
		ASSERT_EQUAL(v3.w, 44.0f);
	}
	
	
	void OPERATOR_MINUS() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		Vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4 v3 = v - v2;
		
		ASSERT_EQUAL(v3.x, 9.0f);
		ASSERT_EQUAL(v3.y, 18.0f);
		ASSERT_EQUAL(v3.z, 27.0f);
		ASSERT_EQUAL(v3.w, 36.0f);
	}
	
	
	void OPERATOR_TIMES() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		Vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		
		// Test for vector multiplication
		float s = v * v2;
		
		ASSERT_EQUAL(s, 300);
		
		// Test for scalar multiplication
		Vec4 v4 = v * 10;
		
		ASSERT_EQUAL(v4.x, 100.0f);
		ASSERT_EQUAL(v4.y, 200.0f);
		ASSERT_EQUAL(v4.z, 300.0f);
		ASSERT_EQUAL(v4.w, 400.0f);
		
		// Test for matrix multiplication
		Vec4 v5(1.0f, 2.0f, 3.0f, 4.0f);
		Mat4 m(v5, v5, v5, v5);
		Vec4 v6 = v5 * m;
		
		ASSERT_EQUAL(v6, m * v5);
		
	}
	
	
	void OPERATOR_DIVIDE() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		Vec4 v2 = v / 10;
		
		ASSERT_EQUAL(v2.x, 1.0f);
		ASSERT_EQUAL(v2.y, 2.0f);
		ASSERT_EQUAL(v2.z, 3.0f);
		ASSERT_EQUAL(v2.w, 4.0f);
	}
	
	
	void OPERATOR_EQUAL() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		
		ASSERT_FALSE(v == Vec4(99.0f, 20.0f, 30.0f, 40.0f));
		ASSERT_FALSE(v == Vec4(10.0f, 99.0f, 30.0f, 40.0f));
		ASSERT_FALSE(v == Vec4(10.0f, 20.0f, 99.0f, 40.0f));
		ASSERT_FALSE(v == Vec4(10.0f, 20.0f, 30.0f, 99.0f));
		
		ASSERT_TRUE(v == Vec4(10.0f, 20.0f, 30.0f, 40.0f));
	}
	
	
	void OPERATOR_NOT_EQUAL() {
		Vec4 v(10.0f, 20.0f, 30.0f, 40.0f);
		
		ASSERT_TRUE(v != Vec4(99.0f, 20.0f, 30.0f, 40.0f));
		ASSERT_TRUE(v != Vec4(10.0f, 99.0f, 30.0f, 40.0f));
		ASSERT_TRUE(v != Vec4(10.0f, 20.0f, 99.0f, 40.0f));
		ASSERT_TRUE(v != Vec4(10.0f, 20.0f, 30.0f, 99.0f));
		
		ASSERT_FALSE(v != Vec4(10.0f, 20.0f, 30.0f, 40.0f));
		
	}
	
	
	void CROSS() {
		Vec4 v(10.0f, 20.0f, 30.0f, 0.0f);
		Vec4 v2(2.0f, 3.0f, 4.0f, 0.0f);
		Vec4 v3 = v.Cross(v2);
		
		ASSERT_EQUAL(v3.x, -10);
		ASSERT_EQUAL(v3.y, 20);
		ASSERT_EQUAL(v3.z, -10);
	}
	
	
	void LENGTH() {
		Vec4 v(3.0f, 4.0f, 0.0f, 0.0f);
		ASSERT_EQUAL(v.Length(), 5.0f);
	}
	
	
	void NORMALIZE() {
		Vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		Vec4 xAxis(1.0f, 0.0f, 0.0f, 0.0f);
		Vec4 yAxis(0.0f, 1.0f, 0.0f, 0.0f);
		Vec4 zAxis(0.0f, 0.0f, 1.0f, 0.0f);
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
		Vec4 v(1.0, 1.0, 1.0, 1.0);
		v.Zero();
		
		ASSERT_EQUAL(v.x, 0);
		ASSERT_EQUAL(v.y, 0);
		ASSERT_EQUAL(v.z, 0);
		ASSERT_EQUAL(v.w, 0);
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
