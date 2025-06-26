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