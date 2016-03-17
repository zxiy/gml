#pragma once
#include <gml/include/vector2.h>

namespace gml
{
	class matrix22
	{
	public:
		static const matrix22 I;
	public:
		union
		{
			float m[2][2] = { 0,0,0,0 };
			struct { float _00, _01, _10, _11; };
			struct { vector2 row[2]; };
		};

		matrix22();

		explicit matrix22(float _00, float _01, float _10, float _11);

		matrix22(const matrix22& other);

		matrix22& operator=(const matrix22& other);

		float& operator[] (int index);

		const float& operator[] (int index) const;

		matrix22& identity();

		matrix22& transpose();

		matrix22& inverse();

		float determinant();
	};
}
