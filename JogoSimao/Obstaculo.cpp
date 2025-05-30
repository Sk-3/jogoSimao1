#include "Obstaculo.h"
namespace Entidades{
	Obstaculo::Obstaculo(sf::Vector2f size, sf::Vector2f pos)
	:Entity(size, pos)
	{
		isColiding = 0; 
		danoso = 0;
	}

	Obstaculo::Obstaculo()
	{
		isColiding = 0;
		danoso = 0;
	}

	Obstaculo::~Obstaculo()
	{
	}

	void Obstaculo::setIsColiding(bool col)
	{
		isColiding = col;
	}

	void Obstaculo::obstacular(Player* pPlayer)
	{
	}
}