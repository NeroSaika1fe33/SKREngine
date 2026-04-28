#include "simple_math/transformation/quaternion/quat.h"

#include <algorithm>

#include "simple_math/math_library.hpp"
#include "simple_math/transformation/vector/vector_3d.h"
#include "simple_math/transformation/rotator/rotator.h"

FQuat::FQuat()
{
    *this = identity();
}

FQuat::FQuat(f32 in_x, f32 in_y, f32 in_z, f32 in_w)
    :x(in_x),y(in_y),z(in_z),w(in_w)
{
}

FQuat FQuat::operator*(const FQuat& q) const
{
    return FQuat(
           w * q.x + x * q.w + y * q.z - z * q.y,
           w * q.y - x * q.z + y * q.w + z * q.x,
           w * q.z + x * q.y - y * q.x + z * q.w,
           w * q.w - x * q.x - y * q.y - z * q.z);
}

FQuat& FQuat::operator*=(const FQuat& q)
{
    *this = *this * q;
    return *this;
}

FQuat FQuat::operator*(const f32& q) const
{
    return FQuat(x*q,y*q,z*q,w*q);
}

FQuat FQuat::operator*(const int32& q) const
{
    return FQuat(x*(f32)q,y*(f32)q,z*(f32)q,w*(f32)q);
}

FQuat& FQuat::operator*=(const f32& q)
{
    *this = *this * q;
    return *this;
}

FQuat& FQuat::operator*=(const int32& q)
{
    *this = *this * q;  
    return *this;
}

FQuat FQuat::operator+(const FQuat& q) const
{
    return FQuat(x+q.x,y+q.y,z+q.z,w+q.w);
}

FQuat FQuat::operator-(const FQuat& q) const
{
    return FQuat(x-q.x,y-q.y,z-q.z,w-q.w);
}

FQuat& FQuat::operator+=(const FQuat& q)
{
    *this = *this + q;
    return *this;
}

FQuat& FQuat::operator-=(const FQuat& q)
{
    *this = *this - q;
    return *this;
}

f32 FQuat::dot(const FQuat& q) const
{
    return x*q.x + y*q.y + z*q.z + w*q.w;
}

FQuat FQuat::CreateRot(const FVector_3d& axis, f32 angle)
{
    f32 half_angle = angle / 2.0f;
    f32 s=sin(half_angle);
    f32 c=cos(half_angle);
    
    FVector_3d n = axis;
    n.normalize();
    
    return FQuat(n.x*s,n.y*s,n.z*s,c);
}

FQuat FQuat::log() const
{
    f32 theta =acos(math_libray::Clamp(w,-1.f,1.f));
    f32 s=sin(theta);
    if (std::abs(theta)>SMALL_NUMBER)
    {
        f32 k=theta/s;
        return FQuat(k*x,k*y,k*z,0.f);
    }
    return FQuat(x,y,z,0.f);
}

FQuat FQuat::exp() const
{
    f32 theta=sqrt(x*x+y*y+z*z);
    f32 s=sin(theta);
    f32 c=cos(theta);
    if (std::abs(theta)>SMALL_NUMBER)
    {
        f32 k=s/theta;
        return FQuat(k*x,k*y,k*z,c);
    }
    return FQuat(0.f,0.f,0.f,1.f);
}

f32 FQuat::size() const
{
    return sqrt(size_squared());
}

f32 FQuat::size_squared() const
{
    return x*x + y*y + z*z + w*w;
}

f32 FQuat::get_half_angle_radian() const
{
    return acos(math_libray::Clamp(w,-1.f,1.f));
}

f32 FQuat::get_angle_radian() const
{
    return get_half_angle_radian()*2.f;
}

f32 FQuat::get_angle() const
{
    return get_angle_radian()*(180.f / PI);
}

void FQuat::normalize(f32 in_tolerance)
{
    const f32 square_sum = size_squared();
    
    if (square_sum >= in_tolerance)
    {
        f32 quat_size = sqrt(square_sum);
        
        x/=quat_size;
        y/=quat_size;
        z/=quat_size;
        w/=quat_size;
    }
    else
    {
        *this = identity();
    }
}

void FQuat::rotator_by_axis(const FVector_3d& axis,f32 angle)
{
    assert(is_normalized());
    *this=CreateRot(axis,angle);
}

void FQuat::rotator_by_x(f32 theta)
{
    rotator_by_axis(FVector_3d(1.f,0.f,0.f),theta);
}

void FQuat::rotator_by_y(f32 theta)
{
    rotator_by_axis(FVector_3d(0.f,1.f,0.f),theta);
}

void FQuat::rotator_by_z(f32 theta)
{
    rotator_by_axis(FVector_3d(0.f,0.f,1.f),theta);
}

FQuat FQuat::inverse() const
{
    assert(is_normalized());
    return FQuat(-x,-y,-z,w);
}

void FQuat::inertia_to_object(const FRotator& in_rot)
{
}

