#include "fases/Fase.h"

#include <iostream>
#include <fstream>

#include "entidades/obstaculos/Espinho.h"
#include "entidades/obstaculos/Meleca.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "fases/PrimeiraFase.h"
#include "gerenciadores/GerenciadorGrafico.h"
#include "observer-pattern/input/InputSubject.h"

#include "dtos/EntidadeDTO.h"
#include "dtos/ObstaculoDTO.h"
#include "dtos/PersonagemDTO.h"
#include "dtos/InimigoDTO.h"
#include "estados/EstadoJogo.h"


namespace jogo {
    namespace fases {
        Jogo* Fase::pjogo = nullptr;
        int Fase::numLista = 0;
        Fase::Fase(int r_numJogadores):
        numJogadores(r_numJogadores), faseAcabou(false)
        {
            entidades::personagens::inimigos::Terrestre::setInstancias(0);
            entidades::personagens::inimigos::Voador::setInstancias(0);
            entidades::personagens::inimigos::Chefao::setInstancias(0);
            entidades::personagens::Jogador::setInstancias(0);
            entidades::obstaculos::Plataforma::setInstancias(0);
            entidades::obstaculos::Meleca::setInstancias(0);
            entidades::obstaculos::Espinho::setInstancias(0);
            entidades::personagens::Jogador::setJogadorExiste(false);

            entidades::personagens::Personagem::setFase(this);
            pLista = pjogo->getLista();
            setarProporcao();
            if (!estados::EstadoJogo::getPrimeiroJogo())
            {
                numLista -= pLista->size();
                pLista->clear();
            }

        }
        Fase::~Fase() {
            for (auto it = listaEntidades.begin(); it != listaEntidades.end(); ++it) {
                delete *it;
            }
            listaEntidades.limpar();
        }




        void Fase::setarProporcao()
        {
            if (pGerenciadorGrafico)
            {
                proporcao.x = pGerenciadorGrafico->getWindowSize().x / 42.f;
                proporcao.y = pGerenciadorGrafico->getWindowSize().y / 24.f;
            }
        }




        void Fase::criarCenario()
        {
            try
            {
                std::ifstream faseTemplate;
                if (dynamic_cast<PrimeiraFase*>(this))
                    faseTemplate.open("../fases-template/primeira-fase.txt");
                else
                    faseTemplate.open("../fases-template/segunda-fase.txt");

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
            if (c == 't' || c == '1' || c == 'v' || c == '2' || c == 'b' || c == '3')
                criarInimigos(c, x, y);
            else if (c == 'c' || c == 'p' || c == '4' || c == 'e' || c == '5' || c == 'm' || c == '6')
                criarObstaculos(c, x, y);
            else if (c == 'j')
                criarJogador(sf::Vector2f(x, y), proporcao);
        }




        void Fase::criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::Jogador::getInstancias() >= numJogadores)
                return;
            if (pLista->empty()||numLista == pLista->size() && numLista<numJogadores)
            {
                entidades::personagens::Jogador *pJogador =
                    new entidades::personagens::Jogador(posicao, tamanho);
                observers::JogadorObserver *pJogadorObserver =
                    new observers::JogadorObserver(pJogador);

                listaEntidades.incluirNoInicio(pJogador);
                gerenciadorColisao.incluirJogador(pJogador);

                observers::InputSubject::getInstancia()->attach(pJogadorObserver);
                jogadorObservers.push_back(pJogadorObserver);
                pLista->push_back(pJogador);
                numLista++;
            }
        }




