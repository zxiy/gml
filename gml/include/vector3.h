#pragma once

namespace gml
{
	class vector4;

	class vector3
	{
	public:
		static const vector3 zero;
		static const vector3 one;
		static const vector3 left;
		static const vector3 right;
		static const vector3 up;
		static const vector3 down;
		static const vector3 forward;
		static const vector3 backward;


	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		vector3(int) = delete;

		vector3();

		vector3(float x, float y, float z);

		vector3(const vector3& other);

		explicit vector3(const vector4& vec4);

		vector3 operator-() const;

		vector3& operator=(const vector3& rhs);

		bool operator==(const vector3& rhs) const;

		bool operator!=(const vector3& rhs) const;

		vector3 operator+(float value) const;

		vector3 operator-(float value) const;

		vector3 operator*(float value) const;

		vector3 operator+(const vector3& rhs) const;

		vector3 operator-(const vector3& rhs) const;

		vector3 operator*(const vector3& rhs) const;

		vector3& operator+=(float value);

		vector3& operator-=(float value);

		vector3& operator*=(float value);

		vector3& operator+=(const vector3& rhs);

		vector3& operator-=(const vector3& rhs);

		vector3& operator*=(const vector3& rhs);

		//hack
		float& operator[](int index);

		const float& operator[](int index) const;

		vector3& set(float x, float y, float z);

		vector3& set(const vector4& vec4);

		vector3 normalized() const;

		vector3& normalize();

		vector3& make_zero();

		vector3& make_one();

		vector3& clamp();

		vector3 clamped() const;

		vector3& inverse();

		vector3 inversed() const;

		float length() const;

		float length_sqr() const;

		vector4 to_vector4() const;

		vector4 to_position4() const;

	};

	vector3 operator+(float value, const vector3& rhs);

	vector3 operator-(float value, const vector3& rhs);

	vector3 operator*(float value, const vector3& rhs);

	float dot(const vector3& lhs, const vector3& rhs);

	vector3 cross(const vector3& lhs, const vector3& rhs);

	vector3 min_combine(const vector3& lhs, const vector3& rhs);

	vector3 max_combine(const vector3& lhs, const vector3& rhs);
}