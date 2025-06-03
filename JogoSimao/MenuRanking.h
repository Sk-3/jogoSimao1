#pragma once
#include "menuState.h"
class MenuRanking : public menuState
{
private:
	Entidades::Button* voltar;
	sf::Text text;
public:
	MenuRanking();
	~MenuRanking();
};

