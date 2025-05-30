#pragma once
#include "Ente.h"
#include "sstream"
#include "Player.h"
class Hud : public Ente
{
private:
	sf::Clock hudClock;
	Entidades::Player* player;
	sf::Text hud;
public:
	Hud();
	~Hud();
	void setPlayer(Entidades::Player* player);
	void draw();
	void executar();


};

