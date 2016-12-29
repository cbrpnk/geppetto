#include <cmath>

#include "test.h"
#include "../math/mat3.h"

namespace TEST_MAT3 {
using namespace Geppetto::Math;
    
    const float init[] = {
        2.0f,  3.0f,  4.0f,
        5.0f,  6.0f,  7.0f,
        8.0f, 9.0f, 10.0f,
    };
    
    void OPERATOR_SUBSCRIPT() {
        Mat3 m(init);
        
        ASSERT_EQUAL(m[0], Vec3(2.0f, 3.0f, 4.0f));
        ASSERT_EQUAL(m[1], Vec3(5.0f, 6.0f, 7.0f));
        ASSERT_EQUAL(m[2], Vec3(8.0f, 9.0f, 10.0f));
        
        // Const subscript
        const Mat3 m2(init);
        
        ASSERT_EQUAL(m2[0], Vec3(2.0f, 3.0f, 4.0f));
        ASSERT_EQUAL(m2[1], Vec3(5.0f, 6.0f, 7.0f));
        ASSERT_EQUAL(m2[2], Vec3(8.0f, 9.0f, 10.0f));
    }
    
    
    void OPERATOR_ASIGN() {
        Mat3 m(init);
        Mat3 m2 = m;
        
        ASSERT_EQUAL(m2, Mat3(init));
    }
    
    
    void OPERATOR_PLUS_ASIGN() {
        Mat3 m(init);
        Mat3 m2(init);
        m += m2;
        
        ASSERT_EQUAL(m, Mat3(init)*2);
    }
    
    
    void OPERATOR_MINUS_ASIGN() {
        Mat3 m(init);
        Mat3 m2(init);
        m -= m2;
        m2.Zero();
            
        ASSERT_EQUAL(m, m2);    
    }
    
    
    void OPERATOR_TIMES_ASIGN() {
        // Scalar multiplication
        Mat3 m(init);
        Mat3 m2(init);
        m *= 2;
        m2 = m2 * 2;
        
        ASSERT_EQUAL(m, m2);
        
        // Matrix multiplication
        Mat3 m3(init);
        Mat3 m4(init);
        m3 *= m3;
        m4 = m4*m4;
        
        ASSERT_EQUAL(m3, m4);
    }
    
    
    void OPERATOR_PLUS() {
        Mat3 m(init);
        Mat3 m2 = m + m;
        
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                ASSERT_EQUAL(m2[i][j], init[i*3+j]*2);
            }
        }
    }
    
    
    void OPERATOR_MINUS() {
        Mat3 m(init);
        Mat3 m2 = m - m*2;
        
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                ASSERT_EQUAL(m2[i][j], -init[i*3+j]);
            }
        }
    }
    
    
    void OPERATOR_TIMES() {
        // Scalar multiplicationj
        Mat3 m(init);
        Mat3 m2 = m * 2;
        
        ASSERT_EQUAL(m2[0], Mat3(init)[0]*2);
        ASSERT_EQUAL(m2[1], Mat3(init)[1]*2);
        ASSERT_EQUAL(m2[2], Mat3(init)[2]*2);
        
        // Vector multiplication
        Mat3 m3(init);
        Vec3 v(2.0f, 3.0f, 4.0f);
        Vec3 v2 = m3 * v;
        
        ASSERT_EQUAL(v2, Vec3(51.0f, 60.0f, 69.0f));
        
        // Matrix multiplication
        const float answer[] = {
            51.0f, 60.0f, 69.0f,
            96.0f, 114.0f, 132.0f,
            141.0f, 168.0f, 195.0f
        };
        Mat3 m4(init);
        Mat3 m5 = m4 * m4;
        
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                ASSERT_EQUAL(m5[i][j], answer[i*3+j]);
            }
        }
    }
    
    
    void OPERATOR_EQUAL() {
        Mat3 m(init);
        Mat3 m2(init);
        
        ASSERT_TRUE(m == m2);
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                m2 = Mat3(init);
                m2[i][j]++;
                ASSERT_FALSE(m == m2);
            }
        }
    }
    
    
    void OPERATOR_NOT_EQUAL() {
        Mat3 m(init);
        Mat3 m2(init);
        
        ASSERT_FALSE(m != m2);
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                m2 = Mat3(init);
                m2[i][j]++;
                ASSERT_TRUE(m != m2);
            }
        }
    }
    
    
    void IDENTITY() {
        Mat3 m;
        m.Identity();
        
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
        Mat3 m(init);
        Mat3 m2(init);
        m.Transpose();
        
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                ASSERT_EQUAL(m[i][j], m2[j][i]);
            }
        }
        
    }
    
    
    void ZERO() {
        Mat3 m;
        Vec3 v;
        m.Zero();
        v.Zero();
        
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

