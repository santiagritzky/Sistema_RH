#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include "empresa.hpp"
#include <fstream>
#include <vector>

using namespace std;

// Default constructor and parameterized constructor
Empresa::Empresa() {}
Empresa::Empresa(string nome, string cnpj, float faturamento)
{
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamento;
    this->nomeEmpresa = nome;
}

// Getter and setter methods for all attributes
float Empresa::getFaturamentoMensal() { return this->faturamentoMensal; }
void Empresa::setFaturamentoMensal(float faturamento) { this->faturamentoMensal = faturamento; }
string Empresa::getNomeEmpresa() { return this->nomeEmpresa; }
void Empresa::setNomeEmpresa(string nome) { this->nomeEmpresa = nome; }
string Empresa::getCnpj() { return this->cnpj; }
void Empresa::setCnpj(string cnpj) { this->cnpj = cnpj; }
vector<Asg> Empresa::getAsgs() { return this->asgs; }
vector<Vendedor> Empresa::getVendedores() { return this->vendedores; }
vector<Gerente> Empresa::getGerentes() { return this->gerentes; }

// Method to execute all functions from the "funcoes.txt" file
void Empresa::carregarFuncoes()
{
    ifstream file("funcoes.txt");
    string linha;

    // Test if the file can be opened
    if (!(file.is_open()))
    {
        cout << "erro na leitura do arquivo funcoes.txt" << endl;
        return;
    }

    // Read the file and call the respective methods
    while (getline(file, linha))
    {
        if (linha == "carregarAsg()")
            carregarAsg();
        else if (linha == "carregarEmpresa()")
            carregarEmpresa();
        else if (linha == "carregaDono()")
            carregaDono();
        else if (linha == "carregarGerente()")
            carregarGerente();
        else if (linha == "carregarVendedor()")
            carregarVendedor();
        else if (linha == "imprimeAsgs()")
            imprimeAsgs();
        else if (linha == "imprimeDono()")
            imprimeDono();
        else if (linha == "imprimeVendedores()")
            imprimeVendedores();
        else if (linha == "imprimeGerentes()")
            imprimeGerentes();
        else if (linha == "contratarFuncionario()")
            contratarFuncionario();
        else if (linha == "buscaFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            buscaFuncionario(parametro);
        }
        else if (linha == "calculaSalarioFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            calculaSalarioFuncionario(parametro);
        }
        else if (linha == "calculaTodosOsSalarios()")
            calculaTodosOsSalarios();
        else if (linha == "calcularRecisao()")
        {
            string matricula;
            string datas;
            Data data;

            getline(file, matricula);

            getline(file, datas);
            data.ano = stoi(datas);
            getline(file, datas);
            data.mes = stoi(datas);
            getline(file, datas);
            data.dia = stoi(datas);

            calcularRecisao(matricula, data);
        }
        else if (linha == "demitirFuncionario()")
        {
            string matricula;
            string datas;
            Data data;

            getline(file, matricula);

            getline(file, datas);
            data.ano = stoi(datas);
            getline(file, datas);
            data.mes = stoi(datas);
            getline(file, datas);
            data.dia = stoi(datas);

            demitirFuncionario(matricula, data);
        }
    }

    file.close();
}

// Method to read the "dono.txt" file and store its information
void Empresa::carregaDono()
{
    ifstream file("dono.txt");
    string linha;

    // Test if the file can be opened
    if (!(file.is_open()))
    {
        cout << "Error na leitura do arquivo dono.txt" << endl;
        return;
    }

    getline(file, linha);
    getline(file, linha);

    // Store the owner's name
    getline(file, linha);
    dono.setNome(linha);

    // Store the owner's CPF
    getline(file, linha);
    dono.setCpf(linha);

    // Store the number of children
    getline(file, linha);
    int filhos = stoi(linha);
    dono.setQtdFilhos(filhos);

    // Store the marital status
    getline(file, linha);
    dono.setEstadoCivil(linha);

    // Store the complete address
    Endereco endereco;
    getline(file, linha);
    endereco.cidade = linha;
    getline(file, linha);
    endereco.cep = linha;
    getline(file, linha);
    endereco.bairro = linha;
    getline(file, linha);
    endereco.rua = linha;
    getline(file, linha);
    int num = stoi(linha);
    endereco.numero = num;
    dono.setEnderecoPessoal(endereco);

    // Store the date of birth
    Data nascimento;
    getline(file, linha);
    int ano = stoi(linha);
    nascimento.ano = ano;
    getline(file, linha);
    int mes = stoi(linha);
    nascimento.mes = mes;
    getline(file, linha);
    int dia = stoi(linha);
    nascimento.dia = dia;
    dono.setDataNascimento(nascimento);

    file.close();
}

