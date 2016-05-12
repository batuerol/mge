#pragma once

#include <iostream>

namespace mge
{
	namespace math
	{
		struct vec4
		{
			union
			{
				struct
				{
					float x, y, z, w;
				};
				struct
				{
					float r, g, b, a;
				};
				float values[4];
			};

			/// --- CONSTRUCTOR/DESTRUCTOR ---
			vec4();
			vec4(const float& x = 0, const float& y = 0, const float& z = 0, const float& w = 0);

			/// --- MEMBER FUNCTIONS ---
			vec4& Add(const vec4& rhs);
			vec4& Sub(const vec4& rhs);
			vec4& Multiply(const vec4& rhs);
			vec4& Divide(const vec4& rhs);

			/// --- OPERATORS ---
			vec4& operator+=(const vec4& rhs);
			vec4& operator-=(const vec4& rhs);
			vec4& operator*=(const vec4& rhs);
			vec4& operator/=(const vec4& rhs);

			bool operator==(const vec4& rhs);
			bool operator!=(const vec4& rhs);

			/// --- FRIEND FUNCTIONS/OPERATORS ---
			friend vec4& operator+(vec4 lhs, const vec4& rhs);
			friend vec4& operator-(vec4 lhs, const vec4& rhs);
			friend vec4& operator*(vec4 lhs, const vec4& rhs);
			friend vec4& operator/(vec4 lhs, const vec4& rhs);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& rhs);
		};
	} // namespace math
} // namespace mge