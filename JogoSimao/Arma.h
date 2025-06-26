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
			static ListaEntidades* listaEntidades;
			static Gerenciadores::GerenciadorColisao* gerenciadorColisao;
			Entidades::Personagens::Personagem* pDono;
			float VelocidadeProjetil;
			sf::Clock Clocktiro;
			float tiroCooldown;
		public:
			Arma(Entidades::Personagens::Personagem* pDono, Armas arma);
			~Arma();
			void atirar();
			static void setContexto(Gerenciadores::GerenciadorColisao*, ListaEntidades*);

		};
	}
}


