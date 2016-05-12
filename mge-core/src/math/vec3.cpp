#include "vec3.h"

namespace mge
{
	namespace math
	{
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float & x, const float & y, const float & z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		vec3& vec3::sub(const vec3& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		vec3 & vec3::multiply(const vec3 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		vec3 & vec3::divide(const vec3 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}		

		vec3 & vec3::operator+=(const vec3 & rhs)
		{
			return add(rhs);
		}

		vec3 & vec3::operator-=(const vec3 & rhs)
		{
			return sub(rhs);
		}

		vec3 & vec3::operator*=(const vec3 & rhs)
		{
			return multiply(rhs);
		}

		vec3 & vec3::operator/=(const vec3 & rhs)
		{
			return divide(rhs);
		}

		bool vec3::operator==(const vec3 & rhs)
		{
			return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
		}

		bool vec3::operator!=(const vec3 & rhs)
		{
			return !(*this == rhs);
		}

		vec3 & operator+(vec3 lhs, const vec3 & rhs)
		{
			return lhs.add(rhs);
		}

		vec3 & operator-(vec3 lhs, const vec3 & rhs)
		{
			return lhs.sub(rhs);
		}

		vec3 & operator*(vec3 lhs, const vec3 & rhs)
		{
			return lhs.multiply(rhs);
		}

		vec3 & operator/(vec3 lhs, const vec3 & rhs)
		{
			return lhs.divide(rhs);
		}

		std::ostream & operator<<(std::ostream & stream, const vec3 & rhs)
		{
			stream << "vec3:(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
