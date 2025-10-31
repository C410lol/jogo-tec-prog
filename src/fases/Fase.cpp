#include "fases/Fase.h"



namespace game {
    namespace fases {

        managers::GraphicManager *Fase::pGraphicManager = nullptr;
        managers::Collision *Fase::pCollision = nullptr;


        Fase::Fase()
        {
            pCollision = new managers::Collision(&player, &obstacle);
        };
        Fase::~Fase() {};

        void Fase::setGraphicManager(
            managers::GraphicManager *r_pGraphicManager
        )
        {
            pGraphicManager = r_pGraphicManager;
        }
        void Fase::setCollision(managers::Collision *r_pCollision)
        {
            pCollision = r_pCollision;
        }

        void Fase::exec()
        {
            player.exec();

            if (pGraphicManager && pCollision)
            {
                pCollision->checkCollisions();

                pGraphicManager->draw(player);
                pGraphicManager->draw(obstacle);
            }
        }


    }
}
