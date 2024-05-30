#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Simpro {

	class SP_API Log
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
#define SP_CORE_TRACE(...)	::Simpro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)	::Simpro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)	::Simpro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...)	::Simpro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...)	::Simpro::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SP_TRACE(...)	::Simpro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)	::Simpro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_WARN(...)	::Simpro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)	::Simpro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_FATAL(...)	::Simpro::Log::GetCoreLogger()->fatal(__VA_ARGS__)