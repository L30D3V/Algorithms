#pragma once

#ifndef HELLODLL_EXPORTS
#define HELLODLL_API __declspec(dllexport)
#else
#define HELLODLL_API __declspec(dllimport)
#endif 


extern "C" HELLODLL_API int dll_double(int a);