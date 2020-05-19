#include <iostream>
#include "Empresa.h"
#include "Menu.h"

int main() {

    Empresa empresa;
    mainMenu(empresa);
    //empresa.showGrafo();
    empresa.updateClientes(empresa);
    empresa.updateEstafetas(empresa);
    empresa.updateEncomendas(empresa);
    return 0;
}
