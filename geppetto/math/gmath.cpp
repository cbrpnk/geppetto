#include <cmath>
#include <ctime>
#include <cassert>
#include <limits>
#include <cstdlib>

#include "gmath.h"


namespace Gmath
{
	static bool prng_seeded = false;


	float degToRad(const float deg)
	{
		return deg * M_PI/180.0f;
	}


	float radToDeg(const float rad)
	{
		return rad * 180.0f/M_PI;
	}


	double randomDouble(const double min, const double max)
	{
		assert(max <= std::numeric_limits<double>::max());
		seedPrng();
		return std::rand() / (double) RAND_MAX * (max-min) + min;
	}


	float randomFloat(const float min, const float max)
	{
		assert(max <= std::numeric_limits<float>::max());
		return (float) randomDouble(min, max);
	}

	int randomInt(const int min, const int max)
	{
		assert(max <= std::numeric_limits<int>::max());
		return std::round(randomDouble(min, max));
	}

	void seedPrng()
	{
		if(!prng_seeded) {
			std::srand(std::time(0));
			prng_seeded = true;
		}
	}
}
