#include "entidades/personagens/Jogador.h"

#include <cmath>
#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            #define DESLOCAMENTO_JOGADOR_PADRAO 7.5




            int Jogador::numInstancias = 0;
            bool Jogador::primeiroExiste = false;
            void Jogador::setJogadorExiste(bool est) {
                primeiroExiste = est;
            }
            int Jogador::getInstancias() { return numInstancias; }
            void Jogador::setInstancias(int r_instancias) { numInstancias = r_instancias; }




            Jogador::Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
            Personagem(r_posicao, r_tamanho, 10, true), ehPrimeiro(false),
            deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0), ultimaPontuacao(0)
            {
                ++numInstancias;

                if (!primeiroExiste)
                {
                    ehPrimeiro = true;
                    primeiroExiste = true;

                    setTexture("../assets/personagens/jogador1.png");
                }
                else
                    setTexture("../assets/personagens/jogador2.png");

                fixTexture();
            }
            Jogador::Jogador
            (
                dtos::PersonagemDTO perDTO, bool r_ehPrimeiro, float r_deslocamentoX, bool r_naMeleca,
                bool r_atacando, int r_cooldown, int r_pontos
            ):
            Personagem(perDTO), ehPrimeiro(r_ehPrimeiro), deslocamentoX(r_deslocamentoX), naMeleca(r_naMeleca),
            atacando(r_atacando), cooldown(r_cooldown), pontos(r_pontos), ultimaPontuacao(r_pontos)
            {
                ++numInstancias;

                if (ehPrimeiro)
                    setTexture("../assets/personagens/jogador1.png");
                else
                    setTexture("../assets/personagens/jogador2.png");

                fixTexture();
            }
            Jogador::Jogador(): deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0) {}
            Jogador::~Jogador() {
                --numInstancias;
            };




            void Jogador::executar()
            {
                Personagem::executar();
                atualizarNaMeleca();

                cooldown /= 2;
            }




            void Jogador::salvar()
            {
                Personagem::salvar();
                buffer << static_cast<int>(IDs::jogador) << " " << ehPrimeiro << " " << deslocamentoX << " " <<
                naMeleca << " " << atacando << " " << cooldown << " " << pontos;
            }




            bool Jogador::getAtacando() const
            {
                return atacando;
            }
            bool Jogador::getEhPrimeiro() const
            {
                return ehPrimeiro;
            }




            void Jogador::setNaMeleca(bool r_estaNaMeleca)
            {
                naMeleca = r_estaNaMeleca;
            }
            void Jogador::setAtacando(bool r_atacando)
            {
                atacando = r_atacando;
            }
            void Jogador::atualizarNaMeleca()
            {
                if (naMeleca)
                    deslocamentoX = 3.f;
                else
                    deslocamentoX = DESLOCAMENTO_JOGADOR_PADRAO;
                naMeleca = false;
            }





            void Jogador::atacar(inimigos::Inimigo *pInimigo)
            {
                if (!pInimigo)
                    return;

                sf::Vector2f vetorVelocidade;
                vetorVelocidade.y = -275;
                if (this->getPosicao().x < pInimigo->getPosicao().x)
                    vetorVelocidade.x = 200;
                else
                    vetorVelocidade.x = -200;

                pInimigo->setNoChao(false);
                pInimigo->setKnokback(true);
                pInimigo->setVelocidade(vetorVelocidade);
                pInimigo->tomarDano(1);

                if (pInimigo->getVidas() <= 0) {
                    pontos += 10;
                    ultimaPontuacao = pontos;
                }
            }




            void Jogador::pular()
            {
                if (noChao && !naMeleca)
                {
                    noChao = false;
                    setVelocidade(sf::Vector2f(getVelocidade().x, -400));
                }
            }
            void Jogador::moverEsquerda()
            {
                olhandoDireita = false;
                mover(-deslocamentoX, 0);
            }
            void Jogador::moverDireita()
            {
                olhandoDireita = true;
                mover(deslocamentoX, 0);
            }
            void Jogador::ataque()
            {
                if (cooldown)
                    return;

                cooldown = std::pow(2, 15);
                atacando = true;
            }




            void Jogador::resetarJogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool resetarPontos)
            {
                buffer = std::ostringstream("");

                posicao = r_posicao;
                tamanho = r_tamanho;
                fixTexture();

                ultimaPontuacao = pontos;

                naMeleca = false;
                atacando = false;
                cooldown = 0;

                if (resetarPontos)
                    pontos = 0;

                velocidade = sf::Vector2f(0, 0);
                deslocamentoX = DESLOCAMENTO_JOGADOR_PADRAO;
                vidas = 10;
                noChao = true;
                olhandoDireita = true;
                knokback = false;

                ativo = true;
            }
            void Jogador::setJogador(
                dtos::PersonagemDTO perDTO, bool r_ehPrimeiro, float r_deslocamentoX,
                bool r_naMeleca, bool r_atacando, int r_cooldown, int r_pontos
            )
            {
                buffer = std::ostringstream("");

                idNumber = perDTO.entDTO.idNumber;
                posicao = perDTO.entDTO.posicao;
                tamanho = perDTO.entDTO.tamanho;
                ativo = perDTO.entDTO.ativo;

                vidas = perDTO.vidas;
                velocidade = perDTO.velocidade;
                sofreGravidade = perDTO.sofreGravidade;
                noChao = perDTO.noChao;
                olhandoDireita = perDTO.olhandoDireita;
                knokback = perDTO.knokback;

                ehPrimeiro = r_ehPrimeiro;
                deslocamentoX = r_deslocamentoX;
                naMeleca = r_naMeleca;
                atacando = r_atacando;
                cooldown = r_cooldown;
                pontos = r_pontos;
                ultimaPontuacao = pontos;

                if (ehPrimeiro)
                    setTexture("../assets/personagens/jogador1.png");
                else
                    setTexture("../assets/personagens/jogador2.png");
                fixTexture();
            }





            int Jogador::getUltimaPontuacao() const
            {
                return ultimaPontuacao;
            }

        }
    }
}

