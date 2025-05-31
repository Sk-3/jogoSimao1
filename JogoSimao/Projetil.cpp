#include "Projetil.h"
#include "Character.h"

namespace Entidades{

	Projetil::Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction, TipoPersonagem tipo)
		:Entity(size, pos), dano(3), tipo(tipo), ativo(1)
	{
		clock.restart();
		if (direction == Directions::LEFT) {
			speed = sf::Vector2f(-35.f, 0.f);
		}
		else {
			speed = sf::Vector2f(35.f, 0.f);
		}
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
	void Projetil::setTipo(TipoPersonagem tipo)
	{
		this->tipo = tipo;
	}

	const TipoPersonagem Projetil::getTipo() const
	{
		return tipo;
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