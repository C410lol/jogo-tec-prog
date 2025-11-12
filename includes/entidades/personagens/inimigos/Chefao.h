#ifndef JOGO_CHEFAO_H
#define JOGO_CHEFAO_H

#include "entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                class Chefao: public Personagem
                {
                private:
                    float cadencia;

                public:
                    Chefao();
                    Chefao(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                    ~Chefao();

                    void executar() override;
                    void deslocar() override;
                };

            }
        }
    }
}




#endif //JOGO_CHEFAO_H