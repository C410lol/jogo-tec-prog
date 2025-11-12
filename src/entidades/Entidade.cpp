#include "./entidades/Entidade.h"
#include <SFML/Graphics.hpp>




namespace jogo {
    namespace entidades {

        Entidade::Entidade(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
        posicao(r_posicao), tamanho(r_tamanho)
        {
            retangulo.setPosition(posicao);
            retangulo.setSize(tamanho);
        }
        Entidade::Entidade() {}
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






        sf::RectangleShape Entidade::getRetangulo() const
        {
            return retangulo;
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
            retangulo.setSize(tamanho);
        }


    }
}
