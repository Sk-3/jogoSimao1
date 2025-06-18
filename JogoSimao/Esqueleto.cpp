#include "Esqueleto.h"


namespace Entidades{
	namespace Personagens{
		Esqueleto::Esqueleto(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, int forca)
			:Inimigo( pos, player, listaEntidade, gerenciadorColisao)
		{
			/**
			*@brief Construtor da classe Boss, inicializa o boss com o tamanho, posição, player e projeteis.
			* @param size Tamanho do boss.
			* @param pos Posição do boss.
			* @param player Ponteiro para o jogador, usado para perseguir o jogador.
			* @param projeteis Vetor de projeteis, usado para adicionar novos projeteis.
			*/
			tipo = TipoPersonagem::INIMIGO;
			arma = new Arma(this, Armas::ARMAESQUELETO);
			Clocktiro.restart();
			range = 800;
			pPlayer = player;
			this->forca = forca;
			health = 5 + (5 * forca);
			shape.setTexture(*pGerGraphic->getBoss());
			shape.setTextureRect(sf::IntRect(0, 0, 81, 89));
			shape.setScale(1.5, 1.5);
		}

		Esqueleto::~Esqueleto()
		{
		}

		

		void Esqueleto::executar() {

			
			if (!vivo()) {
				desativar();
			}
			if (jogadorNoAlcance()) {
				perseguirJogador();
				atirar(listaEntidade, gerColisao);
			}
			else {
				speed.x = 0;
			}

			move();
		}
	}
}