#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include "Ente.h"
#include <SFML/Graphics.hpp>




namespace jogo {
    namespace entidades {

        class Entidade: public Ente
        {
        protected:
            sf::Vector2f posicao;
            sf::RectangleShape retangulo;
            sf::Vector2f tamanho;

        public:
            Entidade();
            virtual ~Entidade();

            virtual void executar() = 0;
            void mover(float x, float y);
            void mover(sf::Vector2f mover);

            sf::RectangleShape getRetangulo() const;
            sf::Vector2f getPosicao() const;
            sf::Vector2f getTamanho() const;

            void setPosicao(sf::Vector2f r_posicao);

        };

    }
}




#endif //JOGO_ENTITY_H