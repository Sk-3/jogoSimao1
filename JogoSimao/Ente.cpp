#include "Ente.h"
Gerenciadores::GerenciadorGrafico* Ente::pGerGraphic(Gerenciadores::GerenciadorGrafico::getGerGraphic());
Ente::Ente():
	id(Id::NULO)
{
	figura = nullptr;
}

void Ente::desenhar()
{
	pGerGraphic->desenharEnte(this); 
}
Ente::~Ente()
{
}

Id Ente::getId()
{
	return id;
}

sf::Drawable* Ente::getFigura()
{
	return figura;
}

void Ente::setFigura(sf::Drawable* fig)
{
	figura = fig;;
}
