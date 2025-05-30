#include "Gravidade.h"



Gravidade::Gravidade(std::vector<Entidades::Character*>* characters, std::vector<Entidades::Projetil*>* projeteis)
{
	gravityForce.x = 0;
	gravityForce.y = 0.2;
	this->characters = characters;
	this->projeteis = projeteis;
}
void Gravidade::executar()
{
	aplyGravity();
}

void Gravidade::aplyGravity()
{
	for (auto& projeteis : *projeteis) {
		projeteis->changeSpeed(gravityForce);
	}
	for (const auto &character : *characters) {
		character->changeSpeed(gravityForce);
	}
}
