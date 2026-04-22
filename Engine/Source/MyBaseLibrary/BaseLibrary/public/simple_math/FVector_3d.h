#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FVector_3d
{
    f32 x;
    f32 y;
    f32 z;
public:
    FVector_3d();
    FVector_3d(f32 x, f32 y, f32 z);
    FVector_3d(f32 Value);
    f32 Length() const;
    static f32 dot(const FVector_3d& a,const FVector_3d& b);
    static FVector_3d crossProduct(const FVector_3d& a,const FVector_3d& b);
    std::string to_string() const;
    void normalize();
public:
    FVector_3d operator+(const FVector_3d& a)const
    {
        return FVector_3d(x + a.x, y + a.y,z + a.z);
    }
    FVector_3d operator-(const FVector_3d& a)const
    {
        return FVector_3d(x - a.x, y - a.y,z - a.z);
    }
    FVector_3d operator*(const FVector_3d& a)const
    {
        return FVector_3d(x*a.x,y*a.y,z*a.z);
    }
    FVector_3d operator/(const FVector_3d& a)const
    {
        assert(a.x != 0.f);
        assert(a.y != 0.f);
        assert(a.z != 0.f);
        return FVector_3d(x/a.x,y/a.y,z/a.z);
    }
    bool operator>(const FVector_3d& a)const
    {
        return x>a.x && y>a.y && z>a.z;
    }
    bool operator<(const FVector_3d& a)const
    {
        return x<a.x && y<a.y && z<a.z;
    }
    bool operator>=(const FVector_3d& a)const
    {
        return x>=a.x && y>=a.y && z>=a.z;
    }
    bool operator<=(const FVector_3d& a)const
    {
        return x<=a.x && y<=a.y && z<=a.z;
    }
    bool operator==(const FVector_3d& a)const
    {
        return x==a.x && y==a.y && z==a.z;
    }
    bool operator!=(const FVector_3d& a)const
    {
        return !(*this==a);
    }
    bool IsNearlyEqual(const FVector_3d& a,f32 epsilon = 1.e-4f)const
    {
        return std::abs(x-a.x) < epsilon 
        && std::abs(y-a.y) < epsilon
        && std::abs(z-a.z) < epsilon;
    }
    FVector_3d& operator+=(const FVector_3d& a)
    {
        *this=*this+a;
        return *this;
    }
    FVector_3d& operator-=(const FVector_3d& a)
    {
        *this=*this-a;
        return *this;
    }
    FVector_3d& operator*=(const FVector_3d& a)
    {
        *this=*this*a;
        return *this;
    }
    FVector_3d& operator/=(const FVector_3d& a)
    {
        assert(a.x!=0.f);
        assert(a.y!=0.f);
        assert(a.z!=0.f);
        *this=*this/a;
        return *this;
    }
    FVector_3d operator*(f32 k)const
    {
        return FVector_3d(x*k,y*k,z*k);
    }
    FVector_3d operator/(f32 k)const
    {
        assert(k != 0.f);
        return FVector_3d(x/k,y/k,z/k);
    }
    FVector_3d& operator*=(f32 k)
    {
        *this=FVector_3d(x*k,y*k,z*k);
        return *this;
    }
    FVector_3d& operator/=(f32 k)
    {
        assert(k != 0.f);
        *this=*this/k;
        return *this;
    }
};