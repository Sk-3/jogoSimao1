#include "Gravidade.h"



Gravidade::Gravidade(std::vector<Entidades::Personagens::Character*>* characters, std::vector<Entidades::Projetil*>* projeteis)
{
	/**
	*@brief Construtor da classe Gravidade, que inicializa a força da gravidade e os vetores de personagens e projeteis.
	*@param characters Vetor de ponteiros para objetos do tipo Character, representando os personagens do jogo.
	*@param projeteis Vetor de ponteiros para objetos do tipo Projetil, representando os projeteis do jogo.
	*@return void
	*/
	gravityForce.x = 0;
	gravityForce.y = 0.2;
	this->characters = characters;
	this->projeteis = projeteis;
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
	for (auto& projeteis : *projeteis) {
		projeteis->changeSpeed(gravityForce);
	}
	for (const auto &character : *characters) {
		character->changeSpeed(gravityForce);
	}
}
