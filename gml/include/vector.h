#pragma once

namespace gml
{
	class vec2;
	class vec3;
	class vec4;

	class vec2
	{
	public:
		static const vec2 zero;
		static const vec2 one;
		static const vec2 left;
		static const vec2 right;
		static const vec2 up;
		static const vec2 down;

	public:
		float x = 0.0f;
		float y = 0.0f;

	public:
		vec2();

		vec2(float x, float y);

		vec2(const vec2& other);

		explicit vec2(const vec3& vec3);

		vec2 operator-() const;

		vec2& operator=(const vec2& rhs);

		bool operator==(const vec2& rhs) const;

		bool operator!=(const vec2& rhs) const;

		vec2 operator+(float value) const;

		vec2 operator-(float value) const;

		vec2 operator*(float value) const;

		vec2 operator+(const vec2& rhs) const;

		vec2 operator-(const vec2& rhs) const;

		vec2 operator*(const vec2& rhs) const;

		vec2& operator+=(float value);

		vec2& operator-=(float value);

		vec2& operator*=(float value);

		vec2& operator+=(const vec2& rhs);

		vec2& operator-=(const vec2& rhs);

		vec2& operator*=(const vec2& rhs);

		//hack
		float& operator[](int index);

		const float& operator[](int index) const;

		vec2& set(float x, float y);

		vec2& set(const vec3& vec3);

		vec2 normalized() const;

		vec2& normalize();

		vec2& clamp();

		vec2 clamped() const;

		vec2& inverse();

		vec2 inversed() const;

		float length() const;

		float length_sqr() const;
	};

	class vec3
	{
	public:
		static const vec3 zero;
		static const vec3 one;
		static const vec3 left;
		static const vec3 right;
		static const vec3 up;
		static const vec3 down;
		static const vec3 forward;
		static const vec3 backward;


	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

	public:
		vec3();

		vec3(float x, float y, float z);

		vec3(const vec2& vec2, float z);

		vec3(const vec3& other);

		explicit vec3(const vec4& vec4);

		vec3 operator-() const;

		vec3& operator=(const vec3& rhs);

		bool operator==(const vec3& rhs) const;

		bool operator!=(const vec3& rhs) const;

		vec3 operator+(float value) const;

		vec3 operator-(float value) const;

		vec3 operator*(float value) const;

		vec3 operator+(const vec3& rhs) const;

		vec3 operator-(const vec3& rhs) const;

		vec3 operator*(const vec3& rhs) const;

		vec3& operator+=(float value);

		vec3& operator-=(float value);

		vec3& operator*=(float value);

		vec3& operator+=(const vec3& rhs);

		vec3& operator-=(const vec3& rhs);

		vec3& operator*=(const vec3& rhs);

		//hack
		float& operator[](int index);

		const float& operator[](int index) const;

		vec3& set(float x, float y, float z);

		vec3& set(const vec4& vec4);

		vec3 normalized() const;

		vec3& normalize();

		vec3& clamp();

		vec3 clamped() const;

		vec3& inverse();

		vec3 inversed() const;

		float length() const;

		float length_sqr() const;
	};

	class vec4
	{
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;

	public:
		vec4();

		vec4(float x, float y, float z, float w);

		vec4(const vec3& vec3, float w);

		vec4(const vec4& other);
		
		vec4& operator=(const vec4& rhs);

		bool operator==(const vec4& rhs) const;

		bool operator!=(const vec4& rhs) const;

		vec4 operator+(float value) const;

		vec4 operator*(float value) const;

		vec4 operator+(const vec4& rhs) const;

		vec4 operator*(const vec4& rhs) const;

		vec4& operator+=(float value);

		vec4& operator*=(float value);

		vec4& operator+=(const vec4& rhs);

		vec4& operator*=(const vec4& rhs);

		//hack
		float& operator[](int index);

		const float& operator[](int index) const;

		explicit operator float*();

		vec4& set(float x, float y, float z, float w);

		vec4& replace(const vec3& vec3);

		float length() const;

		float length_sqr() const;
	};

	//vec2
	vec2 operator+(float value, const vec2& rhs);

	vec2 operator-(float value, const vec2& rhs);

	vec2 operator*(float value, const vec2& rhs);

	float dot(const vec2& lhs, const vec2& rhs);

	float cross(const vec2& lhs, const vec2& rhs);

	vec2 min_combine(const vec2& lhs, const vec2& rhs);

	vec2 max_combine(const vec2& lhs, const vec2& rhs);

	//vec3
	vec3 operator+(float value, const vec3& rhs);

	vec3 operator-(float value, const vec3& rhs);

	vec3 operator*(float value, const vec3& rhs);

	float dot(const vec3& lhs, const vec3& rhs);

	vec3 cross(const vec3& lhs, const vec3& rhs);

	vec3 min_combine(const vec3& lhs, const vec3& rhs);

	vec3 max_combine(const vec3& lhs, const vec3& rhs);

	//vec4
	vec4 operator+(float value, const vec4& rhs);

	vec4 operator*(float value, const vec4& rhs);

	float dot(const vec4& lhs, const vec4& rhs);

	//swizzle
	enum e_swizzle
	{
		x = 0, y = 1, z = 2, w = 3,
	};

	//use e_swizzle instead of template param int below.
	template<e_swizzle SWIZZLE_X, int SWIZZLE_Y>
	inline vec2 swizzle(const vec2& v2)
	{
		return vec2(v2[SWIZZLE_X], v2[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y>
	inline vec2 swizzle(const vec3& v3)
	{
		return vec2(v3[SWIZZLE_X], v3[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y>
	inline vec2 swizzle(const vec4& v4)
	{
		return vec2(v4[SWIZZLE_X], v4[SWIZZLE_Y]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vec3 swizzle(const vec2& v2)
	{
		return vec3(v2[SWIZZLE_X], v2[SWIZZLE_Y], v2[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vec3 swizzle(const vec3& v3)
	{
		return vec3(v3[SWIZZLE_X], v3[SWIZZLE_Y], v3[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z>
	inline vec3 swizzle(const vec4& v4)
	{
		return vec3(v4[SWIZZLE_X], v4[SWIZZLE_Y], v4[SWIZZLE_Z]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vec4 swizzle(const vec2& v2)
	{
		return vec4(v2[SWIZZLE_X], v2[SWIZZLE_Y], v2[SWIZZLE_Z], v2[SWIZZLE_W]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vec4 swizzle(const vec3& v3)
	{
		return vec4(v3[SWIZZLE_X], v3[SWIZZLE_Y], v3[SWIZZLE_Z], v3[SWIZZLE_W]);
	}

	template<int SWIZZLE_X, int SWIZZLE_Y, int SWIZZLE_Z, int SWIZZLE_W>
	inline vec4 swizzle(const vec4& v4)
	{
		return vec4(v4[SWIZZLE_X], v4[SWIZZLE_Y], v4[SWIZZLE_Z], v4[SWIZZLE_W]);
	}
}