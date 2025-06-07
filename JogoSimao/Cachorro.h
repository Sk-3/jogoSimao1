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
			Character* pDono;
			EstadoCachorro* estadoAtual;
		public:
			Cachorro(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, Character* dono);
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
