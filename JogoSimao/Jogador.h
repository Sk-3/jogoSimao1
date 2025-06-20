#pragma once
#include "Personagem.h"
#include "Id.h"
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
		class Jogador : public Personagem
		{
		private:

			int pontos;
			float maxSpeed;
			sf::Vector2f center;
		public:
			Jogador();
			Jogador(sf::Vector2f pos);
			~Jogador();
			sf::Vector2f getPosition();
			//Adicionam velocidade ao vetor de velocidade do jogador
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();
			void posicionarNoInicio();
			void dash();
			void stopAxisX();
			void aumentarPontos();
			int getPontos();
			
			void executar(); 
			void salvar();
			void salvarJogador();
		};
	}

}
