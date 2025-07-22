#ifndef AGENDADOR
#define AGENDADOR

#include "imovel.h"
#include "corretor.h"
#include <vector>
#include <chrono>
#include <cmath>

class Agendador {
public:
    void agendarVisitas(std::vector<Imovel>& imoveis, std::vector<Corretor>& corretores);
};

#endif
