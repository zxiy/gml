#include <gml/include/math_util.h>
#include <gml/include/vector2.h>
#include <cmath>
#include <cassert>

namespace gml
{
	const vector2 vector2::zero(0.0f, 0.0f);
	const vector2 vector2::one(1.0f, 1.0f);
	const vector2 vector2::left(-1.0f, 0.0f);
	const vector2 vector2::right(1.0f, 0.0f);
	const vector2 vector2::up(0.0f, 1.0f);
	const vector2 vector2::down(0.0f, -1.0f);

	vector2::vector2()
	{
	}

	vector2::vector2(float x, float y)
	{
		set(x, y);
	}

	vector2::vector2(const vector2& rhs)
	{
		set(rhs.x, rhs.y);
	}

	vector2::vector2(const vector3& rhs)
	{
		set(rhs.x, rhs.y);
	}

	vector2 vector2::operator-() const
	{
		return vector2(-x, -y);
	}

	vector2& vector2::operator=(const vector2& rhs)
	{
		if (&rhs == this)
			return *this;

		set(rhs.x, rhs.y);
		return *this;
	}

	vector2& vector2::operator=(const vector3& rhs)
	{
		set(rhs.x, rhs.y);
		return *this;
	}

	bool vector2::operator==(const vector2& other) const
	{
		if (&other == this)
			return true;

		return fequal(x, other.x) &&
			fequal(y, other.y);
	}

	bool vector2::operator!=(const vector2& other) const
	{
		if (&other == this)
			return false;

		return !fequal(x, other.x) ||
			!fequal(y, other.y);
	}

	vector2 vector2::operator+(float value) const
	{
		vector2 copy(*this);
		copy += value;
		return copy;
	}

	vector2 vector2::operator-(float value) const
	{
		vector2 copy(*this);
		copy -= value;
		return copy;
	}

	vector2 vector2::operator*(float value) const
	{
		vector2 copy(*this);
		copy *= value;
		return copy;
	}

	vector2 vector2::operator+(const vector2& rhs) const
	{
		return vector2(x + rhs.x, y + rhs.y);
	}


	vector2 vector2::operator-(const vector2& rhs) const
	{
		return vector2(x - rhs.x, y - rhs.y);
	}


	vector2 vector2::operator*(const vector2& rhs) const
	{
		return vector2(rhs.x, rhs.y);
	}

	vector2& vector2::operator+=(float value)
	{
		x += value;
		y += value;
		return *this;
	}

	vector2& vector2::operator-=(float value)
	{
		x -= value;
		y -= value;
		return *this;
	}

	vector2& vector2::operator*=(float value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	vector2& vector2::operator+=(const vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	vector2& vector2::operator-=(const vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	vector2& vector2::operator*=(const vector2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	float& vector2::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vector2*>(this)->operator[](index));
	}

	const float& vector2::operator[](int index) const
	{
		assert(index >= 0 && index < 2);
		return *(&x + index);
	}

	vector2& vector2::set(float x, float y)
	{
		this->x = x;
		this->y = y;
		return *this;
	}

	vector2 vector2::normalized() const
	{
		vector2 copy(*this);
		return copy.normalize();
	}

	vector2& vector2::normalize()
	{
		float lengthrev = length();
		if (!fequal(lengthrev, 0.0f))
		{
			lengthrev = 1.0f / lengthrev;
			x *= lengthrev;
			y *= lengthrev;
		}
		else
		{
			make_zero();
		}
		return *this;
	}

	vector2& vector2::make_zero()
	{
		return set(0.0f, 0.0f);
	}

	vector2& vector2::make_one()
	{
		return set(1.0f, 1.0f);
	}

	vector2& vector2::clamp()
	{
		if (x > 1.0f) x = 1.0f;
		else if (x < 0.0f) x = 0.0f;

		if (y > 1.0f) y = 1.0f;
		else if (y < 0.0f) y = 0.0f;

		return *this;
	}

	vector2 vector2::clamped() const
	{
		vector2 copy(*this);

		return copy.clamp();
	}

	vector2& vector2::inverse()
	{
		x = 1.0f / x;
		y = 1.0f / y;
		return *this;
	}

	vector2 vector2::inversed() const
	{
		vector2 copy(*this);
		return copy.inverse();
	}

	float vector2::length() const
	{
		return sqrtf(x*x + y*y);
	}

	float vector2::length_sqr() const
	{
		return x*x + y*y;
	}

	vector3 vector2::to_vector3() const
	{
		return vector3(x, y, 0.0f);
	}

	vector3 vector2::to_position3() const
	{
		return vector3(x, y, 1.0f);
	}

	vector2 operator+(float value, const vector2& rhs)
	{
		return rhs + value;
	}

	vector2 operator-(float value, const vector2& rhs)
	{
		return rhs - value;
	}

	vector2 operator*(float value, const vector2& rhs)
	{
		return rhs * value;
	}

	float dot(const vector2& lhs, const vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	float cross(const vector2& lhs, const vector2& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	vector2 min_combine(const vector2& lhs, const vector2& rhs)
	{
		return vector2(
			lhs.x < rhs.x ? lhs.x : rhs.x,
			lhs.y < rhs.y ? lhs.y : rhs.y
			);
	}

	vector2 max_combine(const vector2& lhs, const vector2& rhs)
	{
		return vector2(
			lhs.x > rhs.x ? lhs.x : rhs.x,
			lhs.y > rhs.y ? lhs.y : rhs.y
			);
	}
}