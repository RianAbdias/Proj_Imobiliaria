#include <iostream>
#include <vector>
#include <iomanip>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agendador.h"

int main() {
    int numCorretores;
    std::cin >> numCorretores;
    std::vector<Corretor> corretores;
    for (int i = 0; i < numCorretores; ++i) {
        std::string telefone, nome;
        int avaliadorInt;
        double lat, lng;
        std::cin >> telefone >> avaliadorInt >> lat >> lng;
        std::getline(std::cin >> std::ws, nome);
        bool avaliador = (avaliadorInt != 0);
        corretores.emplace_back(telefone, avaliador, lat, lng, nome);
    }

    int numClientes;
    std::cin >> numClientes;
    std::vector<Cliente> clientes;
    for (int i = 0; i < numClientes; ++i) {
        std::string telefone, nome;
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);
        clientes.emplace_back(nome, telefone);
    }

    int numImoveis;
    std::cin >> numImoveis;
    std::vector<Imovel> imoveis;
    for (int i = 0; i < numImoveis; ++i) {
        std::string tipoStr, endereco;
        int proprietarioId;
        double lat, lng, preco;
        std::cin >> tipoStr >> proprietarioId >> lat >> lng >> preco;
        std::getline(std::cin >> std::ws, endereco);
        imoveis.emplace_back(tipoStr, proprietarioId, lat, lng, preco, endereco);
    }

    Agendador agendador;
    agendador.agendarVisitas(imoveis, corretores);

    for (const auto& corretor : corretores) {
        if (!corretor.isAvaliador()) continue;
        if (corretor.getImoveisAgendados().empty()) continue;

        std::cout << "Corretor " << corretor.getId() << "\n";

        for (const Imovel* imovelPtr : corretor.getImoveisAgendados()) {
            auto horario = imovelPtr->getHorarioVisita();
            std::time_t t = std::chrono::system_clock::to_time_t(horario);
            std::cout << std::put_time(std::localtime(&t), "%H:%M") << " Imóvel " << imovelPtr->getId() << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
