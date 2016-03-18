#include <gml/include/vector2.h>
#include <gml/include/vector3.h>
#include <gml/include/vector4.h>
#include <gml/include/math_util.h>
#include <gml/include/swizzle.h>
#include <gml/include/matrix22.h>
#include <gml/include/matrix33.h>
#include <gml/include/matrix44.h>
#include <iostream>

#pragma comment(lib, "gml.lib")
using namespace gml;

void testVector2();
void testVector3();
void testVector4();
void testSwizzle();
void testMatrix22();
void testMatrix33();
void testMatrix44();

int main()
{
	std::cout << "test vector2 \n";
	testVector2();

	std::cout << "test vector3 \n";
	testVector3();

	std::cout << "test vector4 \n";
	testVector4();

	std::cout << "test swizzle \n";
	testSwizzle();

	std::cout << "test matrix22 \n";
	testMatrix22();

	std::cout << "test matrix33 \n";
	testMatrix33();

	std::cout << "test matrix44 \n";
	testMatrix44();

	getchar();
	return 0;
}

void testVector3()
{
	vector3 a = vector3::one;
	vector3 b(3, 4, 5);
	vector3 c;

	std::cout << "  c = <" << c.x << "," << c.y << "," << c.z << ">\n"
		<< "  b.length = " << b.length() << "\n"
		<< "  b.lengthsquare = " << b.length_sqr() << "\n";

	b.normalize();
	std::cout << "  normalized: " << b.length() << "\n\n";


	c = b.normalized() * 3.4f;
	b *= 3.4f;
	std::cout << "  b == c is " << ((c == b) ? "" : "not ") << "equal \n"
		<< "  b == vector3::one is " << ((vector3::one == b) ? "" : "not ") << "equal \n\n";

	a = vector3::one + vector3::left;
	std::cout << "  one + left = <" << a.x << "," << a.y << "," << a.z << ">\n";
	a += vector3::one * vector3::right;
	std::cout << "  result += one * right = <" << a.x << "," << a.y << "," << a.z << ">\n";

	a = b.inversed();
	std::cout << "  b = <" << a.x << "," << a.y << "," << a.z << ">\n";
	a.clamp();
	std::cout << "  b.clmap = <" << a.x << "," << a.y << "," << a.z << ">\n";

	a = cross(b, c);
	std::cout << "  cross(b,b) = <" << a.x << "," << a.y << "," << a.z << ">\n";
	a = cross(b, vector3::one);
	std::cout << "  cross(b,vector3::one) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n"
		<< "  dot(b,c) = " << dot(b, c) << "\n\n";

	a = lerp(b, vector3::one, 0.5f);
	std::cout << "  lerp(b,vector3::one, 0.5f) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n";
	a = lerp(b, vector3::one, 0.0f);
	std::cout << "  lerp(b,vector3::one, 0.0f) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n";
	a = lerp(b, vector3::one, 1.0f);
	std::cout << "  lerp(b,vector3::one, 1.0f) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n\n";


	a = max_combine(vector3(1, 2, 3), vector3(3, 2, 1));
	std::cout << "  max_combine(<1,2,3>, <3,2,1>) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n\n";

	a = min_combine(vector3(1, 2, 3), vector3(3, 2, 1));
	std::cout << "  minx_combine(b,vector3::one, 1.0f) = <" << a[0] << "," << a[1] << "," << a[2] << ">\n\n";
}

