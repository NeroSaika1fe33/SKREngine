#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

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
    f32 determinant(const FMatrix_4x3& in_m);
    FMatrix_4x3& inverse();
    FMatrix_4x3& inverse(const FMatrix_4x3& in_m);
    
};