void FQuat::object_to_inertia(const FRotator& in_rot)
{
}

void FQuat::object_to_inertia_v2(const FRotator& in_rot)
{
}

FRotator FQuat::get_rot_by_object_to_inertia_v2()
{
}

FRotator FQuat::get_rot_by_inertia_to_object_v2()
{
}

FQuat FQuat::lerp(const FQuat& in_q0, const FQuat& in_q1, f32 in_t)
{
    //double cover
    f32 bias = (in_q0.dot(in_q1))>0.f?1.f:-1.f;
    return (in_q0*(bias*(1-in_t)))+in_q1*in_t;    
}

FQuat FQuat::nlerp(const FQuat& in_q0, const FQuat& in_q1, f32 in_t)
{
    //double cover
    f32 bias = (in_q0.dot(in_q1))>0.f?1.f:-1.f;
    FQuat result=(in_q0*(bias*(1-in_t)))+in_q1*in_t;
    result.normalize();
    return result; 
}

FQuat FQuat::blinear_lerp(const FQuat& in_q00, const FQuat& in_q10, const FQuat& in_q01, const FQuat& in_q11,f32 x,f32 y)
{
    FQuat result=lerp(lerp(in_q00,in_q10,x),lerp(in_q01,in_q11,x),y);
    result.normalize();
    return result;
}

FQuat FQuat::s_lerp(const FQuat& in_q0, const FQuat& in_q1, f32 in_t)
{
    if (in_t>=1.f) return in_q1;
    else if (in_t <= 0.f) return in_q0;
    //cos
    f32 c=(in_q0.dot(in_q1));
    FQuat tmp=in_q1;
    if (c<0.f)
    {
        //double cover
        c=-c;
        tmp=FQuat(-in_q1.x,-in_q1.y,-in_q1.z,-in_q1.w);
    }
    
    assert(c<1.1f);
    
    f32 k0 = 0.f;
    f32 k1 = 0.f;
    if (c>=0.99995f)
    {
        //lerp
        k0 = 1.f-in_t;
        k1 = in_t;
    }
    else
    {
        //slerp
        f32 s=sqrt(1.f-c*c);
        f32 theta =atan2(s,c);
        f32 inv_s = 1.f/s;
        
        k0=sin((1.f-in_t)*theta)*inv_s;
        k1=sin(in_t*theta)*inv_s;
    }
    
    return FQuat(
        k0*in_q0.x+k1*tmp.x,
        k0*in_q0.y+k1*tmp.y,
        k0*in_q0.z+k1*tmp.z,
        k0*in_q0.w+k1*tmp.w);
}

FQuat FQuat::s_lerp_full_path(const FQuat& in_q0, const FQuat& in_q1, f32 in_t)
{
    f32 k0 = 0.f;
    f32 k1 = 0.f;
    //cos
    f32 c=in_q0.dot(in_q1);
    c=math_libray::Clamp(c,-1.f,1.f);
    f32 angle = acos(c);
    if (std::abs(angle)<=SMALL_NUMBER)
        return in_q0;
    
    //slerp
    f32 s=sqrt(1.f-c*c);
    f32 inv_s = 1.f/s;
        
    k0=sin((1.f-in_t)*angle)*inv_s;
    k1=sin(in_t*angle)*inv_s;
    
    return in_q0*k0+in_q1*k1;
}

FQuat FQuat::s_quad(const FQuat& in_q0, const FQuat& in_q1, const FQuat& in_s0, const FQuat& in_s1, f32 in_t)
{
    FQuat q1=s_lerp(in_q0,in_q1,in_t);
    FQuat q2=s_lerp_full_path(in_s0,in_s1,in_t);
    FQuat result=s_lerp_full_path(q1,q2,2.f*in_t*(1.f-in_t));
    result.normalize();
    return result;
}

FQuat FQuat::s_quad_full_path(const FQuat& in_q0, const FQuat& in_q1, const FQuat& in_s0, const FQuat& in_s1, f32 in_t)
{
    FQuat q1=s_lerp_full_path(in_q0,in_q1,in_t);
    FQuat q2=s_lerp_full_path(in_s0,in_s1,in_t);
    FQuat result=s_lerp_full_path(q1,q2,2.f*in_t*(1.f-in_t));
    result.normalize();
    return result;
}

FQuat FQuat::get_tangents(const FQuat& in_prev_q, const FQuat& in_q, const FQuat& in_next_q)
{
    //-P1
    FQuat inv_p=in_q.inverse();
    
    //angular displacement
    FQuat r1=(inv_p*in_prev_q).log();
    FQuat r2=(inv_p*in_next_q).log();
    
    FQuat pre_exp=(r1+r2)*-0.25f;
    
    return in_q * pre_exp.exp();
}

const FQuat FQuat::identity()
{
    return FQuat(0.f,0.f,0.f,1.f);
}

bool FQuat::is_normalized()const
{
    return (abs(size_squared()-1.f))<=SMALL_NUMBER;
}
