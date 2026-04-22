#include "simple_math/transformation/Vector/vector_4d.h"
#include "simple_math/Transformation/Vector/vector_3d.h"
#include <cstdio>

FVector_4d::FVector_4d()
    :x(0.f)
    ,y(0.f)
    ,z(0.f)
    ,w(1.f)
{
}

FVector_4d::FVector_4d(f32 x, f32 y, f32 z,f32 w)
    :x(x)
    ,y(y)
    ,z(z)
    ,w(w)
{
}

FVector_4d::FVector_4d(f32 value)
    :x(value)
    ,y(value)
    ,z(value)
    ,w(value)
{
}

FVector_4d::FVector_4d(const FVector_3d& a)
    :x(a.x)
    ,y(a.y)
    ,z(a.z)
    ,w(1.f)
{
}

f32 FVector_4d::dot(const FVector_4d& a, const FVector_4d& b)
{
    return a.x*b.x + a.y*b.y+ a.z*b.z + a.w*b.w;
}

FVector_4d FVector_4d::crossProduct(const FVector_4d& a, const FVector_4d& b)
{
    return FVector_4d(
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x,
        0.0f);
}

f32 FVector_4d::Length()const
{
    return sqrtf(x*x + y*y + z*z + w*w);
}

f32 FVector_4d::Length3d()
{
    return sqrtf(x*x + y*y + z*z );
}

std::string FVector_4d::to_string() const 
{
    char Tmp[128];
    snprintf(Tmp, sizeof(Tmp), "(X=%.2f, Y=%.2f, Z=%.2f, W=%.2f)", x, y, z,w);
    return std::string(Tmp);
}

void FVector_4d::normalize()
{
    const f32 len = Length3d();
    w=0.f;
    if (len > SMALL_NUMBER)
        *this /= len;
}