// Method to read the "empresa.txt" file and store its information
void Empresa::carregarEmpresa()
{
    ifstream file("empresa.txt");
    string linha;

    // Test if the file can be opened
    if (!(file.is_open()))
    {
        cout << "Error na leitura do arquivo empresa.txt" << endl;
        return;
    }

    getline(file, linha);
    getline(file, linha);

    // Store the company name
    getline(file, linha);
    setNomeEmpresa(linha);

    // Store the company's CNPJ
    getline(file, linha);
    setCnpj(linha);

    // Store the monthly revenue of the company
    getline(file, linha);
    setFaturamentoMensal(stof(linha));

    file.close();
}

// Method to read the "asg.txt" file and store its information
void Empresa::carregarAsg()
{
    ifstream file("asg.txt");
    string linha;

    // Test if the file can be opened
    if (!(file.is_open()))
    {
        cout << "Error na leitura do arquivo ASG.txt" << endl;
        return;
    }

    Asg asg;
    Endereco endereco;
    Data datan, datai;

    // Read the file and store the information
    while (getline(file, linha))
    {
        getline(file, linha);
        getline(file, linha);

        // Store the name of the asg
        getline(file, linha);
        asg.setNome(linha);

        // Store the CPF of the asg
        getline(file, linha);

        asg.setCpf(linha);

        // Store the number of children of the asg
        getline(file, linha);
        asg.setQtdFilhos(stoi(linha));

        // Store the marital status of the asg
        getline(file, linha);
        asg.setEstadoCivil(linha);

        // Store the complete address of the asg
        getline(file, linha);
        getline(file, linha);
        endereco.cidade = linha;
        getline(file, linha);
        endereco.cep = linha;
        getline(file, linha);
        endereco.bairro = linha;
        getline(file, linha);
        endereco.rua = linha;
        getline(file, linha);
        endereco.numero = stoi(linha);
        asg.setEnderecoPessoal(endereco);

        // Store the date of birth of the asg
        getline(file, linha);
        getline(file, linha);
        datan.ano = stoi(linha);
        getline(file, linha);
        datan.mes = stoi(linha);
        getline(file, linha);
        datan.dia = stoi(linha);
        asg.setDataNascimento(datan);

        // Store the matricula
        getline(file, linha);
        getline(file, linha);
        asg.setMatricula(linha);

        // Store the salary
        getline(file, linha);
        asg.setSalario(linha);

        // Store the additional insalubridade
        getline(file, linha);
        asg.setAdicionalInsalubridade(stof(linha));

        // Store the number of absences
        getline(file, linha);
        asg.setFaltas(stoi(linha));

        // Store the ingresso date
        getline(file, linha);
        getline(file, linha);
        datai.ano = stoi(linha);
        getline(file, linha);
        datai.mes = stoi(linha);
        getline(file, linha);
        datai.dia = stoi(linha);
        asg.setIngressoEmpresa(datai);

        asgs.push_back(asg);
    }

    file.close();
}

