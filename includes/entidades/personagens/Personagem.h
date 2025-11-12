#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace fases {
        class Fase;
    }

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
                static fases::Fase *pFase;

                int vidas;
                sf::Vector2f velocidade;
                bool sofreGravidade;
                bool noChao;
                bool olhandoDireita;
                bool knokback;

            public:
                Personagem(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade);
                Personagem();
                virtual ~Personagem();

                void executar() override = 0;

                virtual void deslocar() = 0;
                virtual void cair();
                void checarMorte();

                sf::Vector2f getVelocidade() const;
                void setVelocidade(sf::Vector2f r_velocidade);

                bool getNoChao() const;
                void setNoChao(bool r_noChao);

                bool getKnokback() const;
                void setKnokback(bool r_knokback);

                bool getOlhandoDireita() const;

                void tomarDano(int dano);

                static void setFase(fases::Fase *r_pFase);
            };

        }
    }
}




#endif //JOGO_CHARACTER_H