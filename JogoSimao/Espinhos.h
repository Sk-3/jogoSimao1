#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo
		{
		private:
			sf::Clock danoRelogio;
			float danoCooldown;
			float altura;
		public:
			Espinhos(sf::Vector2f pos, float altura = 1);
			Espinhos();
			~Espinhos();
			const float getDanoCooldown() const;
			const float getDanoRelogio() const;
			void obstacular(Personagens::Personagem* pPersonagem);
			void executar();
		};

	}
}

