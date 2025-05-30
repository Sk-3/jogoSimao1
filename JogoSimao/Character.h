#pragma once
#include "Subject.h"
#include "Entity.h"
#include "TipoPersonagem.h"
/**
*	Felipe Simbalista: 25/05/2025
* Classe abstrata de personagens
*	 respons�vel por:
*		responder a colis�es
*		controlar seus status(health, speed, power, jumps)
*		movimentar o personagem com base na sua velocidade
*/
namespace Entidades{

	namespace Obstaculos{
		class Obstaculo;
	}

	namespace Personagens {
		class Character : public Entity, public Subject
		{
		protected:
			sf::Clock Clocktiro;
			float tiroCooldown;
			TipoPersonagem tipo;
			float maxSpeed;
			float moveSpeed;
			int health; 
			int power;
			int jumps;
			Directions direction;
		public:
			//construtor padr�o
			Character();
			//define posi��o e tamanho inicial do personagem
			Character(sf::Vector2f size, sf::Vector2f pos);
			~Character();
			//Fun��es que n�o permitem o jogador entrar dentro do obstaculo passado como parametro
			virtual void hitTop(Obstaculos::Obstaculo* obstaculo);
			//se atinge o ch�o, � movido pra cima, e assim � com todas as outras fun��es
			virtual void hitGround(Obstaculos::Obstaculo* obstaculo);
			virtual void hitLeft (Obstaculos::Obstaculo* obstaculo);
			virtual void hitRight(Obstaculos::Obstaculo* obstaculo);
	
			void tiraVida(int dano);
			const TipoPersonagem getTipo() const;
			const Directions getDirection() const;
			const int getHealth() const;
			const bool vivo() const;
			virtual void executar() = 0;
			virtual void draw();
			const float getClockTiro() const;
			const float getTiroCoooldown() const;
			void resetClockTiro();
		};
	}
}