#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos,Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao) :
			Inimigo(pos, player, listaEntidade, gerenciadorColisao)
		{
			arma = new Arma(this, Armas::RIFLE);


			Clocktiro.restart();
			range = 1000;
			health = 20;
			tipo = TipoPersonagem::INIMIGO;
			shape.setOrigin(getCenter());
			shape.setTexture(*pGerGraphic->getAtiradorTexture());
			shape.setTextureRect(sf::IntRect(0, 0, 46, 71));
			shape.setScale(2, 2);
		}
		Atirador::~Atirador()
		{
		}
		void Atirador::executar() {
			/**
			*@brief Executa o atirador
			*@return void
			*/
			if (!vivo()) {
				desativar();
			}
			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					if(cach->ativado()){
						cach->mandarCacar();
					}
				}

				if (pPlayer->getCenter().x > getCenter().x) {
					shape.setScale(2, 2);
					direction = Directions::RIGHT;
				}
				else {
					shape.setScale(-2, 2);
					direction = Directions::LEFT;
				}
				atirar(listaEntidade, gerColisao);

			}
			else {
				for (const auto& cach : cachorros) {
					if(cach->ativado()){
						cach->mandarSeguir();
					}
				}
			}

			move();
		}
	}
	
}