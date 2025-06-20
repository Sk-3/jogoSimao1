#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos,Jogador* jogador, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao) :
			Inimigo(pos, jogador, listaEntidade, gerenciadorColisao)
		{

			id = Id::Atirador;
			arma = new Arma(this, Armas::RIFLE);

			Clocktiro.restart();
			health = 20;
			range = 1000;
			nivel_maldade = 5 + (rand() % 10);
			setMoveSpeed(2);
			tipo = TipoPersonagem::INIMIGO;
			shape.setTexture(*pGerGraphic->getAtiradorTexture());
			shape.setTextureRect(sf::IntRect(0, 0, 46, 71));
			shape.setScale(1 + (float)nivel_maldade/10, 1 + (float)nivel_maldade/10);
		}
		Atirador::~Atirador()
		{
		}
		void Atirador::adicionarCachorro(Cachorro* cachorro)
		{
			cachorros.emplace_back(cachorro);
		}

		void Atirador::danificar(Jogador* pJogador)
		{
			atirar(listaEntidade, gerColisao);
		}
				

		void Atirador::executar() {
			
			caiuDoMapa();
			if (!vivo()) {
				desativar();
				diminuirInimigos();
			}

			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					if(cach->ativado()){
						cach->mandarCacar();
					}
				}
				perseguirJogador();
				danificar(this->getJogador());
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