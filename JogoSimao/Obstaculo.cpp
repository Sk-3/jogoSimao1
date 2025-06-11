#include "Obstaculo.h"
namespace Entidades{
	namespace Obstaculos{
		Obstaculo::Obstaculo(sf::Vector2f size, sf::Vector2f pos)
		:Entity(size, pos)
		{
			colidivel = 1;
			isColiding = 0; 
			danoso = 0;
		}

		Obstaculo::Obstaculo()
		{
			colidivel = 1;
			isColiding = 0;
			danoso = 0;
		}

		Obstaculo::~Obstaculo()
		{
		}

		const bool Obstaculo::ehColidivel()
		{
			return colidivel;
		}

		void Obstaculo::setIsColiding(bool col)
		{
			isColiding = col;
		}

		void Obstaculo::obstacular(Personagens::Personagem* pPlayer)
		{
		}
	}
}