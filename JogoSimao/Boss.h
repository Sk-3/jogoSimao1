#pragma once
#include "Inimigo.h"
#include "Projetil.h"

/**
*	
*@file Boss.h
*@brief Declaração da classe Boss.
*@details
*Esta classe representa um inimigo mais poderoso no jogo, que herda de Inimigo.
*@data 30/05/2025
*@autor Felipe Simbalista
*/
namespace Entidades{
	namespace Personagens{

		class Boss : public Inimigo
		{
		private:
			std::vector<Projetil*>* pProjeteis;
			Character* pPlayer;
			float range;
		public:
			Boss(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis);
			Boss();
			~Boss();
			bool jogadorNoAlcance();
			void perseguirJogador();
			void executar();
			void atirar();
		};

}
}
