#include "GameOver.h"

GameOver::GameOver()
{
	/**
	* @brief Construtor da classe GameOver
	* @details Cria o botão de voltar e o adiciona ao vetor de botões
	* @return void
	*/
	voltar = new Entidades::Button( sf::Vector2f(200.f, 300.f), "Voltar", Actions::VOLTAR_2_MENUS);
	buttonVector.push_back(voltar);
}

GameOver::~GameOver()
{
	delete voltar;
}
void GameOver::handleEvent()
{
	/***
	* @brief Gerencia o evento de teclado e mouse
	* @return void
	*/

	sf::Event ev;
	while (this->window->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::Closed:
		{
			setAction(Actions::VOLTAR_1_MENU);
		}
		case  sf::Event::KeyPressed:
		{
			if (ev.key.code == sf::Keyboard::Escape) {
				setAction(Actions::VOLTAR_2_MENUS);
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