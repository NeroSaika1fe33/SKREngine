#include "simple_math/transformation/Vector/vector_3id.h"
#include <cstdio>

FVector_3id::FVector_3id()
    :x(0)
    ,y(0)
    ,z(0)
{
}

FVector_3id::FVector_3id(f32 x, f32 y, f32 z)
    :x((f32)x)
    ,y((f32)y)
    ,z((f32)z)
{
}

FVector_3id::FVector_3id(int32 x, int32 y, int32 z)
    :x(x)
    ,y(y)
    ,z(z)
{
}

FVector_3id::FVector_3id(int32 value)
    :x(value)
    ,y(value)
    ,z(value)
{
}

int32 FVector_3id::dot(const FVector_3id& a, const FVector_3id& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

FVector_3id FVector_3id::crossProduct(const FVector_3id& a, const FVector_3id& b)
{
    return FVector_3id(
    a.y*b.z - a.z*b.y,
    a.z*b.x - a.x*b.z,
    a.x*b.y - a.y*b.x);
}

f32 FVector_3id::Length()const
{
    return sqrtf((f32)(x*x) + (f32)(y*y) + (f32)(z*z));
}

std::string FVector_3id::to_string() const 
{
    char Tmp[64];
    snprintf(Tmp, sizeof(Tmp), "(X=%d, Y=%d,Z=%d)", x, y, z);
    return std::string(Tmp);
}