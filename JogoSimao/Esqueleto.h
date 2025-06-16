#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "Arma.h"

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

		class Esqueleto : public Inimigo
		{
		private:
		public:
			Esqueleto(sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis);
			~Esqueleto();
			void executar();
			void atirar();
		};

}
}
