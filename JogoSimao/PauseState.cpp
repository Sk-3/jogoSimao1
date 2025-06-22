#include "PauseState.h"
PauseState::PauseState(Fases::Fase* pfase)
	:fase(pfase)
{
	carregarBotoes();
}

PauseState::~PauseState() {

}
void PauseState::carregarBotoes() {
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(300.f, 300.f), "Voltar ao Jogo", Actions::VOLTAR_1_MENU));
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(300.f, 500.f), "Sair do jogo", Actions::VOLTAR_2_MENUS));
	buttonVector.push_back(new Entidades::Button(sf::Vector2f(300.f, 400.f), "Salvar", Actions::SALVAR));

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