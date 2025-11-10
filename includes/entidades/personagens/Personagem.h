#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            #define JOGADOR_VIDAS 3
            #define GRAVIDADE 50

            class Personagem: public Entidade
            {
            private:
                void atualizaPosicao();
                void atualizaVelocidadeX();
                void atualizaKnokback();

            protected:
                int vidas;
                sf::Vector2f velocidade;
                bool sofreGravidade;
                bool noChao;
                bool olhandoDireita;
                bool knokback;

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

                bool getKnokback() const;
                void setKnokback(bool r_knokback);

                bool getOlhandoDireita() const;

                void operator--();
            };

        }
    }
}




#endif //JOGO_CHARACTER_H