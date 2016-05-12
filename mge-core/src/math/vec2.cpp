#include "vec2.h"

namespace mge
{
	namespace math
	{
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

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

		bool vec2::operator==(const vec2 & rhs)
		{
			return ((x == rhs.x) && (y == rhs.y));
		}

		bool vec2::operator!=(const vec2 & rhs)
		{
			return !(*this == rhs);
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

		std::ostream & operator<<(std::ostream & stream, const vec2 & rhs)
		{
			stream << "vec2:(" << rhs.x << ", " << rhs.y << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
