#include "Boss.h"


namespace Entidades{
	namespace Personagens{
		Boss::Boss(sf::Vector2f pos,Listas::ListaEntidades* lista ,Personagem* player)
			:Inimigo( pos,lista ,player)
		{
			/**
			*@brief Construtor da classe Boss, inicializa o boss com o tamanho, posição, player e projeteis.
			* @param size Tamanho do boss.
			* @param pos Posição do boss.
			* @param player Ponteiro para o jogador, usado para perseguir o jogador.
			* @param projeteis Vetor de projeteis, usado para adicionar novos projeteis.
			*/

			arma = new Arma(lista , this, Armas::ARMABOSS);;
			range = 1000;
			pPlayer = player;
			health = 30;
		}

		Boss::~Boss()
		{
		}

		

		void Boss::executar() {
			if (jogadorNoAlcance()) {
				perseguirJogador();
				atirar();
			}
			else {
				speed.x = 0;
			}
			move();
		}
		void Boss::atirar()
		{
			/**
			*@brief Executa o metodo atirar da arma 
			* 
			*/
			arma->atirar();
		}
	}
}