#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	float WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
	float WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;

	// Create and set window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Battery Cost Analysis - BCA");
	ImGui::SFML::Init(window);
	sf::Clock clock;
	// Make button corners rounded
	float rounding = 10.0f; // Adjust to desired corner rounding
	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, rounding);
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
		//Start adding gui elements
		ImGui::Begin("Location", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

		ImGui::SetWindowFontScale(1.4);
		ImGui::SetWindowPos(ImVec2(0.5 * (WINDOW_WIDTH / 12.0f), WINDOW_HEIGHT / 5.0f));
		ImGui::SetWindowSize(ImVec2(3*(WINDOW_WIDTH /10.0f), 2.0 * (WINDOW_HEIGHT / 10.0f)));
		const char* items_states[] = { "SP", "TO", "GO" };
		static int currentState = 0;
		//ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.20 * (WINDOW_HEIGHT / 10.0f)));
		ImGui::Text("UF");
		ImGui::SetNextItemWidth(200);
		//ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.1 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
		 ImGui::Combo(" ", &currentState, items_states, IM_ARRAYSIZE(items_states));
		switch (currentState)
		{	
			case 0:
			{
				const char* items_cities_SP[] = { "Sao Paulo", "Rio Claro", "Campos de Jordao","Adamantina" };
				static int currentCity = 0;
				//ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.55 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.20 * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("City");
				//ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.1 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
				ImGui::SetNextItemWidth(200);
				ImGui::Combo(" ", &currentCity, items_cities_SP, IM_ARRAYSIZE(items_cities_SP));
				//ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 1.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y - 1 * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("Power distribution \ncompany");
				switch (currentCity)
				{
					case 0:
					{
						ImGui::SetWindowFontScale(2.0);
						ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 1.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.15 * (WINDOW_HEIGHT / 10.0f)));
						ImGui::Text("ENEL SP");
						ImGui::SetWindowFontScale(1.4);
						break;
					}
					case 1:
					{
						ImGui::SetWindowFontScale(2.0);
						ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 1.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.15 * (WINDOW_HEIGHT / 10.0f)));
						ImGui::Text("ELEKTRO");
						ImGui::SetWindowFontScale(1.4);
						break;
					}
					case 2:
					{
						ImGui::SetWindowFontScale(2.0);
						ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 1.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.15 * (WINDOW_HEIGHT / 10.0f)));
						ImGui::Text("ELEKTRO");
						ImGui::SetWindowFontScale(1.4);
						break;
					}
					case 3:
					{
						ImGui::SetWindowFontScale(2.0);
						ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 1.6 * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.15 * (WINDOW_HEIGHT / 10.0f)));
						ImGui::Text("ELEKTRO");
						ImGui::SetWindowFontScale(1.4);
						break;
					}
					default:
						break;
				}
				break;
			}

			case 1:
			{

				break;
			}
			case 2:
			{

			}
			default:
				break;
		
		}

		ImGui::End();

		//Finished adding gui elements 
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