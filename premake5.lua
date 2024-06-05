workspace "Ahsan"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ahsan"
	location "Ahsan"
	kind "sharedlib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ahpch.h"
	pchsource "Ahsan/src/ahpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Ahsan/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"AH_PLATFORM_WINDOWS",
			"AH_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.abspath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "AH_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ahsan/vendor/spdlog/include",
		"Ahsan/src"
	}

	links 
	{
		"Ahsan"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"AH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AH_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "AH_DIST"
		symbols "On"

