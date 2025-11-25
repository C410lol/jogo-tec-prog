#include "fases/Fase.h"

#include <iostream>
#include <fstream>

#include "Jogo.h"
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
#include "entidades/obstaculos/Bandeira.h"


namespace jogo {
    namespace fases {

        Jogo *Fase::pJogo = nullptr;
        void Fase::setJogo(Jogo *r_pJogo) { pJogo = r_pJogo; }




        Fase::Fase(int r_numJogadores):
        numJogadores(r_numJogadores), faseAcabou(false), jogCont(0), jogAtivos(0)
        {
            entidades::personagens::inimigos::Terrestre::setInstancias(0);
            entidades::personagens::inimigos::Voador::setInstancias(0);
            entidades::personagens::inimigos::Chefao::setInstancias(0);
            entidades::personagens::Jogador::setInstancias(0);
            entidades::obstaculos::Plataforma::setInstancias(0);
            entidades::obstaculos::Meleca::setInstancias(0);
            entidades::obstaculos::Espinho::setInstancias(0);

            listaEntidades.retirarJogadores();

            entidades::personagens::Personagem::setFase(this);
            setarProporcao();
        }
        Fase::~Fase() {
            for (auto it = listaEntidades.begin(); it != listaEntidades.end(); ++it)
            {
                if (!(dynamic_cast<entidades::personagens::Jogador*>(*it)))
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
            else if (c == 'c' || c == 'p' || c == '4' || c == 'e' || c == '5' || c == 'm' || c == '6' || c == 'f')
                criarObstaculos(c, x, y);
            else if (c == 'j')
                criarJogador(sf::Vector2f(x, y), proporcao);
        }




        void Fase::criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (jogCont >= numJogadores)
                return;

            entidades::personagens::Jogador *pJogador = pJogo->getJogadores()[jogCont];

            if (Id == IDs::primeira_fase)
                pJogador->resetarJogador(posicao, tamanho, true);
            else
                pJogador->resetarJogador(posicao, tamanho, false);

            listaEntidades.incluirNoInicio(pJogador);
            gerenciadorColisao.incluirJogador(pJogador);

            ++jogCont;
            ++jogAtivos;
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
        void Fase::criaBandeira(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::obstaculos::Bandeira* pBandeira =
                new entidades::obstaculos::Bandeira(posicao, tamanho, false);
            listaEntidades.incluir(pBandeira);
            gerenciadorColisao.incluirObstaculo(pBandeira);
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

                if (--jogAtivos <= 0)
                    faseAcabou = true;
            }
            else
                gerenciadorColisao.retirarInimigo(
                    dynamic_cast<entidades::personagens::inimigos::Inimigo*>(pPersonagem)
                );

            pPersonagem->setAtivo(false);
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
        void Fase::acabarFase() {
            faseAcabou = true;
        }
        int Fase::getNumJogadores() const
        {
            return numJogadores;
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
        void Fase::carregaBandeira(dtos::ObstaculoDTO obsDTO) {
            entidades::obstaculos::Bandeira *pBandeira =
                new entidades::obstaculos::Bandeira(obsDTO);

            listaEntidades.incluir(pBandeira);
            gerenciadorColisao.incluirObstaculo(pBandeira);
        }




        void Fase::carregaPersonagem(std::stringstream &linha, dtos::EntidadeDTO entDTO)
        {
            int vidas; linha >> vidas;
            float velocidadeX; linha >> velocidadeX;
            float velocidadeY; linha >> velocidadeY;
            bool sofreGravidade; linha >> sofreGravidade;
            bool noChao; linha >> noChao;
            bool olhandoDireita; linha >> olhandoDireita;
            bool knokback; linha >> knokback;

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
            float deslocamentoX; linha >> deslocamentoX;
            bool naMeleca; linha >> naMeleca;
            bool atacando; linha >> atacando;
            int cooldown; linha >> cooldown;
            int pontos; linha >> pontos;

            entidades::personagens::Jogador *pJogador = pJogo->getJogadores()[jogCont];
            pJogador->setJogador(perDTO, ehPrimeiro, deslocamentoX, naMeleca, atacando, cooldown, pontos);

            listaEntidades.incluir(pJogador);
            gerenciadorColisao.incluirJogador(pJogador);

            if (perDTO.entDTO.ativo)
                ++jogAtivos;

            ++jogCont;
            ++numJogadores;
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

