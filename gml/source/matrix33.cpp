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
		for (int i = 0; i < 16; i++)
		{
			(*this)[i] = other[i];
		}
		return *this;
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

	matrix33& matrix33::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			//calc adjoint matrix 
		}

		return *this;
	}

	float matrix33::determinant()
	{
		return determinant_impl(
			_00, _01, _02,
			_10, _11, _12,
			_20, _21, _22);
	}
}