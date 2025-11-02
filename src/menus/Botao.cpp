#include "menus/Botao.h"




namespace jogo {
    namespace menus {

        Botao::Botao(sf::Vector2f r_posicao, std::string info):
        posicao(r_posicao), selecionado(false)
        {
            texto.setString(info);
            texto.setFillColor(sf::Color::White);
            texto.setPosition(posicao);
            texto.setFont(*gerenciadores::GerenciadorGrafico::fonte);
        }
        Botao::~Botao() = default;


        void Botao::executar()
        {
            if (selecionado)
                texto.setFillColor(sf::Color::Red);
            else
                texto.setFillColor(sf::Color::White);
        }


        const sf::Text Botao::getTexto() const
        {
            return texto;
        }
        const bool Botao::getSelecionado() const
        {
            return selecionado;
        }


        void Botao::setSelecionado(const bool r_selecionado)
        {
            selecionado = r_selecionado;
        }


    }
}
