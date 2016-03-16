#pragma once

namespace gml
{
	int get_float_exponent_base2(float d);
	bool fequal(float a, float b);

	template<typename T>
	inline T lerp(T left, T right, float fac)
	{
		return left * (1.0f - fac) + right * fac;
	}
}