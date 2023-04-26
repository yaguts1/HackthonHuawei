#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <SFML/Graphics.hpp>


float WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
float WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;


int main()
{
	// Create and set window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Battery Cost Analysis - BCA");
	ImGui::SFML::Init(window);
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();

		}
		// Configure text
		sf::Font font;
		if (!font.loadFromFile("./assets/Garet-Heavy.ttf"))
		{
			// handle font loading error
			return -1;
		}

		ImGui::SFML::Update(window, clock.restart());

		ImGui::Begin("ENTER DATA");
		ImGui::Text("Please Insert the project location");
		ImGui::End();
		sf::Text message("Please Input Necessary Data to calculate battery cost-benefit", font, 30);
		message.setOrigin(message.getLocalBounds().width / 2.0f, 0);
		message.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 8.0f);
		message.setFillColor(sf::Color::Black);


		window.clear(sf::Color(140, 217, 140));
		window.draw(message);
		ImGui::SFML::Render(window);
		window.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}