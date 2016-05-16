#include "mat4.h"
namespace mge
{
	namespace math
	{
		mat4::mat4()
		{
			for (int i = 0; i < 16; ++i)
			{
				elements[i] = 0;
			}
		}

		inline mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 16; ++i)
			{
				elements[i] = 0;
			}

			elements[0 * 4 + 0] = diagonal;
			elements[1 * 4 + 1] = diagonal;
			elements[2 * 4 + 2] = diagonal;
			elements[3 * 4 + 3] = diagonal;
		}

		inline mat4::mat4(float * elements)
		{
			for (int i = 0; i < 4 * 4; ++i)
			{
				this->elements[i] = elements[i];
			}
		}

		inline mat4::mat4(const vec4 & col0, const vec4 & col1, const vec4 & col2, const vec4 & col3)
		{
			this->columns[0] = col0;
			this->columns[1] = col1;
			this->columns[2] = col2;
			this->columns[3] = col3;
		}

		inline void mat4::SetRow(int i, vec4 row)
		{
			// TODO(batuhan): Boundary check.
			this->elements[0 * 4 + i] = row.x;
			this->elements[1 * 4 + i] = row.y;
			this->elements[2 * 4 + i] = row.z;
			this->elements[3 * 4 + i] = row.w;
		}

		vec4 & mat4::operator[](unsigned int i)
		{
			// TODO(batuhan): Assert. Boundary check.
			//return const_cast<vec4&>(static_cast<const mat4&>(*this)[i]);
			return (vec4&)columns[i];
		}

		vec4 & const mat4::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Boundary check.
			return (vec4&)columns[i];
		}

		inline mat4 & mat4::operator=(const mat4 & rhs)
		{
			//memcpy(&this->columns, &rhs.columns, 16 * sizeof(float));
			this->columns[0] = rhs.columns[0];
			this->columns[1] = rhs.columns[1];
			this->columns[2] = rhs.columns[2];
			this->columns[3] = rhs.columns[3];
		}

		inline mat4 & mat4::operator+=(float k)
		{
			this->columns[0] += k;
			this->columns[1] += k;
			this->columns[2] += k;
			this->columns[3] += k;
			return *this;
		}

		inline mat4 & mat4::operator+=(const mat4 & rhs)
		{
			this->columns[0] += rhs.columns[0];
			this->columns[1] += rhs.columns[1];
			this->columns[2] += rhs.columns[2];
			this->columns[3] += rhs.columns[3];
			return *this;
		}

		inline mat4 & mat4::operator-=(float k)
		{
			this->columns[0] -= k;
			this->columns[1] -= k;
			this->columns[2] -= k;
			this->columns[3] -= k;
			return *this;
		}

		inline mat4 & mat4::operator-=(const mat4 & rhs)
		{
			this->columns[0] -= rhs.columns[0];
			this->columns[1] -= rhs.columns[1];
			this->columns[2] -= rhs.columns[2];
			this->columns[3] -= rhs.columns[3];
			return *this;
		}

		inline mat4 & mat4::operator*=(float k)
		{
			this->columns[0] *= k;
			this->columns[1] *= k;
			this->columns[2] *= k;
			this->columns[3] *= k;
			return *this;
		}

		inline mat4 & mat4::operator*=(const mat4 & rhs)
		{
			this->columns[0] *= rhs.columns[0];
			this->columns[1] *= rhs.columns[1];
			this->columns[2] *= rhs.columns[2];
			this->columns[3] *= rhs.columns[3];
			return *this;
		}

		inline mat4 & mat4::operator/=(float k)
		{
			this->columns[0] /= k;
			this->columns[1] /= k;
			this->columns[2] /= k;
			this->columns[3] /= k;
			return *this;
		}

		inline mat4 & mat4::operator/=(const mat4 & rhs)
		{
			this->columns[0] /= rhs.columns[0];
			this->columns[1] /= rhs.columns[1];
			this->columns[2] /= rhs.columns[2];
			this->columns[3] /= rhs.columns[3];
			return *this;
		}

		inline mat4 & mat4::operator++()
		{
			++this->columns[0];
			++this->columns[1];
			++this->columns[2];
			++this->columns[3];
			return *this;
		}

		inline mat4 & mat4::operator--()
		{
			--this->columns[0];
			--this->columns[1];
			--this->columns[2];
			--this->columns[3];
			return *this;
		}

		inline mat4 mat4::operator++(int)
		{
			mat4 result(*this);
			++*this;
			return result;
		}

		inline mat4 mat4::operator--(int)
		{
			mat4 result(*this);
			--*this;
			return result;
		}

		mat4 mat4::Identity()
		{
			return mat4(1.0f);
		}

		inline mat4 mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);
			result.elements[0 * 4 + 0] = 2.0f / (right - left);
			result.elements[1 * 4 + 1] = 2.0f / (top - bottom);
			result.elements[2 * 4 + 2] = -2.0f / (far - near);
			result.elements[3 * 4 + 0] = -(right + left) / (right - left);
			result.elements[3 * 4 + 1] = -(top + bottom) / (top - bottom);
			result.elements[3 * 4 + 2] = -(far + near) / (far - near);

			return result;
		}

		inline mat4 mat4::Perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(0.0f);
			// TODO(batuhan): Use math_func.hpp tan
			const float tanHalfFov = std::tanf(fov / 2.0f);
			result.elements[0 * 4 + 0] = 1.0f / (aspectRatio * tanHalfFov);
			result.elements[1 * 4 + 1] = 1.0f / (tanHalfFov);
			result.elements[2 * 4 + 2] = -(far + near) / (far - near);
			result.elements[2 * 4 + 3] = -1.0f;
			result.elements[3 * 4 + 2] = -(2.0f * far * near) / (far - near);

			return result;
		}

		inline mat4 mat4::LookAt(const vec3 & eye, const vec3 & center, const vec3 & up)
		{
			// NOTE(batuhan): http://www.cs.virginia.edu/~gfx/Courses/1999/intro.fall99.html/lookat.html
			const vec3 f(vec3::Normalize(center - eye));
			const vec3 s(vec3::Normalize(vec3::Cross(f, up)));
			const vec3 u(vec3::Cross(s, f));
			mat4 result(1.0f);
			result.elements[0 * 4 + 0] = s.x;
			result.elements[1 * 4 + 0] = s.y;
			result.elements[2 * 4 + 0] = s.z;
			result.elements[0 * 4 + 1] = u.x;
			result.elements[1 * 4 + 1] = u.y;
			result.elements[2 * 4 + 1] = u.z;
			result.elements[0 * 4 + 2] = -f.x;
			result.elements[1 * 4 + 2] = -f.y;
			result.elements[2 * 4 + 2] = -f.z;
			result.elements[3 * 4 + 0] = -vec3::Dot(s, eye);
			result.elements[3 * 4 + 1] = -vec3::Dot(u, eye);
			result.elements[3 * 4 + 2] = vec3::Dot(f, eye);

			return result;
		}

		inline mat4 mat4::Translate(const vec3 & translation)
		{
			mat4 result(1.0f);
			result.elements[0 + 3 * 4] = translation[0];
			result.elements[1 + 3 * 4] = translation[1];
			result.elements[2 + 3 * 4] = translation[2];

			return result;
		}

		inline mat4 mat4::Rotate(float angle, const vec3 & axis)
		{
			// TODO(batuhan): Change sin/cos to math_func.hpp
			const float a = angle;
			const float c = std::cosf(a);
			const float s = std::sinf(a);

			vec3 normalizedAxis(vec3::Normalize(axis));
			vec3 temp((1.0f - c) * normalizedAxis);
			mat4 result(1.0f);
			result.elements[0 * 4 + 0] = c + temp[0] * normalizedAxis[0];
			result.elements[0 * 4 + 1] = 0 + temp[0] * normalizedAxis[1] + s * normalizedAxis[2];
			result.elements[0 * 4 + 2] = 0 + temp[0] * normalizedAxis[2] - s * normalizedAxis[1];

			result.elements[1 * 4 + 0] = 0 + temp[1] * normalizedAxis[0] - s * normalizedAxis[2];
			result.elements[1 * 4 + 1] = c + temp[1] * normalizedAxis[1];
			result.elements[1 * 4 + 2] = 0 + temp[1] * normalizedAxis[2] + s * normalizedAxis[0];

			result.elements[2 * 4 + 0] = 0 + temp[2] * normalizedAxis[0] + s * normalizedAxis[1];
			result.elements[2 * 4 + 1] = 0 + temp[2] * normalizedAxis[1] - s * normalizedAxis[0];
			result.elements[2 * 4 + 2] = c + temp[2] * normalizedAxis[2];

			return result;
		}

		inline mat4 mat4::Scale(const vec3 & scale)
		{
			mat4 result(1.0f);
			result.elements[0 + 0 * 4] = scale[0];
			result.elements[1 + 1 * 4] = scale[1];
			result.elements[2 + 2 * 4] = scale[2];

			return result;
		}

		inline mat4 mat4::Inverse(const mat4 & matrix)
		{
			float temp[16];

			temp[0] = matrix.elements[5] * matrix.elements[10] * matrix.elements[15] -
				matrix.elements[5] * matrix.elements[11] * matrix.elements[14] -
				matrix.elements[9] * matrix.elements[6] * matrix.elements[15] +
				matrix.elements[9] * matrix.elements[7] * matrix.elements[14] +
				matrix.elements[13] * matrix.elements[6] * matrix.elements[11] -
				matrix.elements[13] * matrix.elements[7] * matrix.elements[10];

			temp[4] = -matrix.elements[4] * matrix.elements[10] * matrix.elements[15] +
				matrix.elements[4] * matrix.elements[11] * matrix.elements[14] +
				matrix.elements[8] * matrix.elements[6] * matrix.elements[15] -
				matrix.elements[8] * matrix.elements[7] * matrix.elements[14] -
				matrix.elements[12] * matrix.elements[6] * matrix.elements[11] +
				matrix.elements[12] * matrix.elements[7] * matrix.elements[10];

			temp[8] = matrix.elements[4] * matrix.elements[9] * matrix.elements[15] -
				matrix.elements[4] * matrix.elements[11] * matrix.elements[13] -
				matrix.elements[8] * matrix.elements[5] * matrix.elements[15] +
				matrix.elements[8] * matrix.elements[7] * matrix.elements[13] +
				matrix.elements[12] * matrix.elements[5] * matrix.elements[11] -
				matrix.elements[12] * matrix.elements[7] * matrix.elements[9];

			temp[12] = -matrix.elements[4] * matrix.elements[9] * matrix.elements[14] +
				matrix.elements[4] * matrix.elements[10] * matrix.elements[13] +
				matrix.elements[8] * matrix.elements[5] * matrix.elements[14] -
				matrix.elements[8] * matrix.elements[6] * matrix.elements[13] -
				matrix.elements[12] * matrix.elements[5] * matrix.elements[10] +
				matrix.elements[12] * matrix.elements[6] * matrix.elements[9];

			temp[1] = -matrix.elements[1] * matrix.elements[10] * matrix.elements[15] +
				matrix.elements[1] * matrix.elements[11] * matrix.elements[14] +
				matrix.elements[9] * matrix.elements[2] * matrix.elements[15] -
				matrix.elements[9] * matrix.elements[3] * matrix.elements[14] -
				matrix.elements[13] * matrix.elements[2] * matrix.elements[11] +
				matrix.elements[13] * matrix.elements[3] * matrix.elements[10];

			temp[5] = matrix.elements[0] * matrix.elements[10] * matrix.elements[15] -
				matrix.elements[0] * matrix.elements[11] * matrix.elements[14] -
				matrix.elements[8] * matrix.elements[2] * matrix.elements[15] +
				matrix.elements[8] * matrix.elements[3] * matrix.elements[14] +
				matrix.elements[12] * matrix.elements[2] * matrix.elements[11] -
				matrix.elements[12] * matrix.elements[3] * matrix.elements[10];

			temp[9] = -matrix.elements[0] * matrix.elements[9] * matrix.elements[15] +
				matrix.elements[0] * matrix.elements[11] * matrix.elements[13] +
				matrix.elements[8] * matrix.elements[1] * matrix.elements[15] -
				matrix.elements[8] * matrix.elements[3] * matrix.elements[13] -
				matrix.elements[12] * matrix.elements[1] * matrix.elements[11] +
				matrix.elements[12] * matrix.elements[3] * matrix.elements[9];

			temp[13] = matrix.elements[0] * matrix.elements[9] * matrix.elements[14] -
				matrix.elements[0] * matrix.elements[10] * matrix.elements[13] -
				matrix.elements[8] * matrix.elements[1] * matrix.elements[14] +
				matrix.elements[8] * matrix.elements[2] * matrix.elements[13] +
				matrix.elements[12] * matrix.elements[1] * matrix.elements[10] -
				matrix.elements[12] * matrix.elements[2] * matrix.elements[9];

			temp[2] = matrix.elements[1] * matrix.elements[6] * matrix.elements[15] -
				matrix.elements[1] * matrix.elements[7] * matrix.elements[14] -
				matrix.elements[5] * matrix.elements[2] * matrix.elements[15] +
				matrix.elements[5] * matrix.elements[3] * matrix.elements[14] +
				matrix.elements[13] * matrix.elements[2] * matrix.elements[7] -
				matrix.elements[13] * matrix.elements[3] * matrix.elements[6];

			temp[6] = -matrix.elements[0] * matrix.elements[6] * matrix.elements[15] +
				matrix.elements[0] * matrix.elements[7] * matrix.elements[14] +
				matrix.elements[4] * matrix.elements[2] * matrix.elements[15] -
				matrix.elements[4] * matrix.elements[3] * matrix.elements[14] -
				matrix.elements[12] * matrix.elements[2] * matrix.elements[7] +
				matrix.elements[12] * matrix.elements[3] * matrix.elements[6];

			temp[10] = matrix.elements[0] * matrix.elements[5] * matrix.elements[15] -
				matrix.elements[0] * matrix.elements[7] * matrix.elements[13] -
				matrix.elements[4] * matrix.elements[1] * matrix.elements[15] +
				matrix.elements[4] * matrix.elements[3] * matrix.elements[13] +
				matrix.elements[12] * matrix.elements[1] * matrix.elements[7] -
				matrix.elements[12] * matrix.elements[3] * matrix.elements[5];

			temp[14] = -matrix.elements[0] * matrix.elements[5] * matrix.elements[14] +
				matrix.elements[0] * matrix.elements[6] * matrix.elements[13] +
				matrix.elements[4] * matrix.elements[1] * matrix.elements[14] -
				matrix.elements[4] * matrix.elements[2] * matrix.elements[13] -
				matrix.elements[12] * matrix.elements[1] * matrix.elements[6] +
				matrix.elements[12] * matrix.elements[2] * matrix.elements[5];

			temp[3] = -matrix.elements[1] * matrix.elements[6] * matrix.elements[11] +
				matrix.elements[1] * matrix.elements[7] * matrix.elements[10] +
				matrix.elements[5] * matrix.elements[2] * matrix.elements[11] -
				matrix.elements[5] * matrix.elements[3] * matrix.elements[10] -
				matrix.elements[9] * matrix.elements[2] * matrix.elements[7] +
				matrix.elements[9] * matrix.elements[3] * matrix.elements[6];

			temp[7] = matrix.elements[0] * matrix.elements[6] * matrix.elements[11] -
				matrix.elements[0] * matrix.elements[7] * matrix.elements[10] -
				matrix.elements[4] * matrix.elements[2] * matrix.elements[11] +
				matrix.elements[4] * matrix.elements[3] * matrix.elements[10] +
				matrix.elements[8] * matrix.elements[2] * matrix.elements[7] -
				matrix.elements[8] * matrix.elements[3] * matrix.elements[6];

			temp[11] = -matrix.elements[0] * matrix.elements[5] * matrix.elements[11] +
				matrix.elements[0] * matrix.elements[7] * matrix.elements[9] +
				matrix.elements[4] * matrix.elements[1] * matrix.elements[11] -
				matrix.elements[4] * matrix.elements[3] * matrix.elements[9] -
				matrix.elements[8] * matrix.elements[1] * matrix.elements[7] +
				matrix.elements[8] * matrix.elements[3] * matrix.elements[5];

			temp[15] = matrix.elements[0] * matrix.elements[5] * matrix.elements[10] -
				matrix.elements[0] * matrix.elements[6] * matrix.elements[9] -
				matrix.elements[4] * matrix.elements[1] * matrix.elements[10] +
				matrix.elements[4] * matrix.elements[2] * matrix.elements[9] +
				matrix.elements[8] * matrix.elements[1] * matrix.elements[6] -
				matrix.elements[8] * matrix.elements[2] * matrix.elements[5];

			float determinant = matrix.elements[0] * temp[0] + matrix.elements[1] * temp[4] + matrix.elements[2] * temp[8] + matrix.elements[3] * temp[12];
			determinant = 1.0f / determinant;

			mat4 result;
			for (int i = 0; i < 4 * 4; i++)
				result.elements[i] = temp[i] * determinant;

			return result;
		}

		inline mat4 mat4::Transpose(const mat4 & matrix)
		{
			mat4 result;
			result.SetRow(0, matrix[0]);
			result.SetRow(1, matrix[1]);
			result.SetRow(2, matrix[2]);
			result.SetRow(3, matrix[3]);

			return result;
		}

		static mat4 operator+(const mat4& rhs)
		{
			return rhs;
		}

		static mat4 operator-(const mat4& rhs)
		{
			return mat4(-rhs[0], -rhs[1], -rhs[2], -rhs[3]);
		}

		static mat4 operator+(const mat4& lhs, float k)
		{
			return mat4(lhs[0] + k, lhs[1] + k, lhs[2] + k, lhs[3] + k);
		}

		static mat4 operator+(float k, const mat4& rhs)
		{
			return (rhs + k);
		}

		static mat4 operator+(const mat4& lhs, const mat4& rhs)
		{
			return mat4(lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3]);
		}

		static mat4 operator-(const mat4& lhs, float k)
		{
			return mat4(lhs[0] - k, lhs[1] - k, lhs[2] - k, lhs[3] - k);
		}

		static mat4 operator-(float k, const mat4& rhs)
		{
			return mat4(k - rhs[0], k - rhs[1], k - rhs[2], k - rhs[3]);
		}

		static mat4 operator-(const mat4& lhs, const mat4& rhs)
		{
			return mat4(lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3]);
		}

		static mat4 operator*(const mat4& lhs, float k)
		{
			return mat4(lhs[0] * k, lhs[1] * k, lhs[2] * k, lhs[3] * k);
		}
		static mat4 operator*(float k, const mat4& rhs)
		{
			return (rhs * k);
		}

		static mat4 operator*(const mat4& lhs, const mat4& rhs)
		{
			const vec4 a0 = lhs[0];
			const vec4 a1 = lhs[1];
			const vec4 a2 = lhs[2];
			const vec4 a3 = lhs[3];

			const vec4 b0 = rhs[0];
			const vec4 b1 = rhs[1];
			const vec4 b2 = rhs[2];
			const vec4 b3 = rhs[3];

			mat4 result;
			result[0] = a0 * b0[0] + a1 * b0[1] + a2 * b0[2] + a3 * b0[3];
			result[1] = a0 * b1[0] + a1 * b1[1] + a2 * b1[2] + a3 * b1[3];
			result[0] = a0 * b2[0] + a1 * b2[1] + a2 * b2[2] + a3 * b2[3];
			result[0] = a0 * b3[0] + a1 * b3[1] + a2 * b3[2] + a3 * b3[3];

			return result;
		}

		static vec4 operator*(const mat4 & lhs, const vec4 & rhs)
		{
			// TODO(batuhan): Compare
			vec4 result = (lhs[0] * rhs[0]) + (lhs[1] * rhs[1]) + (lhs[2] * rhs[2]) + (lhs[3] * rhs[3]);
			return result;

			//return vec4(
			//	lhs[0][0] * rhs[0] + lhs[1][0] * rhs[1] + lhs[2][0] * rhs[2] + lhs[3][0] * rhs[3],
			//	lhs[0][1] * rhs[0] + lhs[1][1] * rhs[1] + lhs[2][1] * rhs[2] + lhs[3][1] * rhs[3],
			//	lhs[0][2] * rhs[0] + lhs[1][2] * rhs[1] + lhs[2][2] * rhs[2] + lhs[3][2] * rhs[3],
			//	lhs[0][3] * rhs[0] + lhs[1][3] * rhs[1] + lhs[2][3] * rhs[2] + lhs[3][3] * rhs[3]);
		}

		static vec4 operator*(const vec4 & lhs, const mat4 & rhs)
		{
			return vec4(
				rhs[0][0] * lhs[0] + rhs[0][1] * lhs[1] + rhs[0][2] * lhs[2] + rhs[0][3] * lhs[3],
				rhs[1][0] * lhs[0] + rhs[1][1] * lhs[1] + rhs[1][2] * lhs[2] + rhs[1][3] * lhs[3],
				rhs[2][0] * lhs[0] + rhs[2][1] * lhs[1] + rhs[2][2] * lhs[2] + rhs[2][3] * lhs[3],
				rhs[3][0] * lhs[0] + rhs[3][1] * lhs[1] + rhs[3][2] * lhs[2] + rhs[3][3] * lhs[3]);
		}

		static mat4 operator/(const mat4& lhs, float k)
		{
			return mat4(lhs[0] / k, lhs[1] / k, lhs[2] / k, lhs[3] / k);
		}

		static mat4 operator/(float k, const mat4& rhs)
		{
			return mat4(k / rhs[0], k / rhs[1], k / rhs[2], k / rhs[3]);
		}

		static mat4 operator/(const mat4& lhs, const mat4& rhs)
		{			
			return mat4::Inverse(lhs) * rhs;			
		}

		static bool operator==(const mat4& lhs, const mat4& rhs)
		{
			return ((lhs[0] == rhs[0]) && (lhs[1] == rhs[1]) && (lhs[2] == rhs[2]) && (lhs[3] == rhs[3]));
		}

		static bool operator!=(const mat4& lhs, const mat4& rhs)
		{
			return !(lhs == rhs);
		}
	} // namespace math
} // namespace mge