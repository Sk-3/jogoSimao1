#include "Principal.h"

Principal::Principal()
	:gerGraphic( Gerenciadores::GerenciadorGrafico::getGerGraphic()),
	gerEstado(Gerenciadores::GerenciadorEstado::getGerEstado())
{
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
	}
}