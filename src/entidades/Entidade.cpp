#include "./entidades/Entidade.h"

#include <iostream>
#include <SFML/Graphics.hpp>




namespace jogo {
    namespace entidades {

        fases::Fase *Entidade::pFase = nullptr;
        void Entidade::setFase(fases::Fase *r_pFase)
        {
            pFase = r_pFase;
        }




        Entidade::Entidade(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
        ativo(true), posicao(r_posicao), tamanho(r_tamanho)
        {
            pSprite->setPosition(posicao);
        }
        Entidade::Entidade() = default;
        Entidade::~Entidade() {}




        void Entidade::mover(const float x, const float y)
        {
            setPosicao(sf::Vector2f(
                getPosicao().x + x, getPosicao().y + y
            ));
        }
        void Entidade::mover(const sf::Vector2f move)
        {
            setPosicao(getPosicao() + move);
        }




        void Entidade::fixTexture()
        {
            sf::FloatRect originalSize = pSprite->getLocalBounds();
            pSprite->setScale(tamanho.x / originalSize.width, tamanho.y / originalSize.height);
            pSprite->setOrigin(originalSize.width / 2, originalSize.height / 2);
        }





        void Entidade::aumentar(float x, float y)
        {
            setTamanho(sf::Vector2f(
                getTamanho().x + x, getTamanho().y + y
            ));
        }
        void Entidade::aumentar(sf::Vector2f aumento)
        {
            setTamanho(getTamanho() + aumento);
        }




        sf::Vector2f Entidade::getPosicao() const
        {
            return posicao;
        }
        sf::Vector2f Entidade::getTamanho() const
        {
            return tamanho;
        }




        void Entidade::setPosicao(sf::Vector2f r_posicao)
        {
            posicao = r_posicao;
        }
        void Entidade::setTamanho(sf::Vector2f r_tamanho)
        {
            tamanho = r_tamanho;
            fixTexture();
        }




        bool Entidade::getAtivo() const
        {
            return ativo;
        }
        void Entidade::setAtivo(bool r_ativo)
        {
            ativo = r_ativo;
        }

    }
}
