#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct BASE_LIBRARY_API FVector_2d
{
    f32 x;
    f32 y;
public:
    FVector_2d();
    FVector_2d(f32 in_x, f32 in_y);
    FVector_2d(f32 in_Value);
    f32 Length() const;
    static f32 dot(const FVector_2d& in_a,const FVector_2d& in_b);
    static f32 crossProduct(const FVector_2d& in_a,const FVector_2d& in_b);
    std::string to_string() const
    void normalize();
public:
    FVector_2d operator+(const FVector_2d& in_a)const
    {
        return FVector_2d(this->x + in_a.x, this->y + in_a.y);
    }
    FVector_2d operator-(const FVector_2d& in_a)const
    {
        return FVector_2d(this->x - in_a.x, this->y - in_a.y);
    }
    FVector_2d operator*(const FVector_2d& in_a)
    {
        return FVector_2d(this->x*in_a.x,this->y*in_a.y);
    }
    FVector_2d operator/(const FVector_2d& in_a)const
    {
        return FVector_2d(this->x/in_a.x,this->y/in_a.y);
    }
    bool operator>(const FVector_2d& in_a)const
    {
        return this->x>in_a.x && this->y>in_a.y;
    }
    bool operator<(const FVector_2d& in_a)const
    {
        return this->x<in_a.x && this->y<in_a.y;
    }
    bool operator>=(const FVector_2d& in_a)const
    {
        return this->x>=in_a.x && this->y>=in_a.y;
    }
    bool operator<=(const FVector_2d& in_a)const
    {
        return this->x<=in_a.x && this->y<=in_a.y;
    }
    void operator+=(const FVector_2d& in_a)
    {
        *this=*this+in_a;
    }
    void operator-=(const FVector_2d& in_a)
    {
        *this=*this-in_a;
    }
    FVector_2d operator+(f32 in_k)const
    {
        return FVector_2d(this->x + in_k,this->y + in_k);
    }
    FVector_2d operator-(f32 in_k)const
    {
        return FVector_2d(this->x - in_k,this->y - in_k);
    }
    FVector_2d operator*(f32 in_k)const
    {
        return FVector_2d(this->x*in_k,this->y*in_k);
    }
    FVector_2d operator/(f32 in_k)const
    {
        return FVector_2d(this->x/in_k,this->y/in_k);
    }
    FVector_2d operator*=(f32 in_k)
    {
        *this=*this*in_k;
        return *this;
    }
    FVector_2d operator/=(f32 in_k)
    {
        *this=*this/in_k;
        return *this;
    }
};
