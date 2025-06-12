#pragma once
#include "Obstaculo.h"
/**
*	Ramon Vargas: 11/06/2025
*
*	Classe teste de Plataforma
*
*
*/

namespace Entidades {
	namespace Obstaculos {
		class PlataformaTeste : public Obstaculo
		{
		private:	
			bool max, min;

		public:
			PlataformaTeste(sf::Vector2f size, sf::Vector2f pos, float vel);
			PlataformaTeste();
			~PlataformaTeste();
			virtual void obstacular(Personagens::Personagem* pPlayer);
			void mover();
			void executar();
		};

	}

}
