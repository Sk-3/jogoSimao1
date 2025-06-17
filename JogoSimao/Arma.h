#pragma once
#include "Armas.h"
#include "Projetil.h"
#include <vector>

namespace Entidades {
	namespace Personagens {
		class Personagem;
	}
}


class Arma
{
private:
	Entidades::Personagens::Personagem* pDono;
	float VelocidadeProjetil;
	sf::Clock Clocktiro;
	float tiroCooldown;
	std::vector<Entidades::Projetil*>* pProjeteis;
public:
	Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Personagem* pDono, float tiroCooldown);
	Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Personagem* pDono, Armas arma);
	~Arma();
	void atirar();

};

