#include <gml/include/vector3.h>
#include <gml/include/vector4.h>
#include <gml/include/math_util.h>
#include <cmath>
#include <cassert>

namespace gml
{
	const vector3 vector3::zero(0.0f, 0.0f, 0.0f);
	const vector3 vector3::one(1.0f, 1.0f, 1.0f);
	const vector3 vector3::left(-1.0f, 0.0f, 0.0f);
	const vector3 vector3::right(1.0f, 0.0f, 0.0f);
	const vector3 vector3::up(0.0f, 1.0f, 0.0f);
	const vector3 vector3::down(0.0f, -1.0f, 0.0f);
	const vector3 vector3::forward(0.0f, 0.0f, 1.0f);
	const vector3 vector3::backward(0.0f, 0.0f, -1.0f);

	vector3::vector3()
	{
	}

	vector3::vector3(float x, float y, float z)
	{
		set(x, y, z);
	}

	vector3::vector3(const vector3& rhs)
	{
		set(rhs.x, rhs.y, rhs.z);
	}

	vector3::vector3(const vector4& rhs)
	{
		set(rhs.x, rhs.y, rhs.z);
	}

	vector3 vector3::operator-() const
	{
		return vector3(-x, -y, -z);
	}

	vector3& vector3::operator=(const vector3& rhs)
	{
		if (&rhs != this)
		{
			set(rhs.x, rhs.y, rhs.z);
		}
		return *this;
	}

	vector3& vector3::operator=(const vector4& rhs)
	{
		set(rhs.x, rhs.y, rhs.z);
		return *this;
	}

	bool vector3::operator==(const vector3& other) const
	{
		if (&other == this)
			return true;

		return fequal(x, other.x) &&
			fequal(y, other.y) &&
			fequal(z, other.z);
	}

	bool vector3::operator!=(const vector3& other) const
	{
		if (&other == this)
			return false;
		return !fequal(x, other.x) ||
			!fequal(y, other.y) ||
			!fequal(z, other.z);
	}

	vector3 vector3::operator+(float value) const
	{
		vector3 copy(*this);
		copy += value;
		return copy;
	}

	vector3 vector3::operator-(float value) const
	{
		vector3 copy(*this);
		copy -= value;
		return copy;
	}

	vector3 vector3::operator*(float value) const
	{
		vector3 copy(*this);
		copy *= value;
		return copy;
	}

	vector3 vector3::operator+(const vector3& rhs) const
	{
		return vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	vector3 vector3::operator-(const vector3& rhs) const
	{
		return vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	vector3 vector3::operator*(const vector3& rhs) const
	{
		return vector3(x * rhs.x, y * rhs.y, z * rhs.z);
	}

	vector3& vector3::operator+=(float value)
	{
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vector3& vector3::operator-=(float value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vector3& vector3::operator*=(float value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vector3& vector3::operator+=(const vector3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	vector3& vector3::operator-=(const vector3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	vector3& vector3::operator*=(const vector3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	float& vector3::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vector3*>(this)->operator[](index));
	}

	const float& vector3::operator[](int index) const
	{
		assert(index >= 0 && index < 3);
		return *(&x + index);
	}

	vector3& vector3::set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	vector3 vector3::normalized() const
	{
		vector3 copy(*this);
		return copy.normalize();
	}

	vector3& vector3::normalize()
	{
		float lengthrev = length();
		if (!fequal(lengthrev, 0.0f))
		{
			lengthrev = 1.0f / lengthrev;
			this->x *= lengthrev;
			this->y *= lengthrev;
			this->z *= lengthrev;
		}
		else
		{
			make_zero();
		}
		return *this;
	}

	vector3& vector3::make_zero()
	{
		return set(0.0f, 0.0f, 0.0f);
	}

	vector3& vector3::make_one()
	{
		return set(1.0f, 1.0f, 1.0f);
	}

	vector3& vector3::clamp()
	{
		if (x > 1.0f) x = 1.0f;
		else if (x < 0.0f) x = 0.0f;

		if (y > 1.0f) y = 1.0f;
		else if (y < 0.0f) y = 0.0f;

		if (z > 1.0f) z = 1.0f;
		else if (z < 0.0f) z = 0.0f;

		return *this;
	}

	vector3 vector3::clamped() const
	{
		vector3 copy(*this);
		return copy.clamp();
	}

	vector3& vector3::inverse()
	{
		x = 1.0f / x;
		y = 1.0f / y;
		z = 1.0f / z;
		return *this;
	}

	vector3 vector3::inversed() const
	{
		vector3 copy(*this);
		return copy.inverse();
	}

	float vector3::length() const
	{
		return sqrtf(x*x + y*y + z*z);
	}

	float vector3::length_sqr() const
	{
		return x*x + y*y + z*z;
	}

	vector4 vector3::to_vector4() const
	{
		return vector4(x, y, z, 0.0f);
	}

	vector4 vector3::to_position4() const
	{
		return vector4(x, y, z, 1.0f);
	}

	vector3 operator+(float value, const vector3& rhs)
	{
		return rhs + value;
	}

	vector3 operator-(float value, const vector3& rhs)
	{
		return rhs - value;
	}

	vector3 operator*(float value, const vector3& rhs)
	{
		return rhs * value;
	}

	float dot(const vector3& lhs, const vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	vector3 cross(const vector3& lhs, const vector3& rhs)
	{
		return vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
			);
	}

	vector3 min_combine(const vector3& lhs, const vector3& rhs)
	{
		return vector3(
			lhs.x < rhs.x ? lhs.x : rhs.x,
			lhs.y < rhs.y ? lhs.y : rhs.y,
			lhs.z < rhs.z ? lhs.z : rhs.z
			);
	}

	vector3 max_combine(const vector3& lhs, const vector3& rhs)
	{
		return vector3(
			lhs.x > rhs.x ? lhs.x : rhs.x,
			lhs.y > rhs.y ? lhs.y : rhs.y,
			lhs.z > rhs.z ? lhs.z : rhs.z
			);
	}
}