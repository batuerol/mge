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
			vec4(const float& x = 0, const float& y = 0, const float& z = 0, const float& w = 0);

			/// --- MEMBER FUNCTIONS ---
			vec4& Add(const vec4& rhs);
			vec4& Sub(const vec4& rhs);
			vec4& Multiply(const vec4& rhs);
			vec4& Divide(const vec4& rhs);

			vec4& Add(float k);
			vec4& Sub(float k);
			vec4& Multiply(float k);
			vec4& Divide(float k);

			/// --- OPERATORS ---
			vec4 operator+(const vec4& v);
			vec4 operator-(const vec4& v);

			vec4& operator+=(const vec4& rhs);
			vec4& operator-=(const vec4& rhs);
			vec4& operator*=(const vec4& rhs);
			vec4& operator/=(const vec4& rhs);

			vec4& operator+=(float k);
			vec4& operator-=(float k);
			vec4& operator*=(float k);
			vec4& operator/=(float k);

			bool operator==(const vec4& rhs);
			bool operator!=(const vec4& rhs);

			/// --- FRIEND FUNCTIONS/OPERATORS ---
			friend vec4& operator+(vec4 lhs, const vec4& rhs);
			friend vec4& operator-(vec4 lhs, const vec4& rhs);
			friend vec4& operator*(vec4 lhs, const vec4& rhs);
			friend vec4& operator/(vec4 lhs, const vec4& rhs);

			friend vec4& operator+(vec4 lhs, float k);
			friend vec4& operator-(vec4 lhs, float k);
			friend vec4& operator*(vec4 lhs, float k);
			friend vec4& operator/(vec4 lhs, float k);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& rhs);
		};
	} // namespace math
} // namespace mge