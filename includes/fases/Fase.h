#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include "managers/GraphicManager.h"
#include "managers/Collision.h"
#include "entities/characters/Player.h"
#include "entities/obstacles/Obstacle.h"




namespace game {
    namespace fases {

        class Fase
        {
        protected:
            static managers::GraphicManager *pGraphicManager;
            static managers::Collision *pCollision;
            entities::characters::Player player;
            entities::obstacles::Obstacle obstacle;

        public:
            Fase();
            virtual ~Fase();

            virtual void exec();

            static void setGraphicManager(managers::GraphicManager *r_pGraphicManager);
            static void setCollision(managers::Collision *r_pCollision);
        };

    }
}




#endif //JOGO_FASE_H