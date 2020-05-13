#include <iostream>
#include <fstream>
#include "Empresa.h"

Empresa::Empresa() {

}

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
    vector<Encomenda*> result;
    string input;

    switch (option)
    {
        case 1:
        {
            result = encomendas;
            break;
        }
        case 2:
        {
            cout<<"Indique o NIF do estafeta:\n";
            getline(cin,input);
            for (auto estafeta : estafetas)
            {
                if (estafeta->getNif() == stol(input)) {result = estafeta->getEntregasFeitas(); break;}
            }
            break;
        }
        case 3:
        {
            cout<<"Indique o NIF do estafeta:\n";
            getline(cin,input);
            for (auto cliente : clientes)
            {
                if (cliente->getNif() == stol(input)) {result = cliente->getEncomendasFeitas(); break;}
            }
            break;
        }
        case 4:
        {
            cout<<"Indique a hora inicial do intervalo:\n";
            getline(cin,input);

            Hora inicio(input);

            cout<<"Indique a hora inicial do intervalo:\n";
            getline(cin,input);

            Hora fim(input);

            for (auto encomenda : encomendas)
            {
                if (*encomenda->getHoraPedido() > inicio && *encomenda->getHoraEntrega() < fim) result.push_back(encomenda);
            }

            break;
        }
        default: {cout<<"Valor de opcao invalido!\n"; break;}
    }
    return result;
}

Encomenda *Empresa::readFromFile(string filename) {
    Prato* prat;
    Restaurante* rest;
    Hora *inicio,*fim;


    ifstream file;
    file.open(filename);

    string line;
    getline(file,line);

    for (auto restaurante: restaurantes)
    {
        if (restaurante->getNome() == line)
        {
            rest = restaurante;
            getline(file,line);
            for (auto prato : restaurante->getPratosDisponiveis())
            {
                if (prato->getNome() == line) prat = prato;
                break;
            }
            break;
        }
    }

    getline(file,line);

    inicio = new Hora(line);
    getline(file,line);
    fim = new Hora(line);

    return new Encomenda(prat,rest,inicio,fim);
}


