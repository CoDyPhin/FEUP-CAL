#include <iostream>
#include "Menu.h"

using namespace std;

void menuClientes(Empresa &empresa){
    while (true)
    {
        cout << "Menu de Clientes" << endl;
        cout << "1 - Encomendas" << endl;
        cout << "2 - Visualização" << endl;
        cout << "3 - Adição" << endl;
        cout << "4 - Remoção" << endl;
        cout << "9 - Voltar atrás" << endl;
        cout << "0 - Sair" << endl << endl;
        cout << "Opção: ";
        int option;
        string input;
        getline(cin, input);
        option = stoi(input);
        switch (option) {
            case 0:
                empresa.updateFiles();
                exit(0);
            case 1:
                menuEncomendas(empresa);
                break;
            case 2:
                for (int i = 0; i < empresa.getClientes().size(); i++) {
                    cout << "Nome: " << empresa.getClientes().at(i)->getNome() << endl;
                    cout << "NIF: " << empresa.getClientes().at(i)->getNif() << endl;
                    cout << "Idade: " << empresa.getClientes().at(i)->getIdade() << endl;
                    cout << "Total de encomendas feitas: " << empresa.getClientes().at(i)->getEncomendasFeitas().size() << endl;
                    if(i != empresa.getClientes().size()-1)
                        cout << "------------------------------" << endl;
                }
                break;
            case 3:
                empresa.criarCliente();
                cout << "Cliente adicionado" << endl;
                break;
            case 4:{
                cout << "NIF do cliente a remover: ";
                string input2;
                long int nif;
                getline(cin,input2);
                nif = stoi(input2);
                empresa.eliminarCliente(nif);
                cout << "Cliente eliminado" << endl;
                break;
            }
            case 9:
                return;
            default:
                cerr<<"Input invalido!\n";
                break;
        }
    }


}

void mainMenu(Empresa &empresa){
    while (true)
    {
        cout << "\nBem-vindo à EatExpress" << endl << endl;
        cout << "1 - Menu Cliente" << endl;
        cout << "2 - Menu Estafeta" << endl;
        cout << "3 - Menu Obras" << endl;
        cout << "4 - Obter analise de conectividade" << endl;
        cout << "0 - Sair " << endl << endl;
        cout << "Opção: ";
        string input;
        int option;
        getline(cin, input);
        option = stoi(input);
        switch (option) {
            case 0:
                cout << "Obrigado por escolher EatExpress" << endl;
                return;
            case 1:
                menuClientes(empresa);
                break;
            case 2:
                menuEstafetas(empresa);
                break;
            case 3:
            {
                menuObras(empresa);
                break;
            }
            case 4:
            {
                empresa.analiseConectividade();
                break;
            }
            default:
                cerr<<"Input invalido!\n";
                break;
        }
    }

}

void menuEncomendas(Empresa &empresa)
{
    while (true)
    {
        string input;

        cout<<"\nMenu de Encomendas\n";
        cout<<"Selecione uma das seguintes opcoes:\n";
        cout<<"1 - Criar uma encomenda\n";
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
            case 0: {empresa.updateClientes(); exit(0);}
            default:{cerr<<"Input invalido!\n"; break;}
        }
    }

}

void menuVisualizarEncomendas(Empresa &empresa)
{
    while (true)
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
            case 0: {empresa.updateFiles(); exit(0);}
            default: break;
        }

        for (auto encomenda : empresa.filtrarEncomendas(option))
        {
            cout<<*encomenda;
        }
    }

}

void menuVisualizarEstafetas(Empresa &empresa)
{
    while (true)
    {
        string input;

        cout<<"\nMenu de Visualizacao de Estafetas\n";
        cout<<"Que estafetas pretende ver? Selecione uma das seguintes opcoes:\n";
        cout<<"1 - Todos\n";
        cout<<"2 - Pesquisar por nome\n";
        cout<<"3 - Pesquisar por NIF\n";
        cout<<"9 - Voltar atras\n";
        cout<<"0 - Sair\n";

        getline(cin,input);

        int option = stoi(input);

        switch(option)
        {
            case 9: return;
            case 0: {empresa.updateFiles();exit(0)};
            default: break;
        }

        for (auto estafeta : empresa.filtrarEstafetas(option))
        {
            cout<<*estafeta;
        }
    }

}

void menuEstafetas(Empresa &empresa){
    while (true)
    {
        string input;

        cout<<"\nMenu de Estafetas\n";
        cout<<"Selecione uma das seguintes opcoes:\n";
        cout<<"1 - Adicionar um estafeta\n";
        cout<<"2 - Eliminar um estafeta\n";
        cout<<"3 - Visualizar estafetas\n";
        cout<<"4 - Mostrar caminho\n";
        cout<<"9 - Voltar atras\n";
        cout<<"0 - Sair\n";

        getline(cin,input);

        int option = stoi(input);

        switch (option)
        {
            case 1: {empresa.criarEstafeta(); break;}
            case 2: {empresa.eliminarEstafeta(); break;}
            case 3: {menuVisualizarEstafetas(empresa); break;}
            case 4: {empresa.mostrarCaminho(); break;}
            case 9: return;
            case 0: {empresa.updateFiles(); exit(0)};
            default:{cerr<<"Input invalido!\n"; break;}
        }
    }


}

void menuObras(Empresa &empresa) {
    string input;

    while (true)
    {
        cout<<"\nMenu Obras\n";
        cout<<"Selecione uma das seguintes opcoes:\n";
        cout<<"1 - Reportar obras numa estrada\n";
        cout<<"2 - Reportar fim de obras numa estrada\n";
        cout<<"9 - Voltar atras\n";
        cout<<"0 - Sair\n";
        getline(cin,input);

        int option = stoi(input);

        switch (option)
        {
            case 1:
            {
                empresa.reportarObras(true);
                break;
            }
            case 2:
            {
                empresa.reportarObras(false);
                break;
            }
            case 9: return;
            case 0: {empresa.updateFiles(); exit(0);}
            default: {cerr<<"Input invalido!\n"; break;}
        }
    }

}

