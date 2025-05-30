#include "PauseState.h"
PauseState::PauseState()
{
	resume = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(300.f, 300.f), "Resume", Actions::VOLTAR_1_MENU);
	quit = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(300.f, 400.f), "Quit", Actions::VOLTAR_2_MENUS);

	buttonVector.push_back(quit);
	buttonVector.push_back(resume);
}

PauseState::~PauseState() {
	delete resume;
	delete quit;
}