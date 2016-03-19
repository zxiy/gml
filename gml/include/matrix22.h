#pragma once
#include <gml/include/vector2.h>

namespace gml
{
	class matrix22
	{
	public:
		static const matrix22 I;

		static matrix22 rotate(float radian);

		static matrix22 scale(float scale);

		static matrix22 scale(float sx, float sy);

		static matrix22 flip_x();

		static matrix22 flip_y();

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

		matrix22& operator=(const matrix22& rhs);

		matrix22 operator* (float scaler) const;

		matrix22 operator* (const matrix22& rhs) const;

		vector2 operator* (const vector2& rhs) const;

		matrix22& operator*= (float scaler);

		matrix22& operator*=(const matrix22& rhs);

		bool operator== (const matrix22& rhs) const;

		bool operator!= (const matrix22& rhs) const;

		float& operator[] (int index);

		const float& operator[] (int index) const;

		vector2 col(int index) const;

		matrix22& identity();

		matrix22& transpose();

		matrix22 transposed() const;

		bool inverse();

		bool is_orthogonal() const;

		float determinant() const;
	};

	matrix22 operator* (float scaler, const matrix22& rhs);

	vector2 operator* (const vector2& lhs, const matrix22& rhs);
}
