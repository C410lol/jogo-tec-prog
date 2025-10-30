#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entities/Entity.h"

#define LIFES 3




namespace game {
    namespace entities {
        namespace characters {

            class Character: public Entity
            {
            protected:
                int lives{};

            public:
                Character();
                ~Character() override;

                void exec() override = 0;
                virtual void mover() = 0;
            };

        }
    }
}




#endif //JOGO_CHARACTER_H