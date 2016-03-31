#include "../include/matrix.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>
#include <cmath>

namespace gml
{
	const mat44 mat44::I(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	mat44 mat44::rotate_x(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return mat44(
			1, 0, 0, 0,
			0, cosr, -sinr, 0,
			0, sinr, cosr, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::rotate_y(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return mat44(
			cosr, 0, -sinr, 0,
			0, 1, 0, 0,
			sinr, 0, cosr, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::rotate_z(float radian)
	{
		float cosr = cosf(radian);
		float sinr = sinf(radian);

		return mat44(
			cosr, -sinr, 0, 0,
			sinr, cosr, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::scale(float scale)
	{
		return mat44(
			scale, 0, 0, 0,
			0, scale, 0, 0,
			0, 0, scale, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::scale(float sx, float sy, float sz)
	{
		return mat44(
			sx, 0, 0, 0,
			0, sy, 0, 0,
			0, 0, sz, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::translate(float x, float y, float z)
	{
		return mat44(
			-1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			x, y, z, 1
			);
	}

	mat44 mat44::flip_x()
	{
		return mat44(
			-1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::flip_y()
	{
		return mat44(
			1, 0, 0, 0,
			0, -1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
			);
	}

	mat44 mat44::flip_z()
	{
		return mat44(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, -1, 0,
			0, 0, 0, 1
			);
	}

	mat44::mat44() {}

	mat44::mat44(float _00, float _01, float _02, float _03, float _10, float _11, float _12, float _13, float _20, float _21, float _22, float _23, float _30, float _31, float _32, float _33)
	{
		this->_00 = _00;	this->_01 = _01;	this->_02 = _02;	this->_03 = _03;
		this->_10 = _10;	this->_11 = _11;	this->_12 = _12;	this->_13 = _13;
		this->_20 = _20;	this->_21 = _21;	this->_22 = _22;	this->_23 = _23;
		this->_30 = _30;	this->_31 = _31;	this->_32 = _32;	this->_33 = _33;
	}

	mat44::mat44(const mat44& other)
	{
		*this = other;
	}

	mat44& mat44::operator=(const mat44& other)
	{
		for (int i = 0; i < 16; i++)
		{
			(*this)[i] = other[i];
		}
		return *this;
	}

	mat44 mat44::operator*(float scaler) const
	{
		mat44 result(*this);
		result *= scaler;
		return result;
	}

	mat44 mat44::operator*(const mat44& rhs) const
	{
		mat44 result(*this);
		result *= rhs;
		return result;
	}

	vec4 mat44::operator* (const vec4& rhs) const
	{
		vec4 result;
		for (int i = 0; i < 4; i++)
		{
			result[i] = dot(row[i], rhs);
		}
		return result;
	}

	mat44& mat44::operator*=(float scaler)
	{
		for (int i = 0; i < 4; i++)
		{
			(*this)[i] *= scaler;
		}
		return *this;
	}

	mat44& mat44::operator*=(const mat44& rhs)
	{
		mat44 copy(*this);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m[i][j] = dot(copy.row[i], rhs.col(j));
			}
		}
		return *this;
	}

	bool mat44::operator== (const mat44& other) const
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

	bool mat44::operator!= (const mat44& other) const
	{
		return !(*this == other);
	}

	float& mat44::operator[] (int index)
	{
		return const_cast<float&>(const_cast<const mat44*>(this)->operator[](index));
	}

	const float& mat44::operator[] (int index) const
	{
		assert(index >= 0 && index < 16);
		return *(&(m[0][0]) + index);
	}

	vec4 mat44::col(int index) const
	{
		assert(index >= 0 && index < 4);
		return vec4(row[0][index], row[1][index], row[2][index], row[3][index]);
	}

	mat44& mat44::identity()
	{
		return *this = I;
	}

	mat44& mat44::transpose()
	{
		swap(this->_10, this->_01);
		swap(this->_20, this->_02);
		swap(this->_30, this->_03);

		swap(this->_21, this->_12);
		swap(this->_31, this->_13);

		swap(this->_32, this->_23);
		return *this;
	}

	mat44 mat44::transposed() const
	{
		mat44 result(*this);
		result.transpose();
		return result;
	}

	bool mat44::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			det = 1.0f / det;
			mat44 copy(*this);

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

	float mat44::determinant() const
	{
		return determinant_impl(
			_00, _01, _02, _03,
			_10, _11, _12, _13,
			_20, _21, _22, _23,
			_30, _31, _32, _33);
	}

	mat44 operator* (float scaler, const mat44& rhs)
	{
		return rhs * scaler;
	}

	vec4 operator* (const vec4& lhs, const mat44& rhs)
	{
		vec4 result;
		for (int i = 0; i < 4; i++)
		{
			result[i] = dot(lhs, rhs.col(i));
		}
		return result;
	}

	vec3 transform_vector(const mat44& lhs, const vec3& rhs)
	{
		vec3 result;
		vec4 rhs4(rhs, 0);
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(rhs4, lhs.col(i));
		}
		return result;
	}

	vec3 transform_point(const mat44& lhs, const vec3& rhs)
	{
		vec3 result;
		vec4 rhs4(rhs, 1);
		for (int i = 0; i < 3; i++)
		{
			result[i] = dot(rhs4, lhs.col(i));
		}
		return result;
	}
}