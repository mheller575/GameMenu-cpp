#pragma once

#include <memory>
#include <thread>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "IScreen.h"

namespace Menu
{
	class IControl;

	class ScreenImpl : public IScreen
	{
	public:
		ScreenImpl(sf::RenderWindow* window, const std::vector<std::shared_ptr<IControl>>& controls, const std::uint32_t& screenUpdateRate_ms);

		virtual ~ScreenImpl() override;

		virtual void Open() override;

		virtual void Close() override;

	private:
		void WindowHandler();
		void DisplayHandler(const std::uint64_t& lastTime_ms);
		void ControlEventHandler();
		std::uint64_t GetCurrentTime_ms();

		const std::uint32_t screenUpdateRate_ms_;
		bool notifyThreadClose_ = false;
		std::thread displayThread_;
		std::thread controlThread_;
		sf::RenderWindow* window_;
		std::vector<std::shared_ptr<IControl>> controls_;

		ScreenImpl(const ScreenImpl&) = delete;
		ScreenImpl& operator=(const ScreenImpl&) = delete;
	};
}