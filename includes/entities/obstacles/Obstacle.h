#ifndef JOGO_OBSTACLE_H
#define JOGO_OBSTACLE_H

#include "entities/Entity.h"




namespace game {
    namespace entities {
        namespace obstacles {
            class Obstacle: public Entity
            {
            protected:
                bool harmful;

            public:
                Obstacle();
                virtual ~Obstacle();

                void exec() override;
                virtual void obstruct(Entity &entity);
            };
        }
    }
}




#endif //JOGO_OBSTACLE_H