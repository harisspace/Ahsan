#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ahsan {

	class AHSAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define AH_CORE_TRACE(...)	::Ahsan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AH_CORE_INFO(...)	::Ahsan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AH_CORE_WARN(...)	::Ahsan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AH_CORE_ERROR(...)	::Ahsan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AH_CORE_FATAL(...)	::Ahsan::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AH_TRACE(...)	::Ahsan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AH_INFO(...)	::Ahsan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AH_WARN(...)	::Ahsan::Log::GetCoreLogger()->warn(__VA_ARGS__)
// #define AH_ERROR(...)	::Ahsan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AH_FATAL(...)	::Ahsan::Log::GetCoreLogger()->fatal(__VA_ARGS__)