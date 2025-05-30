#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorEstado.h"
#include "Ente.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
* Classe principal
*	Chamada pela main
*
*	executa o gerenciador de estados
*
**/
class Principal
{
private:
	Gerenciadores::GerenciadorGrafico* gerGraphic;
	Gerenciadores::GerenciadorEstado* gerEstado;

public:
	Principal();
	~Principal();
	void executar();
};

