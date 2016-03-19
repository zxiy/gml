#include "../include/matrix33.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>
#include <cmath>

namespace gml
{
	const matrix33 matrix33::I(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
		);

	matrix33 matrix33::rotate22(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);
		return matrix33(
			cosr, -sinr, 0,
			sinr, cosr, 0,
			0, 0, 1);
	}

	matrix33 matrix33::matrix33::scale22(float scaler)
	{
		return matrix33(
			scaler, 0, 0,
			0, scaler, 0,
			0, 0, 1);
	}

	matrix33 matrix33::matrix33::scale22(float sx, float sy)
	{
		return matrix33(
			sx, 0, 0,
			0, sy, 0,
			0, 0, 1);
	}
	matrix33 matrix33::translate(float x, float y)
	{
		return matrix33(
			1, 0, 0,
			0, 1, 0,
			x, y, 1);
	}

	matrix33 matrix33::flip22_x()
	{
		return matrix33(
			-1, 0, 0,
			0, 1, 0,
			0, 0, 1);
	}

	matrix33 matrix33::flip22_y()
	{
		return matrix33(
			1, 0, 0,
			0, -1, 0,
			0, 0, 1);
	}

	matrix33 matrix33::rotate33_x(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return matrix33(
			1, 0, 0,
			0, cosr, -sinr,
			0, sinr, cosr
			);
	}

	matrix33 matrix33::rotate33_y(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return matrix33(
			cosr, 0, -sinr,
			0, 1, 0,
			sinr, 0, cosr
			);
	}

	matrix33 matrix33::rotate33_z(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return matrix33(
			cosr, -sinr, 0,
			sinr, cosr, 0,
			0, 0, 1
			);
	}

	matrix33 matrix33::scale33(float scale)
	{
		return matrix33(
			scale, 0, 0,
			0, scale, 0,
			0, 0, scale
			);
	}

	matrix33 matrix33::scale33(float sx, float sy, float sz)
	{
		return matrix33(
			sx, 0, 0,
			0, sy, 0,
			0, 0, sz
			);
	}

	matrix33 matrix33::flip33_x()
	{
		return matrix33(
			-1, 0, 0,
			0, 1, 0,
			0, 0, 1
			);
	}

	matrix33 matrix33::flip33_y()
	{
		return matrix33(
			1, 0, 0,
			0, -1, 0,
			0, 0, 1
			);
	}

	matrix33 matrix33::flip33_z()
	{
		return matrix33(
			1, 0, 0,
			0, 1, 0,
			0, 0, -1
			);
	}

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

	matrix33& matrix33::operator=(const matrix33& rhs)
	{
		if (&rhs != this)
		{
			for (int i = 0; i < 9; i++)
			{
				(*this)[i] = rhs[i];
			}
		}
		return *this;
	}

	matrix33 matrix33::operator*(float scaler) const
	{
		matrix33 result(*this);
		result *= scaler;
		return result;
	}

	matrix33 matrix33::operator*(const matrix33& rhs) const
	{
		matrix33 result(*this);
		result *= rhs;
		return result;
	}

	vector3 matrix33::operator* (const vector3& rhs) const
	{
		vector3 result;
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(row[i], rhs);
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
		matrix33 copy(*this);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m[i][j] = dot(copy.row[i], rhs.col(j));
			}
		}
		return *this;
	}

	bool matrix33::operator== (const matrix33& rhs) const
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

	bool matrix33::operator!= (const matrix33& rhs) const
	{
		return !(*this == rhs);
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
		if (is_orthogonal())
		{
			transpose();
			return true;
		}

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
		for (int i = 0; i < 3; i++)
		{
			if (!fequal(row[i].length_sqr(), 1.0f))
			{
				return false;
			}

			for (int j = i + 1; j < 3; j++)
			{
				if (!fequal(dot(row[i], row[j]), 0.0f))
					return false;
			}
		}
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

	vector3 operator* (const vector3& lhs, const matrix33& rhs)
	{
		vector3 result;
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(lhs, rhs.col(i));
		}
		return result;
	}

	vector2 transform_vector(const matrix33& lhs, const vector2& rhs)
	{
		vector2 result;
		vector3 rhs3(rhs, 0);
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(rhs3, lhs.col(i));
		}
		return result;
	}

	vector2 transform_point(const matrix33& lhs, const vector2& rhs)
	{
		vector2 result;
		vector3 rhs3(rhs, 1);
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(rhs3, lhs.col(i));
		}
		return result;
	}
}