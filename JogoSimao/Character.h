#pragma once
#include "Entity.h"
#include "TipoPersonagem.h"
/**
*	Felipe Simbalista: 25/05/2025
* Classe abstrata de personagens
*	 responsável por:
*		responder a colisões
*		controlar seus status(health, speed, power, jumps)
*		movimentar o personagem com base na sua velocidade
*/
namespace Entidades{

	class Obstaculo;

	class Character : public Entity
	{
	protected:
		TipoPersonagem tipo;
		float maxSpeed;
		float moveSpeed;
		int health; 
		int power;
		int jumps;
		Directions direction;
	public:
		//construtor padrão
		Character();
		//define posição e tamanho inicial do personagem
		Character(sf::Vector2f size, sf::Vector2f pos);
		~Character();
		//Funções que não permitem o jogador entrar dentro do obstaculo passado como parametro
		virtual void hitTop(Obstaculo* obstaculo);
		//se atinge o chão, é movido pra cima, e assim é com todas as outras funções
		virtual void hitGround(Obstaculo* obstaculo);
		virtual void hitLeft (Obstaculo* obstaculo);
		virtual void hitRight(Obstaculo* obstaculo);
	
		void tiraVida(int dano);
		const TipoPersonagem getTipo() const;
		const Directions getDirection() const;
		const int getHealth() const;
		const bool vivo() const;
		virtual void executar() = 0;
		virtual void draw();

	};

}