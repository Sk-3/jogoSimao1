#include "ListaEntidades.h"

namespace Listas
{
    ListaEntidades::ListaEntidades()
        : lista(),
        it()
    {
    }

    ListaEntidades::~ListaEntidades()
    {
        limpar();
    }

    void ListaEntidades::limpar()
    {
        lista.limpar();
    }

    void ListaEntidades::inserirNoFim(Entidades::Entity* ent)
    {
        if (ent)
            lista.inserirNoFim(ent);
    }

    void ListaEntidades::inserirNoInicio(Entidades::Entity* ent)
    {
        if (ent)
            lista.inserirNoInicio(ent);
    }

    void ListaEntidades::removerDoInicio()
    {
        lista.removerDoInicio();
    }

    void ListaEntidades::removerDoFim()
    {
        lista.removerDoFim();
    }

    const int ListaEntidades::getTam() const
    {
        return lista.getTam();
    }

    Lista<Entidades::Entity*>::Iterator ListaEntidades::apagar(Lista<Entidades::Entity*>::Iterator iter)
    {
        return lista.apagar(iter);
    }

    Lista<Entidades::Entity*>::Iterator ListaEntidades::inicio()
    {
        return lista.inicio();
    }

    Lista<Entidades::Entity*>::Iterator ListaEntidades::fim()
    {
        return lista.fim();
    }

    void ListaEntidades::executar()
    {
        for (it = inicio(); it != fim(); ++it)
            (*it)->executar();
    }

    

    void ListaEntidades::salvar()
    {
        //for (it = inicio(); it != fim(); ++it)
            //(*it)->salvar();
    }

    void ListaEntidades::desenhar()
    {
        for (it = inicio(); it != fim(); ++it)
            (*it)->desenhar();
    }

    void ListaEntidades::desalocar()
    {
        it = inicio();
        while (it != fim())
        {
            Entidades::Entity* temp = *it;
            it = apagar(it);
            delete temp;
            ++it;
        }
    }
}