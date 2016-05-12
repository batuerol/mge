#include "vec4.h"

namespace mge
{
	namespace math
	{
		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float & x, const float & y, const float & z, const float & w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		vec4& vec4::sub(const vec4& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		vec4 & vec4::multiply(const vec4 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		vec4 & vec4::divide(const vec4 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		vec4 & vec4::operator+=(const vec4 & rhs)
		{
			return add(rhs);
		}

		vec4 & vec4::operator-=(const vec4 & rhs)
		{
			return sub(rhs);
		}

		vec4 & vec4::operator*=(const vec4 & rhs)
		{
			return multiply(rhs);
		}

		vec4 & vec4::operator/=(const vec4 & rhs)
		{
			return divide(rhs);
		}

		bool vec4::operator==(const vec4 & rhs)
		{
			return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
		}

		bool vec4::operator!=(const vec4 & rhs)
		{
			return !(*this == rhs);
		}

		vec4 & operator+(vec4 lhs, const vec4 & rhs)
		{
			return lhs.add(rhs);
		}

		vec4 & operator-(vec4 lhs, const vec4 & rhs)
		{
			return lhs.sub(rhs);
		}

		vec4 & operator*(vec4 lhs, const vec4 & rhs)
		{
			return lhs.multiply(rhs);
		}

		vec4 & operator/(vec4 lhs, const vec4 & rhs)
		{
			return lhs.divide(rhs);
		}

		std::ostream & operator<<(std::ostream & stream, const vec4 & rhs)
		{
			stream << "vec4:(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.w << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
