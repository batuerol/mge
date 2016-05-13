#include "vec3.h"

namespace mge
{
	namespace math
	{
		vec3::vec3(const float & x, const float & y, const float & z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::Add(const vec3 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		vec3& vec3::Sub(const vec3& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		vec3 & vec3::Multiply(const vec3 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		vec3 & vec3::Divide(const vec3 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		vec3 & vec3::Add(float k)
		{
			x += k;
			y += k;
			z += k;
			return *this;
		}

		vec3 & vec3::Sub(float k)
		{
			return Add(-k);
		}

		vec3 & vec3::Multiply(float k)
		{
			x *= k;
			y *= k;
			z *= k;
			return *this;
		}

		vec3 & vec3::Divide(float k)
		{
			// TODO(batuhan): Handle divide by 0?
			return Multiply(1.0f / k);
		}

		vec3 vec3::operator+(const vec3 & v)
		{
			return v;
		}

		vec3 vec3::operator-(const vec3 & v)
		{
			return vec3(-v.x, -v.y, -v.z);
		}

		vec3 & vec3::operator+=(const vec3 & rhs)
		{
			return Add(rhs);
		}

		vec3 & vec3::operator-=(const vec3 & rhs)
		{
			return Sub(rhs);
		}

		vec3 & vec3::operator*=(const vec3 & rhs)
		{
			return Multiply(rhs);
		}

		vec3 & vec3::operator/=(const vec3 & rhs)
		{
			return Divide(rhs);
		}

		vec3 & vec3::operator+=(float k)
		{
			return Add(k);
		}

		vec3 & vec3::operator-=(float k)
		{
			return Sub(k);
		}

		vec3 & vec3::operator*=(float k)
		{
			return Multiply(k);
		}

		vec3 & vec3::operator/=(float k)
		{
			return Divide(k);
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
			return lhs.Add(rhs);
		}

		vec3 & operator-(vec3 lhs, const vec3 & rhs)
		{
			return lhs.Sub(rhs);
		}

		vec3 & operator*(vec3 lhs, const vec3 & rhs)
		{
			return lhs.Multiply(rhs);
		}

		vec3 & operator/(vec3 lhs, const vec3 & rhs)
		{
			return lhs.Divide(rhs);
		}

		vec3 & operator+(vec3 lhs, float k)
		{
			return lhs.Add(k);
		}

		vec3 & operator-(vec3 lhs, float k)
		{
			return lhs.Sub(k);
		}

		vec3 & operator*(vec3 lhs, float k)
		{
			return lhs.Multiply(k);
		}

		vec3 & operator/(vec3 lhs, float k)
		{
			return lhs.Divide(k);
		}

		std::ostream & operator<<(std::ostream & stream, const vec3 & rhs)
		{
			stream << "vec3:(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
