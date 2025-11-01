#ifndef JOGO_FLYING_H
#define JOGO_FLYING_H

#include "entities/characters/enemies/Enemy.h"




namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                class Flying: public Enemy
                {
                private:

                public:
                    Flying(Player *r_pPlayer);
                    ~Flying();

                    void mover() override;
                };

            }
        }
    }
}




#endif //JOGO_FLYING_H