#include <iostream>
#include "Empresa.h"

void Empresa::criarEncomenda() {
    string input;

    cout<<"Indique o nome do restaurante:\n";
    getline(cin,input);

    Restaurante* restaurante;
    Prato* prato;
    Cliente* cliente;

    for (auto rest : restaurantes)
    {
        if (rest->getNome() == input) {restaurante = rest; break;}
    }

    cout<<"Indique o nome do prato:\n";
    getline(cin,input);

    for (auto prat : restaurante->getPratosDisponiveis())
    {
        if (prat->getNome() == input)
        {
            prato = prat;
            break;
        }
    }

    ///Calcular melhor estafeta

    cout<<"Indique o seu NIF:\n";
    getline(cin,input);

    for (auto cli : clientes)
    {
        if (cli->getNif() == stoi(input))
        {
            cliente = cli;
            break;
        }
    }

    cout<<"Indique a hora:\n";
    getline(cin,input);

    Hora *horaInicio = new Hora(input);

    ///calcular hora do fim

    //encomendas.push_back(novaEncomenda);
}

void Empresa::eliminarEncomenda() {
    string input;

    cout<<"Indique o indice da encomenda a remover:\n";
    getline(cin,input);

    int index = stoi(input);

    int i = 0;
    for (auto it = encomendas.begin(); it != encomendas.end(); it++) {
        if (i == index) {encomendas.erase(it); break;}
        i++;
    }
}



vector<Encomenda *> Empresa::filtrarEncomendas(int option) {
    return vector<Encomenda *>();
}

Empresa::Empresa() {

}
