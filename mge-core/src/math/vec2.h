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
				struct
				{
					float x, y;
				};
				float values[2];
			};

			/// --- CONSTRUCTOR/DESTRUCTOR ---
			vec2();
			vec2(const float& x = 0, const float& y = 0);

			/// --- MEMBER FUNCTIONS ---
			vec2& Add(const vec2& rhs);
			vec2& Sub(const vec2& rhs);
			vec2& Multiply(const vec2& rhs);
			vec2& Divide(const vec2& rhs);

			/// --- OPERATORS --- 
			vec2& operator+=(const vec2& rhs);
			vec2& operator-=(const vec2& rhs);
			vec2& operator*=(const vec2& rhs);
			vec2& operator/=(const vec2& rhs);

			bool operator==(const vec2& rhs);
			bool operator!=(const vec2& rhs);

			/// --- FRIEND METHODS/OPERATORS ---
			friend vec2& operator+(vec2 lhs, const vec2& rhs);
			friend vec2& operator-(vec2 lhs, const vec2& rhs);
			friend vec2& operator*(vec2 lhs, const vec2& rhs);
			friend vec2& operator/(vec2 lhs, const vec2& rhs);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& rhs);
		};
	} // namespace math
} // namespace mge