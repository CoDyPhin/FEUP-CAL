#include <iostream>
#include <fstream>
#include <thread>
#include "Empresa.h"
#include "utils.h"

using namespace std;

Empresa::Empresa() {
    Graph<Posicao> grafo;
    this->grafo = grafo;

    readGrafo();
    readRestaurantes();
    readEncomendas();

}

void Empresa::criarEncomenda() {
    string input;

    cout<<"Indique o nome do restaurante:\n";
    getline(cin,input);

    Restaurante* restaurante = nullptr;
    vector<pair<Prato*,int>> pratos;
    Cliente* cliente;

    for (auto rest : restaurantes)
    {
        if (rest->getNome() == input) {restaurante = rest; break;}
    }
    if (restaurante == nullptr)
    {
        cout<<"Nao ha nenhum restaurante com esse nome!\n";
        return;
    }

    do
    {
        cout<<"Indique o nome do prato que deseja:\n";
        getline(cin,input);

        string nomePrato = input;
        Prato* pratoAtual = nullptr;

        for (auto pratoRest : restaurante->getPratosDisponiveis())
        {
            if (pratoRest->getNome() == nomePrato) {pratoAtual = pratoRest; break;}
        }
        if (pratoAtual == nullptr)
        {
            cout<<"Nao ha nenhum prato com esse nome!\n";
            continue;
        }

        cout<<"Indique a quantidade que deseja:\n";
        getline(cin,input);

        int quant = stoi(input);

        pratos.push_back(pair<Prato*,int>(pratoAtual,quant));

        cout<<"Pretende adicionar mais pratos (s/n)?\n";
        getline(cin,input);
        if (input != "s") break;
    } while(true);

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
    Estafeta* estafeta = new Estafeta(nome, stol(nif), stoi(idade), posicao, Transporte(trpmatricula, stof(trpvel), stoi(trpcapac)), {}, 0);
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


void Empresa::readEncomendas() {
    ifstream file;
    file.open("../ficheiros_texto/encomendas.txt");

    while (!file.eof())
    {
        unsigned int id;
        Prato* prat = nullptr;
        Restaurante* rest = nullptr;
        Hora *inicio = nullptr,*fim = nullptr;
        vector<pair<Prato*,int>> pratosQuants;

        string line;

        getline(file,line);

        id = stoi(line);

        getline(file,line);

        for (auto restaurante: restaurantes)
        {
            if (restaurante->getNome() == line)
            {
                rest = restaurante;
                getline(file,line);
                Prato* pratoAtual = nullptr;

                vector<string> nomesPratos;
                char* nomePratoAtual_cstr;
                int quantidadePrato;
                auto pratos = string_split(line,',');
                for (auto prato : pratos)
                {
                    sscanf(prato.c_str(),"%s - %d",nomePratoAtual_cstr,&quantidadePrato);
                    string nomePratoAtual(nomePratoAtual_cstr);
                    vector<Prato*> copy = restaurante->getPratosDisponiveis();
                    for (auto prato2 : copy)
                    {
                        if (prato2->getNome() == nomePratoAtual) {pratoAtual = prato2; break;}

                    }
                    pratosQuants.emplace_back(pratoAtual,quantidadePrato);
                }
                break;
            }
        }

        if (rest == nullptr) getline(file,line);

        getline(file,line);

        inicio = new Hora(line);
        getline(file,line);
        fim = new Hora(line);

        Encomenda* novaEncomenda = new Encomenda(id,pratosQuants,rest,inicio,fim);
        encomendas.push_back(novaEncomenda);

        getline(file,line);
        if (line == "") break;
    }

}

vector<Cliente*> Empresa::getClientes(){
    return this->clientes;
}

vector<Estafeta*> Empresa::getEstafeta(){
    return this->estafetas;
}

vector<Encomenda*> Empresa::getEncomentas(){
    return this->encomendas;
}

vector<Restaurante*> Empresa::getRestaurantes(){
    return this->restaurantes;
}


void Empresa::eliminarCliente(long nif) {
    for (int i = 0; i < this->clientes.size() ; i++) {
        if(clientes.at(i)->getNif() == nif){
            clientes.erase(clientes.begin()+i);
            return;
        }
    }
    cout << "Não existe um cliente com esse NIF" << endl;
}

deque<Posicao> Empresa::calcPercurso(Posicao inicio, Posicao fim) {
    return grafo.bidirectionalDijkstra(inicio, fim);
}

void Empresa::readGrafo() {
    ifstream file,file2;

    string line;
    double latitude,longitude;
    long int id,id2;


    file.open("../ficheiros_graph/nodes_x_y_porto.txt");
    getline(file,line);
    while (!file.eof())
    {
        getline(file,line);
        sscanf(line.c_str(),"(%ld, %lf, %lf",&id,&latitude,&longitude);
        Posicao novaPosicao(latitude,longitude);
        grafo.addVertex(novaPosicao);
        grafo.addMapPair(id);
    }
    file.close();

    long int origin,dest;
    file2.open("../ficheiros_graph/edges_porto.txt");
    getline(file2,line);

    while (!file2.eof())
    {
        getline(file2,line);
        sscanf(line.c_str(),"(%ld, %ld)",&id,&id2);
        Posicao origem = grafo.getTfromId(id);
        Posicao destino = grafo.getTfromId(id2);
        double peso = origem.calcDist(destino);
        grafo.addEdgeWithIds(id,id2,peso);
    }
    file2.close();
}



void Empresa::showGrafo(){ // tem que ser melhorada e finalizada
    GraphViewer *gv = new GraphViewer(1280, 720, true);
    gv->createWindow(1280, 720);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    //double yPercent, xPercent;
    int id = 0;
    for (Vertex<Posicao> *v: grafo.getVertexSet()) {
        gv->addNode(id);//v->getInfo().getLatitude(),v->getInfo().getLongitude());
        if(id == 5)
            break;
        id++;
    }
}

void Empresa::readRestaurantes() {
    auto mapa = readPratos();

    ifstream file;
    file.open("../ficheiros_texto/restaurantes.txt");
    string line;

    while (!file.eof())
    {
        string nomeRest;
        vector<Prato*> pratos;


        getline(file,line);
        nomeRest = line;
        getline(file,line);
        long int id = stol(line);
        Posicao posRest = grafo.getTfromId(id);
        getline(file,line);

        for (auto nomePrato : string_split(line,','))
        {
            pratos.push_back(mapa[nomePrato]);
        }

        restaurantes.push_back(new Restaurante(nomeRest,posRest,pratos));

        getline(file,line);
        if (line == "") break;
    }
}

map<string, Prato *> Empresa::readPratos() {
    map<string, Prato*> result;

    ifstream file;
    file.open("../ficheiros_texto/pratos.txt");

    string line;

    while (!file.eof())
    {
        string nome;
        vector<string> ingredientes;
        float preco;

        getline(file,line);
        nome = line;
        getline(file,line);
        ingredientes = string_split(line,',');
        getline(file,line);
        preco = stof(line);

        Prato* novoPrato = new Prato(nome,ingredientes,preco);
        result.insert(pair<string,Prato*>(nome,novoPrato));

        getline(file,line);
        if (line == "") break;
    }

    return result;
}








