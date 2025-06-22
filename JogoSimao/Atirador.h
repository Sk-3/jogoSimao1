#pragma once  
#include "Inimigo.h"  
#include "Projetil.h"  
#include "Cachorro.h" 
#include "Arma.h"
/**  
* @file Atirador.h  
* @brief Declaração da classe Atirador, que herda de Inimigo.  
* @autor Felipe Simbalista  
* @data 01/06/2025  
**/  

namespace Entidades{  
	namespace Personagens {  
		class Atirador : public Inimigo  
		{  
		private:
			Cachorro* cachorro;
			int idCachorro;
		public: 

			Atirador(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao);
			~Atirador();  
			void adicionarCachorro(Cachorro* cachorro);


			void setIdCachorro(int id);
			int getIdCachorro() const;
			void danificar(Jogador* jogador);
			std::string salvar();
			void salvarAtirador();
			void executar();  
		};  
	}  
}
