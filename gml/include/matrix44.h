#pragma once
#include <gml/include/vector4.h>

namespace gml
{
	class matrix44
	{
	public:
		static const matrix44 I;
	public:
		union
		{
			float m[4][4] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			struct { float _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33; };
			struct { vector4 row[4]; };
		};

		matrix44();

		explicit matrix44(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33);

		matrix44(const matrix44& other);

		matrix44& operator=(const matrix44& other);

		float& operator[] (int index);

		const float& operator[] (int index) const;

		matrix44& identity();

		matrix44& transpose();

		matrix44& inverse();

		float determinant();
	};
}
