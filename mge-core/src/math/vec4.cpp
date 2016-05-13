#include "vec4.h"

namespace mge
{
	namespace math
	{		
		vec4::vec4(const float & x, const float & y, const float & z, const float & w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::Add(const vec4 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		vec4& vec4::Sub(const vec4& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		vec4 & vec4::Multiply(const vec4 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		vec4 & vec4::Divide(const vec4 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		vec4 & vec4::Add(float k)
		{
			x += k;
			y -= k;
			z -= k;
			w -= k;
			return *this;
		}

		vec4 & vec4::Sub(float k)
		{
			return Add(-k);
		}

		vec4 & vec4::Multiply(float k)
		{
			x *= k;
			y *= k;
			z *= k;
			w *= k;
			return *this;
		}

		vec4 & vec4::Divide(float k)
		{
			// TODO(batuhan): Handle divide by 0?
			return Multiply(1.0f / k);
		}

		float & vec4::operator[](unsigned int i)
		{
			// TODO(batuhan): Implement ArrayCount.
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		float & const vec4::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		vec4 vec4::operator+(const vec4 & v)
		{
			return v;
		}

		vec4 vec4::operator-(const vec4 & v)
		{
			return vec4(-v.x, -v.y, -v.z, -v.w);
		}

		vec4 & vec4::operator+=(const vec4 & rhs)
		{
			return Add(rhs);
		}

		vec4 & vec4::operator-=(const vec4 & rhs)
		{
			return Sub(rhs);
		}

		vec4 & vec4::operator*=(const vec4 & rhs)
		{
			return Multiply(rhs);
		}

		vec4 & vec4::operator/=(const vec4 & rhs)
		{
			return Divide(rhs);
		}

		vec4 & vec4::operator+=(float k)
		{
			return Add(k);
		}

		vec4 & vec4::operator-=(float k)
		{
			return Sub(k);
		}

		vec4 & vec4::operator*=(float k)
		{
			return Multiply(k);
		}

		vec4 & vec4::operator/=(float k)
		{
			return Divide(k);
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
			return lhs.Add(rhs);
		}

		vec4 & operator-(vec4 lhs, const vec4 & rhs)
		{
			return lhs.Sub(rhs);
		}

		vec4 & operator*(vec4 lhs, const vec4 & rhs)
		{
			return lhs.Multiply(rhs);
		}

		vec4 & operator/(vec4 lhs, const vec4 & rhs)
		{
			return lhs.Divide(rhs);
		}

		vec4 & operator+(vec4 lhs, float k)
		{
			return lhs.Add(k);
		}

		vec4 & operator-(vec4 lhs, float k)
		{
			return lhs.Sub(k);
		}

		vec4 & operator*(vec4 lhs, float k)
		{
			return lhs.Multiply(k);
		}

		vec4 & operator/(vec4 lhs, float k)
		{
			return lhs.Divide(k);
		}

		std::ostream & operator<<(std::ostream & stream, const vec4 & rhs)
		{
			stream << "vec4:(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.w << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
