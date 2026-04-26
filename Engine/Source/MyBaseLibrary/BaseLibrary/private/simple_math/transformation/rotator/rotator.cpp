#include "simple_math/transformation/rotator/rotator.h"
#include "simple_math/transformation/matrix/matrix_3x3.h"
#include "simple_math/transformation/quaternion/quat.h"


FRotator::FRotator()
{
}

FRotator::FRotator(f32 in_pitch, f32 in_yaw, f32 in_roll)
{
}

void FRotator::inertia_to_object(const FMatrix_3x3& in_rot_matrix)
{
}

void FRotator::object_to_inertia(const FMatrix_3x3& in_rot_matrix)
{
}

void FRotator::inertia_to_object(const FQuat& in_quat)
{
}

void FRotator::object_to_inertia(const FQuat& in_quat)
{
}

void FRotator::euler_to_rotator(const FEuler& in_euler)
{
}

void FRotator::rotator_to_euler(FEuler& in_euler) const
{
}

FEuler FRotator::rotator_to_euler() const
{
}
