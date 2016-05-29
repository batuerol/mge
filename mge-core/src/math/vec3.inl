namespace mge
{
	namespace math
	{
		inline vec3::vec3() :
			x(0.0f), y(0.0f), z(0.0f)
		{
		}

		inline vec3::vec3(float scalar) :
			x(scalar), y(scalar), z(scalar)
		{
		}

		inline vec3::vec3(const float & x, const float & y, const float & z) :
			x(x), y(y), z(z)
		{
		}

		inline void vec3::Normalize()
		{
			vec3 normalized = vec3::Normalize(*this);
			this->x = normalized.x;
			this->y = normalized.y;
			this->z = normalized.z;
		}

		inline vec3 vec3::Normalized()
		{
			return vec3::Normalize(*this);
		}

		inline float vec3::Magnitude()
		{
			return vec3::Magnitude(*this);
		}

		inline float vec3::SqrMagnitude()
		{
			return vec3::SqrMagnitude(*this);
		}

		inline vec3 vec3::Normalize(const vec3 & v)
		{
			vec3 result(v);

			return v / vec3::Magnitude(v);
		}

		inline float vec3::Magnitude(const vec3 & v)
		{
			return std::sqrtf(vec3::Dot(v, v));
		}

		inline float vec3::SqrMagnitude(const vec3 & v)
		{
			return vec3::Dot(v, v);
		}

		inline float vec3::Dot(const vec3 & lhs, const vec3 & rhs)
		{
			vec3 temp(lhs * rhs);
			return temp.x + temp.y + temp.z;
		}

		inline vec3 vec3::Cross(const vec3 & lhs, const vec3 & rhs)
		{
			return vec3(
				lhs.y * rhs.z - lhs.z * rhs.y,
				lhs.z * rhs.x - lhs.x * rhs.z,
				lhs.x * rhs.y - lhs.y * rhs.x);
		}

		inline vec3 & vec3::operator=(const vec3 & v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}

		inline float & vec3::operator[](unsigned int i)
		{
			// TODO(batuhan): Implement ArrayCount.
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline float & const vec3::operator[](unsigned int i) const
		{
			// TODO(batuhan): Assert. Check i > 0 && i < length
			return (float&)(values[i]);
		}

		inline vec3 & vec3::operator+=(float k)
		{
			this->x += k;
			this->y += k;
			this->z += k;
			return *this;
		}

		inline vec3 & vec3::operator+=(const vec3 & rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}

		inline vec3 & vec3::operator-=(float k)
		{
			this->x -= k;
			this->y -= k;
			this->z -= k;
			return *this;
		}

		inline vec3 & vec3::operator-=(const vec3 & rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}

		inline vec3 & vec3::operator*=(float k)
		{
			this->x *= k;
			this->y *= k;
			this->z *= k;
			return *this;
		}

		inline vec3 & vec3::operator*=(const vec3 & rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			this->z *= rhs.z;
			return *this;
		}

		inline vec3 & vec3::operator/=(float k)
		{
			this->x /= k;
			this->y /= k;
			this->z /= k;
			return *this;
		}

		inline vec3 & vec3::operator/=(const vec3 & rhs)
		{
			this->x /= rhs.x;
			this->y /= rhs.y;
			this->z /= rhs.z;
			return *this;
		}

		inline vec3 & vec3::operator++()
		{
			++this->x;
			++this->y;
			++this->z;
			return *this;
		}

		inline vec3 & vec3::operator--()
		{
			--this->x;
			--this->y;
			--this->z;
			return *this;
		}

		inline vec3 vec3::operator++(int)
		{
			vec3 result(*this);
			++*this;
			return result;
		}

		inline vec3 vec3::operator--(int)
		{
			vec3 result(*this);
			--*this;
			return result;
		}

		static vec3 operator+(const vec3& v)
		{
			return v;
		}

		static vec3 operator-(const vec3& v)
		{
			return vec3(-v.x, -v.y, -v.z);
		}

		static vec3 operator+(const vec3 & v, float scalar)
		{
			return vec3(v.x + scalar, v.y + scalar, v.z + scalar);
		}

		static vec3 operator+(float scalar, const vec3 & v)
		{
			return (v + scalar);
		}

		static vec3 operator+(const vec3 & lhs, const vec3 & rhs)
		{
			return vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.y);
		}

		static vec3 operator-(const vec3 & v, float scalar)
		{
			return vec3(v.x - scalar, v.y - scalar, v.z - scalar);
		}

		static vec3 operator-(float scalar, const vec3 & v)
		{
			return vec3(scalar - v.x, scalar - v.y, scalar - v.z);
		}

		static vec3 operator-(const vec3 & lhs, const vec3 & rhs)
		{
			return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.y);
		}

		static vec3 operator*(const vec3 & v, float scalar)
		{
			return vec3(v.x * scalar, v.y * scalar, v.z * scalar);
		}

		static vec3 operator*(float scalar, const vec3 & v)
		{
			return (v * scalar);
		}

		static vec3 operator*(const vec3 & lhs, const vec3 & rhs)
		{
			return vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
		}

		static vec3 operator/(const vec3 & v, float scalar)
		{
			return vec3(v.x / scalar, v.y / scalar, v.z / scalar);
		}

		static vec3 operator/(float scalar, const vec3 & v)
		{
			return vec3(scalar / v.x, scalar / v.y, scalar / v.z);;
		}

		static vec3 operator/(const vec3 & lhs, const vec3 & rhs)
		{
			return vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.y);
		}

		static bool operator==(const vec3 & lhs, const vec3 & rhs)
		{
			return ((lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z));
		}

		static bool operator!=(const vec3 & lhs, const vec3 & rhs)
		{
			return !(lhs == rhs);
		}

	} // namespace math
} // namespace mge
