#ifndef JOGO_COLISION_H
#define JOGO_COLISION_H

#include "entities/characters/Player.h"
#include "entities/obstacles/Obstacle.h"




namespace game {
    namespace managers {
        class Collision
        {
        private:
            entities::characters::Player *pPlayer;
            entities::obstacles::Obstacle *pObstacle;

        public:
            Collision(
                entities::characters::Player *r_pPlayer,
                entities::obstacles::Obstacle *r_pObstacle
            );
            ~Collision();

            void checkCollisions();
        };
    }
}




#endif //JOGO_COLISION_H