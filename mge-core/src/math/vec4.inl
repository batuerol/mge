namespace mge
{
	namespace math
	{
		inline vec4::vec4() :
			x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
		}

		inline vec4::vec4(float scalar) :
			x(scalar), y(scalar), z(scalar), w(scalar)
		{
		}

		inline vec4::vec4(const float & x, const float & y, const float & z, const float & w) :
			x(x), y(y), z(z), w(w)
		{
		}

		inline void vec4::Normalize()
		{
			vec4 normalized = vec4::Normalize(*this);
			this->x = normalized.x;
			this->y = normalized.y;
			this->z = normalized.z;
			this->w = normalized.w;
		}

		inline vec4 vec4::Normalized()
		{
			return vec4::Normalize(*this);
		}

		inline float vec4::Magnitude()
		{
			return vec4::Magnitude(*this);
		}

		inline float vec4::SqrMagnitude()
		{
			return vec4::SqrMagnitude(*this);
		}

		inline vec4 vec4::Normalize(const vec4 & v)
		{
			return v / vec4::Magnitude(v);
		}

		inline float vec4::Magnitude(const vec4 & v)
		{
			return std::sqrtf(vec4::Dot(v, v));
		}

		inline float vec4::SqrMagnitude(const vec4 & v)
		{
			return vec4::Dot(v, v);
		}

		inline float vec4::Dot(const vec4 & lhs, const vec4 & rhs)
		{
			vec4 temp(lhs * rhs);
			return temp.x + temp.y + temp.z + temp.w;
		}

		inline vec4 & vec4::operator=(const vec4 & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *this;
		}

		inline float & vec4::operator[](unsigned int i)
		{
			// TODO(batuhan): Implement ArrayCount.
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline float & const vec4::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline vec4 & vec4::operator+=(float k)
		{
			x += k;
			y += k;
			z += k;
			w += k;
			return *this;
		}

		inline vec4 & vec4::operator+=(const vec4 & rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			this->w += rhs.w;
			return *this;
		}

		inline vec4 & vec4::operator-=(float k)
		{
			this->x -= k;
			this->y -= k;
			this->z -= k;
			this->w -= k;
			return *this;
		}

		inline vec4 & vec4::operator-=(const vec4 & rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			this->w -= rhs.w;
			return *this;
		}

		inline vec4 & vec4::operator*=(float k)
		{
			this->x *= k;
			this->y *= k;
			this->z *= k;
			this->w *= k;
			return *this;
		}

		inline vec4 & vec4::operator*=(const vec4 & rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			this->z *= rhs.z;
			this->w *= rhs.w;
			return *this;
		}

		inline vec4 & vec4::operator/=(float k)
		{
			this->x /= k;
			this->y /= k;
			this->z /= k;
			this->w /= k;
			return *this;
		}

		inline vec4 & vec4::operator/=(const vec4 & rhs)
		{
			this->x /= rhs.x;
			this->y /= rhs.y;
			this->z /= rhs.z;
			this->w /= rhs.w;
			return *this;
		}

		inline vec4 & vec4::operator++()
		{
			++this->x;
			++this->y;
			++this->z;
			++this->w;
			return *this;
		}

		inline vec4 & vec4::operator--()
		{
			--this->x;
			--this->y;
			--this->z;
			--this->w;
			return *this;
		}

		inline vec4 vec4::operator++(int)
		{
			vec4 result(*this);
			++*this;
			return result;
		}

		inline vec4 vec4::operator--(int)
		{
			vec4 result(*this);
			--*this;
			return result;
		}

		static vec4 operator+(const vec4 & v)
		{
			return v;
		}

		static vec4 operator-(const vec4 & v)
		{
			return vec4(-v.x, -v.y, -v.z, -v.w);
		}

		static vec4 operator+(const vec4 & v, float scalar)
		{
			return vec4(v.x + scalar, v.y + scalar, v.z + scalar, v.w + scalar);
		}

		static vec4 operator+(float scalar, const vec4 & v)
		{
			return (v + scalar);
		}

		static vec4 operator+(const vec4 & lhs, const vec4 & rhs)
		{
			return vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
		}

		static vec4 operator-(const vec4 & v, float scalar)
		{
			return vec4(v.x - scalar, v.y - scalar, v.z - scalar, v.w - scalar);
		}

		static vec4 operator-(float scalar, const vec4 & v)
		{
			return vec4(scalar - v.x, scalar - v.y, scalar - v.z, scalar - v.w);
		}

		static vec4 operator-(const vec4 & lhs, const vec4 & rhs)
		{
			return vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
		}

		static vec4 operator*(const vec4 & v, float scalar)
		{
			return vec4(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
		}

		static vec4 operator*(float scalar, const vec4 & v)
		{
			return (v * scalar);
		}

		static vec4 operator*(const vec4 & lhs, const vec4 & rhs)
		{
			return vec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
		}

		static vec4 operator/(const vec4 & v, float scalar)
		{
			return vec4(v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar);
		}

		static vec4 operator/(float scalar, const vec4 & v)
		{
			return vec4(scalar / v.x, scalar / v.y, scalar / v.z, scalar / v.w);
		}

		static vec4 operator/(const vec4 & lhs, const vec4 & rhs)
		{
			return vec4(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
		}

		static bool operator==(const vec4 & lhs, const vec4 & rhs)
		{
			return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w));
		}

		static bool operator!=(const vec4 & lhs, const vec4 & rhs)
		{
			return !(lhs == rhs);
		}
	}
}