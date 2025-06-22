#pragma once
#include "Ente.h"
#include "sstream"
#include "Jogador.h"
class Hud : public Ente
{
private:
	Entidades::Personagens::Jogador* player2;
	Entidades::Personagens::Jogador* player;
	sf::Text hud;
public:
	Hud();
	~Hud();
	void setPlayer2(Entidades::Personagens::Jogador* player);
	void setPlayer(Entidades::Personagens::Jogador* player);
	void draw();
	void executar();


};

