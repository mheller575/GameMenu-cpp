#include <chrono>
#include <functional>

#include "IControl.h"

#include "ScreenImpl.h"
#include "TimeHelpers.h"

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
		auto lastDrawTime_ms = 0; // Set to 0 so we draw on first pass through.
		while (window_->isOpen() && !notifyThreadClose_)
		{
			const auto currentTime_ms = GetCurrentTimeSinceEpoch_ms();

			if (currentTime_ms - lastDrawTime_ms > screenUpdateRate_ms_)
			{
				// Clear the window.
				window_->clear();

				for (const auto& control : controls_)
				{
					control->Draw(window_);
				}

				// Tell the window to display.
				window_->display();

				lastDrawTime_ms = GetCurrentTimeSinceEpoch_ms();
			}

			// Poll the events from the window.
			sf::Event windowEvent;
			while (window_->pollEvent(windowEvent))
			{
				// Handle the closed event here, but pass all other events to the contained controls.
				if (windowEvent.type == sf::Event::Closed)
				{
					notifyThreadClose_ = true;
				}
				else
				{
					for (auto& control : controls_)
					{
						control->HandleEvent(windowEvent, window_);
					}
				}
			}
		}

		window_->clear();
	}

	void ScreenImpl::Close()
	{
		notifyThreadClose_ = true;
	}
}