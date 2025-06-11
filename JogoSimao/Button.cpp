#include "Button.h"
namespace Entidades{
	Button::Button(sf::Vector2f size, sf::Vector2f pos, std::string txt, Actions action)
		:Entidade(size, pos), buttonAction(action), actualAction(Actions::NADA)
	{
		/**
		*@brief Cria um botao com o tamanho, posicao, texto e acao especificados
		*@param size Tamanho do botao
		*@param pos Posicao do botao
		*@param txt Texto do botao
		*@param action Ação que o botao executa quando clicado
		*/
		buttonText.setPosition(pos);
		buttonText.setFont(*(pGerGraphic->getFont()));
		buttonText.setString(txt);
		buttonText.setCharacterSize(30);
		setFigura(&buttonText);
	}
	Button::~Button() {

	}

	void Button::action()
	{
		/**
		*@brief Executa a ação associada ao botão
		*/
		actualAction = buttonAction;
	}

	void Button::executar()
	{
		
	}

	bool Button::getClicked(sf::Vector2i* mousePos)
	{
		/**
		* @brief Verifica se o botao foi clicado
		* @param mousePos Posição do mouse	
		* @return Verdadeiro se o botao contem a posicao do mouse, falso caso contrario
		*/
		return shape.getGlobalBounds().contains(sf::Vector2f((float)mousePos->x, (float)mousePos->y));
	}

	const Actions Button::getAction() {
		/**
		*@brief Retorna a ação associada ao botão
		* 
		*@return Ação atual do botão
		*/
		return actualAction;
	}

	void Button::setAction(Actions act) {
		/**
		*@brief Define a ação associada ao botão
		*/
		actualAction = act;
	}

}