#pragma once
#include "Entity.h"

namespace Entidades{
	namespace Personagens {
		class Character;
	}
	class Projetil :public Entity
	{
	private:
		int dano;
		bool ativo;
	public:
		Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction);
		Projetil();
		~Projetil();
		void executar();
		void desativar();
		bool Ativado();
		void danifica(Personagens::Character* personagem);
	};

}