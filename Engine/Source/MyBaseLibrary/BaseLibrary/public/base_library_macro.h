#pragma once

#ifndef SIMPLE_LIBRARY_EXPORTS
#define SIMPLE_LIBRARY_EXPORTS
#endif

#ifdef BASE_LIBRARY_EXPORTS
#define BASE_LIBRARY_API __declspec(dllexport)
#else
#define BASE_LIBRARY_API __declspec(dllimport)
#endif // EEE
