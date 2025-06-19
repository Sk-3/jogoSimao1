#include "Projetil.h"
#include "Personagem.h"

namespace Entidades{

	Projetil::Projetil( sf::Vector2f pos, Personagens::Personagem* pDono)
		:Entidade(pos), dano(3), dono(pDono)
	{
		/**
		*@brief Inicializa o projetil com o tamanho, posicao e direcao
		*@param pos Posicao do projetil
		*@param tipo Tipo do personagem que disparou o projetil
		*/
		tipo = pDono->getTipo();
		clock.restart();
		if (dono->getDirection() == Directions::LEFT) {
			speed = sf::Vector2f(-35.f, 0.f);
		}
		else {
			speed = sf::Vector2f(35.f, 0.f);
		}

		if (dono->getTipo() == TipoPersonagem::INIMIGO)
		{
			shape.setTexture(*pGerGraphic->getFireball());
			shape.setTextureRect(sf::IntRect(0,0,64,64));
			shape.setScale(0.4, 0.4);
		}
	}

	Projetil::Projetil()
		:Entidade()
	{
		dano = 0;
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
			desativar();
		}
		if(ativado()){
			move();
		}
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

	void Projetil::aumentaPontosDono()
	{
		dono->aumentarPontos();
	}

}