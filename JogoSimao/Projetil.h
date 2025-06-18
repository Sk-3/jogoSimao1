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
		Personagens::Personagem* dono;
	public:
		Projetil(sf::Vector2f pos, Personagens::Personagem* dono);
		Projetil();
		~Projetil();
		const TipoPersonagem getTipo() const;
		void setTipo(TipoPersonagem tipo);
		void executar();
		void danifica(Personagens::Personagem* personagem);
	};

}