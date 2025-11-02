#include "listas/ListaEntidades.h"




namespace jogo {
    namespace listas {

        ListaEntidades::ListaEntidades() = default;
        ListaEntidades::~ListaEntidades() = default;


        void ListaEntidades::incluir(entidades::Entidade *pEntidade)
        {
            listaEntidades.incluir(pEntidade);
        }
        void ListaEntidades::percorrer()
        {
            Lista<entidades::Entidade>::Iterator it;
            for (it = listaEntidades.begin(); it != listaEntidades.end(); ++it)
            {
                if (*it)
                {
                    (*it)->getInfo()->exec();
                }
            }
        }

    }
}
