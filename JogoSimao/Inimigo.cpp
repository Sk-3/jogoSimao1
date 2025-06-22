#include "Inimigo.h"
#include "Arma.h"
int Entidades::Personagens::Inimigo::quantidadeInimigos = 0;
namespace Entidades{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEnt, Gerenciadores::GerenciadorColisao* gerenciadorColisao)
			:Personagem(pos), pPlayer(player), gerColisao(gerenciadorColisao), listaEntidade(listaEnt)
		{
			danoContatoCooldown = 1;
			quantidadeInimigos++;
			nivel_maldade = 0;
			range = 1000;
		}

		Inimigo::~Inimigo() {

		}

		void Inimigo::setNivelMaldade(int maldade)
		{
			nivel_maldade = maldade;
			shape.setScale(1 + (float)nivel_maldade / 10, 1 + (float)nivel_maldade / 10);
		}

		void Inimigo::zerarInimigos()
		{
			quantidadeInimigos = 0;
		}

		void Inimigo::diminuirInimigos()
		{
			quantidadeInimigos--;
		}

		void Inimigo::aumentarPontos() {

		}

		void Inimigo::salvarInimigo()
		{
			salvarPersonagem();
			buffer << nivel_maldade << " ";
		}

		bool Inimigo::jogadorNoAlcance()
		{
			/**
			*@brief Verifica se o jogador está dentro do alcance do inimigo.
			*@return Retorna 1 se o jogador estiver dentro do alcance, 0 caso contrário.
			*/

			//Vetor do boss até o jogador:
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

		void Inimigo::setAtivo(bool at){
			ativo = at;
			if (!ativo) {
				diminuirInimigos();
			}
		}
		const Personagem* Inimigo::getPlayer() const
		{
			return pPlayer;
		}

		int Inimigo::getQuantidadeInimigos()
		{
			return quantidadeInimigos;
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