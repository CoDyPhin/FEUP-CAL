#include <iostream>
#include "Empresa.h"
#include "Menu.h"

int main() {

    Empresa empresa;
    mainMenu(empresa);
    //empresa.showGrafo();
    empresa.updateEstafetas(empresa);
    empresa.updateEncomendas(empresa);
    empresa.updateClientes(empresa);
    return 0;
}
