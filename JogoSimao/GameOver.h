#pragma once
#include "menuState.h"
class GameOver : public menuState
{
private:
	Entidades::Button* voltar;
public:
	GameOver();
	~GameOver();
};

