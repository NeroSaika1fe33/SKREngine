#include "simple_math\FVector_2id.h"
#include <cstdio>

FVector_2id::FVector_2id()
    :x(0)
    ,y(0)
{
}

FVector_2id::FVector_2id(f32 x, f32 y)
    :x((f32)x)
    ,y((f32)y)
{
}

FVector_2id::FVector_2id(int32 x, int32 y)
    :x(x)
    ,y(y)
{
}

FVector_2id::FVector_2id(int32 value)
    :x(value)
    ,y(value)
{
}

int32 FVector_2id::dot(const FVector_2id& a, const FVector_2id& b)
{
    return a.x*b.x + a.y*b.y;
}

int32 FVector_2id::crossProduct(const FVector_2id& a, const FVector_2id& b)
{
    return a.x*b.y-a.y*b.x;
}

f32 FVector_2id::Length()const
{
    return sqrtf((f32)(x*x) + (f32)(y*y));
}

std::string FVector_2id::to_string() const 
{
    char Tmp[64];
    snprintf(Tmp, sizeof(Tmp), "(X=%d, Y=%d)", x, y);
    return std::string(Tmp);
}