void Empresa::carregarVendedor()
{

    Vendedor vendedorTemp;
    Data nascVendedor;
    Data ingressoVendedor;
    Endereco endVendedor;

    ifstream arquivoSaida("vendedor.txt");
    string linha;
    if (arquivoSaida.is_open())
    {
        while (getline(arquivoSaida, linha))
        {

            if (linha.find("#") != string::npos || linha.find("*") != string::npos || linha.find("VENDEDOR") != string::npos)
            {
                continue;
            }
            // getline(arquivoSaida,linha);
            vendedorTemp.setNome(linha);
            getline(arquivoSaida, linha);
            vendedorTemp.setCpf(linha);
            getline(arquivoSaida, linha);
            vendedorTemp.setQtdFilhos(stoi(linha));
            getline(arquivoSaida, linha);
            vendedorTemp.setEstadoCivil(linha);
            getline(arquivoSaida, linha);
            endVendedor.cidade = linha;
            getline(arquivoSaida, linha);
            endVendedor.cep = linha;
            getline(arquivoSaida, linha);
            endVendedor.bairro = linha;
            getline(arquivoSaida, linha);
            endVendedor.rua = linha;
            getline(arquivoSaida, linha);
            endVendedor.numero = stoi(linha);
            getline(arquivoSaida, linha);
            nascVendedor.ano = stoi(linha);
            getline(arquivoSaida, linha);
            nascVendedor.mes = stoi(linha);
            getline(arquivoSaida, linha);
            nascVendedor.dia = stoi(linha);
            getline(arquivoSaida, linha);
            vendedorTemp.setMatricula(linha);
            getline(arquivoSaida, linha);
            vendedorTemp.setSalario(linha);
            getline(arquivoSaida, linha);
            vendedorTemp.setTipoVendedor(linha[0]);
            getline(arquivoSaida, linha);
            ingressoVendedor.ano = (stof(linha));
            getline(arquivoSaida, linha);
            ingressoVendedor.mes = stof(linha);
            getline(arquivoSaida, linha);
            ingressoVendedor.dia = stof(linha);

            vendedorTemp.setDataNascimento(nascVendedor);
            vendedorTemp.setEnderecoPessoal(endVendedor);
            vendedorTemp.setIngressoEmpresa(ingressoVendedor);

            this->vendedores.push_back(vendedorTemp);
        }

        arquivoSaida.close();
    }
    else
    {
        cout << "o arquivo vendedor.txt nao foi impresso corretamente" << endl;
    }
}


// Method to read the "gerente.txt" file and store its information
void Empresa::carregarGerente()
{
    ifstream file("gerente.txt");
    string linha;

    // Test if the file can be opened
    if (!(file.is_open()))
    {
        cout << "Erro na leitura do arquivo gerente.txt" << endl;
        return;
    }

    Gerente gerente;
    Endereco endereco;
    Data datan, datai;

    // Read the information from the file and store it
    while (getline(file, linha))
    {
        getline(file, linha);
        getline(file, linha);

        // Store the name of the gerente
        getline(file, linha);
        gerente.setNome(linha);

        // Store the CPF of the gerente
        getline(file, linha);
        gerente.setCpf(linha);

        // Store the number of children of the gerente
        getline(file, linha);
        gerente.setQtdFilhos(stoi(linha));

        // Store the marital status of the gerente
        getline(file, linha);
        gerente.setEstadoCivil(linha);

        // Store the complete address of the gerente
        getline(file, linha);
        getline(file, linha);
        endereco.cidade = linha;
        getline(file, linha);
        endereco.cep = linha;
        getline(file, linha);
        endereco.bairro = linha;
        getline(file, linha);
        endereco.rua = linha;
        getline(file, linha);
        endereco.numero = stoi(linha);
        gerente.setEnderecoPessoal(endereco);

        // Store the date of birth of the gerente
        getline(file, linha);
        getline(file, linha);
        datan.ano = stoi(linha);
        getline(file, linha);
        datan.mes = stoi(linha);
        getline(file, linha);
        datan.dia = stoi(linha);
        gerente.setDataNascimento(datan);

        // Store the matricula of the gerente
        getline(file, linha);
        getline(file, linha);
        gerente.setMatricula(linha);

        // Store the salary of the gerente
        getline(file, linha);
        gerente.setSalario(linha);

        // Store the participacaoLucros of the gerente
        getline(file, linha);
        gerente.setParticipacaoLucros(stof(linha));

        // Store the faltas of the gerente
        getline(file, linha);
        gerente.setFaltas(stoi(linha));

        // Store the ingresso date
        getline(file, linha);
        getline(file, linha);
        datai.ano = stoi(linha);
        getline(file, linha);
        datai.mes = stoi(linha);
        getline(file, linha);
        datai.dia = stoi(linha);
        gerente.setIngressoEmpresa(datai);

        gerentes.push_back(gerente);
    }
    file.close();
}

// Method to display the information of all ASGs on the screen
void Empresa::imprimeAsgs()
{
    // Iterate over the vector of ASGs and print the information of each one
    cout << "todos os ASG:" << endl;
    for (auto i : asgs)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereço: rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "status civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQtdFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na compania: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "#################################" << endl;
    }
}

// Method to display the information of all vendedores on the screen
void Empresa::imprimeVendedores()
{
    // Iterate over the vector of vendedores and print the information of each one
    cout << "todos os vendedores:" << endl;
    for (auto i : vendedores)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereço: rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "status civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQtdFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na compania: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "#################################" << endl;
    }
}

