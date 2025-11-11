#include "Ente.h"

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {

    Ente::Ente() = default;
    Ente::~Ente() = default;


    gerenciadores::GerenciadorGrafico *Ente::pGerenciadorGrafico = nullptr;
    void Ente::setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico)
    {
        pGerenciadorGrafico = r_pGerenciadorGrafico;
    }
    void Ente::desenhar()
    {
        pGerenciadorGrafico->desenhar(this);
    }

}
