#pragma once
#include "Entity.h"
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
		class Obstaculo : public Entity
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
			virtual void obstacular(Personagens::Character* pPlayer) = 0;
			virtual void executar() = 0; 
		};
	}
}