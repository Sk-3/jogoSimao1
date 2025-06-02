#include "Inimigo.h"
namespace Entidades{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis)
			:Character(size, pos), pPlayer(player), pProjeteis(projeteis)
		{
			nivel_maldade = 0;
			shape.setFillColor(sf::Color::Red);
		}

		Inimigo::Inimigo()
		{
			nivel_maldade = 0;
			shape.setFillColor(sf::Color::Green);
			shape.setSize(sf::Vector2f(50.f, 50.f));
			shape.setPosition(sf::Vector2f(100.f, 100.f));
		}
		Inimigo::~Inimigo() {

		}



		bool Inimigo::jogadorNoAlcance()
		{
			/**
			*@brief Verifica se o jogador está dentro do alcance do inimigo.
			*@return Retorna 1 se o jogador estiver dentro do alcance, 0 caso contrário.
			*/

			//Vetor do boss até o jogador:
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


		const Character* Inimigo::getPlayer() const
		{
			return pPlayer;
		}

		void Inimigo::executar()
		{
			move();
			pGerGraphic->getWindow()->draw(shape);
		}

		void Inimigo::perseguirJogador() {
		/**
		*@brief Move o inimigo na direção do jogador, se o jogador estiver no alcance.
		*/
			if (getPosition().x - pPlayer->getPosition().x < 0) {
				speed.x = moveSpeed;
				direction = Directions::RIGHT;
			}
			else {
				speed.x = -moveSpeed;
				direction = Directions::LEFT;
			}
		}
	}
}