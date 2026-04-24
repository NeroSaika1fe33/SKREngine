#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"
#include "simple_math/Transformation/vector/vector_3d.h"

struct FRotator;
struct FMatrix_4x4;

struct BASE_LIBRARY_API FMatrix_4x3
{
    union 
    {
        struct
        {
            f32 m11, m12, m13;
            f32 m21, m22, m23;
            f32 m31, m32, m33;
            f32 x, y, z;
        };
        f32 m[4][3];
        f32 m_array[12];
    };
    
public:
    FMatrix_4x3();
    FMatrix_4x3(const FMatrix_4x4& in_matrix);
    FMatrix_4x3(
        f32 m11,f32 m12,f32 m13,
        f32 m21,f32 m22,f32 m23,
        f32 m31,f32 m32,f32 m33,
        f32 x,f32 y,f32 z);
    
    void identity();
    f32 determinant();
    f32 determinant(const FMatrix_4x3& in_m)const;
    FMatrix_4x3 inversion()const;
    FMatrix_4x3 inversion(const FMatrix_4x3& in_m)const;
    
    FVector_3d operator*(const FVector_3d& a)const
    {
        return FVector_3d(
            a.x*m11 + a.y*m21 + a.z*m31+x,
            a.x*m12 + a.y*m22 + a.z*m32+y,
            a.x*m13 + a.y*m23 + a.z*m33+z        
        );
    }
    
    bool FMatrix_4x3::operator==(const FMatrix_4x3& a) const
    {
        for (int32 i = 0; i < 12; ++i)
        {
            if (std::abs(m_array[i] - a.m_array[i]) > SMALL_NUMBER)
            {
                return false;
            }
        }
        return true;
    }
};
