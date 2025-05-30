#include "Hud.h"


Hud::Hud()
{
	player = nullptr;
	hud.setFont(*(pGerGraphic->getFont()));
	hud.setCharacterSize(30);
}

Hud::~Hud()
{
}

void Hud::setPlayer(Entidades::Personagens::Player* player)
{
	this->player = player;
}

void Hud::draw()
{
	sf::RenderWindow* window = pGerGraphic->getWindow();
	window->setView(window->getDefaultView());
	window->draw(hud);
}

void Hud::executar()
{
	std::stringstream ss;
	ss <<"Tempo: "<< hudClock.getElapsedTime().asSeconds() << "\nVida:"<< player->getHealth() << "\nPontos : 0";
	hud.setString(ss.str());

}
