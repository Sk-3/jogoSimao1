#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
	:menuState()
{
	/**
	*@brief Construtor da classe MenuPrincipal, que inicializa o menu principal do jogo.
	*@details Cria os botões start, quit e ranking do menu principal e os adiciona ao vetor de botões.
	*@return void
	*/
	start = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f), "Start Game", Actions::SELECIONAR_FASE);

	quit = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 400.f), "Quit Game", Actions::VOLTAR_1_MENU);

	ranking = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 500.f), "Ranking", Actions::VOLTAR_1_MENU);
	buttonVector.push_back(start);
	buttonVector.push_back(quit);
	buttonVector.push_back(ranking);
}

MenuPrincipal::~MenuPrincipal()
{
	/**
	*@brief Destrutor da classe MenuPrincipal, que libera a memória alocada para os botões do menu principal.
	*/
	delete start;
	delete quit;
	delete ranking;
}

