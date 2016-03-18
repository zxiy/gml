#include "../include/matrix22.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>
#include <cmath>

namespace gml
{
	const matrix22 matrix22::I(
		1.0f, 0.0f,
		0.0f, 1.0f
		);

	matrix22::matrix22() {}

	matrix22::matrix22(float _00, float _01, float _10, float _11)
	{
		this->_00 = _00;	this->_01 = _01;
		this->_10 = _10;	this->_11 = _11;
	}

	matrix22::matrix22(const matrix22& other)
	{
		*this = other;
	}

	matrix22& matrix22::operator=(const matrix22& rhs)
	{
		if (&rhs != this)
		{
			for (int i = 0; i < 4; i++)
			{
				(*this)[i] = rhs[i];
			}
		}
		return *this;
	}

	matrix22 matrix22::operator*(float scaler) const
	{
		matrix22 result(*this);
		result *= scaler;
		return result;
	}

	matrix22 matrix22::operator*(const matrix22& rhs) const
	{
		matrix22 result(*this);
		result *= rhs;
		return result;
	}

	vector2 matrix22::operator* (const vector2& rhs) const
	{
		vector2 result;
		for (int i = 0; i < 2; i++)
		{
			result[i] = dot(row[i], rhs);
		}
		return result;
	}

	matrix22& matrix22::operator*=(float scaler)
	{
		for (int i = 0; i < 4; i++)
		{
			(*this)[i] *= scaler;
		}
		return *this;
	}

	matrix22& matrix22::operator*=(const matrix22& rhs)
	{
		matrix22 copy(*this);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				m[i][j] = dot(copy.row[i], rhs.col(j));
			}
		}
		return *this;
	}

	bool matrix22::operator== (const matrix22& rhs) const
	{
		if (&rhs != this)
		{
			for (int i = 0; i < 4; i++)
			{
				if ((*this)[i] != rhs[i])
					return false;
			}
		}
		return true;
	}

	bool matrix22::operator!= (const matrix22& rhs) const
	{
		return !(*this == rhs);
	}

	float& matrix22::operator[] (int index)
	{
		return const_cast<float&>(const_cast<const matrix22*>(this)->operator[](index));
	}

	const float& matrix22::operator[] (int index) const
	{
		assert(index >= 0 && index < 4);
		return *(&(m[0][0]) + index);
	}

	vector2 matrix22::col(int index) const
	{
		assert(index >= 0 && index < 2);
		return vector2(row[0][index], row[1][index]);
	}

	matrix22& matrix22::identity()
	{
		return *this = I;
	}

	matrix22& matrix22::transpose()
	{
		swap(this->_10, this->_01);
		return *this;
	}

	matrix22 matrix22::transposed() const
	{
		matrix22 result(*this);
		result.transpose();
		return result;
	}

	bool matrix22::inverse()
	{
		if (is_orthogonal())
		{
			transpose();
			return true;
		}

		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			//calc adjoint matrix 
			swap(this->m[0][0], this->m[1][1]);
			this->m[0][1] = -this->m[0][1];
			this->m[1][0] = -this->m[1][0];

			*this *= 1.0f / det;
			return true;
		}
		return false;
	}

	bool matrix22::is_orthogonal() const
	{
		for (int i = 0; i < 2; i++)
		{
			if (!fequal(row[i].length_sqr(), 1.0f))
			{
				return false;
			}

			for (int j = i + 1; j < 2; j++)
			{
				if (!fequal(dot(row[i], row[j]), 0.0f))
					return false;
			}
		}
		return true;
	}

	float matrix22::determinant() const
	{
		return determinant_impl(
			_00, _01,
			_10, _11);
	}

	matrix22 operator* (float scaler, const matrix22& rhs)
	{
		return rhs * scaler;
	}

	vector2 operator* (const vector2& lhs, const matrix22& rhs)
	{
		vector2 result;
		for (int i = 0; i < 2; i++)
		{
			result[i] = dot(lhs, rhs.col(i));
		}
		return result;
	}

	matrix22 rotate(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);
		return matrix22(cosr, -sinr, sinr, cosr);
	}
}