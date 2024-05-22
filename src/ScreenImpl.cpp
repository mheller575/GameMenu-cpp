
#include <chrono>
#include <functional>

#include "IControl.h"

#include "ScreenImpl.h"

namespace Menu
{
	IScreen::IScreen() {}

	IScreen::~IScreen() {}

	ScreenImpl::ScreenImpl(sf::RenderWindow* window, const std::vector<std::shared_ptr<IControl>>& controls, const std::uint32_t& screenUpdateRate_ms)
		: window_(window)
		, controls_(controls)
		, screenUpdateRate_ms_(screenUpdateRate_ms)
	{}

	ScreenImpl::~ScreenImpl() 
	{
		Close();
	}

	void ScreenImpl::Open()
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Sample Menu Example", sf::Style::Close);

		auto lastTime_ms = GetCurrentTime_ms();
		while (window.isOpen())
		{
			const auto currentTime_ms = GetCurrentTime_ms();

			if (currentTime_ms - lastTime_ms > screenUpdateRate_ms_)
			{
				// Clear the window.
				window.clear();

				sf::RectangleShape shape(sf::Vector2f(4.0, 4.0));
				shape.setPosition(sf::Vector2f(4.0, 4.0));
				shape.setFillColor(sf::Color::Blue);

				window.draw(shape);

				//for (const auto& control : controls_)
				//{
				//	control->Draw(window_);
				//}

				// Tell the window to display.
				window.display();
			}

			// Poll the events from the window.
			sf::Event windowEvent;
			while (window.pollEvent(windowEvent))
			{
				// Handle the closed event here, but pass all other events to the contained controls.
				if (windowEvent.type == sf::Event::Closed)
				{
					window.close();
				}
				else
				{
					


					//for (auto& control : controls_)
					//{
					//	control->HandleEvent(windowEvent, window_);
					//}
				}
			}

			lastTime_ms = GetCurrentTime_ms();
		}
	}

	void ScreenImpl::Close()
	{
		notifyThreadClose_ = true;
	}
	void ScreenImpl::WindowHandler()
	{
		
	}

	void ScreenImpl::DisplayHandler(const std::uint64_t& lastTime_ms)
	{
		
	}

	void ScreenImpl::ControlEventHandler()
	{
		
	}

	std::uint64_t ScreenImpl::GetCurrentTime_ms()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}
}