#include <ctime>

#include "Jogo.h"




int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    jogo::Jogo jogo;
    return 0;
}