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
			Gerenciadores::GerenciadorColisao* gc;
			Listas::ListaEntidades* listaEnt;
			float velocidade;			
			Personagem* pDono;
			EstadoCachorro* estadoAtual;
		public:
			Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, Personagem* dono);
			Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao);
			~Cachorro();
			//SETTERS
			void setEstado(EstadoCachorro* novoEstado);
			void setRange(float range);
			void mandarAtacar();
			void mandarCacar();
			void mandarSeguir();		
			
			void seguirDono();

			void danificar(Jogador* jogador);
			void salvar();
			void salvarCachorro();
			void executar();

		};
	}
}
