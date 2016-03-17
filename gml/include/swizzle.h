#pragma once

#include <gml/include/vector2.h>
#include <gml/include/vector3.h>
#include <gml/include/vector4.h>

namespace gml
{
	enum e_swizzle
	{
		x = 0, y = 1, z = 2, w = 3,
	};

	//use e_swizzle instead of template param int below.
	template<e_swizzle SWIZZLE_X, int SWIZZLE_Y>
	inline vector2 swizzle(const vector2& vec2)
	{
		return vector2(vec2[SWIZZLE_X], vec2[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y>
	inline vector2 swizzle(const vector3& vec3)
	{
		return vector2(vec3[SWIZZLE_X], vec3[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y>
	inline vector2 swizzle(const vector4& vec4)
	{
		return vector2(vec4[SWIZZLE_X], vec4[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vector3 swizzle(const vector2& vec2)
	{
		return vector3(vec2[SWIZZLE_X], vec2[SWIZZLE_Y], vec2[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vector3 swizzle(const vector3& vec3)
	{
		return vector3(vec3[SWIZZLE_X], vec3[SWIZZLE_Y], vec3[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vector3 swizzle(const vector4& vec4)
	{
		return vector3(vec4[SWIZZLE_X], vec4[SWIZZLE_Y], vec4[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vector4 swizzle(const vector2& vec2)
	{
		return vector4(vec2[SWIZZLE_X], vec2[SWIZZLE_Y], vec2[SWIZZLE_Z], vec2[SWIZZLE_W]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vector4 swizzle(const vector3& vec3)
	{
		return vector4(vec3[SWIZZLE_X], vec3[SWIZZLE_Y], vec3[SWIZZLE_Z], vec3[SWIZZLE_W]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vector4 swizzle(const vector4& vec4)
	{
		return vector4(vec4[SWIZZLE_X], vec4[SWIZZLE_Y], vec4[SWIZZLE_Z], vec4[SWIZZLE_W]);
	}
}
