#include "simple_math/transformation/vector/vector_2d.h"
#include <cstdio>

FVector_2d::FVector_2d()
    :x(0.f)
    ,y(0.f)
{
}

FVector_2d::FVector_2d(f32 x, f32 y)
    :x(x)
    ,y(y)
{
}

FVector_2d::FVector_2d(f32 value)
    :x(value)
    ,y(value)
{
}

f32 FVector_2d::dot(const FVector_2d& a, const FVector_2d& b)
{
    return a.x*b.x + a.y*b.y;
}

f32 FVector_2d::crossProduct(const FVector_2d& a, const FVector_2d& b)
{
    return a.x*b.y-a.y*b.x;
}

f32 FVector_2d::Length()const
{
    return sqrtf(x*x + y*y);
}

std::string FVector_2d::to_string() const 
{
    char Tmp[64];
    snprintf(Tmp, sizeof(Tmp), "(X=%.2f, Y=%.2f)", x, y);
    return std::string(Tmp);
}

void FVector_2d::normalize()
{
    const f32 len = Length();
    if (len>SMALL_NUMBER)
        *this /= len;
}