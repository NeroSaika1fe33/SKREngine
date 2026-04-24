#include "simple_math/transformation/matrix/matrix_4x3.h"
#include "simple_math/transformation/matrix/matrix_4x4.h"


FMatrix_4x3::FMatrix_4x3()
{
	identity();
}

FMatrix_4x3::FMatrix_4x3(const FMatrix_4x4& in_matrix)
	: m11(in_matrix.m11), m12(in_matrix.m12), m13(in_matrix.m13)
	, m21(in_matrix.m21), m22(in_matrix.m22), m23(in_matrix.m23)
	, m31(in_matrix.m31), m32(in_matrix.m32), m33(in_matrix.m33)
	, x(0.f), y(0.f), z(0.f)
{

}

FMatrix_4x3::FMatrix_4x3(
	float in_m11, float in_m12, float in_m13,
	float in_m21, float in_m22, float in_m23,
	float in_m31, float in_m32, float in_m33,
	float in_x, float in_y, float in_z)
	: m11(in_m11), m12(in_m12), m13(in_m13)
	, m21(in_m21), m22(in_m22), m23(in_m23)
	, m31(in_m31), m32(in_m32), m33(in_m33)
	, x(in_x), y(in_y), z(in_z)
{
}

void FMatrix_4x3::identity()
{
	*this = FMatrix_4x3(
		1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f,
		0.f, 0.f, 0.f);
}

FMatrix_4x3 FMatrix_4x3::inversion(const FMatrix_4x3& in_m)const
{
	float d = determinant(in_m);
	assert(abs(d) > SMALL_NUMBER);

	float det_tmp = 1.f / d;

	FMatrix_4x3 m;
	m.m11 = (in_m.m22 * in_m.m33 - in_m.m23 * in_m.m32) * det_tmp;
	m.m12 = (in_m.m13 * in_m.m32 - in_m.m12 * in_m.m23) * det_tmp;
	m.m13 = (in_m.m12 * in_m.m23 - in_m.m13 * in_m.m22) * det_tmp;

	m.m21 = (in_m.m23 * in_m.m31 - in_m.m21 * in_m.m33) * det_tmp;
	m.m22 = (in_m.m11 * in_m.m33 - in_m.m13 * in_m.m31) * det_tmp;
	m.m23 = (in_m.m13 * in_m.m21 - in_m.m11 * in_m.m23) * det_tmp;

	m.m31 = (in_m.m21 * in_m.m32 - in_m.m22 * in_m.m31) * det_tmp;
	m.m32 = (in_m.m12 * in_m.m31 - in_m.m11 * in_m.m32) * det_tmp;
	m.m33 = (in_m.m11 * in_m.m22 - in_m.m12 * in_m.m21) * det_tmp;

	m.x = -(in_m.x * m.m11 + in_m.y * m.m21 + in_m.z * m.m31);
	m.y = -(in_m.x * m.m12 + in_m.y * m.m22 + in_m.z * m.m32);
	m.z = -(in_m.x * m.m13 + in_m.y * m.m23 + in_m.z * m.m33);

	return m;
}

FMatrix_4x3 FMatrix_4x3::inversion()const
{
	return inversion(*this);
}

f32 FMatrix_4x3::determinant(const FMatrix_4x3& in_m)const
{
	return	in_m.m11 * (in_m.m22 * in_m.m33 - in_m.m23 * in_m.m32)
			- in_m.m12 * (in_m.m21 * in_m.m33 - in_m.m23 * in_m.m31) 
			+ in_m.m13 * (in_m.m21 * in_m.m32 - in_m.m22 * in_m.m31);
}

f32 FMatrix_4x3::determinant()
{
	return determinant(*this);
}