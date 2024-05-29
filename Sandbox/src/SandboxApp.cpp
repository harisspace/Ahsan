#include <Simpro.h>

class Sandbox : public Simpro::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Simpro::Application* Simpro::CreateApplication()
{
	return new Sandbox();
}