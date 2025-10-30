#ifndef JOGO_PROLOGUE_H
#define JOGO_PROLOGUE_H

#include "fases/Fase.h"




namespace game {
    namespace fases {

        class Prologue : public Fase
        {
        public:
            Prologue();
            ~Prologue() override;

            void exec() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H