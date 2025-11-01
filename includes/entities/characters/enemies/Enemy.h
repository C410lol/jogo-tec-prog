#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "entities/characters/Character.h"
#include "entities/characters/Player.h"




namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                #define SPEED 0.05f

                class Enemy: public Character
                {
                protected:
                    Player *pPlayerTarget;

                public:
                    Enemy(Player *r_pPlayerTarget);
                    virtual ~Enemy();

                    void exec() override;
                    virtual void mover() = 0;
                };

            }
        }
    }
}




#endif //JOGO_ENEMY_H