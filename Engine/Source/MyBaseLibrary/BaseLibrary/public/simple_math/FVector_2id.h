#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FVector_2id
{
    int32 x;
    int32 y;
public:
    FVector_2id();
    FVector_2id(int32 x, int32 y);
    FVector_2id(f32 x, f32 y);
    FVector_2id(int32 value);
    f32 Length()const;
    static int32 dot(const FVector_2id& a,const FVector_2id& b);
    static int32 crossProduct(const FVector_2id& a,const FVector_2id& b);
    std::string to_string() const;
public:
    FVector_2id operator+(const FVector_2id& a)const
    {
        return FVector_2id(x+a.x,y+a.y);
    }
    FVector_2id operator-(const FVector_2id& a)const
    {
        return FVector_2id(x-a.x,y-a.y);
    }
    FVector_2id operator*(const FVector_2id& a)const
    {
        return FVector_2id(x*a.x,y*a.y);
    }
    FVector_2id operator/(const FVector_2id& a)const
    {
        assert(a.x!=0);
        assert(a.y!=0);
        return FVector_2id(x/a.x,y/a.y);
    }
    void operator+=(const FVector_2id& a)
    {
        *this=*this+a;
    }
    void operator-=(const FVector_2id& a)
    {
        *this=*this-a;
    }
    void operator*=(const FVector_2id& a)
    {
        *this=*this*a;
    }
    void operator/=(const FVector_2id& a)
    {
        assert(a.x!=0);
        assert(a.y!=0);
        *this=*this/a;
    }
    bool operator>(const FVector_2id& a)const
    {
        return x>a.x && y>a.y;
    }
    bool operator<(const FVector_2id& a)const
    {
        return x<a.x && y<a.y;
    }
    bool operator>=(const FVector_2id& a)const
    {
        return x>=a.x && y>=a.y;
    }
    bool operator<=(const FVector_2id& a)const
    {
        return x<=a.x && y<=a.y;
    }
    bool operator==(const FVector_2id& a)const
    {
        return x==a.x && y==a.y;
    }
    bool operator!=(const FVector_2id& a)const
    {
        return !(*this==a);
    }
    FVector_2id operator*(const f32 k)const
    {
        return FVector_2id((int32)((f32)x*k),(int32)((f32)y*k));
    }
    FVector_2id operator/(const f32 k)const
    {
        assert(k!=0.f);
        return FVector_2id((int32)((f32)x/k),(int32)((f32)y/k));
    }
    FVector_2id& operator*=(const f32 k)
    {
        *this=*this*k;
        return *this;
    }
    FVector_2id& operator/=(const f32 k)
    {
        assert(k!=0.f);
        *this=*this/k;
        return *this;
    }
};