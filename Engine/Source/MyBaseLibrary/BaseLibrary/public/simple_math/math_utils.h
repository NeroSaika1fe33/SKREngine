#pragma once
#include "simple_cpp_core_minimal/simple_core_minimal.h"
#include "simple_core_math.h"

using namespace std;
namespace math_utils
{   
    //mul
    FVector_3d BASE_LIBRARY_API mul(const FVector_2d& in_v,const FMatrix_3x3& in_m);
    FVector_3d BASE_LIBRARY_API mul(const FVector_3d& in_v,const FMatrix_3x3& in_m);
    FVector_3d BASE_LIBRARY_API mul(const FVector_4d& in_v,const FMatrix_4x4& in_m);
    
    //exchange
    f32 BASE_LIBRARY_API angle_to_radian(f32 angle);
    f32 BASE_LIBRARY_API radian_to_angle(f32 radian);
    
    //rotation matrix
    void BASE_LIBRARY_API rot_radian(f32 radian,FMatrix_3x3& in_matrix);
    void BASE_LIBRARY_API rot_angle(f32 angle,FMatrix_3x3& in_matrix);
    
    //zoom
    void BASE_LIBRARY_API set_scale(const FVector_2d& in_scale,FMatrix_3x3& in_world_matrix);
    FMatrix_3x3 BASE_LIBRARY_API set_scale(const FVector_2d& in_scale);
    
    //bool
    bool BASE_LIBRARY_API scalar_nearly_equal_float(f32 f1,f32 f2,f32 epsilon);
    bool BASE_LIBRARY_API scalar_nearly_equal_int(int32 i1,int32 i2,int32 epsilon);
    bool BASE_LIBRARY_API IsNearlyZero(f32 in_vector,f32 epsilon = SMALL_NUMBER);
    
    //perspective
    FMatrix_4x4 BASE_LIBRARY_API matrix_perspective(f32 in_fov_radian,f32 aspect_ratio,f32 near_z, f32 far_z);
    FMatrix_4x4 BASE_LIBRARY_API build_matrix_perspective(const FVector_4d& in_view_pos,const FMatrix_4x4& in_view_matrix);
    
    //look at
    FMatrix_4x4 BASE_LIBRARY_API matrix_look_at(const FVector_4d& in_view_pos,const FVector_4d& in_target_pos,const FVector_4d& in_view_up);
    
    //yxz-axis rot
    FMatrix_4x4 BASE_LIBRARY_API matrix_rotation_y(const f32 angle);
    FMatrix_4x4 BASE_LIBRARY_API matrix_rotation_x(const f32 angle);
    FMatrix_4x4 BASE_LIBRARY_API matrix_rotation_z(const f32 angle);
    
    //n-axis rot
    FMatrix_4x4 BASE_LIBRARY_API matrix_rotation_axis(const FVector_4d& axis,const f32 angle);
    
    //quat to matrix
    void BASE_LIBRARY_API inertia_to_object(const FQuat& in_quat,FMatrix_3x3& out_rot_matrix);
    void BASE_LIBRARY_API object_to_inertia(const FQuat& in_quat,FMatrix_3x3& out_rot_matrix);
    
    //vector
    FVector_3d BASE_LIBRARY_API inertia_to_object(const FVector_3d& in_vector, const FMatrix_3x3& in_rot_matrix);
    FVector_3d BASE_LIBRARY_API object_to_inertia(const FVector_3d& in_vector, const FMatrix_3x3& in_rot_matrix);
    
    //quat
    FVector_3d BASE_LIBRARY_API rotate_quat(const FVector_3d& in_target_v,const FQuat& in_rot_quat);

    //matrix to quat
    void BASE_LIBRARY_API matrix_to_quat(const FMatrix_3x3& in_rot_matrix, FQuat& out_quat);
    FQuat BASE_LIBRARY_API matrix_to_quat(const FMatrix_3x3& in_rot_matrix);
    
    //power
    FQuat BASE_LIBRARY_API pow(const FQuat& in_quat,f32 in_exponent);
}


