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
		Personagens::Personagem* dono;
		int idDono;
	public:
		Projetil(sf::Vector2f pos, Personagens::Personagem* dono);
		Projetil(sf::Vector2f pos);
		Projetil();
		~Projetil();

		std::string salvar();
		
		
		void salvarProjetil();
		const TipoPersonagem getTipo() const;
		
		void setIdDono(int id); 
		int getIdDono(); 
		void setDono(Personagens::Personagem* pdono);
		void setTipo(TipoPersonagem tipo);
		void executar();
		void danifica(Personagens::Personagem* personagem);
		void aumentaPontosDono();
	};

}