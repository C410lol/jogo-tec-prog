#ifndef JOGO_LAND_H
#define JOGO_LAND_H

#include "dtos/InimigoDTO.h"
#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                class Terrestre: public Inimigo
                {
                private:
                    static int numInstancias;

                    int atrito;

                public:
                    Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                    Terrestre(dtos::InimigoDTO iniDTO, int r_atrito);
                    Terrestre();
                    ~Terrestre();

                    void executar() override;
                    void deslocar() override;

                    void salvar() override;

                    static int getInstancias();
                    static void setInstancias(int instancias);
                };

            }
        }
    }
}




#endif //JOGO_LAND_H