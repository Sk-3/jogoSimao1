#pragma once
#include "Inimigo.h"
namespace Entidades{
	class Cachorro : public Inimigo
	{
	private:
	public:
		Cachorro(sf::Vector2f size, sf::Vector2f pos);
		Cachorro();
		~Cachorro();
		void executar();

	};
}
