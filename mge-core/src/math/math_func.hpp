#include <cmath>

namespace mge
{
	namespace math
	{
		// TODO(batuhan): Add trigonometric, min/max, clamp... 
		static const float MG_PI = 3.14159265358f;

		static inline float ToRadians(float degrees)
		{
			return static_cast<float>(degrees * MG_PI / 180.0f);
		}

		static inline float ToDegrees(float radians)
		{
			return static_cast<float>(radians * (180.0f / MG_PI));
		}	
	}
}