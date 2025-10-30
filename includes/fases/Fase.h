#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include "Ente.h"
#include "entities/characters/Player.h"




namespace game {
    namespace fases {

        class Fase: public Ente
        {
        protected:
            entities::characters::Player player;

        public:
            Fase();
            virtual ~Fase();

            void exec() override = 0;
        };

    }
}




#endif //JOGO_FASE_H