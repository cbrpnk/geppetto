#include <cmath>
#include <ctime>
#include <cassert>
#include <limits>
#include <cstdlib>

#include "math.h"


namespace Geppetto {
namespace Math {

    static bool prngSeeded = false;


    float DegToRad(const float deg)
    {
        return deg * M_PI/180.0f;
    }


    float RadToDeg(const float rad)
    {
        return rad * 180.0f/M_PI;
    }


    double RandomDouble(const double min, const double max)
    {
        assert(max <= std::numeric_limits<double>::max());
        SeedPrng();
        return std::rand() / (double) RAND_MAX * (max-min) + min;
    }


    float RandomFloat(const float min, const float max)
    {
        assert(max <= std::numeric_limits<float>::max());
        return (float) RandomDouble(min, max);
    }

    int RandomInt(const int min, const int max)
    {
        assert(max <= std::numeric_limits<int>::max());
        return std::round(RandomDouble(min, max));
    }

    void SeedPrng()
    {
        if(!prngSeeded) {
            std::srand(std::time(0));
            prngSeeded = true;
        }
    }

} // namespace Math
} // namespace Geppetto
