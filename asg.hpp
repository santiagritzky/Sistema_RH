#ifndef ASG_HPP
#define ASG_HPP

#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

// Asg class that inherits from Pessoa and Funcionario
class Asg : public Pessoa, public Funcionario {
private:
    float adicionalInsalubridade;

public:
    // Default constructor and parameterized constructor
    Asg();
    Asg(float adicional);

    // Getter and setter methods for all attributes
    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicional);

    // Class methods
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif