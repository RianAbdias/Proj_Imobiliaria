#include "corretor.h"

//iniciar var estática
int Corretor::guardaid = 1;

//construtor
Corretor::Corretor(std::string nome, std::string telefone, bool avaliador, double lat, double lng)
    : telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome) {
    id = guardaid++;
}

//gettes
int Corretor::getId() { return id; }
std::string Corretor::getNome() { return nome; }
std::string Corretor::getTelefone() { return telefone; }
bool Corretor::isAvaliador() { return avaliador; }
double Corretor::getLat() { return lat; }
double Corretor::getLng() { return lng; }

//setters
void Corretor::setNome(std::string nNome) { nome = nNome; }
void Corretor::setTelefone(std::string nTelefone) { telefone = nTelefone; }
void Corretor::setAvaliador(bool ehAval) { avaliador = ehAval; }
void Corretor::setLat(double nLat) { lat = nLat; }
void Corretor::setLng(double nLng) { lng = nLng; }