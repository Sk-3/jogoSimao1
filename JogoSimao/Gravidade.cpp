#include "Gravidade.h"



Gravidade::Gravidade(ListaEntidades* listaEnt)
{
	/**
	*@brief Construtor da classe Gravidade, que inicializa a força da gravidade e os vetores de personagens e projeteis.
	*@param characters Vetor de ponteiros para objetos do tipo Character, representando os personagens do jogo.
	*@param projeteis Vetor de ponteiros para objetos do tipo Projetil, representando os projeteis do jogo.
	*@return void
	*/
	listaEntidades = listaEnt;
	gravityForce.x = 0;
	gravityForce.y = 0.2;
	projeteis = listaEntidades->getProjeteis();
	obstaculos = listaEntidades->getObstaculos();
	characters = listaEntidades->getPersonagens();
}
void Gravidade::executar()
{
	/**
	*@brief Método que executa a aplicação da gravidade nos personagens e projeteis.
	*@return void
	*/
	aplyGravity();
}

void Gravidade::aplyGravity()
{
	/**
	* @brief Aplica a força da gravidade a todos os personagens e projeteis.
	* @return void
	*/
	for (const auto& projeteis : *projeteis) {
		projeteis->changeSpeed(gravityForce);
	}
	for (const auto &character : *characters) {
		character->changeSpeed(gravityForce);
	}
	for (const auto& obstac : *obstaculos) {
		obstac->changeSpeed(gravityForce);
	}
}
