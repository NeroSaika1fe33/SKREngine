#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FVector_2d
{
    f32 x;
    f32 y;
public:
    FVector_2d();
    FVector_2d(f32 x, f32 y);
    FVector_2d(f32 Value);
    f32 Length() const;
    static f32 dot(const FVector_2d& a,const FVector_2d& b);
    static f32 crossProduct(const FVector_2d& a,const FVector_2d& b);
    std::string to_string() const;
    void normalize();
public:
    FVector_2d operator+(const FVector_2d& a)const
    {
        return FVector_2d(x + a.x, y + a.y);
    }
    FVector_2d operator-(const FVector_2d& a)const
    {
        return FVector_2d(x - a.x, y - a.y);
    }
    FVector_2d operator*(const FVector_2d& a)const
    {
        return FVector_2d(x*a.x,y*a.y);
    }
    FVector_2d operator/(const FVector_2d& a)const
    {
        assert(abs(a.x)>SMALL_NUMBER);
        assert(abs(a.y)>SMALL_NUMBER);
        return FVector_2d(x/a.x,y/a.y);
    }
    bool operator>(const FVector_2d& a)const
    {
        return x>a.x && y>a.y;
    }
    bool operator<(const FVector_2d& a)const
    {
        return x<a.x && y<a.y;
    }
    bool operator>=(const FVector_2d& a)const
    {
        return x>=a.x && y>=a.y;
    }
    bool operator<=(const FVector_2d& a)const
    {
        return x<=a.x && y<=a.y;
    }
    bool operator==(const FVector_2d& a)const
    {
        return x==a.x && y==a.y;
    }
    bool operator!=(const FVector_2d& a)const
    {
        return !(*this==a);
    }
    bool IsNearlyEqual(const FVector_2d& a,f32 epsilon = 1.e-4f)const
    {
        return std::abs(x-a.x) < epsilon && std::abs(y-a.y) < epsilon;
    }
    FVector_2d& operator+=(const FVector_2d& a)
    {
        *this=*this+a;
        return *this;
    }
    FVector_2d& operator-=(const FVector_2d& a)
    {
        *this=*this-a;
        return *this;
    }
    FVector_2d& operator*=(const FVector_2d& a)
    {
        *this=*this*a;
        return *this;
    }
    FVector_2d& operator/=(const FVector_2d& a)
    {
        assert(abs(a.x)>SMALL_NUMBER);
        assert(abs(a.y)>SMALL_NUMBER);
        *this=*this/a;
        return *this;
    }
    FVector_2d operator*(f32 k)const
    {
        return FVector_2d(x*k,y*k);
    }
    FVector_2d operator/(f32 k)const
    {
        assert(abs(k)>SMALL_NUMBER);
        return FVector_2d(x/k,y/k);
    }
    FVector_2d& operator*=(f32 k)
    {
        *this=FVector_2d(x*k,y*k);
        return *this;
    }
    FVector_2d& operator/=(f32 k)
    {
        assert(abs(k)>SMALL_NUMBER);
        *this=*this/k;
        return *this;
    }
};