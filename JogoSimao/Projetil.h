#pragma once
#include "Entidade.h"
#include "TipoPersonagem.h"
namespace Entidades{
	namespace Personagens {
		class Personagem;
	}
	class Projetil :public Entidade
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
		void danifica(Personagens::Personagem* personagem);
	};

}