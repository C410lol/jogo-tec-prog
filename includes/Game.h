#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "fases/Prologue.h"
#include "managers/GraphicManager.h"




namespace game
{
    class Game
    {
        fases::Prologue prologue;
        managers::GraphicManager graphicManager;

    public:
        Game();
        ~Game();

        void exec();
    };
}




#endif //JOGO_JOGO_H