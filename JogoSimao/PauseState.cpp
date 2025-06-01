#include "PauseState.h"
PauseState::PauseState()
{
	/**
	*@brief Construtor da classe PauseState, que inicializa o estado de pausa do jogo.
	*@details Este construtor cria dois botões: um para retomar o jogo e outro para sair do jogo. Ambos os botões são adicionados a um vetor 
			  de botões que será utilizado para gerenciar as ações do usuário durante o estado de pausa.
	*/
	resume = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(300.f, 300.f), "Resume", Actions::VOLTAR_1_MENU);
	quit = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(300.f, 400.f), "Quit", Actions::VOLTAR_2_MENUS);

	buttonVector.push_back(quit);
	buttonVector.push_back(resume);
}

PauseState::~PauseState() {
	/**
	*@brief Destrutor da classe PauseState, que libera a memória alocada para os botões.
	*/
	delete resume;
	delete quit;
}