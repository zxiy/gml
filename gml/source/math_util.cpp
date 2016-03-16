#include <gml/include/math_util.h>

namespace gml
{
	int get_float_exponent_base2(float d)
	{
		int i = 0;
		((short *)(&i))[0] = (((short *)(&d))[1] & (short)0x7FC0); // _123456789ab____ & 0111111110000000
		return (i >> 7) - 127;
	}

	bool fequal(float a, float b)
	{
		if (a == b)
			return true;

		int ea = get_float_exponent_base2(a);
		int eb = get_float_exponent_base2(b);
		int ediff = get_float_exponent_base2(a - b);

		return ((ediff - eb < -22) && (ediff - ea < -22));
	}
}