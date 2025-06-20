#pragma once
#include "EstadoCachorro.h"
namespace Entidades {
	namespace Personagens {
		class EstadoCachorroSeguir : public EstadoCachorro
		{
		private:
			bool seguir;
		public:
			EstadoCachorroSeguir();
			~EstadoCachorroSeguir();
			void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao);			
		};

	}
}

