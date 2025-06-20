#include "PauseState.h"
PauseState::PauseState(Fases::Fase* pfase)
	:fase(pfase)
{
	/**
	*@brief Construtor da classe PauseState, que inicializa o estado de pausa do jogo.
	*@details Este construtor cria dois botões: um para retomar o jogo e outro para sair do jogo. Ambos os botões são adicionados a um vetor 
			  de botões que será utilizado para gerenciar as ações do usuário durante o estado de pausa.
	*/
	resume = new Entidades::Button( sf::Vector2f(300.f, 300.f), "Resume", Actions::VOLTAR_1_MENU);
	quit = new Entidades::Button( sf::Vector2f(300.f, 500.f), "Quit", Actions::VOLTAR_2_MENUS);
	salvar = new Entidades::Button(sf::Vector2f(300.f, 400.f), "Salvar", Actions::SALVAR);
	buttonVector.push_back(quit);
	buttonVector.push_back(resume);
	buttonVector.push_back(salvar);
}

PauseState::~PauseState() {
	/**
	*@brief Destrutor da classe PauseState, que libera a memória alocada para os botões.
	*/
	delete resume;
	delete quit;
}

void PauseState::readButtons()
{
	/**
	* @brief le os botoes do menu e executa a acao
	* @details Percorre o vetor de botoes e verifica se a acao do botao houve alguma alteracao,
	*		   Caso tenha ocorrido, a acao do menuState eh alterada para a acao do botao
	*/
	for (const auto& botao : buttonVector) {
		if (botao->getAction() == Actions::SALVAR) {
			fase->salvar();
			botao->setAction(Actions::NADA);
		}
		if (botao->getAction() != Actions::NADA) {
			this->setAction(botao->getAction());
			botao->setAction(Actions::NADA);

		}
	}
}