#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FMatrix_4x4;
struct FRotator;

struct BASE_LIBRARY_API FMatrix_3x3
{
    union 
    {
        struct
        {
            f32 m11, m12, m13;
            f32 m21, m22, m23;
            f32 m31, m32, m33;
        };
        f32 m[3][3];
        f32 m_array[9];
    };

public:
    FMatrix_3x3();
    FMatrix_3x3(
        f32 m11,f32 m12,f32 m13,
        f32 m21,f32 m22,f32 m23,
        f32 m31,f32 m32,f32 m33);
    FMatrix_3x3(const FMatrix_4x4& in_matrix);
    f32 determinant()const;
    void transpose();
    FMatrix_3x3 to_transpose()const;
    FMatrix_3x3 inverse()const;
    static FMatrix_3x3 identity();
    
public:    
    FMatrix_3x3 operator+(const FMatrix_3x3& a)const
    {
        return FMatrix_3x3(
            m11+a.m11,m12+a.m12,m13+a.m13,
            m21+a.m21,m22+a.m22,m23+a.m23,
            m31+a.m31,m32+a.m32,m33+a.m33);
    }
    
    FMatrix_3x3 operator-(const FMatrix_3x3& a)const
    {
        return FMatrix_3x3(
            m11-a.m11,m12-a.m12,m13-a.m13,
            m21-a.m21,m22-a.m22,m23-a.m23,
            m31-a.m31,m32-a.m32,m33-a.m33);
    }
    
    FMatrix_3x3 operator*(const FMatrix_3x3& a)const
    {
        return FMatrix_3x3(
            m11*a.m11+m12*a.m21+m13*a.m31,
            m11*a.m12+m12*a.m22+m13*a.m32,
            m11*a.m13+m12*a.m23+m13*a.m33,
            
            m21*a.m11+m22*a.m21+m23*a.m31,
            m21*a.m12+m22*a.m22+m23*a.m32,
            m21*a.m13+m22*a.m23+m23*a.m33,
            
            m31*a.m11+m32*a.m21+m33*a.m31,
            m31*a.m12+m32*a.m22+m33*a.m32,
            m31*a.m13+m32*a.m23+m33*a.m33);
    }
    
    FMatrix_3x3& operator+=(const FMatrix_3x3& a)
    {
        *this = *this + a;
        return *this;
    }
    
    FMatrix_3x3& operator-=(const FMatrix_3x3& a)
    {
        *this = *this - a;
        return *this;
    }
    
    FMatrix_3x3& operator*=(const FMatrix_3x3& a)
    {
        *this = *this * a;
        return *this;
    }
    
    FMatrix_3x3 operator+(f32 k)const
    {
        return FMatrix_3x3(
            m11+k,m12+k,m13+k,
            m21+k,m22+k,m23+k,
            m31+k,m32+k,m33+k);
    }
    
    FMatrix_3x3 operator-(f32 k)const
    {
        return FMatrix_3x3(
            m11-k,m12-k,m13-k,
            m21-k,m22-k,m23-k,
            m21-k,m22-k,m23-k);
    }
    
    FMatrix_3x3 operator*(f32 k)const
    {
        return FMatrix_3x3(
            m11*k,m12*k,m13*k,
            m21*k,m22*k,m23*k,
            m21*k,m22*k,m23*k);
    }
    
    FMatrix_3x3 operator/(f32 k)const
    {
        assert(abs(k)>0.f);
        return FMatrix_3x3(
            m11/k,m12/k,m13/k,
            m21/k,m22/k,m23/k,
            m31/k,m32/k,m33/k);
    }
    
    FMatrix_3x3& operator+=(f32 k)
    {
        *this = *this + k;
        return *this;
    }
    
    FMatrix_3x3& operator-=(f32 k)
    {
        *this = *this - k;
        return *this;
    }
    
    FMatrix_3x3& operator*=(f32 k)
    {
        *this = *this * k;
        return *this;
    }
    
    FMatrix_3x3 operator/=(f32 k)
    {
        assert(abs(k)>SMALL_NUMBER);
        *this = *this / k;
        return *this;
    }
    
public:
    void inertia_to_object(const FRotator& in_rot);
    void object_to_inertia(const FRotator& in_rot);
};
