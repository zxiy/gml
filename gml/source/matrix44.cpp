#include "../include/matrix44.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>

namespace gml
{
	const matrix44 matrix44::I(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	matrix44::matrix44() {}

	matrix44::matrix44(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33)
	{
		this->_00 = _00;	this->_01 = _01;	this->_02 = _02;	this->_03 = _03;
		this->_10 = _10;	this->_11 = _11;	this->_12 = _12;	this->_13 = _13;
		this->_20 = _20;	this->_21 = _21;	this->_22 = _22;	this->_23 = _23;
		this->_30 = _30;	this->_31 = _31;	this->_32 = _32;	this->_33 = _33;
	}

	matrix44::matrix44(const matrix44& other)
	{
		*this = other;
	}

	matrix44& matrix44::operator=(const matrix44& other)
	{
		for (int i = 0; i < 16; i++)
		{
			(*this)[i] = other[i];
		}
		return *this;
	}

	matrix44 matrix44::operator*(float scaler) const
	{
		matrix44 result(*this);
		result *= scaler;
		return result;
	}

	matrix44 matrix44::operator*(const matrix44& rhs) const
	{
		matrix44 result(*this);
		result *= rhs;
		return result;
	}

	matrix44& matrix44::operator*=(float scaler)
	{
		for (int i = 0; i < 4; i++)
		{
			(*this)[i] *= scaler;
		}
		return *this;
	}

	matrix44& matrix44::operator*=(const matrix44& rhs)
	{
		matrix44 copy(*this);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m[i][j] = dot(copy.row[i], rhs.col(j));
			}
		}
		return *this;
	}

	bool matrix44::operator== (const matrix44& other) const
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

	bool matrix44::operator!= (const matrix44& other) const
	{
		return !(*this == other);
	}

	float& matrix44::operator[] (int index)
	{
		return const_cast<float&>(const_cast<const matrix44*>(this)->operator[](index));
	}

	const float& matrix44::operator[] (int index) const
	{
		assert(index >= 0 && index < 16);
		return *(&(m[0][0]) + index);
	}

	vector4 matrix44::col(int index) const
	{
		assert(index >= 0 && index < 4);
		return vector4(row[0][index], row[1][index], row[2][index], row[3][index]);
	}

	matrix44& matrix44::identity()
	{
		return *this = I;
	}

	matrix44& matrix44::transpose()
	{
		swap(this->_10, this->_01);
		swap(this->_20, this->_02);
		swap(this->_30, this->_03);

		swap(this->_21, this->_12);
		swap(this->_31, this->_13);

		swap(this->_32, this->_23);
		return *this;
	}

	matrix44 matrix44::transposed() const
	{
		matrix44 result(*this);
		result.transpose();
		return result;
	}

	bool matrix44::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			det = 1.0f / det;
			matrix44 copy(*this);

			//to-do det_impl is calculated above in determinant().
			//try to gcd
			m[0][0] = +determinant_impl(copy._11, copy._12, copy._13, copy._21, copy._22, copy._23, copy._31, copy._32, copy._33) * det;
			m[1][0] = -determinant_impl(copy._10, copy._12, copy._13, copy._20, copy._22, copy._23, copy._30, copy._32, copy._33) * det;
			m[2][0] = +determinant_impl(copy._10, copy._11, copy._13, copy._20, copy._21, copy._23, copy._30, copy._31, copy._33) * det;
			m[3][0] = -determinant_impl(copy._10, copy._11, copy._12, copy._20, copy._21, copy._22, copy._30, copy._31, copy._32) * det;

			m[0][1] = -determinant_impl(copy._01, copy._02, copy._03, copy._21, copy._22, copy._23, copy._31, copy._32, copy._33) * det;
			m[1][1] = +determinant_impl(copy._00, copy._02, copy._03, copy._20, copy._22, copy._23, copy._30, copy._32, copy._33) * det;
			m[2][1] = -determinant_impl(copy._00, copy._01, copy._03, copy._20, copy._21, copy._23, copy._30, copy._31, copy._33) * det;
			m[3][1] = +determinant_impl(copy._00, copy._01, copy._02, copy._20, copy._21, copy._22, copy._30, copy._31, copy._32) * det;

			m[0][2] = +determinant_impl(copy._01, copy._02, copy._03, copy._11, copy._12, copy._13, copy._31, copy._32, copy._33) * det;
			m[1][2] = -determinant_impl(copy._00, copy._02, copy._03, copy._10, copy._12, copy._13, copy._30, copy._32, copy._33) * det;
			m[2][2] = +determinant_impl(copy._00, copy._01, copy._03, copy._10, copy._11, copy._13, copy._30, copy._31, copy._33) * det;
			m[3][2] = -determinant_impl(copy._00, copy._01, copy._02, copy._10, copy._11, copy._12, copy._30, copy._31, copy._32) * det;

			m[0][3] = -determinant_impl(copy._01, copy._02, copy._03, copy._11, copy._12, copy._13, copy._21, copy._22, copy._23) * det;
			m[1][3] = +determinant_impl(copy._00, copy._02, copy._03, copy._10, copy._12, copy._13, copy._20, copy._22, copy._23) * det;
			m[2][3] = -determinant_impl(copy._00, copy._01, copy._03, copy._10, copy._11, copy._13, copy._20, copy._21, copy._23) * det;
			m[3][3] = +determinant_impl(copy._00, copy._01, copy._02, copy._10, copy._11, copy._12, copy._20, copy._21, copy._22) * det;

			return true;
		}
			
		return false;
	}

	float matrix44::determinant() const
	{
		return determinant_impl(
			_00, _01, _02, _03,
			_10, _11, _12, _13,
			_20, _21, _22, _23,
			_30, _31, _32, _33);
	}

	matrix44 operator* (float scaler, const matrix44& rhs)
	{
		return rhs * scaler;
	}
}