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

namespace Entidades{

	namespace Obstaculos{
		class Obstaculo;
	}

	namespace Personagens {
		class Arma;
		class Personagem : public Entidade
		{
		protected:
			Arma* arma;
			//tipo do personagem, usado para identificar o personagem e suas habilidades
			TipoPersonagem tipo;
			float maxSpeed;
			float moveSpeed;
			sf::Clock RelogioPuloCooldown;
			float puloCooldown = 0.2;
			int health; 
			int jumps = 2;
			int danoArma = 3;
			//direção do personagem, usada para saber se o personagem está virado para a direita ou esquerda
			Directions direction;
		public:
			//construtor padrão
			Personagem();
			Personagem(sf::Vector2f pos);
			~Personagem();
			void atirar();
			void colidiu(Entidade* entidade, Directions direction);
			//GETTERS
				const TipoPersonagem getTipo() const;
				const Directions getDirection() const;
				const int getHealth() const;
				const bool vivo() const;
				const int getDanoArma() const;

			//SETTERS
				void setVida(int vida);
				void setPulos(int pulos);

				void caiuDoMapa();
				virtual void aumentarPontos() = 0;
				void tiraVida(int dano);
				void setMoveSpeed(float moveSpeed);
				

			//FUNÇÕES BASE
				void salvarPersonagem();
				virtual std::string salvar() = 0;
				virtual void executar() = 0;
			
		};
	}
}