#include "cliente.h"

//iniciar var estática
int Cliente::guardaid = 1;

//construtor
Cliente::Cliente(std::string nome, std::string telefone)
    : nome(nome), telefone(telefone) {
    id = guardaid++;
}

//getters
int Cliente::getId() { return id; }
std::string Cliente::getNome() { return nome; }
std::string Cliente::getTelefone() { return telefone; }

//setters
void Cliente::setNome(std::string nNome) { nome = nNome; }
void Cliente::setTelefone(std::string nTelefone) { telefone = nTelefone; }
