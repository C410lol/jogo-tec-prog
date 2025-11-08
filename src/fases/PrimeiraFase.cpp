#include "fases/PrimeiraFase.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/obstaculos/Espinho.h"




namespace jogo {
    namespace fases {

        PrimeiraFase::PrimeiraFase(): maxTerrestres(8), maxVoadores(4)
        {
            abrirFaseTemplate();
            criarCenario();
        }
        PrimeiraFase::~PrimeiraFase() = default;




        void PrimeiraFase::abrirFaseTemplate()
        {
            try
            {
                faseTemplate.open("../fases-template/primeira-fase.txt");
            }
            catch (const std::exception& e)
            {
                std::cerr << "Erro: " << e.what() << std::endl;
                exit(-1);
            }
        }





        void PrimeiraFase::criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            jogador = new entidades::personagens::Jogador(posicao, tamanho);
            listaEntidades.incluir(jogador);
            gerenciadorColisao.incluirJogador(jogador);
        }
        void PrimeiraFase::criarInimigos()
        {
            //criarTerrestres();
            //criarVoadores();
        }
        void PrimeiraFase::criarObstaculos()
        {
            std::string linha;
            float x = 0.f;
            float y = 0.f;
            while (std::getline(faseTemplate, linha))
            {
                for (char c: linha)
                {
                    switch (c)
                    {
                        case 'p':
                            criarPlataformas(sf::Vector2f(x, y), proporcao);
                            break;
                        case 'e':
                            criarMelecas(
                                sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2)
                            );
                            break;
                        case 't':
                            criarTerrestres(sf::Vector2f(x, y), proporcao);
                            break;
                        case 'v':
                            criarVoadores(sf::Vector2f(x, y), proporcao);
                            break;
                        case 'j':
                            criarJogadores(sf::Vector2f(x, y), proporcao);
                        default:
                            break;
                    }

                    x += proporcao.x;
                }

                x = 0.f;
                y += proporcao.y;
            }

            //criarPlataformas();
            //criarMelecas();
        }






        void PrimeiraFase::criarTerrestres(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(posicao, tamanho);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }
        void PrimeiraFase::criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(posicao, tamanho, false, false);

            listaEntidades.incluir(pPlataforma);
            gerenciadorColisao.incluirObstaculo(pPlataforma);
        }




        void PrimeiraFase::criarVoadores(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Voador *pVoador =
                new entidades::personagens::inimigos::Voador(posicao, tamanho);

            listaEntidades.incluir(pVoador);
            gerenciadorColisao.incluirInimigo(pVoador);
        }
        void PrimeiraFase::criarMelecas(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::obstaculos::Espinho *pMeleca =
                new entidades::obstaculos::Espinho(posicao, tamanho, true, 1);

            listaEntidades.incluir(pMeleca);
            gerenciadorColisao.incluirObstaculo(pMeleca);
        }

    }
}
