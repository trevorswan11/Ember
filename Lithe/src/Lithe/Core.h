#pragma once

#ifdef LI_PLATFORM_WINDOWS
	#ifdef LI_BUILD_DLL
		#define LITHE_API __declspec(dllexport)
	#else
		#define LITHE_API __declspec(dllimport)
	#endif
#else
	#error Lithe only supports Windows.
#endif

#ifdef LI_ENABLE_ASSERTS
	#define LI_ASSERT(x, ...) { if(!(x)) { LI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LI_CORE_ASSERT(x, ...) { if(!(x)) { LI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LI_ASSERT(x, ...)
	#define LI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)