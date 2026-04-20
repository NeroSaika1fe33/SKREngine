#include "..\public\simple_math\FVector_2d.h"
#include <stdio.h>

FVector_2d::FVector_2d()
    :x(0.f)
    ,y(0.f)
{
}

FVector_2d::FVector_2d(f32 in_x, f32 in_y)
    :x(in_x)
    ,y(in_y)
{
}

FVector_2d::FVector_2d(f32 in_value)
    :x(in_value)
    ,y(in_value)
{
}

f32 FVector_2d::dot(const FVector_2d& in_a, const FVector_2d& in_b)
{
    return in_a.x*in_b.x + in_a.y*in_b.y;
}

f32 FVector_2d::crossProduct(const FVector_2d& in_a, const FVector_2d& in_b)
{
    return in_a.x*in_b.y-in_a.y*in_b.x;
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
    if (Length()>SMALL_NUMBER)
        *this /= Length();
}