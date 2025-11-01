#ifndef JOGO_PROLOGUE_H
#define JOGO_PROLOGUE_H

#include "fases/Fase.h"




namespace jogo {
    namespace fases {

        class PrimeiraFase : public Fase
        {
        public:
            PrimeiraFase();
            ~PrimeiraFase() override;

            void exec() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H