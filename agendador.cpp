#include "agendador.h"
#include <algorithm>
#include <limits>
#include <cmath>

constexpr double EARTH_R = 6371.0;
constexpr double MINUTOS_POR_KM = 2.0; // 2 minutos por km
constexpr int DURACAO_AVALIACAO = 60; // 60 minutos

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d) { return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat / 2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon / 2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void Agendador::agendarVisitas(std::vector<Imovel>& imoveis, std::vector<Corretor>& corretores) {
    if (corretores.empty() || imoveis.empty()) return;

    // Ordena imóveis por ID
    std::sort(imoveis.begin(), imoveis.end(), [](const Imovel& a, const Imovel& b) {
        return a.getId() < b.getId();
    });

    // Filtra apenas corretores avaliadores
    std::vector<Corretor*> avaliadores;
    for (auto& corretor : corretores) {
        if (corretor.isAvaliador()) {
            avaliadores.push_back(&corretor);
        }
    }
    std::sort(avaliadores.begin(), avaliadores.end(), [](const Corretor* a, const Corretor* b) {
        return a->getId() < b->getId();
    });

    if (avaliadores.empty()) return;

    // Distribuição round-robin entre avaliadores
    int numAvaliadores = avaliadores.size();
    for (size_t i = 0; i < imoveis.size(); ++i) {
        int corretorIdx = i % numAvaliadores;
        avaliadores[corretorIdx]->adicionarImovel(&imoveis[i]);
    }

    // Agendamento com roteamento para cada corretor
    for (auto corretor : avaliadores) {
        auto imoveisCorretor = corretor->getImoveisAgendados();
        if (imoveisCorretor.empty()) continue;

        std::vector<bool> visitado(imoveisCorretor.size(), false);
        double atualLat = corretor->getLat();
        double atualLng = corretor->getLng();

        // Horário inicial 09:00
        std::tm horarioBase = {};
        horarioBase.tm_hour = 9;
        horarioBase.tm_min = 0;
        auto horarioAtual = std::chrono::system_clock::from_time_t(std::mktime(&horarioBase));

        while (true) {
            int idxMaisProximo = -1;
            double menorDistancia = std::numeric_limits<double>::max();

            // Encontra o imóvel mais próximo não visitado
            for (size_t j = 0; j < imoveisCorretor.size(); ++j) {
                if (visitado[j]) continue;

                double dist = haversine(atualLat, atualLng,
                                      imoveisCorretor[j]->getLat(),
                                      imoveisCorretor[j]->getLng());

                if (dist < menorDistancia) {
                    menorDistancia = dist;
                    idxMaisProximo = j;
                }
            }

            if (idxMaisProximo == -1) break;

            visitado[idxMaisProximo] = true;

            // Calcula tempo de deslocamento (2 min por km)
            double tempoDeslocamentoMin = menorDistancia * MINUTOS_POR_KM;
            
            // Adiciona tempo de deslocamento ao horário
            horarioAtual += std::chrono::minutes(static_cast<int>(std::floor(tempoDeslocamentoMin)));
            
            // Marca horário da visita
            imoveisCorretor[idxMaisProximo]->setHorarioVisita(horarioAtual);
            
            // Adiciona duração da avaliação (1 hora)
            horarioAtual += std::chrono::minutes(DURACAO_AVALIACAO);
            
            // Atualiza posição atual para o próximo cálculo
            atualLat = imoveisCorretor[idxMaisProximo]->getLat();
            atualLng = imoveisCorretor[idxMaisProximo]->getLng();
        }
    }
}