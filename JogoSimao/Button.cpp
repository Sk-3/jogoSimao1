#include "Button.h"
namespace Entidades{
	Button::Button(sf::Vector2f size, sf::Vector2f pos, std::string txt, Actions action)
		:Entity(size, pos), buttonAction(action), actualAction(Actions::NADA)
	{
		buttonText.setPosition(pos);
		buttonText.setFont(*(pGerGraphic->getFont()));
		buttonText.setString(txt);
		buttonText.setCharacterSize(30);

	}
	Button::~Button() {

	}

	void Button::action()
	{
		actualAction = buttonAction;
	}

	void Button::executar()
	{
		pGerGraphic->getWindow()->draw(buttonText);
	}

	bool Button::getClicked(sf::Vector2i* mousePos)
	{
		/*sf::Vector2f mouse;
		mouse.x = (float)mousePos->x;
		mouse.y = (float)mousePos->y;*/
		return shape.getGlobalBounds().contains(sf::Vector2f((float)mousePos->x, (float)mousePos->y));
	}

	const Actions Button::getAction() {
		return actualAction;
	}

	void Button::setAction(Actions act) {
		actualAction = act;
	}

}