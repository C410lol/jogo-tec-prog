#include "Ente.h"
#include "managers/GraphicManager.h"




namespace game
{
    Ente::Ente() {}
    Ente::~Ente() {}

    void Ente::setGraphicManager(managers::GraphicManager *rGraphicManager)
    {
        pGraphicManager = rGraphicManager;
    }

    managers::GraphicManager* Ente::pGraphicManager = nullptr;
}
