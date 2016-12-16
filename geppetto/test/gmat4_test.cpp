#include <cmath>

#include "test.h"
#include "../gmath/gmath.h"
#include "../gmath/gmat4.h"

namespace TEST_GMAT4 {
	
	const float init[] = {
	    2.0f,  3.0f,  4.0f,  5.0f,
		6.0f,  7.0f,  8.0f,  9.0f,
		10.0f, 11.0f, 12.0f, 13.0f,
		14.0f, 15.0f, 16.0f, 17.0f
	};
	
	void OPERATOR_SUBSCRIPT() {
		GMat4 m(init);
		
		ASSERT_EQUAL(m[0], GVec4(2.0f, 3.0f, 4.0f, 5.0f));
		ASSERT_EQUAL(m[1], GVec4(6.0f, 7.0f, 8.0f, 9.0f));
		ASSERT_EQUAL(m[2], GVec4(10.0f, 11.0f, 12.0f, 13.0f));
		ASSERT_EQUAL(m[3], GVec4(14.0f, 15.0f, 16.0f, 17.0f));
		
		// Const subscript
		const GMat4 m2(init);
		
		ASSERT_EQUAL(m2[0], GVec4(2.0f, 3.0f, 4.0f, 5.0f));
		ASSERT_EQUAL(m2[1], GVec4(6.0f, 7.0f, 8.0f, 9.0f));
		ASSERT_EQUAL(m2[2], GVec4(10.0f, 11.0f, 12.0f, 13.0f));
		ASSERT_EQUAL(m2[3], GVec4(14.0f, 15.0f, 16.0f, 17.0f));
	}
	
	
	void OPERATOR_ASIGN() {
		GMat4 m(init);
		GMat4 m2 = m;
		
		ASSERT_EQUAL(m2, GMat4(init));
	}
	
	
	void OPERATOR_PLUS_ASIGN() {
		GMat4 m(init);
		GMat4 m2(init);
		m += m2;
		
		ASSERT_EQUAL(m, GMat4(init)*2);
	}
	
	
	void OPERATOR_MINUS_ASIGN() {
		GMat4 m(init);
		GMat4 m2(init);
		m -= m2;
		m2.zero();
			
		ASSERT_EQUAL(m, m2);	
	}
	
	
	void OPERATOR_TIMES_ASIGN() {
		// Scalar multiplication
		GMat4 m(init);
		GMat4 m2(init);
		m *= 2;
		m2 = m2 * 2;
		
		ASSERT_EQUAL(m, m2);
		
		// Matrix multiplication
		GMat4 m3(init);
		GMat4 m4(init);
		m3 *= m3;
		m4 = m4*m4;
		
		ASSERT_EQUAL(m3, m4);
	}
	
	
	void OPERATOR_PLUS() {
		GMat4 m(init);
		GMat4 m2 = m + m;
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				ASSERT_EQUAL(m2[i][j], init[i*4+j]*2);
			}
		}
	}
	
	
	void OPERATOR_MINUS() {
		GMat4 m(init);
		GMat4 m2 = m - m*2;
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				ASSERT_EQUAL(m2[i][j], -init[i*4+j]);
			}
		}
	}
	
	
	void OPERATOR_TIMES() {
		// Scalar multiplicationj
		GMat4 m(init);
		GMat4 m2 = m * 2;
		
		ASSERT_EQUAL(m2[0], GMat4(init)[0]*2);
		ASSERT_EQUAL(m2[1], GMat4(init)[1]*2);
		ASSERT_EQUAL(m2[2], GMat4(init)[2]*2);
		ASSERT_EQUAL(m2[3], GMat4(init)[3]*2);
		
		// Vector multiplication
		GMat4 m3(init);
		GVec4 v(2.0f, 3.0f, 4.0f, 5.0f);
		GVec4 v2 = m3 * v;
		
		ASSERT_EQUAL(v2, GVec4(132.0f, 146.0f, 160.0f, 174.0f));
		
		// Matrix multiplication
		const float answer[] = {
		    132.0f, 146.0f, 160.0f, 174.0f,
		    260.0f, 290.0f, 320.0f, 350.0f,
		    388.0f, 434.0f, 480.0f, 526.0f,
		    516.0f, 578.0f, 640.0f, 702.0f
		};
		GMat4 m4(init);
		GMat4 m5 = m4 * m4;
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				ASSERT_EQUAL(m5[i][j], answer[i*4+j]);
			}
		}
	}
	
	
	void OPERATOR_EQUAL() {
		GMat4 m(init);
		GMat4 m2(init);
		
		ASSERT_TRUE(m == m2);
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				m2 = GMat4(init);
				m2[i][j]++;
				ASSERT_FALSE(m == m2);
			}
		}
	}
	
	
	void OPERATOR_NOT_EQUAL() {
		GMat4 m(init);
		GMat4 m2(init);
		
		ASSERT_FALSE(m != m2);
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				m2 = GMat4(init);
				m2[i][j]++;
				ASSERT_TRUE(m != m2);
			}
		}
	}
	
	
	void IDENTITY() {
		GMat4 m;
		m.identity();
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				if(i != j) {
					ASSERT_EQUAL(m[i][j], 0.0f);
				} else {
					ASSERT_EQUAL(m[i][j], 1.0f);
				}
			}
		}
	}
	
	
	void ROTATE() {
		GMat4 m(init);
		GMat4 m2(init);
		float epsilon = 0.001f;
		
		float x = Gmath::degToRad(33.3f);
		float cosx = cos(x);    
		float sinx = sin(x);
		
		float y = Gmath::degToRad(0.0f);
		float cosy = cos(y);    
		float siny = sin(y);
		
		float z = Gmath::degToRad(0.0f);
		float cosz = cos(z);    
		float sinz = sin(z);
	
		const float x_rot[] = {
		     1.0f, 0.0f, 0.0f, 0.0f,
			 0.0f, cosx, sinx, 0.0f,
			 0.0f, -sinx, cosx, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f
		};
		
		const float y_rot[] = {
		     cosy, 0.0f, -siny, 0.0f,
			 0.0f, 1.0f, 0.0f, 0.0f,
			 siny, 0.0f, cosy, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f
		};
		
		const float z_rot[] = {
		     cosz, sinz, 0.0f, 0.0f,
			-sinz, cosz, 0.0f, 0.0f,
			 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f
		};
		
		m.rotate(Gmath::radToDeg(x), Gmath::radToDeg(y), Gmath::radToDeg(z));
		m2 *= GMat4(x_rot);
		m2 *= GMat4(y_rot);
		m2 *= GMat4(z_rot);
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				ASSERT_LESS_THAN(std::abs(m2[i][j] - m[i][j]), epsilon);
			}
		}
	}
	
	
	void TRANSLATE() {
		GMat4 m(init);
		m.translate(9.9f, 9.9f, 9.9f);
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<3; ++j) {
				if(i<3) {
					ASSERT_EQUAL(m[i][j], init[i*4+j]);
				} else {
					ASSERT_EQUAL(m[i][j], 9.9f);
				}
			}
		}
	}
	
	
	void TRANSPOSE() {
		GMat4 m(init);
		GMat4 m2(init);
		m.transpose();
		
		for(int i=0; i<4; ++i) {
			for(int j=0; j<4; ++j) {
				ASSERT_EQUAL(m[i][j], m2[j][i]);
			}
		}
		
	}
	
	
	void ZERO() {
		GMat4 m;
		GVec4 v;
		v.zero();
		m.zero();
		
		ASSERT_EQUAL(m[0], v);
		ASSERT_EQUAL(m[1], v);
		ASSERT_EQUAL(m[2], v);
		ASSERT_EQUAL(m[3], v);
	}
	
	
	void TEST() {
		OPERATOR_SUBSCRIPT();
		OPERATOR_ASIGN();
		OPERATOR_PLUS_ASIGN();
		OPERATOR_MINUS_ASIGN();
		OPERATOR_TIMES_ASIGN();
		OPERATOR_PLUS();
		OPERATOR_MINUS();
		OPERATOR_TIMES();
		OPERATOR_EQUAL();
		OPERATOR_NOT_EQUAL();
		IDENTITY();
		ROTATE();
		TRANSLATE();
		TRANSPOSE();
		ZERO();
	}
}

