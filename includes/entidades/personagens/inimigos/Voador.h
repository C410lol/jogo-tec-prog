#ifndef JOGO_FLYING_H
#define JOGO_FLYING_H

#include "entidades/personagens/inimigos/Inimigo.h"


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {
                class Voador : public Inimigo {
                private:
                    static int numInstancias;

                    int energia;

                public:
                    Voador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);

                    Voador(dtos::InimigoDTO iniDTO, int r_energia);

                    Voador();

                    ~Voador();

                    void deslocar() override;

                    void salvar() override;

                    static int getInstancias();

                    static void setInstancias(int instancias);
                };
            }
        }
    }
}


#endif //JOGO_FLYING_H