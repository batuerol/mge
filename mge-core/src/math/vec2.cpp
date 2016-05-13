#include "vec2.h"

namespace mge
{
	namespace math
	{
		vec2::vec2(const float & x, const float & y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::Add(const vec2 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		vec2& vec2::Sub(const vec2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		vec2 & vec2::Multiply(const vec2 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		vec2 & vec2::Divide(const vec2 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		vec2 & vec2::Add(float k)
		{
			x += k;
			y += k;
			return *this;
		}

		vec2 & vec2::Sub(float k)
		{
			return Add(-k);
		}

		vec2 & vec2::Multiply(float k)
		{
			x *= k;
			y *= k;
			return *this;
		}

		vec2 & vec2::Divide(float k)
		{
			// TODO(batuhan): Handle divide by 0?
			return Multiply(1.0f / k);
		}

		vec2 & vec2::operator+=(const vec2 & rhs)
		{
			return Add(rhs);
		}

		vec2 & vec2::operator-=(const vec2 & rhs)
		{
			return Sub(rhs);
		}

		vec2 & vec2::operator*=(const vec2 & rhs)
		{
			return Multiply(rhs);
		}

		vec2 & vec2::operator/=(const vec2 & rhs)
		{
			return Divide(rhs);
		}

		vec2 & vec2::operator+=(float k)
		{
			return Add(k);
		}

		vec2 & vec2::operator-=(float k)
		{
			return Sub(k);
		}

		vec2 & vec2::operator*=(float k)
		{
			return Multiply(k);
		}

		vec2 & vec2::operator/=(float k)
		{
			return Divide(k);
		}

		bool vec2::operator==(const vec2 & rhs)
		{
			return ((x == rhs.x) && (y == rhs.y));
		}

		bool vec2::operator!=(const vec2 & rhs)
		{
			return !(*this == rhs);
		}

		vec2 vec2::operator+(const vec2 & v)
		{
			return v;
		}

		vec2 vec2::operator-(const vec2 & v)
		{			
			return vec2(-v.x, -v.y);
		}

		vec2 & operator+(vec2 lhs, const vec2 & rhs)
		{
			return lhs.Add(rhs);
		}

		vec2 & operator-(vec2 lhs, const vec2 & rhs)
		{
			return lhs.Sub(rhs);
		}

		vec2 & operator*(vec2 lhs, const vec2 & rhs)
		{
			return lhs.Multiply(rhs);
		}

		vec2 & operator/(vec2 lhs, const vec2 & rhs)
		{
			return lhs.Divide(rhs);
		}

		vec2 & operator+(vec2 lhs, float k)
		{
			return lhs.Add(k);
		}

		vec2 & operator-(vec2 lhs, float k)
		{
			return lhs.Sub(k);
		}

		vec2 & operator*(vec2 lhs, float k)
		{
			return lhs.Multiply(k);
		}

		vec2 & operator/(vec2 lhs, float k)
		{
			return lhs.Divide(k);
		}

		std::ostream & operator<<(std::ostream & stream, const vec2 & rhs)
		{
			stream << "vec2:(" << rhs.x << ", " << rhs.y << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
