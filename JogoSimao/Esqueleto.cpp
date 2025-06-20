#include "Esqueleto.h"


namespace Entidades{
	namespace Personagens{
		Esqueleto::Esqueleto(sf::Vector2f pos, Jogador* jogador, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, int forca)
			:Inimigo( pos, jogador, listaEntidade, gerenciadorColisao)
		{
			id = Id::Esqueleto;
			
			tipo = TipoPersonagem::INIMIGO;
			arma = new Arma(this, Armas::ARMAESQUELETO);
			Clocktiro.restart();
			this->forca = forca;
			health = 5 + (5 * forca);
			range = 800;
			nivel_maldade = 2 + (rand() % 10);						
			shape.setTexture(*pGerGraphic->getBoss());
			shape.setTextureRect(sf::IntRect(0, 0, 81, 89));
			shape.setScale(1 + (float)nivel_maldade / 10, 1 + (float)nivel_maldade / 10);
		}

		Esqueleto::~Esqueleto()
		{
		}

		void Esqueleto::danificar(Jogador* pJogador)
		{
			atirar(listaEntidade, gerColisao);
		}	

		void Esqueleto::executar() {

			caiuDoMapa();
			if (!vivo()) {
				desativar();
				diminuirInimigos();
			}
			if (jogadorNoAlcance()) {
				perseguirJogador();
				danificar(this->getJogador());
			}
			else {
				speed.x = 0;
			}

			move();
		}
	}
}