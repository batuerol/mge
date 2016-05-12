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

		vec2& vec2::add(const vec2 & rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		vec2& vec2::sub(const vec2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		vec2 & vec2::multiply(const vec2 & rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		vec2 & vec2::divide(const vec2 & rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}		

		vec2 & vec2::operator+=(const vec2 & rhs)
		{
			return add(rhs);
		}

		vec2 & vec2::operator-=(const vec2 & rhs)
		{
			return sub(rhs);
		}

		vec2 & vec2::operator*=(const vec2 & rhs)
		{
			return multiply(rhs);
		}

		vec2 & vec2::operator/=(const vec2 & rhs)
		{
			return divide(rhs);
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
			return lhs.add(rhs);
		}

		vec2 & operator-(vec2 lhs, const vec2 & rhs)
		{
			return lhs.sub(rhs);
		}

		vec2 & operator*(vec2 lhs, const vec2 & rhs)
		{
			return lhs.multiply(rhs);
		}

		vec2 & operator/(vec2 lhs, const vec2 & rhs)
		{
			return lhs.divide(rhs);
		}

		std::ostream & operator<<(std::ostream & stream, const vec2 & rhs)
		{
			stream << "vec2:(" << rhs.x << ", " << rhs.y << ")";
			return stream;
		}

	} // namespace math
} // namespace mge
