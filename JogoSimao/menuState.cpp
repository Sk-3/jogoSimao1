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
	//Se o action atual do botão for diferente de NADA, então mudar o estado atual do estado pro estado do botão
	for (const auto& x : buttonVector) {
		if (x->getAction() != Actions::NADA) {

			this->setAction(x->getAction());
			x->setAction(Actions::NADA);

		}
	}
}

void menuState::execButtons()
{
	for (const auto& buttons : buttonVector) {
		buttons->executar();
	}
}

void menuState::executar() {
	pGerGraphic->getWindow()->clear();
	pGerGraphic->updateMousePosition();
	handleEvent();
	readButtons();
	execButtons();
}

void menuState::handleEvent()
{
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
	for (const auto& x : buttonVector) {
		if (x->getClicked(mousePos)) {
			x->action();
		}
	}
}