#include "Projetil.h"
#include "Personagem.h"

namespace Entidades{

	Projetil::Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction, TipoPersonagem tipo)
		:Entidade(size, pos), dano(3), tipo(tipo), ativo(1)
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
		:Entidade()
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
		/**
		*@brief Retorna o tipo do projetil
		*@return TipoPersonagem Tipo do personagem que disparou o projetil
		*/
		return tipo;
	}
	bool Projetil::Ativado()
	{
		/**
		*@brief Verifica se o projetil esta ativo
		*@return bool Retorna true se o projetil esta ativo, false caso contrario
		*/
		return ativo;
	}

	void Projetil::danifica(Personagens::Personagem* personagem)
	{
		/**
		*@brief Aplica dano ao personagem atingido pelo projetil
		*@param personagem Ponteiro para o personagem que foi atingido pelo projetil
		*@details Utilizando a referencia do personagem, chama o metodo tiraVida para aplicar o dano do projetil.
		*@return void
		*/
		personagem->tiraVida(dano);
	}

}