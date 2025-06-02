#include "Boss.h"


namespace Entidades{
	namespace Personagens{
		Boss::Boss(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis)
			:Inimigo(size, pos, player, projeteis)
		{
			/**
			*@brief Construtor da classe Boss, inicializa o boss com o tamanho, posição, player e projeteis.
			* @param size Tamanho do boss.
			* @param pos Posição do boss.
			* @param player Ponteiro para o jogador, usado para perseguir o jogador.
			* @param projeteis Vetor de projeteis, usado para adicionar novos projeteis.
			*/
			Clocktiro.restart();
			range = 1000;
			pProjeteis = projeteis;
			pPlayer = player;
			shape.setFillColor(sf::Color::Magenta);
			health = 30;
		}

		Boss::Boss()
		{
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
			*@brief Adiciona um projetil a pProjeteis se o cooldown de tiro estiver pronto.
			* 
			*/
			if (getClockTiro() > getTiroCoooldown()) {
				sf::Vector2f position = getPosition();
				position.y += (getBounds().height / 2);
				if (getDirection() != Directions::LEFT) {
					position.x += getBounds().width;
				}
				pProjeteis->emplace_back(new Projetil(sf::Vector2f(10.0, 10.0), position, getDirection(), tipo));
				resetClockTiro();
			}
		}
	}
}