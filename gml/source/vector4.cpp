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

	vec4::vec4(const vec3& vec3, float w)
	{
		set(vec3.x, vec3.y, vec3.z, w);
	}

	vec4::vec4(const vec4& other)
	{
		set(other.x, other.y, other.z, other.w);
	}

	vec4& vec4::operator=(const vec4& rhs)
	{
		if (&rhs != this)
		{
			set(rhs.x, rhs.y, rhs.z, rhs.w);
		}
		return *this;
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

	vec4& vec4::replace(const vec3& vec3)
	{
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;
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