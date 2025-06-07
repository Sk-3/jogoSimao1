#include "Arma.h"
#include "Character.h"

Arma::Arma(std::vector<Entidades::Projetil*>* projeteis, Entidades::Personagens::Character* dono, float tiroCooldow)
	:pProjeteis(projeteis), pDono(dono), tiroCooldown(tiroCooldow)
{
	
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
		sf::Vector2f position = pDono->getPosition();
		position.y += (pDono->getBounds().height / 2);
		if (pDono->getDirection() != Directions::LEFT) {
			position.x += pDono->getBounds().width;
		}
		pProjeteis->emplace_back(new Entidades::Projetil(sf::Vector2f(10.0, 10.0), position, pDono->getDirection(), pDono->getTipo()));
		Clocktiro.restart();
	}
}