#include "Boss.h"


namespace Entidades{
	namespace Personagens{
		Boss::Boss(sf::Vector2f size, sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis)
			:Inimigo(size, pos, player, projeteis)
		{
			/**
			*@brief Construtor da classe Boss, inicializa o boss com o tamanho, posição, player e projeteis.
			* @param size Tamanho do boss.
			* @param pos Posição do boss.
			* @param player Ponteiro para o jogador, usado para perseguir o jogador.
			* @param projeteis Vetor de projeteis, usado para adicionar novos projeteis.
			*/

			arma = new Arma(pProjeteis, this, Armas::ARMABOSS);
			Clocktiro.restart();
			range = 1000;
			pProjeteis = projeteis;
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