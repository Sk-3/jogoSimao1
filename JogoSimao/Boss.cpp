#include "Boss.h"
#include "iostream"

namespace Entidades{
	namespace Personagens{
		Boss::Boss(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis)
			:Inimigo(size, pos)
		{
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
			//Vetor do boss até o jogador:
			sf::Vector2f dist;
			dist.x = pPlayer->getPosition().x - getPosition().x;
			dist.y = pPlayer->getPosition().y - getPosition().y;
			//modulo da distancia
			double modDist = sqrt((dist.x * dist.x) + (dist.y * dist.y));

			std::cout << modDist << "\n";
			if (modDist < range) {
				return 1; 
			}

			return 0; 
		}

		void Boss::perseguirJogador()
		{
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
			if (getClockTiro() > getTiroCoooldown()) {
				sf::Vector2f position = getPosition();
				position.y += (getBounds().height / 2);
				if (getDirection() != Directions::LEFT) {
					position.x += getBounds().width;
				}
				pProjeteis->push_back(new Projetil(sf::Vector2f(10.0, 10.0), position, getDirection()));
				resetClockTiro();
			}
		}
	}
}