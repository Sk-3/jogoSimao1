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
		*@param action A��o que o botao executa quando clicado
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
		*@brief Executa a a��o associada ao bot�o
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
		* @param mousePos Posi��o do mouse	
		* @return Verdadeiro se o botao contem a posicao do mouse, falso caso contrario
		*/
		return shape.getGlobalBounds().contains(sf::Vector2f((float)mousePos->x, (float)mousePos->y));
	}

	const Actions Button::getAction() {
		/**
		*@brief Retorna a a��o associada ao bot�o
		* 
		*@return A��o atual do bot�o
		*/
		return actualAction;
	}

	void Button::setAction(Actions act) {
		/**
		*@brief Define a a��o associada ao bot�o
		*/
		actualAction = act;
	}

}