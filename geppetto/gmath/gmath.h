#ifndef _GMATH_H_
#define _GMATH_H_

namespace Gmath
{
	float  degToRad(const float deg);
	float  radToDeg(const float rad);
	double randomDouble(const double min, const double max);
	float  randomFloat(const float min, const float max);
	int    randomInt(const int min, const int max);
	void   seedPrng();
}

#endif
