#include <iostream>
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
        default: {cout<<"Valor de opcao invalido!\n";break;}
    }
    return result;
}

void Empresa::criarEstafeta() {
    string nome, nif, idade, trpvel, trpmatricula, trppeso, trpcapac;
    cout<<"Indique o nome do estafeta:\n";
    getline(cin,nome);
    cout<<"Indique o NIF do estafeta:\n";
    getline(cin,nif);
    cout<<"Indique a idade do estafeta:\n";
    getline(cin,idade);
    cout<<"Indique a matricula do veiculo do estafeta:\n";
    getline(cin,trpvel);
    cout<<"Indique a matricula do veiculo do estafeta:\n";
    getline(cin,trpmatricula);
    cout<<"Indique a capacidade do veiculo do estafeta:\n";
    getline(cin,trpcapac);
    cout<<"Indique o peso do veiculo do estafeta:\n";
    getline(cin,trppeso);
    Posicao posicao = Posicao(0,0);
    Estafeta* estafeta = new Estafeta(nome, stol(nif), stoi(idade), posicao, Transporte(trpmatricula, stof(trpvel), stod(trpcapac), stod(trppeso)), {}, 0);
    estafetas.push_back(estafeta);
}

void Empresa::eliminarEstafeta() {
    string input;

    cout<<"Indique o NIF do estafeta a remover:\n";
    getline(cin,input);

    long nif = stol(input);

    for (auto it = estafetas.begin(); it != estafetas.end(); it++) {
        if ((*it)->getNif() == nif) {estafetas.erase(it); return;}
    }
    cout<<"Nao foi encontrado um estafeta com o NIF providenciado\n";
}

vector<Estafeta *> Empresa::filtrarEstafetas(int option) {
    vector<Estafeta*> result;
    string input;

    switch (option)
    {
        case 1:
        {
            result = estafetas;
            break;
        }
        case 2:
        {
            cout<<"Indique o nome do estafeta:\n";
            getline(cin,input);
            for (auto estafeta : estafetas)
            {
                if (estafeta->getNome().find(input) != estafeta->getNome().npos) {result.push_back(estafeta);}
            }
            break;
        }
        case 3:
        {
            cout<<"Indique o NIF do estafeta:\n";
            getline(cin,input);
            for (auto estafeta : estafetas)
            {
                if (estafeta->getNif() == stol(input)) {result.push_back(estafeta); break;}
            }
            break;
        }
        default: {cout<<"Valor de opcao invalido!\n";break;}
    }
    return result;
}



