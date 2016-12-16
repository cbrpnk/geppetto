#ifndef _TEST_TEST_H_
#define _TEST_TEST_H_

#include <cassert>

#define ASSERT_TRUE(exp) assert(exp);
#define ASSERT_FALSE(exp) assert(!(exp));
#define ASSERT_EQUAL(a, b) assert((a) == (b))
#define ASSERT_NOT_EQUAL(a, b) assert((a) != (b))
#define ASSERT_LESS_THAN(a, b) assert((a) < (b))
#define ASSERT_GREATER_THAN(a, b) assert((a) > (b))
#define ASSERT_LESS_EQUAL(a, b) assert((a) <= (b))
#define ASSERT_GREATER_EQUAL(a, b) assert((a) >= (b))

namespace TEST_GVEC3 {
	void TEST();
}

namespace TEST_GVEC4 {
	void TEST();
}

namespace TEST_GMAT3 {
	void TEST();
}

namespace TEST_GMAT4 {
	void TEST();
}

#endif
