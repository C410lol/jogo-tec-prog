//
// Created by mvmko on 18/11/2025.
//

#ifndef JOGO_ESTADOJOGO_H
#define JOGO_ESTADOJOGO_H

#include "Estado.h"
#include "fases/Fase.h"
#include "observer-pattern/input/InputSubject.h"


namespace jogo {
    namespace estados {
        class EstadoJogo : public Estado {
        private:
            observers::InputSubject *pInputSubject;
            fases::Fase *fase;

        public:
            EstadoJogo(IDs id, int numJogadores = 1, bool continuar = false);

            ~EstadoJogo();

            void executar();

            void criarFase(IDs idFase, int numJogadores = 1, bool continuar = false);
        };
    }
}
#endif //JOGO_ESTADOJOGO_H