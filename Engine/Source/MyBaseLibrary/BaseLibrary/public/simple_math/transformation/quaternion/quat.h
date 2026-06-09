#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"

struct FRotator;
struct FVector_3d;

__declspec(align(16)) struct  BASE_LIBRARY_API FQuat
{
public:
    f32 x,y,z,w;
    
public:
    FQuat();
    FQuat(f32 in_x, f32 in_y, f32 in_z, f32 in_w);
    
    FQuat operator*(const FQuat& q) const;
    FQuat& operator*=(const FQuat& q);
    FQuat operator*(const f32& q)const;
    FQuat operator*(const int32& q)const;
    FQuat& operator*=(const f32& q);
    FQuat& operator*=(const int32& q);
    FQuat operator+(const FQuat& q)const;
    FQuat operator-(const FQuat& q)const;
    FQuat& operator+=(const FQuat& q);
    FQuat& operator-=(const FQuat& q);
    f32 dot(const FQuat& q)const;
    
    
    FQuat log() const;
    FQuat exp() const;
    
    f32 size()const;
    f32 size_squared()const;
    f32 get_half_angle_radian()const;
    f32 get_angle_radian()const;
    f32 get_angle()const;
    void normalize(f32 in_tolerance = SMALL_NUMBER);
    
    static FQuat CreateRot(const FVector_3d& a, f32 angle);
    void rotator_by_axis(const FVector_3d& a,f32 angle);
    void rotator_by_x(f32 theta);
    void rotator_by_y(f32 theta);
    void rotator_by_z(f32 theta);
    FQuat inverse()const;
    
    void inertia_to_object(const FRotator& in_rot);
    void object_to_inertia(const FRotator& in_rot);
    void object_to_inertia_v2(const FRotator& in_rot);
    void inertia_to_object_v2(const FRotator& in_rot);
   

    FRotator get_rot_by_object_to_inertia_v2();
    FRotator get_rot_by_inertia_to_object_v2();
    
    static FQuat lerp(const FQuat& in_q0,const FQuat& in_q1,f32 in_t);
    static FQuat nlerp(const FQuat& in_q0, const FQuat& in_q1, f32 in_t);
    static FQuat blinear_lerp(const FQuat& in_q00,const FQuat& in_q10,const FQuat& in_q01,const FQuat& in_q11,f32 x,f32 y);
    
    static FQuat s_lerp(const FQuat& in_q0,const FQuat& in_q1,f32 in_t);
    
    static FQuat s_lerp_full_path(const FQuat& in_q0,const FQuat& in_q1,f32 in_t);
    static FQuat s_quad(const FQuat& in_q0,const FQuat& in_q1,const FQuat& in_s0,const FQuat& in_s1,f32 in_t);
    static FQuat s_quad_full_path(const FQuat& in_q0,const FQuat& in_q1,const FQuat& in_s0,const FQuat& in_s1,f32 in_t);
    
    //find in_s0 in_s1
    static FQuat get_tangents(const FQuat& in_prev_q,const FQuat& in_q,const FQuat& in_next_q);
    
    const FQuat identity();
    
    bool is_normalized()const;
    
protected:
    void get_cos_sin(const FRotator& in_rot, f32& cos_h_roll, f32& sin_h_roll, f32& cos_h_pitch, f32& sin_h_pitch, f32& cos_h_yaw, f32& sin_h_yaw);

};
