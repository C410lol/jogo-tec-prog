#ifndef JOGO_LISTA_H
#define JOGO_LISTA_H
#include "Lista.h"
#include "entidades/Entidade.h"


namespace jogo {
    namespace listas {

        template <typename TL>
        class Lista
        {
        private:
            class Elemento
            {
            private:
                Elemento *pProximo;
                TL *pInfo;

            public:
                Elemento(TL *r_pInfo);
                ~Elemento();

                TL* getInfo() const;
                Elemento* getProximo() const;

                void setProximo(Elemento *r_pProximo);
            };

        private:
            Elemento *pPrimeiro;
            Elemento *pUltimo;

        public:
            class Iterator
            {
            private:
                Elemento *pElemento;

            public:
                Iterator(Elemento *r_pElemento);
                ~Iterator();

                Elemento* operator*();
                void operator++();
                bool operator==(Iterator it);
                bool operator!=(Iterator it);
            };

            Lista();
            ~Lista();

            void incluir(TL *elemento);
            void retirar(TL *elemento);
            void limpar();

            Iterator begin();
            Iterator end();
        };

    }
}




#endif //JOGO_LISTA_H