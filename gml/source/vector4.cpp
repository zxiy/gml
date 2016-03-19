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

	vector4::vector4(const vector3& vec3, float w)
	{
		set(vec3.x, vec3.y, vec3.z, w);
	}

	vector4::vector4(const vector4& other)
	{
		set(other.x, other.y, other.z, other.w);
	}

	vector4& vector4::operator=(const vector4& rhs)
	{
		if (&rhs != this)
		{
			set(rhs.x, rhs.y, rhs.z, rhs.w);
		}
		return *this;
	}

	bool vector4::operator==(const vector4& rhs) const
	{
		if (&rhs == this)
			return true;

		return fequal(x, rhs.x) &&
			fequal(y, rhs.y) &&
			fequal(z, rhs.z) &&
			fequal(w, rhs.w);
	}

	bool vector4::operator!=(const vector4& rhs) const
	{
		return !(*this == rhs);
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

	vector4& vector4::replace(const vector3& vec3)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
		return *this;
	}

	float dot(const vector4& lhs, const vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}
}