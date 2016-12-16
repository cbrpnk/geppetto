#include <iostream>
#include <string>

#include "test.h"

int main(int argc, char **argv) {

	TEST_GVEC3::TEST();
	std::cout << "GVec3 TEST PASSED\n"; 
	TEST_GVEC4::TEST();
	std::cout << "GVec4 TEST PASSED\n"; 
	TEST_GMAT3::TEST();
	std::cout << "GMat3 TEST PASSED\n"; 
	TEST_GMAT4::TEST();
	std::cout << "GMat4 TEST PASSED\n"; 
	
	std::cout << "\nALL TESTS PASSED\n\n";
	
	return 0;
}
