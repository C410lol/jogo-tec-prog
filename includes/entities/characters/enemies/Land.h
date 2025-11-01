#ifndef JOGO_LAND_H
#define JOGO_LAND_H

#include "entities/characters/enemies/Enemy.h"




namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                #define LAND_MAX_RADIUS 200

                class Land: public Enemy
                {
                private:

                public:
                    Land(Player *r_pPlayer);
                    ~Land();

                    void mover() override;
                };

            }
        }
    }
}




#endif //JOGO_LAND_H