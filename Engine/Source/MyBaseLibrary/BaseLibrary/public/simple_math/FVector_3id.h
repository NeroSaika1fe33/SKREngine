#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FVector_3id
{
    int32 x;
    int32 y;
    int32 z;
public:
    FVector_3id();
    FVector_3id(int32 x, int32 y, int32 z);
    FVector_3id(f32 x, f32 y, f32 z);
    FVector_3id(int32 value);
    f32 Length()const;
    static int32 dot(const FVector_3id& a,const FVector_3id& b);
    static FVector_3id crossProduct(const FVector_3id& a,const FVector_3id& b);
    std::string to_string() const;
public:
    FVector_3id operator+(const FVector_3id& a)const
    {
        return FVector_3id(x+a.x,y+a.y,z+a.z);
    }
    FVector_3id operator-(const FVector_3id& a)const
    {
        return FVector_3id(x-a.x,y-a.y,z-a.z);
    }
    FVector_3id operator*(const FVector_3id& a)const
    {
        return FVector_3id(x*a.x,y*a.y,z*a.z);
    }
    FVector_3id operator/(const FVector_3id& a)const
    {
        assert(a.x!=0);
        assert(a.y!=0);
        assert(a.z!=0);
        return FVector_3id(x/a.x,y/a.y,z/a.z);
    }
    FVector_3id& operator+=(const FVector_3id& a)
    {
        *this=*this+a;
        return *this;
    }
    FVector_3id& operator-=(const FVector_3id& a)
    {
        *this=*this-a;
        return *this;
    }
    FVector_3id& operator*=(const FVector_3id& a)
    {
        *this=*this*a;
        return *this;
    }
    FVector_3id& operator/=(const FVector_3id& a)
    {
        assert(a.x!=0);
        assert(a.y!=0);
        assert(a.z!=0);
        *this=*this/a;
        return *this;
    }
    bool operator>(const FVector_3id& a)const
    {
        return x>a.x && y>a.y && z>a.z;
    }
    bool operator<(const FVector_3id& a)const
    {
        return x<a.x && y<a.y && z<a.z;
    }
    bool operator>=(const FVector_3id& a)const
    {
        return x>=a.x && y>=a.y && z>=a.z;
    }
    bool operator<=(const FVector_3id& a)const
    {
        return x<=a.x && y<=a.y && z<=a.z;
    }
    bool operator==(const FVector_3id& a)const
    {
        return x==a.x && y==a.y && z==a.z;
    }
    bool operator!=(const FVector_3id& a)const
    {
        return !(*this==a);
    }
    FVector_3id operator*(const f32 k)const
    {
        return FVector_3id((int32)((f32)x*k),(int32)((f32)y*k),(int32)((f32)z*k));
    }
    FVector_3id operator/(const f32 k)const
    {
        assert(k!=0.f);
        return FVector_3id((int32)((f32)x/k),(int32)((f32)y/k),(int32)((f32)z/k));
    }
    FVector_3id& operator*=(const f32 k)
    {
        *this=*this*k;
        return *this;
    }
    FVector_3id& operator/=(const f32 k)
    {
        assert(k!=0.f);
        *this=*this/k;
        return *this;
    }
};