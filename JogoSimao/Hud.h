#pragma once
#include "Ente.h"
#include "sstream"
#include "Jogador.h"
class Hud : public Ente
{
private:
	sf::Clock hudClock;
	Entidades::Personagens::Jogador* player;
	sf::Text hud;
public:
	Hud();
	~Hud();
	void setPlayer(Entidades::Personagens::Jogador* player);
	void draw();
	void executar();


};

