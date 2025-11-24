#include "menus/MenuRanking.h"

#include <fstream>
#include <sstream>

#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace menus {

        MenuRanking::MenuRanking()
        {
            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            botoes.push_back(new Botao("Ranking", {posX, 100.f}, {300.f, 50.f}));
            carregarPontuacoes();
            botoes.push_back(new Botao("Voltar", {posX, 600.f}, {300.f, 50.f}));

            setTexture("../assets/Menu.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
        }
        MenuRanking::~MenuRanking()
        {
            std::vector<CaixaTexto*>::iterator it;
            for (it = caixasTexto.begin(); it != caixasTexto.end(); ++it)
                delete (*it);
        }




        void MenuRanking::executar()
        {
            desenhaMenu();
            atualizar();
        }
        void MenuRanking::desenhaMenu()
        {
            pGerenciadorGrafico->desenhar(*pSprite);
            for (size_t i = 0; i < botoes.size(); ++i)
                botoes[i]->desenhar();
            for (size_t i = 0; i < caixasTexto.size(); ++i)
                caixasTexto[i]->desenhar();
        }
        void MenuRanking::atualizar()
        {
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*pGerenciadorGrafico->getJanela()));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (botoes[1]->contem(mousePos))
                {
                    pge->limparEstados();                     // esvazia toda a pilha
                    pge->adicionarEstado(IDs::menu_principal);
                }
            }
        }




        void MenuRanking::carregarPontuacoes()
        {
            std::ifstream file("../salvamentos/pontuacoes.txt");
            std::vector<dtos::PontuacaoDTO> pontuacoes;
            ordenarPontuacoes(file, pontuacoes);

            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            float posY = 200.f;

            for (int i = 0; i < 7; ++i)
            {
                std::string ranking;
                CaixaTexto *caixaTexto;

                if (i >= pontuacoes.size())
                {
                    caixaTexto = new CaixaTexto(sf::Vector2f(posX - 12.5, posY), sf::Vector2f(325.f, 50.f));
                    ranking += std::to_string(i + 1) + ".";
                    caixaTexto->setTexto(ranking);
                    caixasTexto.push_back(caixaTexto);
                    posY += 50;
                    continue;
                }

                ranking += std::to_string(i + 1) + ". " + pontuacoes[i].username + ": " +
                    std::to_string(pontuacoes[i].pontuacao);
                caixaTexto = new CaixaTexto(sf::Vector2f(posX - 12.5, posY), sf::Vector2f(325.f, 50.f));
                caixaTexto->setTexto(ranking);
                caixasTexto.push_back(caixaTexto);
                posY += 50;
            }
        }
        void MenuRanking::ordenarPontuacoes
        (
            std::ifstream &file, std::vector<dtos::PontuacaoDTO> &pontuacoes
        )
        {
            std::string linha;
            while (std::getline(file, linha))
            {
                std::stringstream linhaUtilizavel(linha);

                std::string username; linhaUtilizavel >> username;
                int pontuacao; linhaUtilizavel >> pontuacao;

                pontuacoes.push_back(dtos::PontuacaoDTO(username, pontuacao));
            }

            //  Ordenação do vetor
            int i, j;
            int indexMenor;
            dtos::PontuacaoDTO aux;
            for (i = 0; i < pontuacoes.size() - 1; ++i)
            {
                indexMenor = i;
                for (j = i + 1; j < pontuacoes.size(); ++j)
                {
                    if (pontuacoes[j].pontuacao > pontuacoes[indexMenor].pontuacao)
                        indexMenor = j;
                }

                aux = pontuacoes[i];
                pontuacoes[i] = pontuacoes[indexMenor];
                pontuacoes[indexMenor] = aux;
            }
        }

    }
}
