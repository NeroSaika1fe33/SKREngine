#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"


struct SIMPLE_LIBRARY_API FVector_c
{
    f32 r;
    f32 g;
    f32 b;
    f32 a;

public:
    FVector_c();

    FVector_c(f32 in_value);

    FVector_c(f32 in_r, f32 in_g, f32 in_b = 0.f, f32 in_a = 1.f);
    
    FVector_c GetClamp(f32 min = 0.f, f32 max = 1.f)const;
    
    FVector_c Saturate()const;
    
    static FVector_c lerp(const FVector_c& A, const FVector_c& B, f32 alpha);
    
    static FVector_c TranslateHex(uint32 hex);
    
public:
    FVector_c operator+(const FVector_c& color) const 
    {
        return FVector_c(r + color.r, g + color.g, b + color.b, a); 
    }
    
    FVector_c operator-(const FVector_c& color) const
    {
        return FVector_c(r - color.r, g - color.g, b - color.b, a);
    }

    FVector_c operator*(const FVector_c& color) const 
    {
        return FVector_c(r * color.r, g * color.g, b * color.b, a * color.a);
    }

    FVector_c operator*(f32 k) const 
    {
        return FVector_c(r * k, g * k, b * k, a); 
    }
};