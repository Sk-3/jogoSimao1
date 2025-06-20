#pragma once
#include "EstadoCachorro.h"

namespace Entidades {
	namespace Personagens {
		class EstadoCachorroAtacar : public EstadoCachorro
		{
		private:
			float velAtaque;
		public:
			EstadoCachorroAtacar();
			~EstadoCachorroAtacar();
			void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao, Jogador* jogador);			
		};

	}
}