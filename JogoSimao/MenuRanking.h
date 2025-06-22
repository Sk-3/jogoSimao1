#pragma once
#include "menuState.h"
#include <fstream>
class MenuRanking : public menuState
{
private:
	sf::Text textoRanking;
public:
	MenuRanking();
	~MenuRanking();
	void executar() override;
	void carregarBotoes();
	void carregarRanking();
};

