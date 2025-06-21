#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinho : public Obstaculo 
		{
		private:
			sf::Clock danoRelogio;
			float danoCooldown;
			float altura;
		public:
			Espinho(sf::Vector2f pos, float altura = 1);
			Espinho();
			~Espinho();
			void setAltura(float alt);
			const float getDanoCooldown() const;
			const float getDanoRelogio() const;
			void obstacular(Personagens::Personagem* pPersonagem);
			void executar();
			std::string salvar();
			void salvarEspinho();
		};

	}
}

