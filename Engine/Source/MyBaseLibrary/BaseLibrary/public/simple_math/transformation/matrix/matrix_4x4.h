#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FMatrix_3x3;
struct FRotator;
struct FQuat;
struct FVector_3d;

struct BASE_LIBRARY_API FMatrix_4x4
{
    union 
    {
        struct
        {
            f32 m11, m12, m13, m14;
            f32 m21, m22, m23, m24;
            f32 m31, m32, m33, m34;
            f32 m41, m42, m43, m44;
        };
        f32 m[4][4];
        f32 m_array[16];
    };
    
public:
    FMatrix_4x4();
    FMatrix_4x4(
        f32 m11,f32 m12,f32 m13,f32 m14,    
        f32 m21,f32 m22,f32 m23,f32 m24,
        f32 m31,f32 m32,f32 m33,f32 m34,
        f32 m41,f32 m42,f32 m43,f32 m44    
    );
    
    FMatrix_4x4(const FMatrix_4x4& a);
    FMatrix_4x4(const FMatrix_3x3& a);
    
    FMatrix_4x4& operator=(const FMatrix_3x3& a);
    
public:
    f32 determinant()const;
    
    void transpose();
    
    FMatrix_4x4 to_transpose()const;
    
    FMatrix_4x4 inverse()const;
    
    static FMatrix_4x4 identity();

    FVector_3d get_translation();
    
    FQuat get_quat()const;
    
public:
    FMatrix_4x4 operator+(const FMatrix_4x4& a)const
    {
        return FMatrix_4x4(
            m11+a.m11, m12+a.m12, m13+a.m13, m14+a.m14,
            m21+a.m21, m22+a.m22, m23+a.m23, m24+a.m24,
            m31+a.m31, m32+a.m32, m33+a.m33, m34+a.m34,
            m41+a.m41, m42+a.m42, m43+a.m43, m44+a.m44);
    }
    
    FMatrix_4x4 operator-(const FMatrix_4x4& a)const
    {
        return FMatrix_4x4(
            m11-a.m11, m12-a.m12, m13-a.m13, m14-a.m14,    
            m21-a.m21, m22-a.m22, m23-a.m23, m24-a.m24,
            m31-a.m31, m32-a.m32, m33-a.m33, m34-a.m34,
            m41-a.m41, m42-a.m42, m43-a.m43, m44-a.m44);
    }
    
    FMatrix_4x4 operator*(const FMatrix_4x4& a)const
    {
        return FMatrix_4x4(
            m11 * a.m11 + m12 * a.m21 + m13 * a.m31 + m14 * a.m41,
            m11 * a.m12 + m12 * a.m22 + m13 * a.m32 + m14 * a.m42,
            m11 * a.m13 + m12 * a.m23 + m13 * a.m33 + m14 * a.m43,
            m11 * a.m14 + m12 * a.m24 + m13 * a.m34 + m14 * a.m44,
        
            m21 * a.m11 + m22 * a.m21 + m23 * a.m31 + m24 * a.m41,
            m21 * a.m12 + m22 * a.m22 + m23 * a.m32 + m24 * a.m42,
            m21 * a.m13 + m22 * a.m23 + m23 * a.m33 + m24 * a.m43,
            m21 * a.m14 + m22 * a.m24 + m23 * a.m34 + m24 * a.m44,
        
            m31 * a.m11 + m32 * a.m21 + m33 * a.m31 + m34 * a.m41,
            m31 * a.m12 + m32 * a.m22 + m33 * a.m32 + m34 * a.m42,
            m31 * a.m13 + m32 * a.m23 + m33 * a.m33 + m34 * a.m43,
            m31 * a.m14 + m32 * a.m24 + m33 * a.m34 + m34 * a.m44,
        
            m41 * a.m11 + m42 * a.m21 + m43 * a.m31 + m44 * a.m41,
            m41 * a.m12 + m42 * a.m22 + m43 * a.m32 + m44 * a.m42,
            m41 * a.m13 + m42 * a.m23 + m43 * a.m33 + m44 * a.m43,
            m41 * a.m14 + m42 * a.m24 + m43 * a.m34 + m44 * a.m44);
    }
    
    FMatrix_4x4& operator+=(const FMatrix_4x4& a)
    {
        *this = *this + a;
        return *this;
    }
    
    FMatrix_4x4& operator-=(const FMatrix_4x4& a)
    {
        *this = *this - a;
        return *this;
    }
    
    FMatrix_4x4& operator*=(const FMatrix_4x4& a)
    {
        *this = *this * a;
        return *this;
    }
    
    FMatrix_4x4 operator+(f32 k)const
    {
        return FMatrix_4x4(
            m11+k, m12+k, m13+k, m14+k,
            m21+k, m22+k, m23+k, m24+k,
            m31+k, m32+k, m33+k, m34+k,
            m41+k, m42+k, m43+k, m44+k);
    }
    
    FMatrix_4x4 operator-(f32 k)const
    {
        return FMatrix_4x4(
            m11-k, m12-k, m13-k, m14-k,
            m21-k, m22-k, m23-k, m24-k,
            m31-k, m32-k, m33-k, m34-k,
            m41-k, m42-k, m43-k, m44-k);
    }
    
    FMatrix_4x4 operator*(f32 k)const
    {
        return FMatrix_4x4(
            m11*k, m12*k, m13*k, m14*k,
            m21*k, m22*k, m23*k, m24*k,
            m31*k, m32*k, m33*k, m34*k,
            m41*k, m42*k, m43*k, m44*k);
    }
    
    FMatrix_4x4 operator/(f32 k)const
    {
        assert(abs(k)>SMALL_NUMBER);
        return FMatrix_4x4(
            m11/k, m12/k, m13/k, m14/k,
            m21/k, m22/k, m23/k, m24/k,
            m31/k, m32/k, m33/k, m34/k,
            m41/k, m42/k, m43/k, m44/k);
    }
    
    FMatrix_4x4& operator+=(f32 k)
    {
        *this = *this + k;
        return *this;
    }
    
    FMatrix_4x4& operator-=(f32 k)
    {
        *this = *this - k;
        return *this;
    }
    
    FMatrix_4x4& operator*=(f32 k)
    {
        *this = *this * k;
        return *this;
    }
    
    FMatrix_4x4& operator/=(f32 k)
    {
        assert(abs(k)>SMALL_NUMBER);
        *this = *this / k;
        return *this;
    }
    
public:
    void inertia_to_object(const FRotator& in_rot);
    void object_to_inertia(const FRotator& in_rot);

};
