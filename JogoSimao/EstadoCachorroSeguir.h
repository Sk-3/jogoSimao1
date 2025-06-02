#pragma once
#include "EstadoCachorro.h"
namespace Entidades {
	namespace Personagens {
		class EstadoCachorroSeguir : public EstadoCachorro
		{
		public:
			EstadoCachorroSeguir();
			~EstadoCachorroSeguir();
			virtual void atualizar(Cachorro* cachorro);
			virtual void entrar(Cachorro* cachorro);
			virtual void sair(Cachorro* cachorro);
		};

	}
}

