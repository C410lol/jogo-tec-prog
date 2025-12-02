#ifndef JOGO_INPUTSUBJECT_H
#define JOGO_INPUTSUBJECT_H

#include "observer-pattern/Subject.h"
#include <SFML/Window/Keyboard.hpp>


namespace jogo {
    namespace observers {
        class InputSubject : public Subject {
        private:
            static InputSubject *instancia;

            InputSubject() = default;

        public:
            enum Teclas {
                UP,
                LEFT,
                RIGHT,
                SPACE,
                W,
                A,
                D,
                F
            };

            static InputSubject *getInstancia()
            {
                if (!instancia)
                    instancia = new InputSubject();
                return instancia;
            }

            ~InputSubject() = default;

            void execute()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    notify(UP);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    notify(LEFT);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    notify(RIGHT);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    notify(SPACE);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    notify(W);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    notify(A);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    notify(D);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    notify(F);
            }
        };
    }
}


#endif //JOGO_INPUTSUBJECT_H