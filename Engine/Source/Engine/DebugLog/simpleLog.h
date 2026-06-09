#pragma once
#if defined(_WIN32)

#include "../../MyBaseLibrary/BaseLibrary/public/simple_library.h"

#define Engine_log(format,...) log_log(format,__VA_ARGS__)

#endif
