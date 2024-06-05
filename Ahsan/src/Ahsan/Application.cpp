#include "ahpch.h"
#include "Application.h"

#include "Ahsan/Events/ApplicationEvent.h"
#include "Ahsan/Log.h"


namespace Ahsan {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1080, 480);

		if (e.IsInCategory(EventCategoryApplication))
		{
			AH_TRACE("hello");
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AH_TRACE("World!");
		}

		while (true);
	}

}