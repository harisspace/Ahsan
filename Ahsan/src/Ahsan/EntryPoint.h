#pragma once

#ifdef AH_PLATFORM_WINDOWS

extern Ahsan::Application* Ahsan::CreateApplication();

int main(int argc, char** argv)
{
	Ahsan::Log::Init();
	AH_CORE_WARN("Initialized log!");
	int a = 5;
	AH_INFO("hello test var={0}", a);

	auto app = Ahsan::CreateApplication();
	app->Run();
	delete app;
}

#endif