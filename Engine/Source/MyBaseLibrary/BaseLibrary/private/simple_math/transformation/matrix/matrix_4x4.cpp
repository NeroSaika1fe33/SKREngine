#include "simple_math/transformation/matrix/matrix_4x4.h"
#include "simple_math/transformation/quaternion/quat.h"
#include "simple_math/transformation/vector/vector_3d.h"

FMatrix_4x4::FMatrix_4x4()
{
    *this=FMatrix_4x4::identity();
}

FMatrix_4x4::FMatrix_4x4(
    f32 m11,f32 m12,f32 m13,f32 m14,    
    f32 m21,f32 m22,f32 m23,f32 m24,
    f32 m31,f32 m32,f32 m33,f32 m34,
    f32 m41,f32 m42,f32 m43,f32 m44)
    :m11(m11),m12(m12),m13(m13),m14(m14)
    ,m21(m21),m22(m22),m23(m23),m24(m24)
    ,m31(m31),m32(m32),m33(m33),m34(m34)
    ,m41(m41),m42(m42),m43(m43),m44(m44)
{
    
}

FMatrix_4x4::FMatrix_4x4(const FMatrix_4x4& a)
{
}

FMatrix_4x4::FMatrix_4x4(const FMatrix_3x3& a)
{
}

FMatrix_4x4& FMatrix_4x4::operator=(const FMatrix_3x3& a)
{
}

f32 FMatrix_4x4::determinant() const
{
}

void FMatrix_4x4::transpose()
{
}

FMatrix_4x4 FMatrix_4x4::to_transpose() const
{
}

FMatrix_4x4 FMatrix_4x4::inverse() const
{
}

FMatrix_4x4 FMatrix_4x4::identity()
{
    return FMatrix_4x4(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f);
}

FVector_3d FMatrix_4x4::get_translation()
{
}

FQuat FMatrix_4x4::get_quat() const
{
}

void FMatrix_4x4::inertia_to_object(const FRotator& in_rot)
{
}

void FMatrix_4x4::object_to_inertia(const FRotator& in_rot)
{
}

