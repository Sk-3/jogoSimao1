#pragma once
#include "Jogador.h"
#include <fstream>
#include "Fase.h"
#include "menuState.h"
class GameOver : public menuState
{
private:
	Fases::Fase* pFase;
	sf::Text textoNomeJogador;
	int pontuacao;
	std::string nomeJogador;

public:
	GameOver(Fases::Fase* fase);
	~GameOver();
	void salvarRanking();
	void carregarBotoes();
	void executar() override;
	void handleEvent() override;
};

