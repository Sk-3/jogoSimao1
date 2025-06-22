#include "Principal.h"

Principal::Principal()
	:gerGraphic( Gerenciadores::GerenciadorGrafico::getGerGraphic())
	
{
	jogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(100, 100));
	jogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100, 100));
	gerEstado = new Gerenciadores::GerenciadorEstado(jogador1, jogador2);
	gerGraphic->setFrameLimit(60);
	
}

Principal::~Principal()
{
	delete gerGraphic;
	delete gerEstado;
}

void Principal::executar() {
	
	while (gerGraphic->isOpen()) {
		
		gerEstado->executar();
		gerGraphic->display();
		if (!jogador1->vivo()) {
			
		
			delete jogador1;
			jogador1 = nullptr;
			jogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(100, 100));
			
			gerEstado->setJogador1(jogador1);
		}
		if (!jogador2->vivo()) {
			delete jogador2;
			jogador2 = nullptr;
			jogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100, 100));
			gerEstado->setJogador2(jogador2);
		}
	}
}