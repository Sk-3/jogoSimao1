#pragma once
#include "Entidade.h"
#include "Player.h"

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
			bool isColiding;
			bool danoso;
		public:
			Obstaculo(sf::Vector2f size, sf::Vector2f pos);
			Obstaculo();
			~Obstaculo();
			const bool ehColidivel();
			void setIsColiding(bool col);
			virtual void obstacular(Personagens::Personagem* pPlayer) = 0;
			virtual void executar() = 0; 
		};
	}
}