#include "fases/Fase.h"




namespace game {
    namespace fases {

        managers::GraphicManager *Fase::pGraphicManager = nullptr;
        managers::Collision *Fase::pCollision = nullptr;


        Fase::Fase(): flying(&player), land(&player)
        {
            //pCollision = new managers::Collision(&player, &obstacle);
        };
        Fase::~Fase() = default;


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
            flying.exec();
            land.exec();

            if (pGraphicManager)
            {
                //pCollision->checkCollisions();

                pGraphicManager->draw(player);
                pGraphicManager->draw(flying);
                pGraphicManager->draw(land);
                //pGraphicManager->draw(obstacle);
            }
        }


    }
}
