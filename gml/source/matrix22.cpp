#include "../include/matrix22.h"
#include "../include/math_util.h"
#include "inner_util.h"
#include <cassert>

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

	matrix22& matrix22::operator=(const matrix22& other)
	{
		for (int i = 0; i < 4; i++)
		{
			(*this)[i] = other[i];
		}
		return *this;
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

	matrix22& matrix22::identity()
	{
		return *this = I;
	}

	matrix22& matrix22::transpose()
	{
		swap(this->_10, this->_01);
		return *this;
	}

	matrix22& matrix22::inverse()
	{
		float det = determinant();
		if (!fequal(det, 0.0f))
		{
			//calc adjoint matrix 
		}

		return *this;
	}

	float matrix22::determinant()
	{
		return determinant_impl(
			_00, _01,
			_10, _11);
	}
}