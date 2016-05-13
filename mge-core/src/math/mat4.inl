#include "mat4.h"
namespace mge
{
	namespace math
	{
		mat4::mat4()
		{
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

		mat4 & mat4::Multiply(const mat4 & rhs)
		{

			return mat4(1);
		}

		vec4 & mat4::operator[](unsigned int i)
		{
			// TODO(batuhan): Assert. Boundry check.
			return (vec4&)columns[i];
		}

		vec4 & const mat4::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Boundry check.
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
			// TODO: insert return statement here
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
			// TODO(batuhan): Implement inverse computation for mat4.
			// return inverse(lhs) * rhs;
			return mat4();
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