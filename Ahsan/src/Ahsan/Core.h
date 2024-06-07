#pragma once

#ifdef AH_PLATFORM_WINDOWS
	#ifdef AH_BUILD_DLL
		#define AHSAN_API __declspec(dllexport)
	#else
		#define AHSAN_API __declspec(dllimport)
	#endif // AH_BUILD_DLL
#else
	#error Ahsan only supports windows
#endif // AH_PLATFORM_WINDOWS

#ifdef AH_ENABLE_ASSERT
	#define AH_CORE_ASSERT(x, ...) { if (!(x)) { AH_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define AH_ASSERT(x, ...) { if (!(x)) { AH_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define AH_CORE_ASSERT(x, ...)
	#define AH_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