void testVector2()
{
	vector2 a = vector2::one;
	vector2 b(3, 4);
	vector2 c;

	std::cout << "  c = <" << c.x << "," << c.y << ">\n"
		<< "  b.length = " << b.length() << "\n"
		<< "  b.lengthsquare = " << b.length_sqr() << "\n";

	b.normalize();
	std::cout << "  normalized: " << b.length() << "\n\n";


	c = b.normalized() * 3.4f;
	b *= 3.4f;
	std::cout << "  b == c is " << ((c == b) ? "" : "not ") << "equal \n"
		<< "  b == vector2::one is " << ((vector2::one == b) ? "" : "not ") << "equal \n\n";


	a = vector2::one + vector2::left;
	std::cout << "  one + left = <" << a.x << "," << a.y << ">\n";
	a += vector2::one * vector2::right;
	std::cout << "  result += one * right = <" << a.x << "," << a.y << ">\n";

	a = b.inversed();
	std::cout << "  b = <" << a.x << "," << a.y << ">\n";
	a.clamp();
	std::cout << "  b.clmap = <" << a.x << "," << a.y << ">\n";


	std::cout << "  cross(b,b) = <" << cross(b, c) << ">\n";
	std::cout << "  cross(b,vector2::one) = <"
		<< cross(b, vector2::one) << ">\n"
		<< "  dot(b,c) = " << dot(b, c) << "\n\n";

	a = lerp(b, vector2::one, 0.5f);
	std::cout << "  lerp(b,vector2::one, 0.5f) = <" << a[0] << "," << a[1] << ">\n";
	a = lerp(b, vector2::one, 0.0f);
	std::cout << "  lerp(b,vector2::one, 0.0f) = <" << a[0] << "," << a[1] << ">\n";
	a = lerp(b, vector2::one, 1.0f);
	std::cout << "  lerp(b,vector2::one, 1.0f) = <" << a[0] << "," << a[1] << ">\n\n";


	a = max_combine(vector2(1, 2), vector2(3, 1));
	std::cout << "  max_combine(<1,2,3>, <3,2,1>) = <" << a[0] << "," << a[1] << ">\n\n";

	a = min_combine(vector2(1, 3), vector2(3, 2));
	std::cout << "  minx_combine(b,vector2::one, 1.0f) = <" << a[0] << "," << a[1] << ">\n\n";
}

void testMatrix44()
{
	matrix44 m;

	std::cout << " union data verify:\n   m.operator[]= {";
	for (int i = 0; i < 16; i++)
	{
		m[i] = i * 1.0f;
		std::cout << m[i] << (i == 15 ? "" : ",");
	}
	std::cout << "}\n   m.vector4   = {";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m.row[i][j] << (i == 3 && j == 3 ? "" : ",");
		}
	}
	std::cout << "}\n   m.array     = {";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << m.m[i][j] << (i == 3 && j == 3 ? "" : ",");
		}
	}

	std::cout << "}\n   m.struct    = {"
		<< m._00 << ","
		<< m._01 << ","
		<< m._02 << ","
		<< m._03 << ","

		<< m._10 << ","
		<< m._11 << ","
		<< m._12 << ","
		<< m._13 << ","

		<< m._20 << ","
		<< m._21 << ","
		<< m._22 << ","
		<< m._23 << ","

		<< m._30 << ","
		<< m._31 << ","
		<< m._32 << ","
		<< m._33 << "}\n\n";

	matrix44 a(-4, -3, 3, 0, 0, 2, -2, 0, 1, 4, -1, 0, 1, 2, 50, 1);
	matrix44 b(a);

	std::cout << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << "\n"
		<< a[4] << "," << a[5] << "," << a[6] << "," << a[7] << "\n"
		<< a[8] << "," << a[9] << "," << a[10] << "," << a[11] << "\n"
		<< a[12] << "," << a[13] << "," << a[14] << "," << a[15] << "\n\n";

	//a.transpose();
	std::cout << "can inverse = " << a.inverse() << "\n";

	std::cout << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << "\n"
		<< a[4] << "," << a[5] << "," << a[6] << "," << a[7] << "\n"
		<< a[8] << "," << a[9] << "," << a[10] << "," << a[11] << "\n"
		<< a[12] << "," << a[13] << "," << a[14] << "," << a[15] << "\n\n";

	a = a * b;

	std::cout << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << "\n"
		<< a[4] << "," << a[5] << "," << a[6] << "," << a[7] << "\n"
		<< a[8] << "," << a[9] << "," << a[10] << "," << a[11] << "\n"
		<< a[12] << "," << a[13] << "," << a[14] << "," << a[15] << "\n\n";
}

void testVector4()
{

}

