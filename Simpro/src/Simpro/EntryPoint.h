#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Simpro::Application* Simpro::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Simpro::CreateApplication();
	app->Run();
	delete app;
}

#endif