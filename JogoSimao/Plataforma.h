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
			bool topo, fundo, obstaculou;
			float max, min; 

		public:
			Plataforma(sf::Vector2f pos, float vel, float h_Max, float h_Min);
			Plataforma();
			~Plataforma();
			void obstacular(Personagens::Personagem* pPersonagem);
			void mover();
			void executar();
		};

	}

}