#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <iostream>
#include "funcionario.hpp"
#include "pessoa.hpp"
#include "util.hpp"

using namespace std;

// Gerente class that inherits from Pessoa and Funcionario
class Gerente : public Pessoa, public Funcionario {
    // All attributes of the class are private
private:
    float participacaoLucros;

public:
    // Empty constructor and parameterized constructor
    Gerente();
    Gerente(float lucro);

    // Get and set methods for all attributes
    float getParticipacaoLucros();
    void setParticipacaoLucros(float lucro);

    // Class methods
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif