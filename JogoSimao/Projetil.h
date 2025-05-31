#pragma once
#include "Entity.h"
#include "TipoPersonagem.h"
namespace Entidades{
	namespace Personagens {
		class Character;
	}
	class Projetil :public Entity
	{
	private:
		TipoPersonagem tipo;
		int dano;
		bool ativo;
	public:
		Projetil(sf::Vector2f size, sf::Vector2f pos, Directions direction, TipoPersonagem tipo);
		Projetil();
		~Projetil();
		const TipoPersonagem getTipo() const;
		void setTipo(TipoPersonagem tipo);
		void executar();
		void desativar();
		bool Ativado();
		void danifica(Personagens::Character* personagem);
	};

}