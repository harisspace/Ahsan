#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SIMPRO_API __declspec(dllexport)
	#else
		#define SIMPRO_API __declspec(dllimport)
	#endif // SP_BUILD_DLL
#else
	#error Simpro only supports windows
#endif // SP_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
