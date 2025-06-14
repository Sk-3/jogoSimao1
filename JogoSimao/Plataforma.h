#pragma once
#include "Obstaculo.h"
/**
*	Felipe Simbalista: 25/05/2025
*	Ramon Vargas: 12/06/2025
* 
*	Classe concreta Plataforma
*	
*	Plataforma móvel com velocidade e limites variáveis
*	
*/

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo
		{
		private:
			bool topo, fundo;
			float max, min;

		public:
			Plataforma(sf::Vector2f pos, float vel, float h_Max, float h_Min);
			Plataforma();
			~Plataforma();
			virtual void obstacular(Personagens::Personagem* pPlayer);
			void mover();
			void executar();
		};

	}

}