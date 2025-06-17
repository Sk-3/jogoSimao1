#pragma once
#include <vector>
#include <set>
#include "Personagem.h"
#include "Projetil.h"
#include "ListaEntidades.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe concreta gravidade
*
*	Aplica uma aceleração negativa no eixo Y em todas as entidades que são afetadas pela gravidade(projeteis e personagens)
*/
class Gravidade
{
	ListaEntidades* listaEntidades;
	sf::Vector2f gravityForce;
	std::set<Entidades::Projetil*>* projeteis;
	std::vector<Entidades::Personagens::Personagem*>* characters;
public:
	Gravidade(ListaEntidades* lista);
	void executar();
	void aplyGravity();
};

