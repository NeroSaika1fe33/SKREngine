#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FMatrix_3x3;
struct FQuat;

struct BASE_LIBRARY_API FEuler
{
    //pitch yaw roll in radian
    f32 pitch_radian;
    f32 yaw_radian;
    f32 roll_radian;
    FEuler()
    :pitch_radian(0),yaw_radian(0),roll_radian(0)
    {}
    FEuler(f32 in_pitch_radian,f32 in_yaw_radian,f32 in_roll_radian)
        :pitch_radian(in_pitch_radian),yaw_radian(in_yaw_radian),roll_radian(in_roll_radian)
    {}
    FEuler operator/(f32 k)
    {
        assert(std::abs(k)>SMALL_NUMBER);
        
        return FEuler(pitch_radian/k,yaw_radian/k,roll_radian/k);
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
