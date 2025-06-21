#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao) :
			Inimigo(pos, player, listaEntidade, gerenciadorColisao)
		{

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
		void Atirador::adicionarCachorro(Cachorro* cachorro)
		{
			cachorros.emplace_back(cachorro);
		}
		void Atirador::danificar(Jogador* jogador)
		{
			if (danoContatoRelogio.getElapsedTime().asSeconds() > danoContatoCooldown) {
				danoContatoRelogio.restart();
				jogador->tiraVida(nivel_maldade);
			}
		}


		
		void Atirador::salvar() {
			salvarAtirador();
		}
		void Atirador::salvarAtirador()
		{
			salvarInimigo();

			buffer << "{";
			for (std::vector<Entidades::Personagens::Cachorro*>::const_iterator i = cachorros.begin(); i != cachorros.end(); i++) {
				if (i + 1 != cachorros.end()) {
					buffer << (*i)->getIdUnico() << ", ";
				}
				else {
					buffer << (*i)->getIdUnico();
				}
				
			}
			buffer << "}" << " ";
			std::cout << buffer.str() <<"\nChamando salvar Atirador\n";
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