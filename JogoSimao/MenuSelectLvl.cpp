#include "MenuSelectLvl.h"

MenuSelectLvl::MenuSelectLvl()
	:menuState()
{
	carregarBotoes();
}

MenuSelectLvl::~MenuSelectLvl()
{

}

void MenuSelectLvl::carregarBotoes() {
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(50.f, 100.f), "Voltar", Actions::VOLTAR_1_MENU));
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(200.f, 300.f), "Fase 1", Actions::FASE_1));
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(200.f, 400.f), "Fase 2", Actions::FASE_2));
}