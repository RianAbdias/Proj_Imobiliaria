#ifndef CORRETOR
#define CORRETOR

#include <string>

class Corretor {
private:
    static int guardaid;
    int id;
    std::string nome;
    std::string telefone;
    bool avaliador;
    double lat;
    double lng;

public:
    Corretor(std::string nome, std::string telefone, bool avaliador, double lat, double lng);
    
    int getId();
    std::string getNome();
    std::string getTelefone();
    bool isAvaliador();
    double getLat();
    double getLng();

    void setNome(std::string nNome);
    void setTelefone(std::string nTelefone);
    void setAvaliador(bool ehAval);
    void setLat(double nLat);
    void setLng(double nLng);
};

#endif