void testSwizzle()
{
	vector2 a, vec2(2.1f, 2.2f);
	vector3 b, vec3(3.1f, 3.2f, 3.3f);
	vector4 c, vec4(4.1f, 4.2f, 4.3f, 4.4f);

	std::cout << " vec2 : <" << vec2.x << ", " << vec2.y << ">\n";
	std::cout << " vec3 : <" << vec3.x << ", " << vec3.y << ", " << vec3.z << ">\n";
	std::cout << " vec4 : <" << vec4.x << ", " << vec4.y << ", " << vec4.z << ", " << vec4.w << ">\n";

	//a = vec3;
	a = vector2(vec3);

	a = swizzle<y, x>(vec2);
	std::cout << "  vec2 = vec2.yx : <" << a.x << ", " << a.y << ">\n";
	a = swizzle<y, z>(vec3);
	std::cout << "  vec2 = vec3.yz : <" << a.x << ", " << a.y << ">\n";
	a = swizzle<w, w>(vec4);
	std::cout << "  vec2 = vec4.ww : <" << a.x << ", " << a.y << ">\n\n";

	//b = vec4;
	b = vector3(vec4);

	b = swizzle<y, x, y>(vec2);
	std::cout << "  vec3 = vec2.yxy : <" << b.x << ", " << b.y << ", " << b.z << ">\n";
	b = swizzle<y, z, x>(vec3);
	std::cout << "  vec3 = vec3.yzx : <" << b.x << ", " << b.y << ", " << b.z << ">\n";
	b = swizzle<w, w, x>(vec4);
	std::cout << "  vec3 = vec4.wwx : <" << b.x << ", " << b.y << ", " << b.z << ">\n\n";

	c = swizzle<y, x, x, y>(vec2);
	std::cout << "  vec4 = vec2.yxxy : <" << c.x << ", " << c.y << ", " << c.z << ", " << c.w << ">\n";
	c = swizzle<y, z, x, z>(vec3);
	std::cout << "  vec4 = vec3.yzxz : <" << c.x << ", " << c.y << ", " << c.z << ", " << c.w << ">\n";
	c = swizzle<z, z, w, y>(vec4);
	std::cout << "  vec4 = vec4.zzwy : <" << c.x << ", " << c.y << ", " << c.z << ", " << c.w << ">\n\n";
}

void testMatrix22()
{
	const float r = 0.5f;
	matrix22 a(cos(r), -sin(r), sin(r), cos(r));
	matrix22 b(a);

	std::cout << "  a = \n  |"
		<< a[0] << "," << a[1] << "|\n  |"
		<< a[2] << "," << a[3] << "| is"
		<< (a.is_orthogonal() ? " " : " not ")
		<< "orthogonal\n\n";

	a._11 += 20.0f;
	std::cout << "  a = \n  |"
		<< a[0] << "," << a[1] << "|\n  |"
		<< a[2] << "," << a[3] << "| is"
		<< (a.is_orthogonal() ? " " : " not ")
		<< "orthogonal\n\n";

	b = a;
	std::cout << "  a can"
		<<( a.inverse()? " " : " not ")
		<<"inverse.\n\n";

	
	std::cout << "  a.inv =\n  |"
		<< a[0] << "," << a[1] << "|\n  |"
		<< a[2] << "," << a[3] << "|\n\n";

	a = a * b;

	std::cout <<"  a * b =\n"
		<< "  |"
		<< a[0] << "," << a[1] << "|\n  |"
		<< a[2] << "," << a[3] << "|\n\n";
}

void testMatrix33()
{
	matrix33 a(-4, -3, 3, 0, 2, -2, 1, 4, -1);
	matrix33 b(a);

	std::cout << a[0] << "," << a[1] << "," << a[2] << "\n"
		<< a[3] << "," << a[4] << "," << a[5] << "\n"
		<< a[6] << "," << a[7] << "," << a[8] << "\n\n";

	//a.transpose();
	std::cout << "can inverse = " << a.inverse() << "\n";

	std::cout << a[0] << "," << a[1] << "," << a[2] << "\n"
		<< a[3] << "," << a[4] << "," << a[5] << "\n"
		<< a[6] << "," << a[7] << "," << a[8] << "\n\n";

	a = a * b;

	std::cout << a[0] << "," << a[1] << "," << a[2] << "\n"
		<< a[3] << "," << a[4] << "," << a[5] << "\n"
		<< a[6] << "," << a[7] << "," << a[8] << "\n\n";
}