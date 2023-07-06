#include <iostream>
#include "empresa.hpp"

/**
 * @brief Test Class
 * @author Guilherme Santiago, José Kermany, Mario Luiz
 * @version 1.0
 * @since 04-07-2023
 * @paragraph The program simulates an HR system where a company can be registered with its employees and access their methods, such as salary, date of birth, severance pay, among others.
*/
int main() {
    // Creating a new company
    Empresa *atacadoDosCalcados = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56);
    atacadoDosCalcados->carregarFuncoes();

    return 0;
}