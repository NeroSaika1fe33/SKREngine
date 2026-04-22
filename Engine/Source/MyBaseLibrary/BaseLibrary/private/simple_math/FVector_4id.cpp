#include "simple_math\FVector_4id.h"
#include "simple_math\FVector_3id.h"
#include <cstdio>

FVector_4id::FVector_4id()
    :x(0)
    ,y(0)
    ,z(0)
    ,w(1)
{
}

FVector_4id::FVector_4id(f32 x, f32 y, f32 z, f32 w)
    :x((f32)x)
    ,y((f32)y)
    ,z((f32)z)
    ,w((f32)w)
{
}

FVector_4id::FVector_4id(int32 x, int32 y, int32 z,int32 w)
    :x(x)
    ,y(y)
    ,z(z)
    ,w(w)
{
}

FVector_4id::FVector_4id(const FVector_3id& a)
    :x(a.x)
    ,y(a.y)
    ,z(a.z)
    ,w(1)
{
    
}

FVector_4id::FVector_4id(int32 value)
    :x(value)
    ,y(value)
    ,z(value)
    ,w(value)
{
}

int32 FVector_4id::dot(const FVector_4id& a, const FVector_4id& b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

FVector_4id FVector_4id::crossProduct(const FVector_4id& a, const FVector_4id& b)
{
    return FVector_4id(
    a.y*b.z - a.z*b.y,
    a.z*b.x - a.x*b.z,
    a.x*b.y - a.y*b.x,
    0);
}

f32 FVector_4id::Length()const
{
    return sqrtf((f32)(x*x) + (f32)(y*y) + (f32)(z*z) + (f32)(w*w));
}

f32 FVector_4id::Length3id()const
{
    return sqrt((f32)(x*x) + (f32)(y*y) + (f32)(z*z));
}

std::string FVector_4id::to_string() const 
{
    char Tmp[128];
    snprintf(Tmp, sizeof(Tmp), "(X=%d, Y=%d, Z=%d, W=%d)", x, y, z, w);
    return std::string(Tmp);
}