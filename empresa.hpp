#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include <vector>

using namespace std;

// Empresa class
class Empresa {
private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

public:
    // Default constructor and parameterized constructor
    Empresa();
    Empresa(string nome, string cnpj, float faturamento);

    // Getter and setter methods for all attributes
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamento);
    string getNomeEmpresa();
    void setNomeEmpresa(string nome);
    string getCnpj();
    void setCnpj(string cnpj);
    vector<Asg> getAsgs();
    vector<Vendedor> getVendedores();
    vector<Gerente> getGerentes();

    // Class methods
    void carregarFuncoes();
    void carregarEmpresa();
    void carregarAsg();
    void carregaDono();
    void carregarVendedor();
    void carregarGerente();
    void imprimeAsgs();
    void imprimeVendedores();
    void imprimeGerentes();
    void imprimeDono();
    bool buscaFuncionario(string matricula);
    float calculaSalarioFuncionario(string matricula);
    void calculaTodosOsSalarios();
    float calcularRecisao(string matricula, Data desligamento);
    void demitirFuncionario(string matricula, Data desligamento);
    void contratarFuncionario();
};

#endif