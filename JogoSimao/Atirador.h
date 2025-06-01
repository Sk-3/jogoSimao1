#pragma once
#include "Inimigo.h"
/**
* @file Atirador.h
* @brief Declaração da classe Atirador, que herda de Inimigo.
* @autor Felipe Simbalista
* @data 01/06/2025
**/

namespace Entidades{
	namespace Personagens {
		class Atirador : public Inimigo
		{
		private:
			sf::Clock tempoTiro;
			sf::Time intervaloTiro = sf::seconds(1.0f);
		public:
			Atirador(sf::Vector2f size, sf::Vector2f pos);
			Atirador();
			~Atirador();
			void executar();

		};
	}
}
