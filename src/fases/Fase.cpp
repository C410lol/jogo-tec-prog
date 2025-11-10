#include "fases/Fase.h"

#include <cstdlib>

#include "entidades/obstaculos/Espinho.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace fases {

        Fase::Fase() { setarProporcao(); }
        Fase::~Fase() = default;




        void Fase::setarProporcao()
        {
            if (pGerenciadorGrafico)
            {
                proporcao.x = pGerenciadorGrafico->getWindowSize().x / 42.f;
                proporcao.y = pGerenciadorGrafico->getWindowSize().y / 24.f;
            }
        }




        void Fase::criarFase()
        {
            try
            {
                std::ifstream faseTemplate("../fases-template/primeira-fase.txt");
                std::string linha;

                float x = 0.f;
                float y = 0.f;
                while (std::getline(faseTemplate, linha))
                {
                    for (char c: linha)
                    {
                        criarEntidade(c, x, y);
                        x += proporcao.x;
                    }

                    x = 0.f;
                    y += proporcao.y;
                }
            }
            catch (const std::exception e)
            {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }
        void Fase::criarEntidade(char c, float x, float y)
        {
            switch (c)
            {
                case 'p':   //  Plataforma
                    criarPlataforma(sf::Vector2f(x, y), proporcao);
                    break;
                case 'e':   //  Espinho
                    criarEspinho(
                        sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2)
                    );
                    break;
                case 't':   //  Terrestre
                    criarTerrestre(sf::Vector2f(x, y), proporcao);
                    break;
                case 'v':   //  Voador
                    criarVoador(sf::Vector2f(x, y), proporcao);
                    break;
                case 'j':   //  Jogador
                    criarJogador(sf::Vector2f(x, y), proporcao);
                    break;
                case '1':   //  Terrestre aleatório
                    if (rand() % 2)
                        criarTerrestre(sf::Vector2f(x, y), proporcao);
                    break;
                case '2':   //  Voador aleatório
                    if (rand() % 2)
                        criarVoador(sf::Vector2f(x, y), proporcao);
                    break;
                case '4':   //  Espinho aleatório
                    if (rand() % 2)
                        criarEspinho(
                            sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2)
                        );
                    break;
                default:
                    break;
            }
        }





        void Fase::criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            jogador = new entidades::personagens::Jogador(posicao, tamanho);
            listaEntidades.incluir(jogador);
            gerenciadorColisao.incluirJogador(jogador);
        }




        void Fase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(posicao, tamanho);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }
        void Fase::criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Voador *pVoador =
                new entidades::personagens::inimigos::Voador(posicao, tamanho);

            listaEntidades.incluir(pVoador);
            gerenciadorColisao.incluirInimigo(pVoador);
        }




        void Fase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(posicao, tamanho, false, false);

            listaEntidades.incluir(pPlataforma);
            gerenciadorColisao.incluirObstaculo(pPlataforma);
        }
        void Fase::criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::obstaculos::Espinho *pEspinho =
                new entidades::obstaculos::Espinho(posicao, tamanho, true, 1);

            listaEntidades.incluir(pEspinho);
            gerenciadorColisao.incluirObstaculo(pEspinho);
        }




        void Fase::inicializar()
        {
            criarFase();
        }

        void Fase::executar()
        {
            gerenciadorColisao.checarColisoes();
            listaEntidades.percorrer();
        }

    }
}

