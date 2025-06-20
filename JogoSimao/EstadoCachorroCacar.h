#pragma once
#include "EstadoCachorro.h"

namespace Entidades {
	namespace Personagens {
		class EstadoCachorroCacar : public EstadoCachorro
		{
		private:
			float alcance;
		public:
			EstadoCachorroCacar();
			~EstadoCachorroCacar();
			void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao, Jogador* jogador);			
		};

	}
}

