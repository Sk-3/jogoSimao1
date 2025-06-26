#pragma once
#include "ListaEntidades.h"
#include "GerenciadorColisao.h"

namespace Entidades{
	namespace Personagens{
		class Cachorro;
		class Personagem;

		class EstadoCachorro
		{
		protected:
			int id;
		public:
			virtual ~EstadoCachorro(){}
			virtual void atualizar(Cachorro* cachorro) = 0;
			const int getIdCachorro() const;
		};
	}
}