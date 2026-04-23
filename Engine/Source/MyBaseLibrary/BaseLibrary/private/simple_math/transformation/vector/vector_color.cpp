#include "simple_math/Transformation/Vector/vector_color.h"
#include "simple_math/simple_core_math.h"

FVector_c::FVector_c()
    :r(0.f)
    ,g(0.f)
    ,b(0.f)
    ,a(1.f)
{
}

FVector_c::FVector_c(f32 in_value)
    :r(in_value)
    ,g(in_value)
    ,b(in_value)
    ,a(1.f)
{
}

FVector_c::FVector_c(f32 in_r, f32 in_g, f32 in_b, f32 in_a)
    :r(in_r)
    ,g(in_g)
    ,b(in_b)
    ,a(in_a)
{
}

FVector_c FVector_c::GetClamp(f32 min , f32 max )const
{
    return FVector_c(
    math_libray::Clamp(r,min,max),
    math_libray::Clamp(g,min,max),  
    math_libray::Clamp(b,min,max),
    math_libray::Clamp(a,min,max)
    );
}

FVector_c FVector_c::lerp(const FVector_c& A, const FVector_c& B, f32 alpha)
{
    return FVector_c(
    math_libray::Lerp(A.r,B.r,alpha),
    math_libray::Lerp(A.g,B.g,alpha),
    math_libray::Lerp(A.b,B.b,alpha),
    math_libray::Lerp(A.a,B.a,alpha)    
    );
}

FVector_c FVector_c::Saturate()const
{
    return GetClamp(0.f,1.f);
}

FVector_c FVector_c::TranslateHex(uint32 hex)
{
    return FVector_c(
        ((hex >> 24) & 0xFF) / 255.f, // R
        ((hex >> 16) & 0xFF) / 255.f, // G
        ((hex >> 8)  & 0xFF) / 255.f, // B
        (hex & 0xFF)         / 255.f  // A
    );
}