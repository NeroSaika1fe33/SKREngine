#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
#endif  

#define _WIN32_LEAN_AND_MEAN
#include <windows.h>

//c++
#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>

#include "base_library_macro.h"

#define PI                  (3.1415926535897932f)
#define SMALL_NUMBER        (1.e-8f)
#define KINDA_SMALL_NUMBER  (1.e-4f)

using uint8    = unsigned char;
using uint16   = unsigned short;
using uint32   = unsigned int;
using uint64   = unsigned long long;
using int8     = signed char;
using int16    = signed short;
using int32    = signed int;
using int64    = signed long long;
using f32      = float;
using f64      = double;
using ANSICHAR = char;


