#include "imovel.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>

int Imovel::guardaid = 1;

Imovel::Imovel(const std::string& tipoStr, int propId, double latitude, double longitude, double valor, const std::string& end)
    : id(guardaid++), proprietarioId(propId), lat(latitude), lng(longitude), endereco(end), preco(valor) {

    std::string tipoLower = tipoStr;
    std::transform(tipoLower.begin(), tipoLower.end(), tipoLower.begin(),
        [](unsigned char c){ return std::tolower(c); });

    if (tipoLower == "casa") {
        tipo = CASA;
    } else if (tipoLower == "apartamento") {
        tipo = APARTAMENTO;
    } else {
        tipo = TERRENO;
    }
}

// Getters
int Imovel::getId() const { return id; }
Imovel::Tipo Imovel::getTipo() const { return tipo; }
int Imovel::getProprietarioId() const { return proprietarioId; }
double Imovel::getLat() const { return lat; }
double Imovel::getLng() const { return lng; }
const std::string& Imovel::getEndereco() const { return endereco; }
double Imovel::getPreco() const { return preco; }

std::string Imovel::getTipoString() const {
    switch(tipo) {
        case CASA: return "Casa";
        case APARTAMENTO: return "Apartamento";
        case TERRENO: return "Terreno";
        default: return "Desconhecido";
    }
}

std::chrono::system_clock::time_point Imovel::getHorarioVisita() const {
    return horarioVisita;
}

std::string Imovel::getHorarioVisitaString() const {
    std::time_t tt = std::chrono::system_clock::to_time_t(horarioVisita);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%H:%M", std::localtime(&tt));
    return std::string(buffer);
}

// Setters
void Imovel::setTipo(Tipo novoTipo) { tipo = novoTipo; }
void Imovel::setProprietarioId(int id) { proprietarioId = id; }
void Imovel::setLat(double latitude) { lat = latitude; }
void Imovel::setLng(double longitude) { lng = longitude; }
void Imovel::setEndereco(const std::string& end) { endereco = end; }
void Imovel::setPreco(double valor) { preco = valor; }
void Imovel::setHorarioVisita(const std::chrono::system_clock::time_point& horario) {
    horarioVisita = horario;
}

