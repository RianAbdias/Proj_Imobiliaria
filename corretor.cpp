#include "corretor.h"
#include <iostream>

int Corretor::guardaid = 1;

Corretor::Corretor(const std::string& telefone, bool avaliador, double lat, double lng, const std::string& nome)
    : id(guardaid++), telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome) {}

// Getters
int Corretor::getId() const { return id; }
std::string Corretor::getNome() const { return nome; }
std::string Corretor::getTelefone() const { return telefone; }
bool Corretor::isAvaliador() const { return avaliador; }
double Corretor::getLat() const { return lat; }
double Corretor::getLng() const { return lng; }
const std::vector<Imovel*>& Corretor::getImoveisAgendados() const { return imoveisAgendados; }

// Setters
void Corretor::setNome(const std::string& novoNome) { nome = novoNome; }
void Corretor::setTelefone(const std::string& novoTelefone) { telefone = novoTelefone; }
void Corretor::setAvaliador(bool a) { avaliador = a; }
void Corretor::setLat(double novaLat) { lat = novaLat; }
void Corretor::setLng(double novaLng) { lng = novaLng; }

// Agendamento
void Corretor::adicionarImovel(Imovel* imovel) {
    imoveisAgendados.push_back(imovel);
}

void Corretor::limparAgendamentos() {
    imoveisAgendados.clear();
}

