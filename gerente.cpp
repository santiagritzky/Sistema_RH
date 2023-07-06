#include <iostream>
#include "gerente.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"

using namespace std;

// Empty constructor and parameterized constructor
Gerente::Gerente() {}
Gerente::Gerente(float lucro) { this->participacaoLucros = lucro; }

// Get and set methods for all attributes
float Gerente::getParticipacaoLucros() { return this->participacaoLucros; }
void Gerente::setParticipacaoLucros(float lucro) { this->participacaoLucros = lucro; }

// Function to calculate the salary of the gerente
float Gerente::calcularSalario() {
    // First, get the base salary using the get method
    float salarioBase = stof(getSalario());
    // Then deduct the value for absences
    salarioBase -= (salarioBase / 30) * getFaltas();
    // Add the participation value
    salarioBase += participacaoLucros;
    // Finally, add the bonus per child
    salarioBase = salarioBase + (getQtdFilhos() * 100);
    return salarioBase;
}

// Function to calculate the severance pay of the gerente
float Gerente::calcularRecisao(Data desligamento) {
    // First, get the ingresso date and desligamento date in days
    float diaIngressadoNaEmpresa = getIngressoEmpresa().ano * 365 + (getIngressoEmpresa().mes) * 30 + getIngressoEmpresa().dia;
    float diaDeDesligamento = desligamento.ano * 365 + desligamento.mes * 30 + desligamento.dia;
    // Then find the difference between the two dates and convert this difference back to years to get the number of days worked
    float diferencaEmAnos = (diaDeDesligamento - diaIngressadoNaEmpresa) / 365;

    // With this information, we can multiply the base salary by the number of years worked and return that value
    float adicional = stof(getSalario()) * diferencaEmAnos;
    return adicional;
}