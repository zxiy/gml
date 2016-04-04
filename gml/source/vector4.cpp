#include "../include/vector.h"
#include "../include/math_util.h"
#include <cassert>
#include <cmath>

namespace gml
{
	vec4::vec4(){ }

	vec4::vec4(float x, float y, float z, float w)
	{
		set(x, y, z, w);
	}

	vec4::vec4(const vec3& v3, float w)
	{
		set(v3.x, v3.y, v3.z, w);
	}

	bool vec4::operator==(const vec4& rhs) const
	{
		if (&rhs == this)
			return true;

		return fequal(x, rhs.x) &&
			fequal(y, rhs.y) &&
			fequal(z, rhs.z) &&
			fequal(w, rhs.w);
	}

	bool vec4::operator!=(const vec4& rhs) const
	{
		return !(*this == rhs);
	}

	//hack
	float& vec4::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vec4*>(this)->operator[](index));
	}

	const float& vec4::operator[](int index) const
	{
		assert(index >= 0 && index < 4);
		return *(&x + index);
	}

	vec4::operator float*()
	{
		return &(this->x);
	}

	vec4& vec4::set(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	vec4& vec4::replace(const vec3& v3)
	{
		this->x = v3.x;
		this->y = v3.y;
		this->z = v3.z;
		return *this;
	}

	float vec4::length() const
	{
		return sqrtf(x*x + y*y + z*z + w*w);
	}

	float vec4::length_sqr() const
	{
		return x*x + y*y + z*z + w*w;
	}

	float dot(const vec4& lhs, const vec4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}
}