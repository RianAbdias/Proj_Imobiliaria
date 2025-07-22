#ifndef CORRETOR
#define CORRETOR

#include <string>
#include <vector>
#include "imovel.h"

class Corretor {
private:
    static int guardaid;
    int id;
    std::string nome;
    std::string telefone;
    bool avaliador;
    double lat;
    double lng;
    std::vector<Imovel*> imoveisAgendados;

public:
    Corretor(const std::string& telefone, bool avaliador, double lat, double lng, const std::string& nome);

    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getTelefone() const;
    bool isAvaliador() const;
    double getLat() const;
    double getLng() const;
    const std::vector<Imovel*>& getImoveisAgendados() const;

    // Setters
    void setNome(const std::string& novoNome);
    void setTelefone(const std::string& novoTelefone);
    void setAvaliador(bool avaliador);
    void setLat(double novaLat);
    void setLng(double novaLng);

    // Agendamento
    void adicionarImovel(Imovel* imovel);
    void limparAgendamentos();
};

#endif
