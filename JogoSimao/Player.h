#pragma once
#include "Character.h"
/**
*	Classe concreta Player
* 
*	Representa o jogador principal
* 
*	é responsável por alterar a velocidade do jogador e realizar ações com base nos comandos chamados pelo objeto Fase
*/

namespace Entidades{
	namespace Personagens{
		class Player : public Character
		{
		private:
			float maxSpeed;
			sf::Vector2f center;
		public:
			Player();
			sf::Vector2f getPosition();
			//Adicionam velocidade ao vetor de velocidade do jogador
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();
			void dash();
			void stopAxisX();
			void executar(); 
			void draw()override;
		};
	}

}
