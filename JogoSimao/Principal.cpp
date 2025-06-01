#include "Principal.h"

Principal::Principal()
	:gerGraphic( Gerenciadores::GerenciadorGrafico::getGerGraphic()),
	gerEstado(Gerenciadores::GerenciadorEstado::getGerEstado())
{
	/**
	*@brief Construtor da classe Principal.
	*@details Inicializa o gerenciador grafico e o gerenciador de estados do jogo.
	*/
	gerGraphic->setFrameLimit(60);
	
}

Principal::~Principal()
{
	delete gerGraphic;
	delete gerEstado;
}

void Principal::executar() {
	/**
	*@brief Executa o jogo enquanto a janela estiver aberta.
	*@details O loop principal do jogo executa o gerenciador de estados e atualiza a tela.
	*@return void
	*/
	while (gerGraphic->isOpen()) {
		gerEstado->executar();
		gerGraphic->display();
	}
}