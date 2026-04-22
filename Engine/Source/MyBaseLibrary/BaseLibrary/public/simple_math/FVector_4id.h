#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"
#include "simple_math/FVector_3id.h"

struct FVector_3id;
struct BASE_LIBRARY_API FVector_4id
{
    int32 x;
    int32 y;
    int32 z;
    int32 w;
public:
    FVector_4id();
    FVector_4id(int32 x, int32 y, int32 z, int32 w);
    FVector_4id(f32 x, f32 y, f32 z,f32 w);
    FVector_4id(const FVector_3id& a);
    FVector_4id(int32 value);
    f32 Length()const;
    f32 Length3id()const;
    static int32 dot(const FVector_4id& a,const FVector_4id& b);
    static FVector_4id crossProduct(const FVector_4id& a,const FVector_4id& b);
    std::string to_string() const;
public:
    FVector_4id operator+(const FVector_4id& a)const
    {
        return FVector_4id(x+a.x,y+a.y,z+a.z,w+a.w);
    }
    FVector_4id operator-(const FVector_4id& a)const
    {
        return FVector_4id(x-a.x,y-a.y,z-a.z,w-a.w);
    }
    FVector_4id operator*(const FVector_4id& a)const
    {
        return FVector_4id(x*a.x,y*a.y,z*a.z,w*a.w);
    }
    FVector_4id operator/(const FVector_4id& a)const
    {
        assert(a.x!=0);
        assert(a.y!=0);
        assert(a.z!=0);
        return FVector_4id(x/a.x,y/a.y,z/a.z,w/a.w);
    }
    FVector_4id& operator+=(const FVector_4id& a)
    {
        *this=*this+a;
        return *this;
    }
    FVector_4id& operator-=(const FVector_4id& a)
    {
        *this=*this-a;
        return *this;
    }
    FVector_4id& operator*=(const FVector_4id& a)
    {
        *this=*this*a;
        return *this;
    }
    FVector_4id& operator/=(const FVector_4id& a)
    {
        assert(a.x!=0);
        assert(a.y!=0);
        assert(a.z!=0);
        *this=*this/a;
        return *this;
    }
    bool operator>(const FVector_4id& a)const
    {
        return x>a.x && y>a.y && z>a.z && w>a.w;
    }
    bool operator<(const FVector_4id& a)const
    {
        return x<a.x && y<a.y && z<a.z && w<a.w;
    }
    bool operator>=(const FVector_4id& a)const
    {
        return x>=a.x && y>=a.y && z>=a.z && w>=a.w;
    }
    bool operator<=(const FVector_4id& a)const
    {
        return x<=a.x && y<=a.y && z<=a.z && w<=a.w;
    }
    bool operator==(const FVector_4id& a)const
    {
        return x==a.x && y==a.y && z==a.z && w==a.w;
    }
    bool operator!=(const FVector_4id& a)const
    {
        return !(*this==a);
    }
    FVector_4id operator*(const f32 k)const
    {
        return FVector_4id((int32)((f32)x*k),(int32)((f32)y*k),(int32)((f32)z*k),(int32)((f32)w*k));
    }
    FVector_4id operator/(const f32 k)const
    {
        assert(k!=0.f);
        return FVector_4id((int32)((f32)x/k),(int32)((f32)y/k),(int32)((f32)z/k),(int32)((f32)w/k));
    }
    FVector_4id& operator*=(const f32 k)
    {
        *this=*this*k;
        return *this;
    }
    FVector_4id& operator/=(const f32 k)
    {
        assert(k!=0.f);
        *this=*this/k;
        return *this;
    }
};