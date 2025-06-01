#include "Projetil.h"
#include "Character.h"

namespace Entidades{

	Projetil::Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction, TipoPersonagem tipo)
		:Entity(size, pos), dano(3), tipo(tipo), ativo(1)
	{
		/**
		*@brief Inicializa o projetil com o tamanho, posicao e direcao
		*@param size Tamanho do projetil
		*@param pos Posicao do projetil
		*@param direction Direcao do projetil (LEFT ou RIGHT)
		*@param tipo Tipo do personagem que disparou o projetil
		*@details Se o tipo for LEFT, o projetil se move para a esquerda, caso contrario, para a direita.
		*/
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
		/**
		*@brief Executa o projetil, movendo-o e desenhando-o na tela
		*@return void
		*/
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
		/**
		*@brief Desativa o projetil, tornando-o inativo
		*@return void
		*/
		ativo = 0; 
	}
	void Projetil::setTipo(TipoPersonagem tipo)
	{
		/**
		*@brief Define o tipo do projetil
		*@param tipo Tipo do personagem que disparou o projetil
		*@return void
		*/
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