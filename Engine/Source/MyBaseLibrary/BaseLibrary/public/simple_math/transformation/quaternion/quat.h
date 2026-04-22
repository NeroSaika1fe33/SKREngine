#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

__declspec(align(16)) struct  BASE_LIBRARY_API FQuat
{
public:
    f32 x, y, z, w;
    
public:
    FQuat();
    FQuat(f32 in_x, f32 in_y, f32 in_z, f32 in_w);
    
    FQuat operator*(const FQuat& q) const;
    FQuat operator*=(const FQuat& q);
    FQuat operator*(const f32& q)const;
    FQuat operator*(const int32& q)const;
    
};
