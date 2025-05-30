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
public:

	Ente();
	void drawEnte(Ente* ente);
	virtual ~Ente();

	virtual void executar() = 0;
};

