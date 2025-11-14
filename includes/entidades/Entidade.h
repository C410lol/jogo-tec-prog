#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include "Ente.h"
#include <SFML/Graphics.hpp>




namespace jogo {
    namespace fases {
        class Fase;
    }

    namespace entidades {

        class Entidade: public Ente
        {
        private:
            bool ativo;

        protected:
            static fases::Fase *pFase;
            sf::Vector2f posicao;
            sf::Vector2f tamanho;

        public:
            Entidade(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
            Entidade();
            virtual ~Entidade();

            virtual void executar() = 0;
            void mover(float x, float y);
            void mover(sf::Vector2f mover);
            void aumentar(float x, float y);
            void aumentar(sf::Vector2f aumento);

            void fixTexture();

            sf::Vector2f getPosicao() const;
            sf::Vector2f getTamanho() const;

            void setPosicao(sf::Vector2f r_posicao);
            void setTamanho(sf::Vector2f r_tamanho);

            bool getAtivo() const;
            void setAtivo(bool r_ativo);

            static void setFase(fases::Fase *r_pFase);
        };

    }
}




#endif //JOGO_ENTITY_H