#pragma once
#include "Obstaculo.h"
/**
*	Ramon Vargas: 14/06/2025
*
*	Classe concreta Fosso
*
*	Fosso com com largura variável
*
*/

namespace Entidades {
	namespace Obstaculos {
		class Fosso: public Obstaculo
		{
		private:
			float largura;
			bool obstaculou;

		public:
			Fosso(sf::Vector2f pos, float largura);
			Fosso();
			~Fosso();
			void obstacular(Personagens::Personagem* pPersonagem);
			void desabar();
			void antiGravidade();
			void executar();
		};
	}
}
