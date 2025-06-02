#pragma once  
#include "Inimigo.h"  
#include "Projetil.h"  
#include "Cachorro.h" 
#include <array>
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
			std::vector<Character*>* personagens;
			std::array<Cachorro*, 3> cachorros;
		public:  
			Atirador(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, std::vector<Character*>* personagens);  
			Atirador();  
			~Atirador();  
			void executar();  
		};  
	}  
}
