#pragma once
#include "Armas.h"
#include "Projetil.h"
#include <vector>

namespace Entidades {
	namespace Personagens {
		class Character;
	}
}


class Arma
{
private:
	Entidades::Personagens::Character* pDono;
	float VelocidadeProjetil;
	sf::Clock Clocktiro;
	float tiroCooldown;
	std::vector<Entidades::Projetil*>* pProjeteis;
public:
	Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Character* pDono, float tiroCooldown);
	Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Character* pDono, Armas arma);
	~Arma();
	void atirar();

};