// Method to display the information of all Gerentes on the screen
void Empresa::imprimeGerentes()
{
    // Iterate over the vector of gerentes and print the information of each one
    cout << "todos os gerentes:" << endl;
    for (auto i : gerentes)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereço: rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "status civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQtdFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na compania: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "#################################" << endl;
    }
}

// Method to display the information of the dono on the screen
void Empresa::imprimeDono()
{
    // Display all information about the dono
    cout << "informações do dono:" << endl;
    cout << "Nome: " << dono.getNome() << endl;
    cout << "CPF: " << dono.getCpf() << endl;
    cout << "Data de nascimento: " << dono.getDataNascimento().dia << "/" << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().ano << endl;
    cout << "Endereço: rua " << dono.getEnderecoPessoal().rua << ", " << dono.getEnderecoPessoal().numero << endl;
    cout << "status civil: " << dono.getEstadoCivil() << endl;
    cout << "Numero de filhos: " << dono.getQtdFilhos() << endl;
}

// Method to search for an employee
bool Empresa::buscaFuncionario(string matricula)
{
    // Iterate through the vectors of ASGs, vendedores, and gerentes and compare with the given matricula
    // If the matricula matches the iterated object, the employee is found
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Empregado com a matricula " << matricula << " encontrado!" << endl;
            return true;
        }
    }
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Empregado com a matricula " << matricula << " encontrado!" << endl;
            return true;
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Empregado com a matricula  " << matricula << " encontrado!" << endl;
            return true;
        }
    }

    // If the iteration goes through everything and no match is found, the employee is not found
    cout << "Empregado com a matricula " << matricula << " não encontrado" << endl;
    return false;
}

// Method to calculate the severance payment of an employee given a matricula
float Empresa::calcularRecisao(string matricula, Data desligamento)
{
    // Iterate through the vectors of ASGs, vendedores, and gerentes and compare with the given matricula
    // If the matricula matches the iterated object, it means that the employee is found, so their severance payment is returned
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisão de pagamento do funcionario referente a matricula: " << matricula << " é: " << i.calcularRecisao(desligamento) << endl;
            return i.calcularRecisao(desligamento);
        }
    }
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisão de pagamento do funcionario referente a matricula: " << matricula << " é: " << i.calcularRecisao(desligamento) << endl;
            return i.calcularRecisao(desligamento);
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisão de pagamento do funcionario referente a matricula: " << matricula << " é: " << i.calcularRecisao(desligamento) << endl;
            return i.calcularRecisao(desligamento);
        }
    }
    // If it iterates through everything and no match is found, it means that the employee is not found
    cout << "O funcionario referente a matricula " << matricula << " Não encontrado!" << endl;
    return -1;
}

// Method to calculate the salary of an employee given a matricula
float Empresa::calculaSalarioFuncionario(string matricula)
{
    // Iterate through the vectors of ASGs, vendedores, and gerentes and compare with the given matricula
    // If the matricula matches the iterated object, it means that the employee is found, so their salary is returned
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario referente a matricula: " << matricula << " é: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario referente a matricula: " << matricula << " é: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario referente a matricula: " << matricula << " é: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }

    // If it iterates through everything and no match is found, it means that the employee is not found
    cout << "O funcionario referente a matricula  " << matricula << " Não encontrado!" << endl;
    return -1;
}

