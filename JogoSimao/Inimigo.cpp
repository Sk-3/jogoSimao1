#include "Inimigo.h"
#include "Arma.h"
namespace Entidades{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis)
			:Personagem(pos), pPlayer(player), pProjeteis(projeteis)
		{
			nivel_maldade = 0;
		}

		Inimigo::~Inimigo() {

		}



		bool Inimigo::jogadorNoAlcance()
		{
			/**
			*@brief Verifica se o jogador est� dentro do alcance do inimigo.
			*@return Retorna 1 se o jogador estiver dentro do alcance, 0 caso contr�rio.
			*/

			//Vetor do boss at� o jogador:
			sf::Vector2f dist;
			dist.x = pPlayer->getCenter().x - getCenter().x;
			dist.y = pPlayer->getCenter().y - getCenter().y;
			//modulo da distancia
			double modDist = sqrt((dist.x * dist.x) + (dist.y * dist.y));
			if (modDist < range) {
				return 1;
			}

			return 0;
		}


		const Personagem* Inimigo::getPlayer() const
		{
			return pPlayer;
		}

		void Inimigo::atirar() {
			arma->atirar();
		}

		void Inimigo::executar()
		{
			move();
		}

		void Inimigo::perseguirJogador() {
		/**
		*@brief Move o inimigo na dire��o do jogador, se o jogador estiver no alcance.
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