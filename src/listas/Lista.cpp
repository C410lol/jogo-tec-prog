#include "listas/Lista.h"




/*
namespace jogo {
    namespace listas {


        //  CLASSE LISTA
        template<typename TL>
        Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr) { limpar(); }
        template<typename TL>
        Lista<TL>::~Lista() = default;


        template<typename TL>
        void Lista<TL>::incluir(TL elemento)
        {
            if (!pPrimeiro)
            {
                pPrimeiro = new Elemento(elemento);
                pUltimo = pPrimeiro;
            }
            else
            {
                pUltimo->setProximo(new Elemento(elemento));
                pUltimo = pUltimo->getProximo();
            }
        }
        template<typename TL>
        void Lista<TL>::retirar(TL elemento)
        {
            Iterator itAtual = begin();
            Iterator itAnterior = end();
            while (itAtual != end() && *itAtual != elemento)
            {
                itAnterior = itAtual;
                ++itAtual;
            }

            if (itAtual != end())
            {
                Elemento* elementoAtual = *itAtual;
                Elemento* elementoAnterior = *itAnterior;

                if (elementoAtual == pPrimeiro)
                {
                    pPrimeiro = pPrimeiro->getProximo();
                    if (pPrimeiro == nullptr)
                        pUltimo = nullptr;
                }
                else if (elementoAtual == pUltimo)
                {
                    pUltimo = elementoAnterior;
                    pUltimo->setProximo(nullptr);
                }
                else
                {
                    elementoAnterior->setProximo(elementoAtual->getProximo());
                }

                delete elementoAtual;
            }
        }
        template<typename TL>
        void Lista<TL>::limpar()
        {
            Iterator itAtual = begin();
            Iterator itAux = end();
            while (itAtual != end())
            {
                itAux = itAtual;
                ++itAtual;
                delete *itAux;
            }

            pPrimeiro = nullptr;
            pUltimo = nullptr;
        }



        template<typename TL>
        typename Lista<TL>::Iterator Lista<TL>::begin()
        {
            return Iterator(pPrimeiro);
        }
        template<typename TL>
        typename Lista<TL>::Iterator Lista<TL>::end()
        {
            return Iterator(nullptr);
        }




        //  CLASSE ELEMENTO
        template<typename TL>
        Lista<TL>::Elemento::Elemento(TL r_pInfo) : pProximo(nullptr)
        {
            pInfo = r_pInfo;
        }
        template<typename TL>
        Lista<TL>::Elemento::~Elemento()
        {
            pProximo = nullptr;
        }
        template<typename TL>
        TL Lista<TL>::Elemento::getInfo() const
        {
            return pInfo;
        }
        template<typename TL>
        typename Lista<TL>::Elemento* Lista<TL>::Elemento::getProximo() const
        {
            return pProximo;
        }
        template<typename TL>
        void Lista<TL>::Elemento::setProximo(Elemento *r_pProximo)
        {
            pProximo = r_pProximo;
        }




        //  CLASSE ITERATOR
        template<typename TL>
        Lista<TL>::Iterator::Iterator(Elemento *r_pElemento)
        {
            pElemento = r_pElemento;
        }
        template<typename TL>
        Lista<TL>::Iterator::Iterator()
        {
            pElemento = nullptr;
        };
        template<typename TL>
        Lista<TL>::Iterator::~Iterator()
        {
            pElemento = nullptr;
        }
        template<typename TL>
        TL Lista<TL>::Iterator::operator*()
        {
            return pElemento->getInfo();
        }
        template<typename TL>
        void Lista<TL>::Iterator::operator++()
        {
            pElemento = pElemento->getProximo();
        }
        template<typename TL>
        bool Lista<TL>::Iterator::operator==(Iterator it)
        {
            return pElemento->getInfo() == *it;
        }
        template<typename TL>
        bool Lista<TL>::Iterator::operator!=(Iterator it)
        {
            return pElemento->getInfo() != *it;
        }


    }
}
*/
