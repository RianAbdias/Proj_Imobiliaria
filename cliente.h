#ifndef CLIENTE
#define CLIENTE

#include <string>

class Cliente {
private:
    static int guardaid;
    int id;
    std::string nome;
    std::string telefone;

public:
    Cliente(std::string nome, std::string telefone);
    
    int getId();
    std::string getNome();
    std::string getTelefone();

    void setNome(std::string nNome);
    void setTelefone(std::string nTelefone);
};

#endif