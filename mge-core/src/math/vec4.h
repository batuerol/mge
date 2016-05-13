#pragma once

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
			vec4(const vec4& v) = default;

			vec4();
			explicit vec4(float scalar);
			explicit vec4(const float& x, const float& y, const float& z, const float& w);	

			/// --- MEMBER FUNCTIONS ---

			/// --- OPERATORS ---
			vec4& operator=(const vec4& v);

			float& operator[](unsigned int i);
			float& const operator[](unsigned int i) const;

			vec4& operator+=(float k);
			vec4& operator+=(const vec4& rhs);

			vec4& operator-=(float k);
			vec4& operator-=(const vec4& rhs);

			vec4& operator*=(float k);
			vec4& operator*=(const vec4& rhs);

			vec4& operator/=(float k);
			vec4& operator/=(const vec4& rhs);

			vec4& operator++();
			vec4& operator--();

			vec4 operator++(int);
			vec4 operator--(int);
			//friend std::ostream& operator<<(std::ostream& stream, const vec4& rhs);
		};

		/// --- Unary operators ---
		static vec4 operator+(const vec4& v);
		static vec4 operator-(const vec4& v);

		/// --- Binary operators ---
		static vec4 operator+(const vec4& v, float scalar);
		static vec4 operator+(float scalar, const vec4& v);
		static vec4 operator+(const vec4& lhs, const vec4& rhs);

		static vec4 operator-(const vec4& v, float scalar);
		static vec4 operator-(float scalar, const vec4& v);
		static vec4 operator-(const vec4& lhs, const vec4& rhs);

		static vec4 operator*(const vec4& v, float scalar);
		static vec4 operator*(float scalar, const vec4& v);
		static vec4 operator*(const vec4& lhs, const vec4& rhs);

		static vec4 operator/(const vec4& v, float scalar);
		static vec4 operator/(float scalar, const vec4& v);
		static vec4 operator/(const vec4& lhs, const vec4& rhs);
		
		static bool operator==(const vec4& lhs, const vec4& rhs);
		static bool operator!=(const vec4& lhs, const vec4& rhs);
	} // namespace math
} // namespace mge

#include "vec4.inl"