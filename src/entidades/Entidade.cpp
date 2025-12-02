#include "./entidades/Entidade.h"

#include <iostream>

#include "entidades/personagens/Personagem.h"

#include <SFML/Graphics.hpp>


namespace jogo {
    namespace entidades {
        int Entidade::idCont = 0;
        fases::Fase *Entidade::pFase = nullptr;

        void Entidade::setFase(fases::Fase *r_pFase)
        {
            pFase = r_pFase;
        }


        Entidade::Entidade(sf::Vector2f r_posicao, sf::Vector2f r_tamanho) : idNumber(++idCont), ativo(true),
                                                                             posicao(r_posicao), tamanho(r_tamanho)
        {
            pSprite->setPosition(posicao);
        }

        Entidade::Entidade(dtos::EntidadeDTO entDTO) : idNumber(entDTO.idNumber), ativo(entDTO.ativo),
                                                       posicao(entDTO.posicao), tamanho(entDTO.tamanho)
        {
            pSprite->setPosition(posicao);
        }

        Entidade::Entidade() = default;

        Entidade::~Entidade()
        {
        }


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


        void Entidade::salvar()
        {
            buffer << idNumber << " " << ativo << " " << posicao.x << " " << posicao.y << " " <<
                    tamanho.x << " " << tamanho.y << " ";
        }

        std::string Entidade::getBufferString() const
        {
            return buffer.str();
        }


        void Entidade::fixTexture()
        {
            sf::FloatRect originalSize = pSprite->getLocalBounds();
            pSprite->setScale(tamanho.x / originalSize.width, tamanho.y / originalSize.height);
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


        int Entidade::getIdNumber() const
        {
            return idNumber;
        }
    }
}