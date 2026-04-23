#include "simple_math/transformation/matrix/matrix_3x3.h"
#include "simple_math/transformation/matrix/matrix_4x4.h"


FMatrix_3x3::FMatrix_3x3()
{
    *this = FMatrix_3x3::identity();
}

FMatrix_3x3::FMatrix_3x3(
    f32 m11,f32 m12,f32 m13,
    f32 m21,f32 m22,f32 m23,
    f32 m31,f32 m32,f32 m33)
    :m11(m11),m12(m12),m13(m13)
    ,m21(m21),m22(m22),m23(m23)
    ,m31(m31),m32(m32),m33(m33)
{
}

FMatrix_3x3::FMatrix_3x3(const FMatrix_4x4& in_matrix)
    :m11(in_matrix.m11),m12(in_matrix.m12),m13(in_matrix.m13)
    ,m21(in_matrix.m21),m22(in_matrix.m22),m23(in_matrix.m23)
    ,m31(in_matrix.m31),m32(in_matrix.m32),m33(in_matrix.m33)
{
}

f32 FMatrix_3x3::determinant()const
{
    return m11 * (m22 * m33 - m23 * m32)-
           m12 * (m21 * m33 - m23 * m31)+
           m13 * (m21 * m32 - m22 * m31);
}

void FMatrix_3x3::transpose()
{
    std::swap(m[0][1],m[1][0]);
    std::swap(m[0][2],m[2][0]);
    std::swap(m[1][2],m[2][1]);
}

FMatrix_3x3 FMatrix_3x3::to_transpose()const
{
    FMatrix_3x3 m=*this;
    m.transpose();
    return m;
}

FMatrix_3x3 FMatrix_3x3::inverse()const
{
    f32 d=determinant();
    assert (abs(d)>SMALL_NUMBER);
        return FMatrix_3x3(
        m22*m33-m32*m23,m31*m23-m21*m33,m21*m32-m31*m22,
        m32*m13-m12*m33,m11*m33-m31*m13,m31*m12-m11*m32,
        m12*m23-m22*m13,m21*m13-m11*m23,m11*m22-m21*m12
        )/d;
}
FMatrix_3x3 FMatrix_3x3::identity()
{
    return FMatrix_3x3(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
}

void FMatrix_3x3::inertia_to_object(const FRotator& in_rot)
{
}

void FMatrix_3x3::object_to_inertia(const FRotator& in_rot)
{
}
