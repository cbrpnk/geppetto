#include <iostream>
#include <string>

#include "test.h"

int main(int argc, char **argv) {

    TEST_VEC3::TEST();
    std::cout << "Vec3 TEST PASSED\n"; 
    TEST_VEC4::TEST();
    std::cout << "Vec4 TEST PASSED\n"; 
    TEST_MAT3::TEST();
    std::cout << "Mat3 TEST PASSED\n"; 
    TEST_MAT4::TEST();
    std::cout << "Mat4 TEST PASSED\n"; 
    
    std::cout << "\nALL TESTS PASSED\n\n";
    
    return 0;
}
