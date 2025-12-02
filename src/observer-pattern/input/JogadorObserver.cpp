#include "observer-pattern/input/JogadorObserver.h"

#include <iostream>

#include "observer-pattern/input/InputSubject.h"


namespace jogo {
    namespace observers {
        JogadorObserver::JogadorObserver(entidades::personagens::Jogador *r_pJogador) : pJogador(r_pJogador)
        {
        }

        JogadorObserver::JogadorObserver() : pJogador(nullptr)
        {
        }

        JogadorObserver::~JogadorObserver() = default;


        void JogadorObserver::update(int message)
        {
            if (!pJogador)
                return;

            if (pJogador->getKnokback())
                return;

            if (pJogador->getEhPrimeiro()) {
                if (message == InputSubject::Teclas::W)
                    pJogador->pular();
                if (message == InputSubject::Teclas::A)
                    pJogador->moverEsquerda();
                if (message == InputSubject::Teclas::D)
                    pJogador->moverDireita();

                if (message == InputSubject::Teclas::F)
                    pJogador->ataque();
                else
                    pJogador->setAtacando(false);
            } else {
                if (message == InputSubject::Teclas::UP)
                    pJogador->pular();
                if (message == InputSubject::Teclas::LEFT)
                    pJogador->moverEsquerda();
                if (message == InputSubject::Teclas::RIGHT)
                    pJogador->moverDireita();

                if (message == InputSubject::Teclas::SPACE)
                    pJogador->ataque();
                else
                    pJogador->setAtacando(false);
            }
        }


        entidades::personagens::Jogador *JogadorObserver::getJogador() const
        {
            return pJogador;
        }
    }
}