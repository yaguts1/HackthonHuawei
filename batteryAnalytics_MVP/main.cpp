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
	// Configure text
	sf::Font font;
	if (!font.loadFromFile("./assets/Garet-Heavy.ttf"))
	{
		// handle font loading error
		return -1;
	}
	// Load font
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font1 = io.Fonts->AddFontFromFileTTF("./assets/Garet-Book.ttf", 30.0f);
	// Build font atlas
	ImGui::SFML::UpdateFontTexture();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
				window.close();

		}
		ImGui::SFML::Update(window, clock.restart());
		//Start adding gui elements
		// Use the loaded font
		ImGui::PushFont(font1);
		ImGui::Begin("TUSD Fio B based on Location", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);


		const char* items_states[] = { "SP", "TO", "GO" };

		const char* items_cities_SP[] = { "Sao Paulo", "Rio Claro", "Campos de Jordao","Adamantina" };
		const char* items_cities_TO[] = { "Palmas", "Gurupi", "Porto Nacional" };
		const char* items_cities_GO[] = { "Goiania", "Anapolis", "Catalao" };
		const float pos_power_textX = 3.0f;
		const float pos_power_textY = 0.1f;
		const float pos_fio_textX = 3.0f;
		const float pos_fio_textY = 0.2f;
		const float pos_input_textX = 0.3f;
		const float pos_input_textY = 0.5f;


		static int current_state = 0;
		static int current_city = 0;
		ImGui::SetWindowFontScale(1.0);
		ImGui::SetWindowPos(ImVec2(0.5f * (WINDOW_WIDTH / 12.0f), 1.0f * WINDOW_HEIGHT / 5.0f));
		ImGui::SetWindowSize(ImVec2(9.0f * (WINDOW_WIDTH / 10.0f), 7.0f * (WINDOW_HEIGHT / 10.0f)));
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.6f * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.20f * (WINDOW_HEIGHT / 10.0f)));
		ImGui::Text("");
		ImGui::SetNextItemWidth(200);
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.4f * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.40f * (WINDOW_HEIGHT / 10.0f)));
		ImGui::Combo(" State", &current_state, items_states, IM_ARRAYSIZE(items_states));

		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.55f * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + 0.20f * (WINDOW_HEIGHT / 10.0f)));
		ImGui::Text("");
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 0.4f * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y ));
		ImGui::SetNextItemWidth(200);

		switch (current_state) {
		case 0: // SP

			ImGui::Combo(" City", &current_city, items_cities_SP, IM_ARRAYSIZE(items_cities_SP));
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y - 1.5f* (WINDOW_HEIGHT / 10.0f)));
			ImGui::Text("Power distribution \ncompany");
			switch (current_city) {
			case 0: // Sao Paulo
				// do something for Sao Paulo in SP
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("ENEL SP");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_fio_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 211,34 R$/MWh ");
				break;
			case 1: // Rio Claro
				// do something for Rio Claro in SP
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("ELEKTRO");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 2.0f * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 195,62 R$/MWh");
				break;
			case 2: // Campos de Jordao
				// do something for Campos de Jordao in SP
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("ELEKTRO");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_fio_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 195,62 R$/MWh");

				break;
			case 3: // Adamantina
				// do something for Adamantina in SP
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("ESS");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_fio_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 104,23 R$/MWh");
				break;
			}
			break;
		case 1: // TO
			ImGui::Combo(" City", &current_city, items_cities_TO, IM_ARRAYSIZE(items_cities_TO));
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y - 1.5f * (WINDOW_HEIGHT / 10.0f)));
			ImGui::Text("Power distribution \ncompany");
			switch (current_city) {
			case 0: // Palmas
				// do something for Palmas in TO
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("Energisa TO");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_fio_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 361,44 R$/MWh");
				break;
			case 1: // Gurupi
				// do something for Gurupi in TO
				break;
			case 2: // Porto Nacional
				// do something for Porto Nacional in TO
				break;
			}
			break;
		case 2: // GO
			ImGui::Combo(" City", &current_city, items_cities_GO, IM_ARRAYSIZE(items_cities_GO));
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y - 1.5f * (WINDOW_HEIGHT / 10.0f)));
			ImGui::Text("Power distribution \ncompany");
			switch (current_city) {
			case 0: // Goiania
				// do something for Goiania in GO
				ImGui::SetWindowFontScale(2.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_power_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_power_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("ENEL GO");
				ImGui::SetWindowFontScale(1.0);
				ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_fio_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_fio_textY * (WINDOW_HEIGHT / 10.0f)));
				ImGui::Text("TUSD FIO B --> 174,57 R$/MWh");
				break;
			case 1: // Anapolis
				// do something for Anapolis in GO
				break;
			case 2: // Catalao
				// do something for Catalao in GO
				break;
			}
			break;
		}
		// declare an integer variable to store the input value
		static float generated_energy = 10.96f;
		static float lifespan = 20.0f;
		static float battery_cost = 0.0f;
		static float battery_capacity = 10.0f;
		static int current_year = 2023;

		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_input_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y + pos_input_textY * (WINDOW_HEIGHT / 10.0f)));

		ImGui::SetWindowFontScale(1.0f);
		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("   Generated Energy   [KWh/day]", &generated_energy, 0, 0);
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_input_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("   Battery Lifespan       [years]", &lifespan, 0, 0);
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_input_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("   Battery Cost              [R$]", &battery_cost, 0, 0);
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_input_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
		ImGui::SetNextItemWidth(100);
		ImGui::SetNextItemWidth(100);
		ImGui::InputFloat("   Battery Capacity      [KWh]", &battery_capacity, 0, 0);
		ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + pos_input_textX * (WINDOW_WIDTH / 10.0f), ImGui::GetCursorPos().y));
		ImGui::SetNextItemWidth(100);
		ImGui::InputInt("   Project date               [years]", &current_year, 0, 0, ImGuiInputTextFlags_CharsDecimal);
		ImGui::Text("My fer number is: %.2f", static_cast<float>(current_year));
		ImGui::End();
		ImGui::PopFont();

		//Finished adding gui elements 
		sf::Text message("Please Input Necessary Data to calculate battery cost-benefit", font, 30);
		message.setOrigin(message.getLocalBounds().width / 2.0f, 0);
		message.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 12.0f);
		message.setFillColor(sf::Color::Black);


		window.clear(sf::Color(140, 217, 140));
		window.draw(message);
		ImGui::SFML::Render(window);
		window.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}