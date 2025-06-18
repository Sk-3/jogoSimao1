#pragma once
#include "Inimigo.h"
#include "Arma.h"
#include "EstadoCachorro.h"
#include "EstadoCachorroAtacar.h"
#include "EstadoCachorroCacar.h"
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
			Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, Personagem* dono);
			~Cachorro();
			//SETTERS
			void setEstado(EstadoCachorro* novoEstado);
			void mandarAtacar();
			void mandarCacar();
			void mandarSeguir();
			//GETTERS
			const float getVelocidadeSeguindo() const;
			const float getVelocidadeCacando() const;
			
			void seguirDono();
			void executar();

		};
	}
}
