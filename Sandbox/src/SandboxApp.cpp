#include <Ahsan.h>

class Sandbox : public Ahsan::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Ahsan::Application* Ahsan::CreateApplication()
{
	return new Sandbox();
}