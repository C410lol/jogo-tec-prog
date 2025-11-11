#include "listas/ListaEntidades.h"

#include <list>

#include "entidades/obstaculos/Obstaculo.h"


namespace jogo {
    namespace listas {

        ListaEntidades::ListaEntidades() = default;
        ListaEntidades::~ListaEntidades() = default;


        void ListaEntidades::incluir(entidades::Entidade *pEntidade)
        {
            listaEntidades.incluir(pEntidade);
        }
        void ListaEntidades::retirar(entidades::Entidade *pEntidade)
        {
            listaEntidades.retirar(pEntidade);
        }




        void ListaEntidades::percorrer()
        {
            Lista<entidades::Entidade*>::Iterator it;
            for (it = listaEntidades.begin(); it != listaEntidades.end(); ++it)
            {
                if (*it)
                    (*it)->executar();
            }
        }

    }
}
