#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "Inimigo.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe abstrata Obstaculo
*	
*	Representa os objetos do jogo com que as entidades irão colidir
*/
namespace Entidades{
	namespace Obstaculos {
		class Obstaculo : public Entidade
		{
		protected:
			bool colidivel;
			bool danoso;
		public:
			Obstaculo(sf::Vector2f pos);
			Obstaculo();
			~Obstaculo();
			const bool ehColidivel();
			virtual void obstacular(Personagens::Personagem* pPlayer) = 0;
			virtual void executar() = 0; 
		};
	}
}