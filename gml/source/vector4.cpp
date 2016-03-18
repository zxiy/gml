#include "../include/vector4.h"
#include "../include/vector3.h"
#include "../include/math_util.h"
#include <cassert>

namespace gml
{
	vector4::vector4(){ }

	vector4::vector4(float x, float y, float z, float w)
	{
		set(x, y, z, w);
	}

	vector4::vector4(const vector4& rhs)
	{
		set(rhs.x, rhs.y, rhs.z, rhs.w);
	}

	vector4& vector4::operator=(const vector4& rhs)
	{
		if (&rhs != this)
		{
			set(rhs.x, rhs.y, rhs.z, rhs.w);
		}
		return *this;
	}

	bool vector4::operator==(const vector4& other) const
	{
		if (&other == this)
			return true;

		return fequal(x, other.x) &&
			fequal(y, other.y) &&
			fequal(z, other.z) &&
			fequal(w, other.w);
	}

	bool vector4::operator!=(const vector4& other) const
	{
		if (&other == this)
			return false;

		return !fequal(x, other.x) ||
			!fequal(y, other.y) ||
			!fequal(z, other.z) ||
			!fequal(w, other.w);

	}

	//hack
	float& vector4::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vector4*>(this)->operator[](index));
	}

	const float& vector4::operator[](int index) const
	{
		assert(index >= 0 && index < 4);
		return *(&x + index);
	}

	vector4::operator float*()
	{
		return &(this->x);
	}

	vector4& vector4::set(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	vector4& vector4::replace(const vector3& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
		return *this;
	}

	float dot(const vector4& lhs, const vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}
}