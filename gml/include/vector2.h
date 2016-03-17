#pragma once

namespace gml
{
	class vector3;

	class vector2
	{
	public:
		static const vector2 zero;
		static const vector2 one;
		static const vector2 left;
		static const vector2 right;
		static const vector2 up;
		static const vector2 down;

	public:
		float x = 0.0f;
		float y = 0.0f;

		vector2(int) = delete;

		vector2();

		vector2(float x, float y);

		vector2(const vector2& rhs);

		explicit vector2(const vector3& rhs);

		vector2 operator-() const;

		vector2& operator=(const vector2& rhs);

		bool operator==(const vector2& other) const;

		bool operator!=(const vector2& other) const;

		vector2 operator+(float value) const;
		
		vector2 operator-(float value) const;
		
		vector2 operator*(float value) const;

		vector2 operator+(const vector2& rhs) const;

		vector2 operator-(const vector2& rhs) const;

		vector2 operator*(const vector2& rhs) const;

		vector2& operator+=(float value);

		vector2& operator-=(float value);

		vector2& operator*=(float value);

		vector2& operator+=(const vector2& rhs);

		vector2& operator-=(const vector2& rhs);

		vector2& operator*=(const vector2& rhs);

		//hack
		float& operator[](int index);

		const float& operator[](int index) const;

		vector2& set(float x, float y);

		vector2& set(const vector3& vec3);

		vector2 normalized() const;

		vector2& normalize();

		vector2& make_zero();

		vector2& make_one();

		vector2& clamp();

		vector2 clamped() const;

		vector2& inverse();

		vector2 inversed() const;

		float length() const;

		float length_sqr() const;

		vector3 to_vector3() const;

		vector3 to_position3() const;

	};
	
	vector2 operator+(float value, const vector2& rhs);
	
	vector2 operator-(float value, const vector2& rhs);
	
	vector2 operator*(float value, const vector2& rhs);
	
	float dot(const vector2& lhs, const vector2& rhs);
	
	float cross(const vector2& lhs, const vector2& rhs);
		
	vector2 min_combine(const vector2& lhs, const vector2& rhs);

	vector2 max_combine(const vector2& lhs, const vector2& rhs);
}