// Method to display the information of the "salario.txt" file
void Empresa::calculaTodosOsSalarios()
{
    float total = 0, totala = 0, totalv = 0, totalg = 0;
    ofstream file("salarios.txt");

    // Check if the file can be opened
    if (!(file.is_open()))
    {
        cout << "Error in reading the file" << endl;
        return;
    }

    // Iterate over the vector of asgs
    for (auto i : asgs)
    {
        file << "Nome do funcionário:" << i.getNome() << endl;
        cout << "Nome do funcionário:" << i.getNome() << endl;
        file << "Cargo do funcionário: ASG" << endl;
        cout << "Cargo do funcionário: ASG" << endl;
        file << "Salário do funcionário: " << i.calcularSalario() << endl;
        cout << "Salário do funcionário: " << i.calcularSalario() << endl;
        file << "###########################################" << endl;
        cout << "###########################################" << endl;
        total += i.calcularSalario();
        totala += i.calcularSalario();
    }
    file << "---------//---------//---------" << endl;
    cout << "---------//---------//---------" << endl;

    // Iterate over the vector of vendedores
    for (auto i : vendedores)
    {
        file << "Nome do funcionário:" << i.getNome() << endl;
        cout << "Nome do funcionário:" << i.getNome() << endl;
        file << "Cargo do funcionário: vendedor" << endl;
        cout << "Cargo do funcionário: vendedor" << endl;
        file << "Salário do funcionário: " << i.calcularSalario() << endl;
        cout << "Salário do funcionário: " << i.calcularSalario() << endl;
        file << "###########################################" << endl;
        cout << "###########################################" << endl;
        total += i.calcularSalario();
        totalv += i.calcularSalario();
    }
    file << "---------//---------//---------" << endl;
    cout << "---------//---------//---------" << endl;

    // Iterate over the vector of gerentes
    for (auto i : gerentes)
    {
        file << "Nome do funcionário:" << i.getNome() << endl;
        cout << "Nome do funcionário:" << i.getNome() << endl;
        file << "Cargo do funcionário: gerente" << endl;
        cout << "Cargo do funcionário: gerente" << endl;
        file << "Salário do funcionário: " << i.calcularSalario() << endl;
        cout << "Salário do funcionário: " << i.calcularSalario() << endl;
        file << "###########################################" << endl;
        cout << "###########################################" << endl;
        total += i.calcularSalario();
        totalg += i.calcularSalario();
    }
    file << "---------//---------//---------" << endl;
    cout << "---------//---------//---------" << endl;

    file<<"Total de salários dos funcionários ASG: "<<totala<<endl;
    cout<<"Total de salários dos funcionários ASG: "<<totala<<endl;
    file<<"Total de salários dos vendedores: "<<totalv<<endl;
    cout<<"Total de salários dos vendedores: "<<totalv<<endl;
    file<<"Total de salários dos gerentes: "<<totalg<<endl;
    cout<<"Total de salários dos gerentes: "<<totalg<<endl;

    file << "---------//---------//---------" << endl;
    cout << "---------//---------//---------" << endl;
    file<<"Total de salários dos funcionários: "<<total<<endl;
    cout<<"Total de salários dos funcionários: "<<total<<endl;
    file.close();

    ofstream relatorioFinanceiroFile("relatorioFinanceiro.txt");

    relatorioFinanceiroFile << "######### Relatório Financeiro ########" << endl
                            << endl;

    relatorioFinanceiroFile << "Cargo: ASG" << endl;
    for (auto i : asgs)
    {
        relatorioFinanceiroFile << i.getMatricula() << " - " << i.getNome() << " - R$ " << i.calcularSalario() << endl;
    };
    relatorioFinanceiroFile << "Total ASG: R$ " << totala << endl
                            << endl;

    relatorioFinanceiroFile << "Cargo: Vendedor" << endl;
    for (auto i : vendedores)
    {
        relatorioFinanceiroFile << i.getMatricula() << " - " << i.getNome() << " - R$ " << i.calcularSalario() << endl;
    }
    relatorioFinanceiroFile << "Total Vendedor: R$" << totalv << endl
                            << endl;

    relatorioFinanceiroFile << "Cargo: Gerente" << endl;
    for (auto i : gerentes)
    {
        relatorioFinanceiroFile << i.getMatricula() << " - " << i.getNome() << " - R$ " << i.calcularSalario() << endl;
    }
    relatorioFinanceiroFile << "Total Gerente: R$ " << totalg << endl
                            << endl;

    relatorioFinanceiroFile << "CUSTO TOTAL: R$ " << total << endl
                            << endl;

    relatorioFinanceiroFile << "FATURAMENTO MENSAL: R$ " << this->getFaturamentoMensal() << endl
                            << endl;

    relatorioFinanceiroFile << "Custo ASG(%):" << (totala / total) * 100 << "%" << endl;
    relatorioFinanceiroFile << "Custo Vendedor(%):" << (totalv / total) * 100 << "%" << endl;
    relatorioFinanceiroFile << "Custo Gerente(%):" << (totalg / total) * 100 << "%" << endl
                            << endl;

    relatorioFinanceiroFile << "LUCRO DA EMPRESA: R$ " << this->getFaturamentoMensal() - total << endl
                            << endl;

    if (this->getFaturamentoMensal() - total > 0)
    {
        relatorioFinanceiroFile << "SITUAÇÃO: Lucro" << endl;
    }
    else
    {
        relatorioFinanceiroFile << "SITUAÇÃO: Prejuízo" << endl;
    }
}



