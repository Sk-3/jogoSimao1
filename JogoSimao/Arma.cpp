#include "Arma.h"
#include "Personagem.h"

Arma::Arma(Listas::ListaEntidades* listaEnt, Entidades::Personagens::Personagem* dono, Armas arma) :
	pDono(dono), lista(listaEnt)
{
	switch (arma) {
		case Armas::METRALHADORA:{
			tiroCooldown = 0.2;
			VelocidadeProjetil = 10;
			break;
		}
		case Armas::ARMACACHORRO:{
			tiroCooldown = 1;
			VelocidadeProjetil = 5;
			break;
		}
		case Armas::ARMAESQUELETO: {
			tiroCooldown = 0.8;
			VelocidadeProjetil = 10;			
			break;
		}
		case Armas::RIFLE:{
			tiroCooldown = 2;
			VelocidadeProjetil = 50;
			break;
		}
		default:{
			break;
		}
	}
	
}
Arma::~Arma()
{
}



void Arma::atirar() {
	/**
	*@brief Dispara projeteis
	*@details verifica se o tempo passado desde o ultimo reset de clockTiro é maior que o cooldown do tiro
	*nesse caso, insere um novo projetil no vetor de projeteis e reseta o relógio
	*@return void
	*/
	if (Clocktiro.getElapsedTime().asSeconds() > tiroCooldown) {
		sf::Vector2f position = pDono->getCenter();
		lista->inserirNoFim(new Entidades::Projetil(position, pDono->getDirection(), pDono->getTipo()));
		Clocktiro.restart();
	}
}