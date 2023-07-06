#include <iostream>
#include "asg.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

// Default constructor and parameterized constructor
Asg::Asg() {}
Asg::Asg(float adicional) { this->adicionalInsalubridade = adicional; }

// Getter and setter methods for all attributes
float Asg::getAdicionalInsalubridade() { return this->adicionalInsalubridade; }
void Asg::setAdicionalInsalubridade(float adicional) { this->adicionalInsalubridade = adicional; }

// Function to calculate the salary of the assistant
float Asg::calcularSalario() {
//  get the base salary using the get method
float salarioBase = stof(getSalario());
// deduct the value for absences
salarioBase -= (salarioBase / 30) * getFaltas();
// Then add the insalubrity bonus
salarioBase = salarioBase * (1 + adicionalInsalubridade);
// add the bonus per child
salarioBase = salarioBase + (getQtdFilhos() * 100);
return salarioBase;
}

// Function to calculate the severance payment 
float Asg::calcularRecisao(Data desligamento) {
// First, get the entry and separation dates from the company and convert them to days
float diaIngressadoNaEmpresa = getIngressoEmpresa().ano * 365 + (getIngressoEmpresa().mes) * 30 + getIngressoEmpresa().dia;
float diaDeDesligamento = desligamento.ano * 365 + desligamento.mes * 30 + desligamento.dia;
// Then find the difference between the two dates and convert that difference back to years to get the number of days worked
float diferencaEmAnos = (diaDeDesligamento - diaIngressadoNaEmpresa) / 365;

// return that value
float adicional = stof(getSalario()) * diferencaEmAnos;
return adicional;

}