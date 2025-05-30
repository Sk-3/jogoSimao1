#include "Projetil.h"
#include "Character.h"

namespace Entidades{

	Projetil::Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction)
		:Entity(size, pos), dano(3)
	{


		clock.restart();
		if (direction == Directions::LEFT) {
			speed = sf::Vector2f(-35.f, 0.f);
		}
		else {
			speed = sf::Vector2f(35.f, 0.f);
		}
		ativo = 1;
	}

	Projetil::Projetil()
		:Entity()
	{
		dano = 0;
		ativo = 1;
	}

	Projetil::~Projetil()
	{
	}

	void Projetil::executar()
	{
		if(clock.getElapsedTime().asSeconds() > 0.5){
			ativo = 0;
		}
		if(ativo){
			move();
			pGerGraphic->getWindow()->draw(shape);
		}
	}

	void Projetil::desativar()
	{
		ativo = 0; 
	}

	bool Projetil::Ativado()
	{
		return ativo;
	}

	void Projetil::danifica(Personagens::Character* personagem)
	{
		personagem->tiraVida(dano);
	}

}