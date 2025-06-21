#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao) :
			Inimigo(pos, player, listaEntidade, gerenciadorColisao)
		{
			cachorro = nullptr;
			idCachorro = -1;
			id = Id::Atirador;
			arma = new Arma(this, Armas::RIFLE);
			health = 20;
			range = 2000;
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
		void Atirador::adicionarCachorro(Cachorro* pCachorro)
		{
			cachorro = pCachorro;
			idCachorro = cachorro->getIdUnico();
		}
		void Atirador::setIdCachorro(int id)
		{
			idCachorro = id;
		}

		int Atirador::getIdCachorro() const
 		{
			return idCachorro;
		}

		void Atirador::danificar(Jogador* jogador)
		{
			if (danoContatoRelogio.getElapsedTime().asSeconds() > danoContatoCooldown) {
				danoContatoRelogio.restart();
				jogador->tiraVida(nivel_maldade);
			}
		}


		
		std::string Atirador::salvar() {
			salvarAtirador();
			return buffer.str();
		}
		void Atirador::salvarAtirador()
		{
			salvarInimigo();

			buffer << idCachorro;
			std::cout << buffer.str() <<"\n";
		}
	
		void Atirador::executar() {
			
			caiuDoMapa();
			if (!vivo()) {
				desativar();
				diminuirInimigos();
			}

			if (jogadorNoAlcance()) {
				if(cachorro){
					if(cachorro->ativado()){
						cachorro->mandarCacar();
					}
				}
				
				perseguirJogador();
				atirar(listaEntidade, gerColisao);
			}
			else {
			
				if(cachorro){
					if(cachorro->ativado()){
						cachorro->mandarSeguir();
					}
				}
				
			}

			move();
			
		}
	}
	
}