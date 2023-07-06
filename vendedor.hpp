#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

// Class Vendedor that inherits from Pessoa and Funcionario
class Vendedor:public Pessoa, public Funcionario {
    // All attributes of the class are private
    private:
    char tipoVendedor;

    // In the public section, we have all the methods
    public:
    // Empty constructor and parameterized constructor
    Vendedor();
    Vendedor(char tipo);

    // Getters and setters for all attributes
    char getTipoVendedor();
    void setTipoVendedor(char tipo);

    // Class methods
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif