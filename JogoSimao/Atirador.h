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
			std::vector<Personagem*>* personagens;
			std::vector<Cachorro*> cachorros;
		public:  
			Atirador(sf::Vector2f pos, Listas::ListaEntidades* lista, Personagem* jogador);
			~Atirador();			
			void eliminarCachorros();
			void executar();  
		};  
	}  
}
