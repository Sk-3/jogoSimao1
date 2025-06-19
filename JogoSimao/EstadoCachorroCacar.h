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
			void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao);
			void entrar(Cachorro* cachorro);
			void sair(Cachorro* cachorro);
		};

	}
}

