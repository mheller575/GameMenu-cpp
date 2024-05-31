
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
	buttonStyle.PressedColor = sf::Color::Black; // DimGray
	buttonStyle.Text = "Press Me!";
	
	buttonStyle.TextStyle.Color = sf::Color::Red;
	buttonStyle.TextStyle.Font.loadFromFile("C:\\gitrepo\\GameMenu-cpp\\build\\Debug\\sansation.ttf");
	buttonStyle.TextStyle.FontSize = 18;
	buttonStyle.TextHorizontalAlignment = HorizontalAlignment::Center;
	buttonStyle.TextVerticalAlignment = VerticalAlignment::Center;
	buttonStyle.UnpressedColor = sf::Color::White;

	const auto button = BuildButton(buttonLocation, buttonStyle);
	auto unsubscriber1 = button->SubscribeToOnPressedDown(ButtonPressed);
	auto unsubscriber2 = button->SubscribeToOnPressedUp(ButtonReleased);

	const auto textLabelLocation = sf::Vector2f(160, 20);

	TextLabelStyle textLabelStyle;
	textLabelStyle.Color = sf::Color::Yellow;
	textLabelStyle.Font.loadFromFile("C:\\gitrepo\\GameMenu-cpp\\build\\Debug\\sansation.ttf");
	textLabelStyle.FontSize = 18;

	const auto textLabel = BuildTextLabel("Labeled!", textLabelLocation, textLabelStyle);

	auto logger = BuildLogger();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Sample Menu Example", sf::Style::Close);

	std::vector<std::shared_ptr<IControl>> controls = 
	{
		button,
		textLabel,
	};

	ScreenImpl screen(&window, controls, screenUpdateRate_ms);

	screen.Open();

	screen.Close();
}