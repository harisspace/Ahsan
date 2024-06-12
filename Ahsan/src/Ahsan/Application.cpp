#include "ahpch.h"

#include "Application.h"
#include "Ahsan/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>
#include <functional>


namespace Ahsan {

#define BIND_CALLBACK_FN(x) std::bind(x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_CALLBACK_FN(&Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_CALLBACK_FN(&Application::OnWindowClose));

		AH_CORE_TRACE(e.ToString());
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}