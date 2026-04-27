#include "simple_math/math_utils.h"

f32 math_utils::angle_to_radian(f32 angle)
{
    return angle*PI / 180.0f;
}

f32 math_utils::radian_to_angle(f32 radian)
{
    return radian*180.0f/PI;
}
