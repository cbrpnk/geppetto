#include <cmath>

#include "test.h"
#include "../gmath/gmat3.h"

namespace TEST_GMAT3 {
	
	const float init[] = {
	    2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,
		8.0f, 9.0f, 10.0f,
	};
	
	void OPERATOR_SUBSCRIPT() {
		GMat3 m(init);
		
		ASSERT_EQUAL(m[0], GVec3(2.0f, 3.0f, 4.0f));
		ASSERT_EQUAL(m[1], GVec3(5.0f, 6.0f, 7.0f));
		ASSERT_EQUAL(m[2], GVec3(8.0f, 9.0f, 10.0f));
		
		// Const subscript
		const GMat3 m2(init);
		
		ASSERT_EQUAL(m2[0], GVec3(2.0f, 3.0f, 4.0f));
		ASSERT_EQUAL(m2[1], GVec3(5.0f, 6.0f, 7.0f));
		ASSERT_EQUAL(m2[2], GVec3(8.0f, 9.0f, 10.0f));
	}
	
	
	void OPERATOR_ASIGN() {
		GMat3 m(init);
		GMat3 m2 = m;
		
		ASSERT_EQUAL(m2, GMat3(init));
	}
	
	
	void OPERATOR_PLUS_ASIGN() {
		GMat3 m(init);
		GMat3 m2(init);
		m += m2;
		
		ASSERT_EQUAL(m, GMat3(init)*2);
	}
	
	
	void OPERATOR_MINUS_ASIGN() {
		GMat3 m(init);
		GMat3 m2(init);
		m -= m2;
		m2.zero();
			
		ASSERT_EQUAL(m, m2);	
	}
	
	
	void OPERATOR_TIMES_ASIGN() {
		// Scalar multiplication
		GMat3 m(init);
		GMat3 m2(init);
		m *= 2;
		m2 = m2 * 2;
		
		ASSERT_EQUAL(m, m2);
		
		// Matrix multiplication
		GMat3 m3(init);
		GMat3 m4(init);
		m3 *= m3;
		m4 = m4*m4;
		
		ASSERT_EQUAL(m3, m4);
	}
	
	
	void OPERATOR_PLUS() {
		GMat3 m(init);
		GMat3 m2 = m + m;
		
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				ASSERT_EQUAL(m2[i][j], init[i*3+j]*2);
			}
		}
	}
	
	
	void OPERATOR_MINUS() {
		GMat3 m(init);
		GMat3 m2 = m - m*2;
		
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				ASSERT_EQUAL(m2[i][j], -init[i*3+j]);
			}
		}
	}
	
	
	void OPERATOR_TIMES() {
		// Scalar multiplicationj
		GMat3 m(init);
		GMat3 m2 = m * 2;
		
		ASSERT_EQUAL(m2[0], GMat3(init)[0]*2);
		ASSERT_EQUAL(m2[1], GMat3(init)[1]*2);
		ASSERT_EQUAL(m2[2], GMat3(init)[2]*2);
		
		// Vector multiplication
		GMat3 m3(init);
		GVec3 v(2.0f, 3.0f, 4.0f);
		GVec3 v2 = m3 * v;
		
		ASSERT_EQUAL(v2, GVec3(51.0f, 60.0f, 69.0f));
		
		// Matrix multiplication
		const float answer[] = {
		    51.0f, 60.0f, 69.0f,
		    96.0f, 114.0f, 132.0f,
		    141.0f, 168.0f, 195.0f
		};
		GMat3 m4(init);
		GMat3 m5 = m4 * m4;
		
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				ASSERT_EQUAL(m5[i][j], answer[i*3+j]);
			}
		}
	}
	
	
	void OPERATOR_EQUAL() {
		GMat3 m(init);
		GMat3 m2(init);
		
		ASSERT_TRUE(m == m2);
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				m2 = GMat3(init);
				m2[i][j]++;
				ASSERT_FALSE(m == m2);
			}
		}
	}
	
	
	void OPERATOR_NOT_EQUAL() {
		GMat3 m(init);
		GMat3 m2(init);
		
		ASSERT_FALSE(m != m2);
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				m2 = GMat3(init);
				m2[i][j]++;
				ASSERT_TRUE(m != m2);
			}
		}
	}
	
	
	void IDENTITY() {
		GMat3 m;
		m.identity();
		
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				if(i != j) {
					ASSERT_EQUAL(m[i][j], 0.0f);
				} else {
					ASSERT_EQUAL(m[i][j], 1.0f);
				}
			}
		}
	}
	
	
	void TRANSPOSE() {
		GMat3 m(init);
		GMat3 m2(init);
		m.transpose();
		
		for(int i=0; i<3; ++i) {
			for(int j=0; j<3; ++j) {
				ASSERT_EQUAL(m[i][j], m2[j][i]);
			}
		}
		
	}
	
	
	void ZERO() {
		GMat3 m;
		GVec3 v;
		m.zero();
		v.zero();
		
		ASSERT_EQUAL(m[0], v);
		ASSERT_EQUAL(m[1], v);
		ASSERT_EQUAL(m[2], v);
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
		TRANSPOSE();
		ZERO();
	}
}

