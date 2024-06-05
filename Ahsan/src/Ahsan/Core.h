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

#define BIT(x) (1 << x)
