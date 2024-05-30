#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Simpro::Application* Simpro::CreateApplication();

int main(int argc, char** argv)
{
	Simpro::Log::Init();
	SP_CORE_WARN("Initialized log!");
	int a = 5;
	SP_INFO("hello test var={0}", a);

	auto app = Simpro::CreateApplication();
	app->Run();
	delete app;
}

#endif