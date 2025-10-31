#include "managers/Collision.h"




namespace game {
    namespace managers {

        Collision::Collision(
            entities::characters::Player *r_pPlayer,
            entities::obstacles::Obstacle *r_pObstacle
        ): pPlayer(r_pPlayer), pObstacle(r_pObstacle)
        {}
        Collision::~Collision()
        {
            pPlayer = nullptr;
            pObstacle = nullptr;
        }

        void Collision::checkCollisions()
        {
            if (pObstacle && pPlayer)
            {
                pObstacle->obstruct(*pPlayer);
            }
        }


    }
}
