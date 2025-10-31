#include "./entities/characters/Character.h"




namespace game {
    namespace entities {
        namespace characters {

            Character::Character() = default;
            Character::~Character() = default;

            void Character::exec()
            {
                fall();
                rectangle.setPosition(position);
            }


            void Character::fall()
            {
                position.y += GRAVITY;
            }


        }
    }
}
