#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entidades/Entidade.h"

#include "dtos/PersonagemDTO.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            #define GRAVIDADE 50

            class Personagem: public Entidade
            {
            private:
                void atualizaSprite();
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
                Personagem(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade);
                Personagem(dtos::PersonagemDTO perDTO);
                Personagem();
                virtual ~Personagem();

                virtual void executar() = 0;

                virtual void salvar();

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
            };

        }
    }
}




#endif //JOGO_CHARACTER_H