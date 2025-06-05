#pragma once
#include "GerenciadorGrafico.h"	

/**
*	Felipe Simbalista: 25/05/2025
* Classe abstrata Ente
* 
*	Responsável por definir um gerenciador gráfico global para todos os Entes da aplicação
*	fazendo com que todos realizem ações sempre na mesma janela
*	todo terá um clock para fins de controle de tempo
*/
class Ente
{
protected:
	sf::Clock clock;
	int id;
	static Gerenciadores::GerenciadorGrafico* pGerGraphic;
	sf::Drawable* figura;
public:

	Ente();
	virtual void desenhar();
	virtual ~Ente();
	virtual void executar() = 0;
	//GETTERS
	sf::Drawable* getFigura();
	//SETTERS
	void setFigura(sf::Drawable* figura);

};

