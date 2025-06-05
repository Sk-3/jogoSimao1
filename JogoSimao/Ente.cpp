#include "Ente.h"
Gerenciadores::GerenciadorGrafico* Ente::pGerGraphic(Gerenciadores::GerenciadorGrafico::getGerGraphic());
Ente::Ente():
	id(0)
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

sf::Drawable* Ente::getFigura()
{
	return figura;
}

void Ente::setFigura(sf::Drawable* fig)
{
	figura = fig;;
}
