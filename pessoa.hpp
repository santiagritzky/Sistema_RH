#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"
using namespace std;

// Class Pessoa
class Pessoa {
    // All attributes of the class are private
    private:
    string nome;
    string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    string estadoCivil;
    int qtdFilhos;

    // In the public section, we have all the methods
    public:
    // Empty constructor and parameterized constructor
    Pessoa();
    Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos);

    // Get and set methods for all attributes
    string getNome();
    void setNome(string nome);
    string getCpf();
    void setCpf(string cpf);
    Data getDataNascimento();
    void setDataNascimento(Data dataNascimento);
    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(Endereco enderecoPessoal);
    string getEstadoCivil();
    void setEstadoCivil(string estadoCivil);
    int getQtdFilhos();
    void setQtdFilhos(int qtdFilhos);
};

#endif