#pragma once
#include "EstadoCachorro.h"

namespace Entidades {
	namespace Personagens {
		class EstadoCachorroAtacar : public EstadoCachorro
		{
		public:
			EstadoCachorroAtacar();
			~EstadoCachorroAtacar();
			virtual void atualizar(Cachorro* cachorro);
			virtual void entrar(Cachorro* cachorro);
			virtual void sair(Cachorro* cachorro);
		};

	}
}

