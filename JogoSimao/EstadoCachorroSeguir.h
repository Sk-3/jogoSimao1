#pragma once
#include "EstadoCachorro.h"
namespace Entidades {
	namespace Personagens {
		class EstadoCachorroSeguir : public EstadoCachorro
		{
		private:
			int id;
		public:
			EstadoCachorroSeguir();
			~EstadoCachorroSeguir();
			void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao);
			void entrar(Cachorro* cachorro);
			void sair(Cachorro* cachorro);
		};

	}
}

