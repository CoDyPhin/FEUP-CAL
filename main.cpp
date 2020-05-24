#include <iostream>
#include "Empresa.h"
#include "Menu.h"

int main() {

    Empresa empresa;
    mainMenu(empresa);

    empresa.updateClientes();
    empresa.updateEstafetas();
    empresa.updateEncomendas();
    return 0;
}
