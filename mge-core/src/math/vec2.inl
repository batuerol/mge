#include "vec2.h"
namespace mge
{
	namespace math
	{
		inline vec2::vec2(float scalar) :
			x(scalar), y(scalar)
		{
		}

		inline vec2::vec2(const float & x, const float & y) :
			x(x), y(y)
		{
		}

		inline vec2 & vec2::operator=(const vec2 & v)
		{
			this->x = v.x;
			this->y = v.y;
			return *this;
		}

		inline float & vec2::operator[](unsigned int i)
		{
			// TODO(batuhan): Implement ArrayCount.
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline float & const vec2::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline vec2 & vec2::operator+=(float k)
		{
			this->x += k;
			this->y += k;
			return *this;
		}

		inline vec2 & vec2::operator+=(const vec2 & rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		inline vec2 & vec2::operator-=(float k)
		{
			this->x -= k;
			this->y -= k;
			return *this;
		}

		inline vec2 & vec2::operator-=(const vec2 & rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		inline vec2 & vec2::operator*=(float k)
		{
			this->x *= k;
			this->y *= k;
			return *this;
		}

		inline vec2 & vec2::operator*=(const vec2 & rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			return *this;
		}

		inline vec2 & vec2::operator/=(float k)
		{
			this->x /= k;
			this->y /= k;
			return *this;
		}

		inline vec2 & vec2::operator/=(const vec2 & rhs)
		{
			this->x /= rhs.x;
			this->y /= rhs.y;
			return *this;
		}

		inline vec2 & vec2::operator++()
		{
			++this->x;
			++this->y;
			return *this;
		}

		inline vec2 & vec2::operator--()
		{
			--this->x;
			--this->y;
			return *this;
		}

		inline vec2 vec2::operator++(int)
		{
			vec2 result(*this);
			++*this;
			return result;
		}

		inline vec2 vec2::operator--(int)
		{
			vec2 result(*this);
			--*this;
			return result;
		}

		static vec2 operator+(const vec2& v)
		{
			return v;
		}

		static vec2 operator-(const vec2& v)
		{
			return vec2(-v.x, -v.y);
		}

		static vec2 operator+(const vec2 & v, float scalar)
		{
			return vec2(v.x + scalar, v.y + scalar);
		}

		static vec2 operator+(float scalar, const vec2 & v)
		{
			return (v + scalar);
		}

		static vec2 operator+(const vec2 & lhs, const vec2 & rhs)
		{
			return vec2(lhs.x + rhs.x, lhs.y + rhs.y);
		}

		static vec2 operator-(const vec2 & v, float scalar)
		{
			return vec2(v.x - scalar, v.y - scalar);
		}

		static vec2 operator-(float scalar, const vec2 & v)
		{
			return vec2(scalar - v.x, scalar - v.y);
		}

		static vec2 operator-(const vec2 & lhs, const vec2 & rhs)
		{
			return vec2(lhs.x - rhs.x, lhs.y - rhs.y);
		}

		static vec2 operator*(const vec2 & v, float scalar)
		{
			return vec2(v.x * scalar, v.y * scalar);
		}

		static vec2 operator*(float scalar, const vec2 & v)
		{
			return (v * scalar);
		}

		static vec2 operator*(const vec2 & lhs, const vec2 & rhs)
		{
			return vec2(lhs.x * rhs.x, lhs.y * rhs.y);
		}

		static vec2 operator/(const vec2 & v, float scalar)
		{
			return vec2(v.x / scalar, v.y / scalar);
		}

		static vec2 operator/(float scalar, const vec2 & v)
		{
			return vec2(scalar / v.x, scalar / v.y);
		}

		static vec2 operator/(const vec2 & lhs, const vec2 & rhs)
		{
			return vec2(lhs.x / rhs.x, lhs.y / rhs.y);
		}

		static bool operator==(const vec2 & lhs, const vec2 & rhs)
		{
			return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
		}

		static bool operator!=(const vec2 & lhs, const vec2 & rhs)
		{
			return !(lhs == rhs);
		}

	} // namespace math
} // namespace mge
