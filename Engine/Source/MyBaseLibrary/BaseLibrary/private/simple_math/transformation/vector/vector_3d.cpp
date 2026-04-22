#include "simple_math/transformation/vector/vector_3d.h"
#include <cstdio>

FVector_3d::FVector_3d()
    :x(0.f)
    ,y(0.f)
    ,z(0.f)
{
}

FVector_3d::FVector_3d(f32 x, f32 y, f32 z)
    :x(x)
    ,y(y)
    ,z(z)
{
}

FVector_3d::FVector_3d(f32 value)
    :x(value)
    ,y(value)
    ,z(value)
{
}

f32 FVector_3d::dot(const FVector_3d& a, const FVector_3d& b)
{
    return a.x*b.x + a.y*b.y+ a.z*b.z;
}

FVector_3d FVector_3d::crossProduct(const FVector_3d& a, const FVector_3d& b)
{
    return FVector_3d(
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x);
}

f32 FVector_3d::Length()const
{
    return sqrtf(x*x + y*y + z*z);
}

std::string FVector_3d::to_string() const 
{
    char Tmp[64];
    snprintf(Tmp, sizeof(Tmp), "(X=%.2f, Y=%.2f,Z=%.2f)", x, y, z);
    return std::string(Tmp);
}

void FVector_3d::normalize()
{
    const f32 len = Length();
    if (len > SMALL_NUMBER)
        *this /= len;
}