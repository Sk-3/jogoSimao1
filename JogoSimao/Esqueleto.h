#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "Arma.h"

/**
*	
*@file Esqueleto.h
*@brief Declaração da classe Esqueleto.
*@details
*Esta classe representa um inimigo mais poderoso no jogo, que herda de Inimigo.
*@data 15/06/2025
*@autor Ramon Vargas
*/
namespace Entidades{
	namespace Personagens{

		class Esqueleto : public Inimigo
		{
		private:
			int forca;
		public:
			Esqueleto(sf::Vector2f pos,ListaEntidades* lista, Personagem* player, int forca);
			~Esqueleto();
			void executar();
			void atirar();
		};

}
}
