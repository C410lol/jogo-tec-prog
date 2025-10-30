#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "entities/characters/Character.h"




namespace game {
    namespace entities {
        namespace characters {

            class Player: public Character
            {
            private:
                int points;

            public:
                Player();
                ~Player() override;

                void exec() override;
                void mover() override;
            };

        }
    }

}




#endif //JOGO_PLAYER_H