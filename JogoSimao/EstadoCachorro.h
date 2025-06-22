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
			virtual void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao) = 0;
			const int getId() const;
		};
	}
}