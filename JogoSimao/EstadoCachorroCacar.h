#pragma once
#include "EstadoCachorro.h"

namespace Entidades {
	namespace Personagens {
		class EstadoCachorroCacar : public EstadoCachorro
		{
		private:
			int id;
		public:
			EstadoCachorroCacar();
			~EstadoCachorroCacar();
			virtual void atualizar(Cachorro* cachorro);
			virtual void entrar(Cachorro* cachorro);
			virtual void sair(Cachorro* cachorro);
		};

	}
}

