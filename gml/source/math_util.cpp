#include "../include/math_util.h"
#include "inner_util.h"

namespace gml
{
	bool fequal(float a, float b)
	{
		if (a == b)
			return true;

		int ea = get_float_exponent_base2(a);
		int eb = get_float_exponent_base2(b);
		int ediff = get_float_exponent_base2(a - b);

		return ((ediff - eb < -22) && (ediff - ea < -22));
	}

	int get_float_exponent_base2(float d)
	{
		int i = 0;
		((short *)(&i))[0] = (((short *)(&d))[1] & (short)0x7FC0); // _123456789ab____ & 0111111110000000
		return (i >> 7) - 127;
	}

	float raw_determinant(
		float a00, float a01,
		float a10, float a11)
	{
		return a00 * a11 - a01 * a10;
	}

	float raw_determinant(
		float a00, float a01, float a02,
		float a10, float a11, float a12,
		float a20, float a21, float a22)
	{
		return a00 * a11 * a22
			+ a01 * a12 * a20
			+ a02 * a10 * a21
			- a00 * a12 * a21
			- a01 * a10 * a22
			- a02 * a11 * a20;
	}

	float raw_determinant(
		float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23,
		float a30, float a31, float a32, float a33)
	{
		return a00 * raw_determinant(a11, a12, a13,
								 a21, a22, a23,
								 a31, a32, a33)

			- a01 * raw_determinant(a10, a12, a13,
								a20, a22, a23,
								a30, a32, a33)

			+ a02 * raw_determinant(a10, a11, a13,
								a20, a21, a23,
								a30, a31, a33)

			- a03 * raw_determinant(a10, a11, a12,
								a20, a21, a22,
								a30, a31, a32);
	}
}