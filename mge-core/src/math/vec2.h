#pragma once

#include <iostream>

namespace mge
{
	namespace math
	{
		struct vec2
		{
			union 
			{
				float x, y;				
				float values[2];
			};

			vec2();
			vec2(const float& x = 0, const float& y = 0);

			vec2& add(const vec2& rhs);
			vec2& sub(const vec2& rhs);
			vec2& multiply(const vec2& rhs);
			vec2& divide(const vec2& rhs);

			vec2& operator+=(const vec2& rhs);
			vec2& operator-=(const vec2& rhs);
			vec2& operator*=(const vec2& rhs);
			vec2& operator/=(const vec2& rhs);

			bool operator==(const vec2& rhs);
			bool operator!=(const vec2& rhs);

			friend vec2& operator+(vec2 &lhs, const vec2& rhs);
			friend vec2& operator-(vec2 &lhs, const vec2& rhs);
			friend vec2& operator*(vec2 &lhs, const vec2& rhs);
			friend vec2& operator/(vec2 &lhs, const vec2& rhs);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& rhs);
		};
	} // namespace math
} // namespace mge