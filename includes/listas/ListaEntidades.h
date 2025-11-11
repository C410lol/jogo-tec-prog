#ifndef JOGO_LISTAENTIDADES_H
#define JOGO_LISTAENTIDADES_H

#include "listas/Lista.h"
#include "entidades/Entidade.h"


namespace jogo::entidades::personagens
{
    class Jogador;
}

namespace jogo {
    namespace listas {

        class ListaEntidades
        {
        private:
            Lista<entidades::Entidade*> listaEntidades;

        public:
            ListaEntidades();
            ~ListaEntidades();

            void incluir(entidades::Entidade *pEntidade);
            void retirar(entidades::Entidade *pEntidade);
            void percorrer();
        };

    }
}




#endif //JOGO_LISTAENTIDADES_H