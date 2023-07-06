#include <iostream>
#include "vendedor.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

// Empty constructor and parameterized constructor
Vendedor::Vendedor() {}
Vendedor::Vendedor(char tipo) { this->tipoVendedor=tipo; }

// Getters and setters for all attributes
char Vendedor::getTipoVendedor() { return this->tipoVendedor; }
void Vendedor::setTipoVendedor(char tipo) { this->tipoVendedor=tipo; }

// Function to calculate the salary of the salesperson
float Vendedor::calcularSalario() {
    // First, we get the number of absences and the base salary
    int faltas=getFaltas();
    float salarioBase=stof(getSalario());
    
    // Then, we deduct the value of absences
    salarioBase-=(salarioBase/30)*faltas;
    // Next, we add the bonus to the salesperson's salary based on the type of salesperson
    if(tipoVendedor=='A')
        salarioBase*=1.25;
    else if(tipoVendedor=='B')
        salarioBase*=1.1;
    else if(tipoVendedor=='C')
        salarioBase*=1.05;
    // Finally, we add the bonus per child
    salarioBase+=getQtdFilhos()*100;
    return salarioBase;
}

// Function to calculate the severance payment of the salesperson
float Vendedor::calcularRecisao(Data desligamento) {
    // First, we get the date of entry and the date of departure from the company and convert them to days
    float diaIngressadoNaEmpresa=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;
    float diaDeDesligamento=desligamento.ano*365+desligamento.mes*30+desligamento.dia;
    // Then, we find the difference between the two dates and convert this difference back to years to get the number of days worked
    float diferencaEmAnos=(diaDeDesligamento-diaIngressadoNaEmpresa)/365;

    // With this information, we can multiply the base salary by the number of years worked and return that value
    float adicional=stof(getSalario())*diferencaEmAnos;
    return adicional;
}