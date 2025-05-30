#include "Plataforma.h"
namespace Entidades{
	Plataforma::Plataforma(sf::Vector2f size, sf::Vector2f pos)
		:Obstaculo(size, pos)
	{
	}

	Plataforma::Plataforma()
	{

	}

	Plataforma::~Plataforma()
	{
	}

	void Plataforma::obstacular(Player* pPlayer)
	{
		pPlayer->changeSpeed(sf::Vector2f(0.f, 5.f));
	}

	void Plataforma::executar()
	{

		//se esta colidindo, muda a cor pra vermelho, caso contrário fica branco
		if (isColiding) {
			shape.setFillColor(sf::Color::Red);
		}
		else {
			shape.setFillColor(sf::Color::White);
		}

		//desenha a plataforma
		pGerGraphic->getWindow()->draw(shape);
	}
}