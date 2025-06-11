#include "Arma.h"
#include "Personagem.h"

Arma::Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Personagem* dono, float tiroCooldow)
	:pProjeteis(projeteis), pDono(dono), tiroCooldown(tiroCooldow)
{
	
}
Arma::Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Personagem* dono, Armas arma)
	:pProjeteis(projeteis), pDono(dono)
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
		case Armas::ARMABOSS: {
			tiroCooldown = 0.4;
			VelocidadeProjetil = 15;
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
		pProjeteis->emplace_back(new Entidades::Projetil(sf::Vector2f(10.0, 10.0), position, pDono->getDirection(), pDono->getTipo()));
		Clocktiro.restart();
	}
}