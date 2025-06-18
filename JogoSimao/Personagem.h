#pragma once
#include "Entidade.h"
#include "TipoPersonagem.h"
#include "ListaEntidades.h"
#include "Armas.h"


/**
*	Felipe Simbalista: 25/05/2025
* Classe abstrata de personagens
*	 responsável por:
*		responder a colisões
*		controlar seus status(health, speed, power, jumps)
*		movimentar o personagem com base na sua velocidade
*/
namespace Gerenciadores {
	class GerenciadorColisao;
}
class Arma;
namespace Entidades{

	namespace Obstaculos{
		class Obstaculo;
	}

	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			//clock que controla o tempo de tiro do personagem
			sf::Clock Clocktiro;
			float tiroCooldown;
			Arma* arma;
			//tipo do personagem, usado para identificar o personagem e suas habilidades
			TipoPersonagem tipo;
			float maxSpeed;
			float moveSpeed;
			int health; 
			int power;
			int jumps;
			//direção do personagem, usada para saber se o personagem está virado para a direita ou esquerda
			Directions direction;
		public:
			//construtor padrão
			Personagem();
			//define posição e tamanho inicial do personagem
			Personagem(sf::Vector2f pos);
			~Personagem();

			void atirar(Listas::ListaEntidades* listaEntidade,Gerenciadores::GerenciadorColisao* gerenciadorColisao);
			//RELACIONADO A COLISÃO
				//Funções que não permitem o jogador entrar dentro do obstaculo passado como parametro
			void colidiu(Entidade* entidade, Directions direction);
			void hitTop(Entidade* entidade);
				void hitGround(Entidade* entidade);
				void hitLeft (Entidade* entidade);
				void hitRight(Entidade* entidade);
				
			//GETTERS
				const TipoPersonagem getTipo() const;
				const Directions getDirection() const;
				const int getHealth() const;
				const float getClockTiro() const;
				const float getTiroCoooldown() const;
				const bool vivo() const;

			//SETTERS
				void tiraVida(int dano);
				void resetClockTiro();
				void setMoveSpeed(float moveSpeed);
				

			//FUNÇÕES BASE
			virtual void executar() = 0;
			
		};
	}
}