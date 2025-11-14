#pragma once

#include "listas/Lista.h"
#include "entidades/Entidade.h"




namespace jogo {
    namespace listas {

        class ListaEntidades {
        private:
            Lista<entidades::Entidade> LEs;

        public:
            ListaEntidades();
            ~ListaEntidades();

            void incluir(entidades::Entidade *pE);
            void deletar(entidades::Entidade *pE);
            const int getSize() const;
            void limpar();
            Lista<entidades::Entidade>::Iterator begin();
            Lista<entidades::Entidade>::Iterator end();

            void executar();
        };

    } // namespace Listas
}