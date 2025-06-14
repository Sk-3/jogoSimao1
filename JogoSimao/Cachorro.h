#pragma once
#include "Inimigo.h"
#include "Arma.h"
#include "EstadoCachorro.h"
#include "EstadoCachorroAtacar.h"
#include "EstadoCachorroSeguir.h"
namespace Entidades{
	namespace Personagens {
		class Cachorro : public Inimigo
		{
		private:
			float velocidadeSeguindo;
			float velocidadeCacando;
			Personagem* pDono;
			EstadoCachorro* estadoAtual;
		public:
			Cachorro(sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis, Personagem* dono);
			~Cachorro();
			

			//SETTERS
			void setEstado(EstadoCachorro* novoEstado);
			void mandarAtacar();
			void mandarSeguir();
			//GETTERS
			const float getVelocidadeSeguindo() const;
			const float getVelocidadeCacando() const;
			
			void seguirDono();
			void executar();

		};
	}
}
