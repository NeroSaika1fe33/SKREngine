#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FMatrix_2x2
{
    union 
    {
        struct 
        {
            f32 m11, m12;
            f32 m21, m22;
        };
        f32 m[2][2];
        f32 m_array[4];
    };

public:
    FMatrix_2x2();
    FMatrix_2x2(
    f32 in_m11,    
    f32 in_m12,
    f32 in_m21,
    f32 in_m22);
    
    f32 determinant()const;
    FMatrix_2x2 inverse() const;
    static FMatrix_2x2 identity();
public:
    FMatrix_2x2 operator+(const FMatrix_2x2& a)const
    {
        return FMatrix_2x2(
        m11+a.m11,    
        m12+a.m12,
        m21+a.m21,
        m22+a.m22);
    }
    
    FMatrix_2x2 operator-(const FMatrix_2x2& a)const
    {
        return FMatrix_2x2(
        m11-a.m11,    
        m12-a.m12,
        m21-a.m21,
        m22-a.m22
        );
    }
    
    FMatrix_2x2 operator*(const FMatrix_2x2& a)const
    {
        return FMatrix_2x2(
        m11*a.m11+m12*a.m21,
        m11*a.m12+m12*a.m22,
        m21*a.m11+m22*a.m21,
        m21*a.m12+m22*a.m22
        );
    }
    
    FMatrix_2x2& operator+=(const FMatrix_2x2& a)
    {
        *this=*this+a;
        return *this;
    }
    
    FMatrix_2x2& operator-=(const FMatrix_2x2& a)
    {
        *this=*this-a;
        return *this;
    }
    
    FMatrix_2x2& operator*=(const FMatrix_2x2& a)
    {
        *this=*this*a;
        return *this;
    }
    
    FMatrix_2x2 operator+(const f32 k)const
    {
        return FMatrix_2x2(m11+k,m12+k,m21+k,m22+k);
    }
    
    FMatrix_2x2 operator-(const f32 k)const
    {
        return FMatrix_2x2(m11-k,m12-k,m21-k,m22-k);
    }
    
    FMatrix_2x2 operator*(const f32 k)const
    {
        return FMatrix_2x2(m11*k,m12*k,m21*k,m22*k);
    }
    
    FMatrix_2x2 operator/(const f32 k)const
    {
        assert(abs(k)>SMALL_NUMBER);
        return FMatrix_2x2(m11/k,m12/k,m21/k,m22/k);
    }
    
    FMatrix_2x2& operator+=(const f32 k)
    {
        *this=*this+k;
        return *this;
    }
    
    FMatrix_2x2& operator-=(const f32 k)
    {
        *this=*this-k;
        return *this;
    }
    
    FMatrix_2x2& operator*=(const f32 k)
    {
        *this=*this*k;
        return *this;
    }
    
    FMatrix_2x2& operator/=(const f32 k)
    {
        assert(std::abs(k)>SMALL_NUMBER);
        *this=*this/k;
        return *this;
    }
    
    bool FMatrix_2x2::operator==(const FMatrix_2x2& a) const
    {
        for (int32 i = 0; i < 4; ++i)
        {
            if (std::abs(m_array[i] - a.m_array[i]) > SMALL_NUMBER)
            {
                return false;
            }
        }
        return true;
    }
};
