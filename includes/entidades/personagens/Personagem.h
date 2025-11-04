#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            #define JOGADOR_VIDAS 3
            #define GRAVIDADE 10

            class Personagem: public Entidade
            {
            protected:
                int vidas;
                sf::Vector2f velocidade;
                bool sofreGravidade;
                bool noChao;
                bool olhandoDireita;

            public:
                Personagem(int r_vidas, bool r_sofreGravidade);
                ~Personagem() override;

                void executar() override = 0;

                virtual void deslocar() = 0;
                virtual void cair();

                sf::Vector2f getVelocidade() const;
                void setVelocidade(sf::Vector2f r_velocidade);

                bool getNoChao() const;
                void setNoChao(bool r_noChao);
            };

        }
    }
}




#endif //JOGO_CHARACTER_H