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
			vec3(const vec3& v) = default;

			vec3();
			explicit vec3(float scalar);
			explicit vec3(const float& x, const float& y, const float& z);

			/// --- MEMBER FUNCTIONS ---

			/// --- OPERATORS ---
			vec3& operator=(const vec3& v);

			float& operator[](unsigned int i);
			float& const operator[](unsigned int i) const;

			vec3& operator+=(float k);
			vec3& operator+=(const vec3& rhs);

			vec3& operator-=(float k);
			vec3& operator-=(const vec3& rhs);

			vec3& operator*=(float k);
			vec3& operator*=(const vec3& rhs);

			vec3& operator/=(float k);
			vec3& operator/=(const vec3& rhs);

			vec3& operator++();
			vec3& operator--();

			vec3 operator++(int);
			vec3 operator--(int);
		};

		/// --- Unary operators ---
		static vec3 operator+(const vec3& v);
		static vec3 operator-(const vec3& v);

		/// --- Binary operators ---
		static vec3 operator+(const vec3& v, float scalar);
		static vec3 operator+(float scalar, const vec3& v);
		static vec3 operator+(const vec3& lhs, const vec3& rhs);

		static vec3 operator-(const vec3& v, float scalar);
		static vec3 operator-(float scalar, const vec3& v);
		static vec3 operator-(const vec3& lhs, const vec3& rhs);

		static vec3 operator*(const vec3& v, float scalar);
		static vec3 operator*(float scalar, const vec3& v);
		static vec3 operator*(const vec3& lhs, const vec3& rhs);

		static vec3 operator/(const vec3& v, float scalar);
		static vec3 operator/(float scalar, const vec3& v);
		static vec3 operator/(const vec3& lhs, const vec3& rhs);

		static bool operator==(const vec3& lhs, const vec3& rhs);
		static bool operator!=(const vec3& lhs, const vec3& rhs);
	} // namespace math
} // namespace mge

#include "vec3.inl"