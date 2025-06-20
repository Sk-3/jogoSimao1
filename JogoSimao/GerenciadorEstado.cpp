#include "GerenciadorEstado.h"

namespace Gerenciadores {
	void GerenciadorEstado::setJogador1(Entidades::Personagens::Jogador* jogador)
	{
		jogador1 = jogador;
	}
	void GerenciadorEstado::setJogador2(Entidades::Personagens::Jogador* jogador)
	{
		jogador2 = jogador;
	}
	GerenciadorEstado::GerenciadorEstado(Entidades::Personagens::Jogador* jogador_1, Entidades::Personagens::Jogador* jogador_2)
	{
		/**
		* @brief Inicializa o gerenciador de estados com o menu principal.
		*/
		jogador1 = jogador_1;
		jogador2 = jogador_2;
		push(new MenuPrincipal());
		
	}

	void GerenciadorEstado::handleEvent()
	{
		/**
		* @brief Trata os eventos do estado atual do jogo.
		* @details Verifica se há algum estado na pilha e chama o método handleEvent do estado atual.
		* @return void
		*/
		if (!stack.empty()) {
			stack.back()->handleEvent();
		}
	}

	void GerenciadorEstado::update()
	{
		/**
		*@brief Atualiza o estado atual do jogo, verificando a ação a ser tomada.
		*@details Dependendo da ação, pode-se mudar de fase, voltar ao menu principal, selecionar uma fase, ou entrar no estado de pausa.
		*@return void
		*/
		switch (stack.back()->getAction()) {
		case Actions::VOLTAR_1_MENU: {
			pop();
			break;
		}
		case Actions::MENU_RANKING: {
			push(new MenuRanking());
			break;
		}
		case Actions::FASE_1: {
			push(new Fases::Fase1(jogador1, jogador2));
			break;
		}
		case Actions::FASE_2: {
			push(new Fases::Fase2(jogador1, jogador2));
			break;
		}
		case Actions::VOLTAR_2_MENUS: {
			pop();
			pop();
			break;
		}
		case Actions::SELECIONAR_FASE: {
			push(new MenuSelectLvl());
			break;
		}
		case Actions::PAUSE: {
			push(new PauseState());
			break;
		}
		case Actions::GAME_OVER:
		{
			push(new GameOver());
			break;
		}
		case Actions::PASSOU_DE_FASE:
		{
			pop();
			push(new Fases::Fase2(jogador1, jogador2));
			break;
		}

		default:
			break;

		}


	}


	void GerenciadorEstado::executar()
	{
		/**
		* @brief Executa o estado atual do jogo.
		* @details Verifica se há algum estado na pilha e chama o método executar do estado atual.
		* @return void
		*/
		if (stack.empty()) {
			pGerGraphic->close();
			return;
		}


		update();
		if (!stack.empty()) {
			stack.back()->executar();
		}
	}

	void GerenciadorEstado::pop()
	{
		/**
		* @brief Remove o estado atual da pilha de estados.
		* @details Verifica se há algum estado na pilha, deleta o estado atual e ajusta o estado anterior.
		* @return void
		*/
		if (!stack.empty()) {
			delete stack.back();
			stack.pop_back();
		}
		if (!stack.empty()) {
			stack.back()->setAction(Actions::NADA);
		}
	}

	void GerenciadorEstado::push(State* newState)
	{
		/**
		* @brief Adiciona um novo estado à pilha de estados.
		*/
		stack.emplace_back(newState);
	}

	void GerenciadorEstado::clear()
	{
		/**
		* @brief Limpa a pilha de estados, deletando todos os estados nela contidos.
		* @return void
		*/
		int i;

		for (i = stack.size() - 1; i >= 0; i--) {
			delete (*stack.begin() + i);
			stack.pop_back();

		}
	}

}