        void Fase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(posicao, tamanho);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }




        void Fase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao, IDs id)
        {
            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(posicao, tamanho, false, ehChao, id);

            listaEntidades.incluir(pPlataforma);
            gerenciadorColisao.incluirObstaculo(pPlataforma);
        }




        void Fase::criarProjetil(entidades::personagens::inimigos::Chefao *pChefao, float velocidade)
        {
            entidades::Projetil *pProjetil =
                new entidades::Projetil
                (
                    pChefao->getPosicao(), proporcao / 2.f, pChefao,
                    velocidade, pChefao->getNivelMaldade()
                );

            listaEntidades.incluir(pProjetil);
            gerenciadorColisao.incluirProjetil(pProjetil);
        }




        void Fase::retirarPersonagem(entidades::personagens::Personagem *pPersonagem)
        {
            entidades::personagens::Jogador *pJogador =
                dynamic_cast<entidades::personagens::Jogador*>(pPersonagem);
            if (pJogador)
            {
                gerenciadorColisao.retirarJogador(pJogador);
                retirarJogadorObserver(pJogador);

                if (entidades::personagens::Jogador::getInstancias() - 1 <= 0)
                    faseAcabou = true;
            }
            else
                gerenciadorColisao.retirarInimigo(
                    dynamic_cast<entidades::personagens::inimigos::Inimigo*>(pPersonagem)
                );

            pPersonagem->setAtivo(false);
        }
        void Fase::retirarJogadorObserver(entidades::personagens::Jogador *pJogador)
        {
            std::vector<observers::JogadorObserver*>::iterator itJogadorObserver;
            for
            (
                itJogadorObserver = jogadorObservers.begin();
                itJogadorObserver != jogadorObservers.end();
                ++itJogadorObserver
            )
            {
                if (*itJogadorObserver)
                {
                    if ((*itJogadorObserver)->getJogador() == pJogador)
                    {
                        observers::InputSubject::getInstancia()->detach(*itJogadorObserver);
                        delete *itJogadorObserver;
                        jogadorObservers.erase(itJogadorObserver);
                        break;
                    }
                }
            }
        }
        void Fase::retirarProjetil(entidades::Projetil *pProjetil)
        {
            gerenciadorColisao.retirarProjetil(pProjetil);

            pProjetil->setAtivo(false);
        }




        void Fase::inicializar()
        {
            criarCenario();
        }
        void Fase::executar()
        {
            pGerenciadorGrafico->desenhar(*pSprite);
            listaEntidades.executar();
            gerenciadorColisao.checarColisoes();
        }




        void Fase::salvarFase()
        {
            listaEntidades.salvarEntidades(Id);
        }




        bool Fase::getfaseAcabou() const
        {
            return faseAcabou;
        }












        void Fase::carregarFase()
        {
            std::ifstream file("../salvamentos/salvamento.txt");

            //  Se não conseguir abrir o arquivo, criar uma nova fase
            if (!file)
            {
                inicializar();
                return;
            }

            std::string linha;
            std::getline(file, linha);  //  Pula a linha da fase
            while (std::getline(file, linha))
            {
                std::stringstream linhaUtilizavel(linha);

                int idNumber;   linhaUtilizavel >> idNumber;
                bool ativo;     linhaUtilizavel >> ativo;
                float posicaoX; linhaUtilizavel >> posicaoX;
                float posicaoY; linhaUtilizavel >> posicaoY;
                float tamanhoX; linhaUtilizavel >> tamanhoX;
                float tamanhoY; linhaUtilizavel >> tamanhoY;

                dtos::EntidadeDTO entDTO(
                    idNumber, ativo, sf::Vector2f(posicaoX, posicaoY), sf::Vector2f(tamanhoX, tamanhoY)
                );

                int t; linhaUtilizavel >> t;
                IDs tipo = static_cast<IDs>(t);

                if (tipo == IDs::obstaculo)
                    carregaObstaculos(linhaUtilizavel, entDTO);
                else if (tipo == IDs::personagem)
                {
                    carregaPersonagem(linhaUtilizavel, entDTO);
                }
                else if (tipo == IDs::projetil)
                    carregaProjetil(linhaUtilizavel, entDTO);
            }
        }




        dtos::ObstaculoDTO Fase::carregaObstaculos(std::stringstream& linha, dtos::EntidadeDTO entDTO)
        {
            bool danoso; linha >> danoso;
            double cooldown; linha >> cooldown;

            return dtos::ObstaculoDTO(entDTO, danoso, cooldown);
        }
        void Fase::carregaPlataforma(std::stringstream &linha, dtos::ObstaculoDTO obsDTO)
        {
            bool ehChao; linha >> ehChao;
            bool invisivel; linha >> invisivel;

            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(obsDTO, ehChao, invisivel);

            listaEntidades.incluir(pPlataforma);
            gerenciadorColisao.incluirObstaculo(pPlataforma);
        }




        void Fase::carregaPersonagem(std::stringstream &linha, dtos::EntidadeDTO entDTO)
        {
            int vidas; linha >> vidas;
            int velocidadeX; linha >> velocidadeX;
            int velocidadeY; linha >> velocidadeY;
            int sofreGravidade; linha >> sofreGravidade;
            int noChao; linha >> noChao;
            int olhandoDireita; linha >> olhandoDireita;
            int knokback; linha >> knokback;

            dtos::PersonagemDTO perDTO(
                entDTO, vidas, sf::Vector2f(velocidadeX, velocidadeY),
                sofreGravidade, noChao, olhandoDireita, knokback
            );

            int t; linha >> t;
            IDs tipo = static_cast<IDs>(t);

            if (tipo == IDs::inimigo)
                carregaInimigos(linha, perDTO);
            else if (tipo == IDs::jogador)
                carregaJogador(linha, perDTO);
        }




        dtos::InimigoDTO Fase::carregaInimigos(std::stringstream &linha, dtos::PersonagemDTO perDTO)
        {
            int pJogadorAlvoId; linha >> pJogadorAlvoId;
            int nivelMaldade; linha >> nivelMaldade;
            int deslocamento; linha >> deslocamento;

            entidades::personagens::Jogador *pJogadorAlvo =
                dynamic_cast<entidades::personagens::Jogador*>(listaEntidades.procurarPeloId(pJogadorAlvoId));

            return dtos::InimigoDTO(perDTO, pJogadorAlvo,nivelMaldade, deslocamento);
        }
        void Fase::carregaTerrestre(std::stringstream &linha, dtos::InimigoDTO iniDTO)
        {
            int atrito; linha >> atrito;

            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(iniDTO, atrito);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }





        void Fase::carregaJogador(std::stringstream &linha, dtos::PersonagemDTO perDTO)
        {
            bool ehPrimeiro; linha >> ehPrimeiro;
            bool deslocamentoX; linha >> deslocamentoX;
            bool naMeleca; linha >> naMeleca;
            bool atacando; linha >> atacando;
            bool cooldown; linha >> cooldown;
            bool pontos; linha >> pontos;

            entidades::personagens::Jogador *pJogador =
                new entidades::personagens::Jogador
                (
                    perDTO, ehPrimeiro, deslocamentoX, naMeleca, atacando, cooldown, pontos
                );
            observers::JogadorObserver *pJogadorObserver =
                new observers::JogadorObserver(pJogador);

            listaEntidades.incluir(pJogador);
            gerenciadorColisao.incluirJogador(pJogador);

            observers::InputSubject::getInstancia()->attach(pJogadorObserver);
            jogadorObservers.push_back(pJogadorObserver);
        }




        void Fase::carregaProjetil(std::stringstream &linha, dtos::EntidadeDTO entDTO)
        {
            int dano; linha >> dano;
            int vel; linha >> vel;
            int pDonoId; linha >> pDonoId;

            entidades::personagens::Personagem *pDono =
                dynamic_cast<entidades::personagens::Personagem*>(listaEntidades.procurarPeloId(pDonoId));

            entidades::Projetil *pProjetil =
                new entidades::Projetil(entDTO, dano, vel, pDono);

            listaEntidades.incluir(pProjetil);
            gerenciadorColisao.incluirProjetil(pProjetil);
        }

    }
}

