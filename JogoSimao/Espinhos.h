#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo
		{
		private:
			sf::Clock danoRelogio;
			float danoCooldown;
		public:
			Espinhos(sf::Vector2f size, sf::Vector2f pos);
			Espinhos();
			~Espinhos();
			const float getDanoCooldown() const;
			const float getDanoRelogio() const;
			void obstacular(Personagens::Personagem* pPlayer);
			void executar();
		};

	}
}

