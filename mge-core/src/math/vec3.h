#pragma once

#include <iostream>

namespace mge
{
	namespace math
	{
		struct vec3
		{
			union {
				struct
				{
					float x, y, z;
				};
				struct
				{
					float r, g, b;
				};
				float values[3];
			};

			/// --- CONSTRUCTOR/DESTRUCTOR ---
			vec3();
			vec3(const float& x = 0, const float& y = 0, const float& z = 0);

			/// --- MEMBER FUNCTIONS ---
			vec3& Add(const vec3& rhs);
			vec3& Sub(const vec3& rhs);
			vec3& Multiply(const vec3& rhs);
			vec3& Divide(const vec3& rhs);

			/// --- OPERATORS --- 
			vec3& operator+=(const vec3& rhs);
			vec3& operator-=(const vec3& rhs);
			vec3& operator*=(const vec3& rhs);
			vec3& operator/=(const vec3& rhs);

			bool operator==(const vec3& rhs);
			bool operator!=(const vec3& rhs);

			/// --- FRIEND METHODS/OPERATORS ---
			friend vec3& operator+(vec3 lhs, const vec3& rhs);
			friend vec3& operator-(vec3 lhs, const vec3& rhs);
			friend vec3& operator*(vec3 lhs, const vec3& rhs);
			friend vec3& operator/(vec3 lhs, const vec3& rhs);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& rhs);
		};
	} // namespace math
} // namespace mge