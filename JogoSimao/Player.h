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
	class Projetil;
	namespace Personagens{
		class Player : public Character
		{
		private:
			
			float maxSpeed;
			sf::Vector2f center;
		public:
			Player();
			Player(sf::Vector2f size, sf::Vector2f pos);
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
			void atirar(std::vector<Projetil*>* projeteis);
		};
	}

}
