#include "simple_math/transformation/matrix/matrix_4x4.h"
#include "simple_math/transformation/quaternion/quat.h"
#include "simple_math/transformation/vector/vector_3d.h"
#include "simple_math/transformation/matrix/matrix_3x3.h"

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

FMatrix_4x4::FMatrix_4x4(const FMatrix_4x4& in_matrix)
    :m11(in_matrix.m11),m12(in_matrix.m12),m13(in_matrix.m13),m14(in_matrix.m14)
    ,m21(in_matrix.m21),m22(in_matrix.m22),m23(in_matrix.m23),m24(in_matrix.m24)
    ,m31(in_matrix.m31),m32(in_matrix.m32),m33(in_matrix.m33),m34(in_matrix.m34)
    ,m41(in_matrix.m41),m42(in_matrix.m42),m43(in_matrix.m43),m44(in_matrix.m44)
{
}

FMatrix_4x4::FMatrix_4x4(const FMatrix_3x3& in_matrix)
    :m11(in_matrix.m11),m12(in_matrix.m12),m13(in_matrix.m13),m14(0.0f)
    ,m21(in_matrix.m21),m22(in_matrix.m22),m23(in_matrix.m23),m24(0.0f)
    ,m31(in_matrix.m31),m32(in_matrix.m32),m33(in_matrix.m33),m34(0.0f)
    ,m41(0.0f),m42(0.0f),m43(0.0f),m44(1.0f)
{
}

FMatrix_4x4& FMatrix_4x4::operator=(const FMatrix_3x3& a)
{
    m11 = a.m11; m12 = a.m12; m13 = a.m13; m14 = 0.0f;
    m21 = a.m21; m22 = a.m22; m23 = a.m23; m24 = 0.0f;
    m31 = a.m31; m32 = a.m32; m33 = a.m33; m34 = 0.0f;
    m41 = 0.0f;  m42 = 0.0f;  m43 = 0.0f;  m44 = 1.0f;
    
    return *this;
}

f32 FMatrix_4x4::determinant() const
{
    f32 m11_algebraic_cofactor = FMatrix_3x3(
        m22, m23, m24,
        m32, m33, m34,
        m42, m43, m44).determinant();
    f32 m12_algebraic_cofactor = FMatrix_3x3(
        m21, m23, m24,
        m31, m33, m34,
        m41, m43, m44).determinant();
    f32 m13_algebraic_cofactor = FMatrix_3x3(
        m21, m22, m24,
        m31, m32, m34,
        m41, m42, m44).determinant();
    f32 m14_algebraic_cofactor = FMatrix_3x3(
        m21, m22, m23,
        m31, m32, m33,
        m41, m42, m43).determinant();
    
    return  m11 * m11_algebraic_cofactor -
            m12 * m12_algebraic_cofactor +
            m13 * m13_algebraic_cofactor -
            m14 * m14_algebraic_cofactor;
}

void FMatrix_4x4::transpose()
{
    std::swap(m[0][1],m[1][0]);
    std::swap(m[0][2],m[2][0]);
    std::swap(m[0][3],m[3][0]);
    std::swap(m[1][2],m[2][1]);
    std::swap(m[1][3],m[3][1]);
    std::swap(m[2][3],m[3][2]);
}

FMatrix_4x4 FMatrix_4x4::to_transpose() const
{
    FMatrix_4x4 m=*this;
    m.transpose();
    return m;
}

FMatrix_4x4 FMatrix_4x4::inverse() const
{
    f32 aug[4][8];
    for (int32 i = 0; i < 4; i++) {
        for (int32 j = 0; j < 4; j++) {
            aug[i][j] = m[i][j];         
            aug[i][j + 4] = (i == j) ? 1.0f : 0.0f; 
        }
    }

    for (int32 i = 0; i < 4; i++) {
        if (std::abs(aug[i][i]) < SMALL_NUMBER) {
            for (int32 k = i + 1; k < 4; k++) {
                if (std::abs(aug[k][i]) > std::abs(aug[i][i])) {
                    for (int32 j = 0; j < 8; j++) std::swap(aug[i][j], aug[k][j]);
                    break;
                }
            }
        }

        assert(std::abs(aug[i][i]) > SMALL_NUMBER);

        f32 divisor = aug[i][i];
        for (int32 j = 0; j < 8; j++) {
            aug[i][j] /= divisor;
        }

        for (int32 k = 0; k < 4; k++) {
            if (k != i) {
                f32 multiplier = aug[k][i];
                for (int32 j = 0; j < 8; j++) {
                    aug[k][j] -= multiplier * aug[i][j];
                }
            }
        }
    }
    FMatrix_4x4 result;
    for (int32 i = 0; i < 4; i++) {
        for (int32 j = 0; j < 4; j++) {
            result.m[i][j] = aug[i][j + 4];
        }
    }
    return result;
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
    return FVector_3d(m41, m42, m43);
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

