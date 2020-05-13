#include <iostream>
#include "Menu.h"

using namespace std;

void mainMenu(Empresa empresa){

}

void menuEncomendas(Empresa empresa)
{
    string input;

    cout<<"\nMenu de Encomendas\n";
    cout<<"Selecione uma das seguintes opcoes:\n";
    cout<<"1 - Criar um encomenda\n";
    cout<<"2 - Eliminar uma encomenda\n";
    cout<<"3 - Visualizar encomendas\n";
    cout<<"9 - Voltar atras\n";
    cout<<"0 - Sair\n";

    getline(cin,input);

    int option = stoi(input);

    switch (option)
    {
        case 1: {empresa.criarEncomenda(); break;}
        case 2: {empresa.eliminarEncomenda(); break;}
        case 3: {menuVisualizarEncomendas(empresa); break;}
        case 9: return;
        case 0: exit(0);
        default:{cerr<<"Input invalido!\n"; break;}
    }
}

void menuVisualizarEncomendas(Empresa empresa)
{
    string input;

    cout<<"\nMenu de Visualizacao de Encomendas\n";
    cout<<"Que encomendas pretende ver? Selecione uma das seguintes opcoes:\n";
    cout<<"1 - Todas\n";
    cout<<"2 - Todas as associadas a um estafeta\n";
    cout<<"3 - Todas as associadas a um cliente\n";
    cout<<"4 - Todas as realizadas entre um determinado intervalo de tempo\n";
    cout<<"9 - Voltar atras\n";
    cout<<"0 - Sair\n";

    getline(cin,input);

    int option = stoi(input);

    switch(option)
    {
        case 9: return;
        case 0: exit(0);
        default: break;
    }

    for (auto encomenda : empresa.filtrarEncomendas(option))
    {
        cout<<*encomenda;
    }
}
