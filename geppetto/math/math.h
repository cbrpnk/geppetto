#ifndef _GMATH_H_
#define _GMATH_H_

namespace Geppetto {
namespace Math {
	
	float  DegToRad(const float deg);
	float  RadToDeg(const float rad);
	double RandomDouble(const double min, const double max);
	float  RandomFloat(const float min, const float max);
	int    RandomInt(const int min, const int max);
	void   SeedPrng();

} // namespace math
} // namespace Geppetto

#endif
