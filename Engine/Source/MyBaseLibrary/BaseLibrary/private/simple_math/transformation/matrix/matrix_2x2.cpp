#include "simple_math/transformation/matrix/matrix_2x2.h"


FMatrix_2x2::FMatrix_2x2()
{
    *this = FMatrix_2x2::identity();
}

FMatrix_2x2::FMatrix_2x2(f32 in_m11, f32 in_m12, f32 in_m21, f32 in_m22)
    :m11(in_m11)
    ,m12(in_m12)
    ,m21(in_m21)
    ,m22(in_m22)
{
}

float FMatrix_2x2::determinant() const
{
    return m11*m22 - m12*m21;
}

FMatrix_2x2 FMatrix_2x2::identity()
{
    return FMatrix_2x2(1.f,0.f,
                       0.f,1.f);
}

FMatrix_2x2 FMatrix_2x2::inverse()const
{
    f32 d=determinant();
    assert(abs(d)>SMALL_NUMBER);
    return FMatrix_2x2(m22,-m12,
                       -m21,m11)/d;
    
    
}
