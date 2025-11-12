#ifndef JOGO_LAND_H
#define JOGO_LAND_H

#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                class Terrestre: public Inimigo
                {
                private:
                    int atrito;
                public:
                    static int instancias;
                public:
                    Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                    Terrestre();
                    ~Terrestre();

                    void executar() override;
                    void deslocar() override;
                };

            }
        }
    }
}




#endif //JOGO_LAND_H