#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FMatrix_3x3;
struct FQuat;

struct BASE_LIBRARY_API FEuler
{
    f32 heading;
    f32 pitch;
    f32 roll;
    FEuler()
    :heading(0),pitch(0),roll(0)
    {}
    FEuler(f32 in_heading,f32 in_pitch,f32 in_roll)
        :heading(in_heading),pitch(in_pitch),roll(in_roll)
    {}
    FEuler operator/(f32 k)
    {
        assert(std::abs(k)>SMALL_NUMBER);
        
        return FEuler(heading/k,pitch/k,roll/k);
    }
    
    FEuler& operator/=(f32 k)
    {
        assert(std::abs(k)>SMALL_NUMBER);
        *this=*this/k;
        return *this;
    }
};

//ue like
struct BASE_LIBRARY_API FRotator
{
    //y right axis
    f32 pitch;
    //z up axis
    f32 yaw;
    //x forward axis
    f32 roll;
    
public:
    FRotator();
    FRotator(f32 in_pitch,f32 in_yaw,f32 in_roll);
    FRotator operator+(const FRotator& a)const
    {
        return FRotator(pitch+a.pitch,yaw+a.yaw,roll+a.roll);
    }
    FRotator operator-(const FRotator& a)const
    {
        return FRotator(pitch-a.pitch,yaw-a.yaw,roll-a.roll);
    }
    FRotator operator*(const f32 k)const
    {
        return FRotator(pitch*k,yaw*k,roll*k);
    }
    FRotator& operator+=(const FRotator& a)
    {
        *this=*this+a;
        return *this;
    }
    FRotator& operator-=(const FRotator& a)
    {
        *this=*this-a;
        return *this;
    }
    FRotator& operator*=(const f32 k)
    {
        *this=*this*k;
        return *this;
    }
public:
    void inertia_to_object(const FMatrix_3x3& in_rot_matrix);
    void object_to_inertia(const FMatrix_3x3& in_rot_matrix);
    
    void inertia_to_object(const FQuat& in_quat);
    void object_to_inertia(const FQuat& in_quat);
    
    void euler_to_rotator(const FEuler& in_euler);
    void rotator_to_euler(FEuler& in_euler)const;
    FEuler rotator_to_euler()const;
};
