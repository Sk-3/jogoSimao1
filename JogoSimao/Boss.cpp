#include "Boss.h"


namespace Entidades{
	namespace Personagens{
		Boss::Boss(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis)
			:Inimigo(size, pos)
		{
			/**
			*@brief Construtor da classe Boss, inicializa o boss com o tamanho, posi��o, player e projeteis.
			* @param size Tamanho do boss.
			* @param pos Posi��o do boss.
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

		bool Boss::jogadorNoAlcance()
		{
			/**
			*@brief Verifica se o jogador est� dentro do alcance do boss.
			*@return Retorna 1 se o jogador estiver dentro do alcance, 0 caso contr�rio.
			*/

			//Vetor do boss at� o jogador:
			sf::Vector2f dist;
			dist.x = pPlayer->getPosition().x - getPosition().x;
			dist.y = pPlayer->getPosition().y - getPosition().y;
			//modulo da distancia
			double modDist = sqrt((dist.x * dist.x) + (dist.y * dist.y));
			if (modDist < range) {
				return 1; 
			}

			return 0; 
		}

		void Boss::perseguirJogador()
		{
			/**
			*@brief Move o boss na dire��o do jogador, se o jogador estiver no alcance.
			*/
			if(getPosition().x - pPlayer->getPosition().x < 0){
				speed.x = 2;
				direction = Directions::RIGHT;
			}
			else {
				speed.x = -2;
				direction = Directions::LEFT;
			}
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