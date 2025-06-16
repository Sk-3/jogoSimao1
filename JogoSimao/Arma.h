#pragma once
#include "Armas.h"
#include "Projetil.h"
#include <set>
#include "ListaEntidades.h"

namespace Entidades {
	namespace Personagens {
		class Personagem;
	}
}


class Arma
{
private:
	Listas::ListaEntidades* lista;
	Entidades::Personagens::Personagem* pDono;
	float VelocidadeProjetil;
	sf::Clock Clocktiro;
	float tiroCooldown;
	
public:
	Arma(Listas::ListaEntidades* lista, Entidades::Personagens::Personagem* pDono, Armas arma);
	~Arma();
	void atirar();

};

