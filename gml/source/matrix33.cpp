#include "../include/matrix33.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>

namespace gml
{
	const matrix33 matrix33::I(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
		);

	matrix33::matrix33() {}

	matrix33::matrix33(float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22)
	{
		this->_00 = _00;	this->_01 = _01;	this->_02 = _02;
		this->_10 = _10;	this->_11 = _11;	this->_12 = _12;
		this->_20 = _20;	this->_21 = _21;	this->_22 = _22;
	}

	matrix33::matrix33(const matrix33& other)
	{
		*this = other;
	}

	matrix33& matrix33::operator=(const matrix33& other)
	{
		for (int i = 0; i < 9; i++)
		{
			(*this)[i] = other[i];
		}
		return *this;
	}

	matrix33 matrix33::operator*(float scaler) const
	{
		matrix33 result(*this);
		for (int i = 0; i < 4; i++)
		{
			result[i] *= scaler;
		}
		return result;
	}

	matrix33 matrix33::operator*(const matrix33& rhs) const
	{
		matrix33 result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.m[i][j] = dot(row[i], rhs.col(j));
			}
		}
		return result;
	}

	matrix33& matrix33::operator*=(float scaler)
	{
		for (int i = 0; i < 4; i++)
		{
			(*this)[i] *= scaler;
		}
		return *this;
	}

	matrix33& matrix33::operator*=(const matrix33& rhs)
	{
		*this = *this * rhs;
		return *this;
	}

	bool matrix33::operator== (const matrix33& other) const
	{
		if (&other != this)
		{
			for (int i = 0; i < 4; i++)
			{
				if ((*this)[i] != other[i])
					return false;
			}
		}
		return true;
	}

	bool matrix33::operator!= (const matrix33& other) const
	{
		return !(*this == other);
	}

	float& matrix33::operator[] (int index)
	{
		return const_cast<float&>(const_cast<const matrix33*>(this)->operator[](index));
	}

	const float& matrix33::operator[] (int index) const
	{
		assert(index >= 0 && index < 16);
		return *(&(m[0][0]) + index);
	}

	vector3 matrix33::col(int index) const
	{
		assert(index >= 0 && index < 3);
		return vector3(row[0][index], row[1][index], row[2][index]);
	}

	matrix33& matrix33::identity()
	{
		return *this = I;
	}

	matrix33& matrix33::transpose()
	{
		swap(this->_10, this->_01);
		swap(this->_20, this->_02);

		swap(this->_21, this->_12);

		return *this;
	}

	matrix33 matrix33::transposed() const
	{
		matrix33 result(*this);
		result.transpose();
		return result;
	}

	bool matrix33::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			det = 1.0f / det;
			matrix33 copy(*this);

			//to-do det_impl is calculated above in determinant().
			//try to gcd
			m[0][0] = +determinant_impl(copy._11, copy._12, copy._21, copy._22) * det;
			m[1][0] = -determinant_impl(copy._10, copy._12, copy._20, copy._22) * det;
			m[2][0] = +determinant_impl(copy._10, copy._11, copy._20, copy._21) * det;

			m[0][1] = -determinant_impl(copy._01, copy._02, copy._21, copy._22) * det;
			m[1][1] = +determinant_impl(copy._00, copy._02, copy._20, copy._22) * det;
			m[2][1] = -determinant_impl(copy._00, copy._01, copy._20, copy._21) * det;

			m[0][2] = +determinant_impl(copy._01, copy._02, copy._11, copy._12) * det;
			m[1][2] = -determinant_impl(copy._00, copy._02, copy._10, copy._12) * det;
			m[2][2] = +determinant_impl(copy._00, copy._01, copy._10, copy._11) * det;

			return true;
		}

		return false;
	}

	bool matrix33::is_orthogonal() const
	{
		//todo.
		return false;
	}

	float matrix33::determinant() const
	{
		return determinant_impl(
			_00, _01, _02,
			_10, _11, _12,
			_20, _21, _22);
	}

	matrix33 operator* (float scaler, const matrix33& rhs)
	{
		return rhs * scaler;
	}
}