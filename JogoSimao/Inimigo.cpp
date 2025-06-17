#include "Inimigo.h"
#include "Arma.h"
#include "ListaEntidades.h"
namespace Entidades{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos, Listas::ListaEntidades* listaEnt, Personagem* jogador)
			:Personagem(pos, listaEnt), pJogador(jogador)
		{
			pProjeteis = listaEnt->getProjeteis();
			nivel_maldade = 0;
			range = 1000;
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
			dist.x = pJogador->getCenter().x - getCenter().x;
			dist.y = pJogador->getCenter().y - getCenter().y;
			//modulo da distancia
			double modDist = sqrt((dist.x * dist.x) + (dist.y * dist.y));
			if (modDist < range) {
				return 1;
			}

			return 0;
		}


		const Personagem* Inimigo::getJogador() const
		{
			return pJogador;
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
		*@brief Move o inimigo na direção do jogador, se o jogador estiver no alcance.
		*/
			if (getPosition().x - pJogador->getPosition().x < 0) {
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