#ifndef IMOVEL
#define IMOVEL

#include <string>
#include <chrono>

class Imovel {
public:
    enum Tipo { CASA, APARTAMENTO, TERRENO };

private:
    static int guardaid;
    int id;
    Tipo tipo;
    int proprietarioId;
    double lat;
    double lng;
    std::string endereco;
    double preco;
    std::chrono::system_clock::time_point horarioVisita;

public:
    Imovel(const std::string& tipoStr, int propId, double latitude, double longitude, double valor, const std::string& end);

    // Getters
    int getId() const;
    Tipo getTipo() const;
    std::string getTipoString() const;
    int getProprietarioId() const;
    double getLat() const;
    double getLng() const;
    const std::string& getEndereco() const;
    double getPreco() const;
    std::chrono::system_clock::time_point getHorarioVisita() const;
    std::string getHorarioVisitaString() const;

    // Setters
    void setTipo(Tipo novoTipo);
    void setProprietarioId(int id);
    void setLat(double latitude);
    void setLng(double longitude);
    void setEndereco(const std::string& end);
    void setPreco(double valor);
    void setHorarioVisita(const std::chrono::system_clock::time_point& horario);
};

#endif