void Empresa::demitirFuncionario(string matricula, Data desligamento)
{

    float recisao = calcularRecisao(matricula, desligamento);
    string fileToUpdate;

    ofstream file("relatórioDemissional.txt");

    // Teste para se o arquivo pode ser aberto
    if (!(file.is_open()))
    {
        cout << "Erro na criação do arquivo" << endl;
        return;
    }

    Gerente gerenteDemitido;
    Asg asgDemitido;
    Vendedor vendedorDemitido;

    string cargo, nome, cpf;
    Data ingressoEmpresa;

    for (auto i : gerentes)
    {
        int index = 0;
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario da matricula " << matricula << " encontrado!" << endl;
            gerenteDemitido = i;
            cargo = "Gerente";
            nome = i.getNome();
            cpf = i.getCpf();
            ingressoEmpresa = i.getIngressoEmpresa();
            this->gerentes.erase(this->gerentes.begin() + index);
            fileToUpdate = "gerente.txt";
        }
        index++;
    }
    for (auto i : asgs)
    {
        int index = 0;
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario da matricula " << matricula << " encontrado!" << endl;
            asgDemitido = i;
            cargo = "ASG";
            nome = i.getNome();
            cpf = i.getCpf();
            ingressoEmpresa = i.getIngressoEmpresa();
            this->asgs.erase(this->asgs.begin() + index);
            fileToUpdate = "asg.txt";
        }
        index++;
    }
    for (auto i : vendedores)
    {
        int index = 0;
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario da matricula " << matricula << " encontrado!" << endl;
            vendedorDemitido = i;
            cargo = "Vendedor";
            nome = i.getNome();
            cpf = i.getCpf();
            ingressoEmpresa = i.getIngressoEmpresa();
            this->vendedores.erase(this->vendedores.begin() + index);
            fileToUpdate = "vendedor.txt";
        }
        index++;
    }

    long int diasTrabalhados = ((desligamento.ano * 365) + (desligamento.mes * 30) + desligamento.dia) - ((ingressoEmpresa.ano * 365) + (ingressoEmpresa.mes * 30) + ingressoEmpresa.dia);

    Data tempoDeTrabalho;
    tempoDeTrabalho.ano = (int)diasTrabalhados / 365;
    diasTrabalhados = diasTrabalhados % 365;
    tempoDeTrabalho.mes = (int)diasTrabalhados / 30;
    diasTrabalhados = diasTrabalhados % 30;
    tempoDeTrabalho.dia = diasTrabalhados;

    file << "##############################" << endl;
    file << "    Relatorio Demissional" << endl;
    file << "##############################" << endl;
    file << "Cargo: " << cargo << endl;
    file << "Nome: " << nome << endl;
    file << "CPF: " << cpf << endl;
    file << "Matrícula: " << matricula << endl;
    file << "Data de ingresso: " << ingressoEmpresa.dia << "/" << ingressoEmpresa.mes << "/" << ingressoEmpresa.ano << endl;
    file << "Data de demissão: " << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << endl;
    file << "********************************" << endl;
    file << "Valor de rescisão: R$ " << recisao << endl;
    file << "********************************" << endl;
    file << "Tempo de Trabalho: " << tempoDeTrabalho.ano << " anos, " << tempoDeTrabalho.mes << " meses e " << tempoDeTrabalho.dia << " dias" << endl;

    file.close();

    ofstream updatedFile(fileToUpdate);

    if (cargo == "Gerente")
    {
        int index = 0;
        for (auto i : gerentes)
        {
            updatedFile << "#########################################################" << endl;
            updatedFile << "Gerente N°" << index << endl;
            updatedFile << "##### DADOS PESSOAIS #####" << endl;
            updatedFile << i.getNome() << endl;
            updatedFile << i.getCpf() << endl;
            updatedFile << i.getQtdFilhos() << endl;
            updatedFile << i.getEstadoCivil() << endl;
            updatedFile << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            updatedFile << i.getEnderecoPessoal().cidade << endl;
            updatedFile << i.getEnderecoPessoal().cep << endl;
            updatedFile << i.getEnderecoPessoal().bairro << endl;
            updatedFile << i.getEnderecoPessoal().rua << endl;
            updatedFile << i.getEnderecoPessoal().numero << endl;
            updatedFile << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            updatedFile << i.getDataNascimento().ano << endl;
            updatedFile << i.getDataNascimento().mes << endl;
            updatedFile << i.getDataNascimento().dia << endl;
            updatedFile << "##### DADOS FUNCIONAIS #####" << endl;
            updatedFile << i.getMatricula() << endl;
            updatedFile << i.getSalario() << endl;
            updatedFile << i.getParticipacaoLucros() << endl;
            updatedFile << i.getFaltas() << endl;
            updatedFile << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            updatedFile << i.getIngressoEmpresa().ano << endl;
            updatedFile << i.getIngressoEmpresa().mes << endl;
            updatedFile << i.getIngressoEmpresa().dia << endl;
            index++;
        }
    }
    else if (cargo == "ASG")
    {
        int index = 0;
        for (auto i : asgs)
        {
            updatedFile << "#########################################################" << endl;
            updatedFile << "ASG N°" << index << endl;
            updatedFile << "##### DADOS PESSOAIS #####" << endl;
            updatedFile << i.getNome() << endl;
            updatedFile << i.getCpf() << endl;
            updatedFile << i.getQtdFilhos() << endl;
            updatedFile << i.getEstadoCivil() << endl;
            updatedFile << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            updatedFile << i.getEnderecoPessoal().cidade << endl;
            updatedFile << i.getEnderecoPessoal().cep << endl;
            updatedFile << i.getEnderecoPessoal().bairro << endl;
            updatedFile << i.getEnderecoPessoal().rua << endl;
            updatedFile << i.getEnderecoPessoal().numero << endl;
            updatedFile << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            updatedFile << i.getDataNascimento().ano << endl;
            updatedFile << i.getDataNascimento().mes << endl;
            updatedFile << i.getDataNascimento().dia << endl;
            updatedFile << "##### DADOS FUNCIONAIS #####" << endl;
            updatedFile << i.getMatricula() << endl;
            updatedFile << i.getSalario() << endl;
            updatedFile << i.getAdicionalInsalubridade() << endl;
            updatedFile << i.getFaltas() << endl;
            updatedFile << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            updatedFile << i.getIngressoEmpresa().ano << endl;
            updatedFile << i.getIngressoEmpresa().mes << endl;
            updatedFile << i.getIngressoEmpresa().dia << endl;
            index++;
        }
    }
    else if (cargo == "Vendedor")
    {
        int index = 0;
        for (auto i : vendedores)
        {
            updatedFile << "#########################################################" << endl;
            updatedFile << "Vendedor N°" << index << endl;
            updatedFile << "##### DADOS PESSOAIS #####" << endl;
            updatedFile << i.getNome() << endl;
            updatedFile << i.getCpf() << endl;
            updatedFile << i.getQtdFilhos() << endl;
            updatedFile << i.getEstadoCivil() << endl;
            updatedFile << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
            updatedFile << i.getEnderecoPessoal().cidade << endl;
            updatedFile << i.getEnderecoPessoal().cep << endl;
            updatedFile << i.getEnderecoPessoal().bairro << endl;
            updatedFile << i.getEnderecoPessoal().rua << endl;
            updatedFile << i.getEnderecoPessoal().numero << endl;
            updatedFile << "***** Data de nascimento (ano, mes, dia) ****" << endl;
            updatedFile << i.getDataNascimento().ano << endl;
            updatedFile << i.getDataNascimento().mes << endl;
            updatedFile << i.getDataNascimento().dia << endl;
            updatedFile << "##### DADOS FUNCIONAIS #####" << endl;
            updatedFile << i.getMatricula() << endl;
            updatedFile << i.getSalario() << endl;
            updatedFile << i.getTipoVendedor() << endl;
            updatedFile << i.getFaltas() << endl;
            updatedFile << "***** Data de ingresso (ano, mes, dia) ****" << endl;
            updatedFile << i.getIngressoEmpresa().ano << endl;
            updatedFile << i.getIngressoEmpresa().mes << endl;
            updatedFile << i.getIngressoEmpresa().dia << endl;
        }
        index++;
    }

    updatedFile.close();
}

