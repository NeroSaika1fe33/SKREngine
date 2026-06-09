#include "simple_math/math_utils.h"

FVector_3d math_utils::mul(const FVector_2d& in_v, const FMatrix_3x3& in_m)
{
}

FVector_3d math_utils::mul(const FVector_3d& in_v, const FMatrix_3x3& in_m)
{
}

FVector_3d math_utils::mul(const FVector_4d& in_v, const FMatrix_4x4& in_m)
{
}

void math_utils::rot_radian(f32 radian, FMatrix_3x3& in_matrix)
{
}

void math_utils::rot_angle(f32 angle, FMatrix_3x3& in_matrix)
{
}

void math_utils::set_scale(const FVector_2d& in_scale, FMatrix_3x3& in_world_matrix)
{
}

FMatrix_3x3 math_utils::set_scale(const FVector_2d& in_scale)
{
}

bool math_utils::scalar_nearly_equal_float(f32 f1, f32 f2, f32 epsilon)
{
}

bool math_utils::scalar_nearly_equal_int(int32 i1, int32 i2, int32 epsilon)
{
}

bool math_utils::IsNearlyZero(f32 k, f32 epsilon)
{
    if (std::abs(k) <= epsilon)
    {
        return true;       
    }
    return false;    
}

FMatrix_4x4 math_utils::matrix_perspective(f32 in_fov_radian, f32 aspect_ratio, f32 near_z, f32 far_z)
{
}

FMatrix_4x4 math_utils::build_matrix_perspective(const FVector_4d& in_view_pos, const FMatrix_4x4& in_view_matrix)
{
}

FMatrix_4x4 math_utils::matrix_look_at(const FVector_4d& in_view_pos, const FVector_4d& in_target_pos,
    const FVector_4d& in_view_up)
{
    FVector_4d n = in_target_pos-in_view_pos;
    n.normalize();
    
    FVector_4d u=FVector_4d::crossProduct(in_view_up,n);
    u.normalize();
    
    FVector_4d v=FVector_4d::crossProduct(n,u);
    v.normalize();
    
    return FMatrix_4x4(
    u.x,v.x,n.x,0.f,
    u.y,v.y,n.y,0.f,
    u.z,v.z,n.z,0.f,
    -FVector_4d::dot(u,in_view_pos),
    -FVector_4d::dot(v,in_view_pos),
    -FVector_4d::dot(n,in_view_pos),1.f);
}

FMatrix_4x4 math_utils::matrix_rotation_y(const f32 angle)
{
}

FMatrix_4x4 math_utils::matrix_rotation_x(const f32 angle)
{
}

FMatrix_4x4 math_utils::matrix_rotation_z(const f32 angle)
{
}

FMatrix_4x4 math_utils::matrix_rotation_axis(const FVector_4d& axis, const f32 angle)
{
}

void math_utils::inertia_to_object(const FQuat& in_quat, FMatrix_3x3& out_rot_matrix)
{
}

void math_utils::object_to_inertia(const FQuat& in_quat, FMatrix_3x3& out_rot_matrix)
{
}

FVector_3d math_utils::inertia_to_object(const FVector_3d& in_vector, const FMatrix_3x3& in_rot_matrix)
{
}

FVector_3d math_utils::object_to_inertia(const FVector_3d& in_vector, const FMatrix_3x3& in_rot_matrix)
{
}

FVector_3d math_utils::rotate_quat(const FVector_3d& in_target_v, const FQuat& in_rot_quat)
{
}

void math_utils::matrix_to_quat(const FMatrix_3x3& in_rot_matrix, FQuat& out_quat)
{   
    f32 value[4]={0};
    value[0]=in_rot_matrix.m11+in_rot_matrix.m22+in_rot_matrix.m33;//4w^2-1
    value[1]=in_rot_matrix.m11-in_rot_matrix.m22-in_rot_matrix.m33;//4x^2-1
    value[2]=-in_rot_matrix.m11+in_rot_matrix.m22-in_rot_matrix.m33;//4y^2-1
    value[3]=-in_rot_matrix.m11-in_rot_matrix.m22+in_rot_matrix.m33;//4z^2-1
    
    //biggest value
    f32 tmp=0.f;
    int32 index=0;
    for (int32 i=0; i<4; i++)
    {
        if (value[i]>tmp)
        {
            tmp=value[i];
            index=i;
        }
    }
    
    //switch case
    if (tmp!=0.f)
    {
        f32 value_sqrt = sqrt(tmp+1.f)*0.5f;
        f32 mult=0.25f/value_sqrt;
        switch (index)
        {
            case 0://w
                out_quat.w=value_sqrt;
                out_quat.x=(in_rot_matrix.m23-in_rot_matrix.m32)*mult;
                out_quat.y=(in_rot_matrix.m31-in_rot_matrix.m13)*mult;
                out_quat.z=(in_rot_matrix.m12-in_rot_matrix.m21)*mult;
                break;
            case 1://x
                out_quat.w=(in_rot_matrix.m23-in_rot_matrix.m32)*mult;
                out_quat.x=value_sqrt;
                out_quat.y=(in_rot_matrix.m12+in_rot_matrix.m21)*mult;
                out_quat.z=(in_rot_matrix.m31+in_rot_matrix.m13)*mult;
                break;
            case 2://y
                out_quat.w=(in_rot_matrix.m31-in_rot_matrix.m13)*mult;
                out_quat.x=(in_rot_matrix.m12+in_rot_matrix.m21)*mult;
                out_quat.y=value_sqrt;
                out_quat.z=(in_rot_matrix.m23+in_rot_matrix.m32)*mult;
                break;
            case 3://z
                out_quat.w=(in_rot_matrix.m12-in_rot_matrix.m21)*mult;
                out_quat.x=(in_rot_matrix.m31+in_rot_matrix.m13)*mult;
                out_quat.y=(in_rot_matrix.m23+in_rot_matrix.m32)*mult;
                out_quat.z=value_sqrt;
                break;
        }
        out_quat.normalize();
    }
}

FQuat math_utils::matrix_to_quat(const FMatrix_3x3& in_rot_matrix)
{
    FQuat q;
    matrix_to_quat(in_rot_matrix,q);
    return q;
}

FQuat math_utils::pow(const FQuat& in_quat, f32 in_exponent)
{
}

f32 math_utils::angle_to_radian(f32 angle)
{
    return angle*PI / 180.0f;
}

f32 math_utils::radian_to_angle(f32 radian)
{
    return radian*180.0f/PI;
}
