#ifndef JOGO_FLYING_H
#define JOGO_FLYING_H

#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                class Voador: public Inimigo
                {
                private:
                    int energia;

                public:
                    static int instancias;
                public:
                    Voador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                    Voador();
                    ~Voador();

                    void deslocar() override;
                    void atacar();
                };

            }
        }
    }
}




#endif //JOGO_FLYING_H