void Empresa::contratarFuncionario()
{
    ifstream novoFuncionarioFile("novoFuncionario.txt");
    string linha;
    string fileToUpdate;

    // Check if the file is opened
    if (!(novoFuncionarioFile.is_open()))
    {
        cout << "Error opening the file" << endl;
        return;
    }

    // Read the employee's information from the file
    getline(novoFuncionarioFile, linha);
    string cargo = linha;

    getline(novoFuncionarioFile, linha); // Personal data

    getline(novoFuncionarioFile, linha);
    string nome = linha;

    getline(novoFuncionarioFile, linha);
    string cpf = linha;

    getline(novoFuncionarioFile, linha);
    int qntDeFilhos = stoi(linha);

    getline(novoFuncionarioFile, linha);
    string estadoCivil = linha;

    getline(novoFuncionarioFile, linha); // Address

    Endereco novoEndereco;
    getline(novoFuncionarioFile, linha);
    novoEndereco.cidade = linha;
    getline(novoFuncionarioFile, linha);
    novoEndereco.cep = linha;
    getline(novoFuncionarioFile, linha);
    novoEndereco.bairro = linha;
    getline(novoFuncionarioFile, linha);
    novoEndereco.rua = linha;
    getline(novoFuncionarioFile, linha);
    novoEndereco.numero = stoi(linha);

    getline(novoFuncionarioFile, linha); // Birth date

    Data novoNascimento;
    getline(novoFuncionarioFile, linha);
    novoNascimento.ano = stoi(linha);
    getline(novoFuncionarioFile, linha);
    novoNascimento.mes = stoi(linha);
    getline(novoFuncionarioFile, linha);
    novoNascimento.dia = stoi(linha);

    getline(novoFuncionarioFile, linha); // Job-related data

    getline(novoFuncionarioFile, linha);
    string matricula = linha;

    getline(novoFuncionarioFile, linha);
    string salario = linha;

    getline(novoFuncionarioFile, linha);
    string dadoAdicional = linha;

    getline(novoFuncionarioFile, linha);
    int faltas = stoi(linha);

    getline(novoFuncionarioFile, linha); // Hiring date

    Data novoIngresso;
    getline(novoFuncionarioFile, linha);
    novoIngresso.ano = stoi(linha);
    getline(novoFuncionarioFile, linha);
    novoIngresso.mes = stoi(linha);
    getline(novoFuncionarioFile, linha);
    novoIngresso.dia = stoi(linha);

    novoFuncionarioFile.close();

    // Create a new employee object based on their job position
    if (cargo == "Gerente")
    {
        float participacaoLucros = stoi(dadoAdicional);

        Gerente novoFuncionario;
        novoFuncionario.setNome(nome);
        novoFuncionario.setCpf(cpf);
        novoFuncionario.setQtdFilhos(qntDeFilhos);
        novoFuncionario.setEstadoCivil(estadoCivil);
        novoFuncionario.setEnderecoPessoal(novoEndereco);
        novoFuncionario.setDataNascimento(novoNascimento);
        novoFuncionario.setMatricula(matricula);
        novoFuncionario.setSalario(salario);
        novoFuncionario.setParticipacaoLucros(participacaoLucros);
        novoFuncionario.setFaltas(faltas);
        novoFuncionario.setIngressoEmpresa(novoIngresso);

        this->gerentes.push_back(novoFuncionario);

        fileToUpdate = "gerente.txt";
    }
    else if (

cargo == "ASG")
    {
        float adicionalInsalubridade = stof(dadoAdicional);

        Asg novoFuncionario;

        novoFuncionario.setNome(nome);
        novoFuncionario.setCpf(cpf);
        novoFuncionario.setQtdFilhos(qntDeFilhos);
        novoFuncionario.setEstadoCivil(estadoCivil);
        novoFuncionario.setEnderecoPessoal(novoEndereco);
        novoFuncionario.setDataNascimento(novoNascimento);
        novoFuncionario.setMatricula(matricula);
        novoFuncionario.setSalario(salario);
        novoFuncionario.setAdicionalInsalubridade(adicionalInsalubridade);
        novoFuncionario.setFaltas(faltas);
        novoFuncionario.setIngressoEmpresa(novoIngresso);

        this->asgs.push_back(novoFuncionario);

        fileToUpdate = "asg.txt";
    }
    else if (cargo == "Vendedor")
    {
        char tipoVendedor = dadoAdicional[0];
        Vendedor novoFuncionario;

        novoFuncionario.setNome(nome);
        novoFuncionario.setCpf(cpf);
        novoFuncionario.setQtdFilhos(qntDeFilhos);
        novoFuncionario.setEstadoCivil(estadoCivil);
        novoFuncionario.setEnderecoPessoal(novoEndereco);
        novoFuncionario.setDataNascimento(novoNascimento);
        novoFuncionario.setMatricula(matricula);
        novoFuncionario.setSalario(salario);
        novoFuncionario.setTipoVendedor(tipoVendedor);
        novoFuncionario.setFaltas(faltas);
        novoFuncionario.setIngressoEmpresa(novoIngresso);

        this->vendedores.push_back(novoFuncionario);

        fileToUpdate = "vendedor.txt";
    }
}
