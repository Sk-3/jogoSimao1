#pragma once

#include "Lista.h"
#include "Entity.h"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entity*> lista;
        Lista<Entidades::Entity*>::Iterator it;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void limpar();

        void inserirNoFim(Entidades::Entity* ent);
        void inserirNoInicio(Entidades::Entity* ent);

        void removerDoInicio();
        void removerDoFim();

        const int getTam() const;

        Lista<Entidades::Entity*>::Iterator apagar(Lista<Entidades::Entity*>::Iterator iter);
        Lista<Entidades::Entity*>::Iterator inicio();
        Lista<Entidades::Entity*>::Iterator fim();

        void executar();
        void salvar();
        void desenhar();
        void desalocar();
    };
} using namespace Listas;