#pragma once
#include "Personagem.h"
/**
*	Classe concreta Player
* 
*	Representa o jogador principal
* 
*	é responsável por alterar a velocidade do jogador e realizar ações com base nos comandos chamados pelo objeto Fase
*/

namespace Entidades{
	class Projetil;
	namespace Personagens{
		class Player : public Personagem
		{
		private:

			
			float maxSpeed;
			sf::Vector2f center;
		public:
			Player();
			Player(sf::Vector2f size, sf::Vector2f pos,std::vector<Projetil*>* projeteis);
			~Player();
			sf::Vector2f getPosition();
			//Adicionam velocidade ao vetor de velocidade do jogador
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();
			void dash();
			void stopAxisX();
			void executar(); 
			void atirar();
		};
	}

}
