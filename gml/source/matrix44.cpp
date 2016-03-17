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

	float& matrix44::operator[] (int index)
	{
		return const_cast<float&>(const_cast<const matrix44*>(this)->operator[](index));
	}

	const float& matrix44::operator[] (int index) const
	{
		assert(index >= 0 && index < 16);
		return *(&(m[0][0]) + index);
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

	matrix44& matrix44::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			//calc adjoint matrix 
		}
			
		return *this;
	}

	float matrix44::determinant()
	{
		return raw_determinant(
			_00, _01, _02, _03,
			_10, _11, _12, _13,
			_20, _21, _22, _23,
			_30, _31, _32, _33);
	}
}