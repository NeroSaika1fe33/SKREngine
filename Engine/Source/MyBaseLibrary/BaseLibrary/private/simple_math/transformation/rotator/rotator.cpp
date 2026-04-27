#include "simple_math/transformation/rotator/rotator.h"

#include "simple_math/math_utils.h"
#include "simple_math/transformation/matrix/matrix_3x3.h"
#include "simple_math/transformation/quaternion/quat.h"


FRotator::FRotator()
    :pitch(0.f),yaw(0.f),roll(0.f)
{
}

FRotator::FRotator(f32 in_pitch, f32 in_yaw, f32 in_roll)
    :pitch(in_pitch),yaw(in_yaw),roll(in_roll)
{
}

void FRotator::inertia_to_object(const FMatrix_3x3& in_rot_matrix)
{
    FEuler euler;
    //assume in_rot_matrix.m31=-sin(beta)
    f32 s=-in_rot_matrix.m31;
    s=math_libray::Clamp(s,-1.0f, 1.0f);
    //Gimbal Lock
    if (std::abs(euler.pitch_radian)>0.99999f)
    {
        euler.pitch_radian=PI/2.f;
        euler.yaw_radian=atan2(-in_rot_matrix.m31,in_rot_matrix.m11);
        euler.roll_radian=0.f;
    }
    else
    {
        
        euler.pitch_radian=std::asin(s);
        euler.yaw_radian=atan2(-in_rot_matrix.m12,in_rot_matrix.m11);
        euler.roll_radian=std::atan2(in_rot_matrix.m23,in_rot_matrix.m33);
    }
    euler_to_rotator(euler);
}

void FRotator::object_to_inertia(const FMatrix_3x3& in_rot_matrix)
{
    FEuler euler;
    //assume in_rot_matrix.m13=-sin(beta)
    f32 s=-in_rot_matrix.m13;
    s=math_libray::Clamp(s,-1.0f, 1.0f);
    //Gimbal Lock
    if (std::abs(euler.pitch_radian) > 0.99999f)
    {
        euler.pitch_radian=(s>0.f)?(PI*0.5f):-(PI*0.5f);
        euler.yaw_radian=std::atan2(-in_rot_matrix.m12,in_rot_matrix.m11);
        euler.roll_radian=0.f;
    }
    else
    {
        euler.pitch_radian=std::asin(s);
        euler.yaw_radian=std::atan2(in_rot_matrix.m21,in_rot_matrix.m11);
        euler.roll_radian=std::atan2(in_rot_matrix.m32,in_rot_matrix.m33);
    }
    euler_to_rotator(euler);
}

void FRotator::inertia_to_object(const FQuat& in_quat)
{
}

void FRotator::object_to_inertia(const FQuat& in_quat)
{
}

void FRotator::euler_to_rotator(const FEuler& in_euler)
{
    pitch = math_utils::radian_to_angle(in_euler.pitch_radian);
    yaw = math_utils::radian_to_angle(in_euler.yaw_radian);
    roll = math_utils::radian_to_angle(in_euler.roll_radian);
}

void FRotator::rotator_to_euler(FEuler& in_euler) const
{
    in_euler.pitch_radian = math_utils::angle_to_radian(pitch);
    in_euler.yaw_radian = math_utils::angle_to_radian(yaw);
    in_euler.roll_radian= math_utils::angle_to_radian(roll);
}

FEuler FRotator::rotator_to_euler() const
{
    FEuler euler;
    rotator_to_euler(euler);
    return euler;
}
