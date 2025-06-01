#include "menuState.h"

menuState::~menuState()
{
}

menuState::menuState()
	:State()
{
}

void menuState::readButtons()
{
	/**
	* @brief le os botoes do menu e executa a acao
	* @details Percorre o vetor de botoes e verifica se a acao do botao houve alguma alteracao,
	*		   Caso tenha ocorrido, a acao do menuState eh alterada para a acao do botao
	*/
	for (const auto& x : buttonVector) {
		if (x->getAction() != Actions::NADA) {

			this->setAction(x->getAction());
			x->setAction(Actions::NADA);

		}
	}
}

void menuState::execButtons()
{
	/**
	*@brief executa os botoes do menu
	*@return void
	*/
	for (const auto& buttons : buttonVector) {
		buttons->executar();
	}
}

void menuState::executar() {
	/**
	*@brief executa o menuState
	*@details Atualiza a posicao do mouse, limpa a janela e le e executa os botoes
	*@return void
	*/
	pGerGraphic->getWindow()->clear();
	pGerGraphic->updateMousePosition();
	handleEvent();
	readButtons();
	execButtons();
}

void menuState::handleEvent()
{
	/**
	*@brief trata os eventos de teclado e mouse do menuState
	*@return void
	*/
	sf::Event ev;
	while(this->window->pollEvent(ev)){
		switch (ev.type) {
		case sf::Event::Closed:
		{
			setAction(Actions::VOLTAR_1_MENU);
		}
		case  sf::Event::KeyPressed:
		{
			if (ev.key.code == sf::Keyboard::Escape) {
				setAction(Actions::VOLTAR_1_MENU);
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
		if (x->getClicked(mousePos)) {
			x->action();
		}
	}
}