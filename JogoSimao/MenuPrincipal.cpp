#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
	:menuState()
{
	/**
	*@brief Construtor da classe MenuPrincipal, que inicializa o menu principal do jogo.
	*@details Cria os botões start, quit e ranking do menu principal e os adiciona ao vetor de botões.
	*@return void
	*/
	start = new Entidades::Button(sf::Vector2f(200.f, 225.f), "Start Game", Actions::SELECIONAR_FASE);

	continuar = new Entidades::Button(sf::Vector2f(200.f, 325.f), "Continuar", Actions::CARREGAR_SAVE);

	ranking = new Entidades::Button(sf::Vector2f(200.f, 425.f), "Ranking", Actions::MENU_RANKING);

	quit = new Entidades::Button(sf::Vector2f(200.f, 525.f), "Quit Game", Actions::VOLTAR_1_MENU);

	
	buttonVector.push_back(start);
	buttonVector.push_back(quit);
	buttonVector.push_back(ranking);
	buttonVector.push_back(continuar);
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

