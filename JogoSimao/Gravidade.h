#pragma once
#include <vector>
#include "Personagem.h"
#include "Projetil.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe concreta gravidade
*
*	Aplica uma aceleração negativa no eixo Y em todas as entidades que são afetadas pela gravidade(projeteis e personagens)
*/
class Gravidade
{
	sf::Vector2f gravityForce;
	std::vector<Entidades::Projetil*>* projeteis;
	std::vector<Entidades::Personagens::Personagem*>* characters;
public:
	Gravidade(std::vector<Entidades::Personagens::Personagem*>* characters, std::vector<Entidades::Projetil*>* projeteis);
	void executar();
	void aplyGravity();
};

