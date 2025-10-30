#include "fases/Prologue.h"
#include "managers/GraphicManager.h"




namespace game {
    namespace fases {

        Prologue::Prologue() {}
        Prologue::~Prologue() {}

        void Prologue::exec()
        {
            player.exec();

            if (pGraphicManager)
            {
                pGraphicManager->clear();
                pGraphicManager->draw(player);
                pGraphicManager->display();
            }
        }

    }
}
