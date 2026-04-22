#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FVector_3d;
struct BASE_LIBRARY_API FVector_4d
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
public:
    FVector_4d();
    FVector_4d(f32 x, f32 y, f32 z,f32 w);
    FVector_4d(f32 Value);
    FVector_4d(const FVector_3d& a);
    f32 Length() const;
    f32 Length3d();
    static f32 dot(const FVector_4d& a,const FVector_4d& b);
    static FVector_4d crossProduct(const FVector_4d& a,const FVector_4d& b);
    std::string to_string() const;
    void normalize();
public:
    FVector_4d operator+(const FVector_4d& a)const
    {
        return FVector_4d(x + a.x, y + a.y,z + a.z,w + a.w);
    }
    FVector_4d operator-(const FVector_4d& a)const
    {
        return FVector_4d(x - a.x, y - a.y,z - a.z,w - a.w);
    }
    FVector_4d operator*(const FVector_4d& a)const
    {
        return FVector_4d(x*a.x,y*a.y,z*a.z,w*a.w);
    }
    FVector_4d operator/(const FVector_4d& a)const
    {
        assert(abs(a.x)>SMALL_NUMBER);
        assert(abs(a.y)>SMALL_NUMBER);
        assert(abs(a.z)>SMALL_NUMBER);

        return FVector_4d(x/a.x,y/a.y,z/a.z,w/a.w);
    }
    bool operator>(const FVector_4d& a)const
    {
        return x>a.x && y>a.y && z>a.z && w>a.w;
    }
    bool operator<(const FVector_4d& a)const
    {
        return x<a.x && y<a.y && z<a.z && w<a.w;
    }
    bool operator>=(const FVector_4d& a)const
    {
        return x>=a.x && y>=a.y && z>=a.z && w>=a.w;
    }
    bool operator<=(const FVector_4d& a)const
    {
        return x<=a.x && y<=a.y && z<=a.z && w<=a.w;
    }
    bool operator==(const FVector_4d& a)const
    {
        return x==a.x && y==a.y && z==a.z && w==a.w;
    }
    bool operator!=(const FVector_4d& a)const
    {
        return !(*this==a);
    }
    bool IsNearlyEqual(const FVector_4d& a,f32 epsilon = 1.e-4f)const
    {
        return std::abs(x-a.x) < epsilon 
        && std::abs(y-a.y) < epsilon
        && std::abs(z-a.z) < epsilon
        && std::abs(w-a.w) < epsilon;
    }
    FVector_4d& operator+=(const FVector_4d& a)
    {
        *this=*this+a;
        return *this;
    }
    FVector_4d& operator-=(const FVector_4d& a)
    {
        *this=*this-a;
        return *this;
    }
    FVector_4d& operator*=(const FVector_4d& a)
    {
        *this=*this*a;
        return *this;
    }
    FVector_4d& operator/=(const FVector_4d& a)
    {
        assert(abs(a.x)>SMALL_NUMBER);
        assert(abs(a.y)>SMALL_NUMBER);
        assert(abs(a.z)>SMALL_NUMBER);
        *this=*this/a;
        return *this;
    }
    FVector_4d operator*(f32 k)const
    {
        return FVector_4d(x*k,y*k,z*k,w*k);
    }
    FVector_4d operator/(f32 k)const
    {
        assert(abs(k)>SMALL_NUMBER);
        return FVector_4d(x/k,y/k,z/k,w/k);
    }
    FVector_4d& operator*=(f32 k)
    {
        *this=FVector_4d(x*k,y*k,z*k,w*k);
        return *this;
    }
    FVector_4d& operator/=(f32 k)
    {
        assert(abs(k)>SMALL_NUMBER);
        *this=*this/k;
        return *this;
    }
};