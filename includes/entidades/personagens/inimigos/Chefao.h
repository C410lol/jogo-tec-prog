#ifndef JOGO_CHEFAO_H
#define JOGO_CHEFAO_H

#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                #define RAIO_MAX 100

                class Chefao: public Inimigo
                {
                private:
                    static int numInstancias;
                    float cooldown;
                    float rapidez;

                public:
                    Chefao();
                    Chefao(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                    Chefao(dtos::InimigoDTO iniDTO, float r_cooldown, float r_rapidez);
                    ~Chefao();

                    void executar() override;
                    void deslocar() override;

                    void salvar() override;

                    void atirar();

                    float getRapidez() const;

                    static int getInstancias();
                    static void setInstancias(int n);
                };

            }
        }
    }
}




#endif //JOGO_CHEFAO_H