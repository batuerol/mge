#pragma once

namespace mge
{
	namespace math
	{
		// NOTE(batuhan): Column major order matrix. [column * 4 + row]		
		struct mat4
		{
			union 
			{				
				float elements[4 * 4];
				vec4 columns[4];
			};
			
			/// --- CONSTRUCTOR/DESTRUCTOR ---
			mat4();
			mat4(float diagonal);
			mat4(float *elements);			
			mat4(const vec4& col0, const vec4& col1, const vec4& col2, const vec4& col3);
			mat4(const mat4& rhs) = default;

			/// --- MEMBER FUNCTIONS ---			
			void SetRow(int i, vec4 row);

			/// --- OPERATORS ---
			vec4& operator[](unsigned int i);
			vec4& const operator[](unsigned int i) const;

			mat4& operator=(const mat4& rhs);
			
			mat4& operator+=(float k);
			mat4& operator+=(const mat4& rhs);

			mat4& operator-=(float k);
			mat4& operator-=(const mat4& rhs);

			mat4& operator*=(float k);
			mat4& operator*=(const mat4& rhs);

			mat4& operator/=(float k);
			mat4& operator/=(const mat4& rhs);

			mat4& operator++();
			mat4& operator--();
			mat4 operator++(int);
			mat4 operator--(int);
			
			/// --- STATIC FUNCTIONS --- 
			static mat4 Identity();
			static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 Perspective(float fov, float aspectRatio, float near, float far);
			static mat4 LookAt(const vec3& eye, const vec3& center, const vec3& up);

			// TODO(batuhan): Rotation with quaternions.			
			static mat4 Translate(const vec3& translation);
			static mat4 Rotate(float angle, const vec3& axis);
			static mat4 Scale(const vec3& scale);

			static mat4 Inverse(const mat4& matrix);
			static mat4 Transpose(const mat4& matrix);

			/// --- FRIEND FUNCTIONS/OPERATORS ---
		};

		static mat4 operator+(const mat4& rhs);
		static mat4 operator-(const mat4& rhs);

		static mat4 operator+(const mat4& lhs, float k);
		static mat4 operator+(float k, const mat4& rhs);
		static mat4 operator+(const mat4& lhs, const mat4& rhs);

		static mat4 operator-(const mat4& lhs, float k);
		static mat4 operator-(float k, const mat4& rhs);
		static mat4 operator-(const mat4& lhs, const mat4& rhs);

		static mat4 operator*(const mat4& lhs, float k);
		static mat4 operator*(float k, const mat4& rhs);
		static mat4 operator*(const mat4& lhs, const mat4& rhs);
		static vec4 operator*(const mat4& lhs, const vec4& rhs);
		static vec4 operator*(const vec4& lhs, const mat4& rhs);

		static mat4 operator/(const mat4& lhs, float k);
		static mat4 operator/(float k, const mat4& rhs);
		static mat4 operator/(const mat4& lhs, const mat4& rhs);

		static bool operator==(const mat4& lhs, const mat4& rhs);
		static bool operator!=(const mat4& lhs, const mat4& rhs);
	} // namespace math
} // namespace mge

#include "mat4.inl"