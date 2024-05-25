
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "ScreenImpl.h"
#include "ButtonImpl.h"
#include "ILogger.h"
#include "SFMLHelpers.h"

using namespace Menu;

void ButtonPressed()
{
	std::cout << "Button was pressed down!" << std::endl;
}

void ButtonReleased()
{
	std::cout << "Button was released!" << std::endl;
}

int main()
{
	const std::uint32_t screenUpdateRate_ms = 16;

	const auto buttonLocation = sf::Vector2f(20, 20);

	ButtonStyle buttonStyle;
	buttonStyle.BorderColor = sf::Color::Red; // DimGray
	buttonStyle.ButtonBorderThickness = 2;
	buttonStyle.ButtonSize = sf::Vector2f(120, 60);
	buttonStyle.Padding.Bottom = 5;
	buttonStyle.Padding.Left = 5;
	buttonStyle.Padding.Right = 5;
	buttonStyle.Padding.Top = 5;
	buttonStyle.PressedColor = sf::Color::Black; // DimGray
	buttonStyle.Text = "Press Me!";
	
	buttonStyle.TextStyle.Color = sf::Color::Red;
	buttonStyle.TextStyle.Font.loadFromFile("C:\\gitrepo\\GameMenu-cpp\\build\\Debug\\sansation.ttf");
	buttonStyle.TextStyle.FontSize = 18;
	buttonStyle.TextStyle.HorizAlign = HorizontalAlignment::Center;
	buttonStyle.TextStyle.VertAlign = VerticalAlignment::Center;
	buttonStyle.UnpressedColor = sf::Color::White;

	const auto button = BuildButton(buttonLocation, buttonStyle);
	auto unsubscriber1 = button->SubscribeToOnPressedDown(ButtonPressed);
	auto unsubscriber2 = button->SubscribeToOnPressedUp(ButtonReleased);

	auto logger = BuildLogger();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Sample Menu Example", sf::Style::Close);

	//while (window.isOpen())
	//{
	//	// Clear the window.
	//	window.clear();

	//	button->Draw(&window);

	//	// Tell the window to display.
	//	window.display();

	//	// Poll the events from the window.
	//	sf::Event windowEvent;
	//	while (window.pollEvent(windowEvent))
	//	{
	//		//std::stringstream logMessageStream;
	//		//logMessageStream << "Event received: " << ConvertEventTypeToString(windowEvent.type) << " | " << ConvertEventDataToString(windowEvent);
	//		//logger->LogInformation(logMessageStream.str());

	//		// Handle the closed event here, but pass all other events to the contained controls.
	//		if (windowEvent.type == sf::Event::Closed)
	//		{
	//			window.close();
	//		}
	//		else
	//		{
	//			button->HandleEvent(windowEvent, &window);
	//		}
	//	}
	//}

	std::vector<std::shared_ptr<IControl>> controls = { button };

	ScreenImpl screen(&window, controls, screenUpdateRate_ms);

	screen.Open();

	screen.Close();
}