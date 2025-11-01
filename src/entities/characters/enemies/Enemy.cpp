#include "entities/characters/enemies/Enemy.h"




namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                Enemy::Enemy(Player *r_pPlayerTarget): pPlayerTarget(r_pPlayerTarget) {}
                Enemy::~Enemy() = default;


                void Enemy::exec()
                {
                    mover();

                    //Character::fall();
                    Character::exec();
                }

            }
        }
    }
}
