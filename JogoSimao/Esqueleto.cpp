#include "Esqueleto.h"


namespace Entidades{
	namespace Personagens{
		Esqueleto::Esqueleto(sf::Vector2f pos, Personagem* player, int forca)
			:Inimigo( pos, player)
		{
			id = Id::Esqueleto;
			tipo = TipoPersonagem::INIMIGO;
			arma = new Arma(this, Armas::ARMAESQUELETO);
			this->forca = forca;
			health = 5 + (5 * forca);
			range = 800;
			nivel_maldade = 2 + (rand() % 10);
			pPlayer = player;			
			shape.setTexture(*pGerGraphic->getTextura(Texturas::boss));
			shape.setTextureRect(sf::IntRect(0, 0, 81, 89));
			shape.setScale(1 + (float)nivel_maldade / 10, 1 + (float)nivel_maldade / 10);
		}

		Esqueleto::~Esqueleto()
		{
		}

		

		void Esqueleto::danificar(Jogador* jogador)
		{
			if (danoContatoRelogio.getElapsedTime().asSeconds() > danoContatoCooldown) {
				danoContatoRelogio.restart();
				jogador->tiraVida(nivel_maldade);
			}
		}

		void Esqueleto::executar() {

			caiuDoMapa();
			if (!vivo()) {
				desativar();
				diminuirInimigos();
			}
			if (jogadorNoAlcance()) {
				perseguirJogador();
				atirar();
			}
			else {
				speed.x = 0;
			}

			move();
		}
		std::string Esqueleto::salvar()
		{
			salvarEsqueleto();
			return buffer.str();
		}

		void Esqueleto::salvarEsqueleto()
		{
			salvarInimigo();
			buffer << forca << " ";
		}
	}
}