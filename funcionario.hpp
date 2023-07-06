#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include "util.hpp"

using namespace std;

// Abstract class Funcionario
class Funcionario {
    // All attributes are private
private:
    string salario;
    string matricula;
    Data ingressoEmpresa;
    int faltas;

public:
    //get and set methods
    string getSalario();
    void setSalario(string salario);
    string getMatricula();
    void setMatricula(string matricula);
    Data getIngressoEmpresa();
    void setIngressoEmpresa(Data ingressoEmpresa);
    int getFaltas();
    void setFaltas(int diasfaltas);

    // the virtual methods
    virtual float calcularSalario() = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif