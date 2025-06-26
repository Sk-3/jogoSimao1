#include "Button.h"
namespace Entidades{
	Button::Button(sf::Vector2f pos, std::string txt, Actions action)
		:Ente(), buttonAction(action)
	{
		/**
		*@brief Cria um botao com o tamanho, posicao, texto e acao especificados
		*@param size Tamanho do botao
		*@param pos Posicao do botao
		*@param txt Texto do botao
		*@param action Ação que o botao executa quando clicado
		*/
		mediador = mediadorEventos::getMediadorEventos();
		buttonText.setPosition(pos);
		buttonText.setFont(*(pGerGraphic->getFont()));
		buttonText.setString(txt);
		buttonText.setCharacterSize(30);
		setFigura(&buttonText);
	}
	Button::~Button() {

	}

	void Button::executar()
	{
		
	}

	void Button::getClicked(sf::Vector2i* mousePos)
	{
		/**
		* @brief Verifica se o botao foi clicado
		* @param mousePos Posição do mouse	
		* @return Verdadeiro se o botao contem a posicao do mouse, falso caso contrario
		*/
		if (buttonText.getGlobalBounds().contains(sf::Vector2f((float)mousePos->x, (float)mousePos->y))) {
			mediador->notify(buttonAction);
		}
	}
}