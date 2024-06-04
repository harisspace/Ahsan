#include "Application.h"

#include "Simpro/Events/ApplicationEvent.h"
#include "Simpro/Log.h"


namespace Simpro {

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
			SP_TRACE("hello");
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SP_TRACE("World!");
		}

		while (true);
	}
}