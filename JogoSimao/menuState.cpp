#include "menuState.h"

menuState::~menuState()
{
	for (auto& botao : buttonVector) {
		delete botao;
	}
}

menuState::menuState()
	:State()
{
	fundoMenu.setTexture(*pGerGraphic->getFundoMenu());
	fundoMenu.setScale(0.84, 0.7);
	setFigura(&fundoMenu);
}
void menuState::execButtons()
{
	/**
	*@brief executa os botoes do menu
	*@return void
	*/
	for (const auto& buttons : buttonVector) {
		buttons->desenhar();
	}
}

void menuState::executar() {
	/**
	*@brief executa o menuState
	*@details Atualiza a posicao do mouse, limpa a janela e le e executa os botoes
	*@return void
	*/

	
	pGerGraphic->clear();
	pGerGraphic->updateMousePosition();
	desenhar();
	handleEvent();
	execButtons();

}

void menuState::handleEvent()
{
	/**
	*@brief trata os eventos de teclado e mouse do menuState
	*@return void
	*/
	sf::Event ev;
	while (pGerGraphic->getWindow()->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::Closed:
		{
			mediador->notify(Actions::VOLTAR_1_MENU);
		}
		case  sf::Event::KeyPressed:
		{
			if (ev.key.code == sf::Keyboard::Escape) {
				mediador->notify(Actions::VOLTAR_1_MENU);
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (ev.mouseButton.button == sf::Mouse::Left) {
				mouseClick();
			}
		}
		default:
			break;
		}
	}
}

void menuState::mouseClick()
{
	/**
	*@brief trata o clique do mouse no menuState
	*@details Verifica se o mouse esta sobre algum botao e executa a acao do botao
	*@return void
	*/
	for (const auto& x : buttonVector) {
		x->getClicked(mousePos);
	}
}