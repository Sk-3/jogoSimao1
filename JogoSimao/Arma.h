#pragma once
#include "Armas.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include <vector>

namespace Entidades {
	namespace Personagens {
		class Personagem;
		class Arma
		{
		private:
			Gerenciadores::GerenciadorColisao* gerenciadorColisao;
			Entidades::Personagens::Personagem* pDono;
			float VelocidadeProjetil;
			sf::Clock Clocktiro;
			float tiroCooldown;
		public:
			Arma(Entidades::Personagens::Personagem* pDono, Armas arma);
			~Arma();
			void atirar(Listas::ListaEntidades* lista,Gerenciadores::GerenciadorColisao* gerColisao);

		};
	}
}


