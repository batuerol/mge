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
			vec2(const vec2& v) = default;

			vec2();
			explicit vec2(float scalar);
			explicit vec2(const float& x, const float& y);

			/// --- MEMBER FUNCTIONS ---

			/// --- OPERATORS ---
			vec2& operator=(const vec2& v);

			float& operator[](unsigned int i);
			float& const operator[](unsigned int i) const;

			vec2& operator+=(float k);
			vec2& operator+=(const vec2& rhs);

			vec2& operator-=(float k);
			vec2& operator-=(const vec2& rhs);

			vec2& operator*=(float k);
			vec2& operator*=(const vec2& rhs);

			vec2& operator/=(float k);
			vec2& operator/=(const vec2& rhs);

			vec2& operator++();
			vec2& operator--();

			vec2 operator++(int);
			vec2 operator--(int);
		};

		/// --- Unary operators ---
		static vec2 operator+(const vec2& v);
		static vec2 operator-(const vec2& v);

		/// --- Binary operators ---
		static vec2 operator+(const vec2& v, float scalar);
		static vec2 operator+(float scalar, const vec2& v);
		static vec2 operator+(const vec2& lhs, const vec2& rhs);

		static vec2 operator-(const vec2& v, float scalar);
		static vec2 operator-(float scalar, const vec2& v);
		static vec2 operator-(const vec2& lhs, const vec2& rhs);

		static vec2 operator*(const vec2& v, float scalar);
		static vec2 operator*(float scalar, const vec2& v);
		static vec2 operator*(const vec2& lhs, const vec2& rhs);

		static vec2 operator/(const vec2& v, float scalar);
		static vec2 operator/(float scalar, const vec2& v);
		static vec2 operator/(const vec2& lhs, const vec2& rhs);

		static bool operator==(const vec2& lhs, const vec2& rhs);
		static bool operator!=(const vec2& lhs, const vec2& rhs);
	} // namespace math
} // namespace mge

#include "vec2.inl"