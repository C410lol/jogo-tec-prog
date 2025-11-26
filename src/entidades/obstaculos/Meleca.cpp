#include "entidades/obstaculos/Meleca.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Meleca::numInstancias = 0;
            int Meleca::getInstancias() { return numInstancias; }
            void Meleca::setInstancias(int r_instancias) { numInstancias = r_instancias; }




            Meleca::Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), viscosidade(r_viscosidade),
            tamMaximo(r_tamanho.x * 5), tamMinimo(r_tamanho.x), aumentando(true)
            {
                ++numInstancias;

                setTexture("../assets/obstaculos/meleca.png");
                fixTexture();
            }
            Meleca::Meleca
            (
                dtos::ObstaculoDTO obsDTO, int r_viscosidade,
                float r_tamMaximo, float r_tamMinimo, bool r_aumentando
            ):
            Obstaculo(obsDTO), viscosidade(r_viscosidade),
            tamMaximo(r_tamMaximo), tamMinimo(r_tamMinimo), aumentando(r_aumentando)
            {
                ++numInstancias;

                setTexture("../assets/obstaculos/meleca.png");
                fixTexture();
            }
            Meleca::Meleca(): viscosidade(0) {}
            Meleca::~Meleca() = default;




            void Meleca::executar()
            {
                if (aumentando)
                {
                    aumentar(getTamanho().x / 50, 0);
                    mover(getTamanho().x / -100, 0);
                    if (getTamanho().x >= tamMaximo)
                        aumentando = false;
                }
                else
                {
                    aumentar(getTamanho().x / -50, 0);
                    mover(getTamanho().x / 100, 0);
                    if (getTamanho().x <= tamMinimo)
                        aumentando = true;
                }

                pSprite->setPosition(getPosicao());
            }




            void Meleca::obstaculizar(Entidade *pEntidade)
            {
                if (!pEntidade)
                    return;

                personagens::Jogador* pJogador = dynamic_cast<personagens::Jogador*>(pEntidade);
                if (!pJogador)
                    return;

                pJogador->setNaMeleca(true);
            }




            void Meleca::salvar()
            {
                Obstaculo::salvar();
                buffer << static_cast<int>(IDs::meleca) << " " << viscosidade << " " << tamMaximo << " " <<
                tamMinimo << " " << aumentando;
            }

        }
    }
}
