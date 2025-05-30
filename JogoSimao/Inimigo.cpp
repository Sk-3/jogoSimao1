#include "Inimigo.h"
namespace Entidades{
	Inimigo::Inimigo(sf::Vector2f size, sf::Vector2f pos)
		:Character(size, pos)
	{
		nivel_maldade = 0;
		shape.setFillColor(sf::Color::Red);
	}

	Inimigo::Inimigo()
	{
		nivel_maldade = 0;
		shape.setFillColor(sf::Color::Green);
		shape.setSize(sf::Vector2f(50.f, 50.f));
		shape.setPosition(sf::Vector2f(100.f, 100.f));
	}
	Inimigo::~Inimigo() {

	}

	void Inimigo::executar()
	{
		move();
		pGerGraphic->getWindow()->draw(shape);
	}
}