#include <iostream>
#include <fstream>
#include <thread>
#include <cmath>
#include "Empresa.h"
#include "utils.h"

using namespace std;

Empresa::Empresa() {
    Graph<Posicao> grafo;
    this->grafo = grafo;

    readGrafo();
    readRestaurantes();
    readEncomendas();
    readEstafetas();
    readClientes();

}

void Empresa::criarEncomenda() {
    string input;

    cout<<"Indique o nome do restaurante:\n";
    getline(cin,input);

    Restaurante* restaurante = nullptr;
    vector<pair<Prato*,int>> pratos;
    Cliente* cliente = nullptr;
    int quantidadeTotal = 0;
    float custo = 0;

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
        quantidadeTotal+= quant;

        pratos.emplace_back(pratoAtual,quant);

        custo += pratoAtual->getPreco() * quant;

        cout<<"Pretende adicionar mais pratos (s/n)?\n";
        getline(cin,input);
        if (input != "s") break;
    } while(true);

    ///Calcular melhor estafeta
    Estafeta* estafeta = escolherEstafeta(quantidadeTotal,restaurante);

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

    auto caminhoTodo = calcPercurso(estafeta->getPosicao(),restaurante->getPosicao());
    auto caminhoRestauranteCliente = calcPercurso(restaurante->getPosicao(),cliente->getPosicao());
    caminhoRestauranteCliente.pop_front();
    caminhoTodo.insert(caminhoTodo.end(),caminhoRestauranteCliente.begin(),caminhoRestauranteCliente.end());
    double distanciaTotal = 0;

    for (auto pos = caminhoTodo.begin(); pos != caminhoTodo.end(); pos++)
    {
        if (*pos != caminhoTodo.back())
        {
            distanciaTotal += (*pos).calcDist(*(pos + 1));
        }
    }

    float velocidade = estafeta->getTransporte()->getVelocidade();
    float tempoEmHoras = distanciaTotal/velocidade;

    int tempoMinutos = round(tempoEmHoras * 60);

    ///calcular hora do fim
    Encomenda* novaEncomenda = new Encomenda(encomendas.size()+1,pratos,restaurante,horaInicio,horaInicio->calcPassagemTempo(tempoMinutos),custo);
    novaEncomenda->setCaminho(caminhoTodo);
    encomendas.push_back(novaEncomenda);
    cliente->addEncomenda(novaEncomenda);
    cliente->setTotalGasto(cliente->getTotalGasto() + custo);
    estafeta->addEncomenda(novaEncomenda);
    estafeta->setLucroTotal(estafeta->getLucroTotal() + custo * 0.3);

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
    string nome, nif, idade, idno, trpvel, trpmatricula, trpcapac;
    cout<<"Indique o nome do estafeta:\n";
    getline(cin,nome);
    cout<<"Indique o NIF do estafeta:\n";
    getline(cin,nif);
    cout<<"Indique a idade do estafeta:\n";
    getline(cin,idade);
    cout<<"Indique o ID do no em que se encontra o estafeta:\n";
    getline(cin,idno);
    cout<<"Indique a velocidade do veiculo do estafeta:\n";
    getline(cin,trpvel);
    cout<<"Indique a matricula do veiculo do estafeta:\n";
    getline(cin,trpmatricula);
    cout<<"Indique a capacidade do veiculo do estafeta:\n";
    getline(cin,trpcapac);
    Posicao posicao = grafo.getTfromId(stol(idno));
    Estafeta* estafeta = new Estafeta(nome, stol(nif), stoi(idade),stol(idno), posicao, new Transporte(trpmatricula, stof(trpvel), stoi(trpcapac)), {}, 0);
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
        float custo;

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
                string nomePratoAtual;
                int quantidadePrato;
                auto pratos = string_split(line,',');
                for (auto prato : pratos)
                {
                    vector<string> componentes = string_split(prato,'-');
                    nomePratoAtual = componentes.at(0);
                    quantidadePrato = stoi(componentes.at(1));
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

        getline(file,line);
        custo = stof(line);

        Encomenda* novaEncomenda = new Encomenda(id,pratosQuants,rest,inicio,fim,custo);
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

vector<Encomenda*> Empresa::getEncomendas(){
    return this->encomendas;
}

vector<Restaurante*> Empresa::getRestaurantes(){
    return this->restaurantes;
}

void Empresa::criarCliente() {
    string nome, nif, idade, idno, trpvel, trpmatricula, trppeso, trpcapac;
    cout << "Indique o nome do cliente:\n";
    getline(cin, nome);
    cout << "Indique o NIF do cliente:\n";
    getline(cin, nif);
    cout << "Indique a idade do cliente:\n";
    getline(cin, idade);
    cout << "Indique o ID do no em que se encontra o cliente:\n";
    getline(cin, idno);
    Posicao posicao = grafo.getTfromId(stol(idno));
    Cliente *cliente = new Cliente(nome, stol(nif), stoi(idade), stol(idno), posicao,
    {}, 0);
    clientes.push_back(cliente);
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

    double maxX = -INF;
    double maxY = -INF;
    double minX = INF;
    double minY = INF;

    string line;
    double latitude,longitude;
    long int id,id2;


    file.open("../ficheiros_graph/nodes_x_y_porto.txt");
    getline(file,line);
    while (!file.eof())
    {
        getline(file,line);
        sscanf(line.c_str(),"(%ld, %lf, %lf",&id,&latitude,&longitude);
        if (latitude < minX) minX = latitude;
        if (latitude > maxX) maxX = latitude;
        if (longitude < minY) minY = longitude;
        if (longitude > maxY) maxY = longitude;
        Posicao novaPosicao(latitude,longitude,id);
        grafo.addVertex(novaPosicao);
        grafo.addMapPair(id);
    }
    file.close();

    grafo.setMaxX(maxX);
    grafo.setMaxY(maxY);
    grafo.setMinX(minX);
    grafo.setMinY(minY);

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
    file.close();
}

map<string, Prato *> Empresa::readPratos(){
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
    file.close();

    return result;
}

void Empresa::readEstafetas() {
    auto mapaMatriculaTransporte = readTransportes();

    ifstream file;
    file.open("../ficheiros_texto/estafetas.txt");

    string line;

    while (!file.eof())
    {
        string nome;
        long int nif, idno;
        int idade;
        vector<string> idEncomendas;
        vector<Encomenda*> encomendasEstafeta;
        double lucro;

        getline(file,nome);
        getline(file,line);
        nif = stol(line);
        getline(file,line);
        idade = stoi(line);
        getline(file,line);
        idno = stol(line);
        Posicao posicao = grafo.getTfromId(idno);
        getline(file,line);
        Transporte* transporte = mapaMatriculaTransporte[line];
        getline(file,line);

        idEncomendas = string_split(line,',');
        if(idEncomendas.size() == 1 && idEncomendas.at(0) == "-"){
            encomendasEstafeta = {};
            lucro = 0;
        }
        else {
            for (string id : idEncomendas) {
                for (auto encomenda : encomendas) {
                    if (encomenda->getId() == stoi(id)) {
                        encomendasEstafeta.push_back(encomenda);
                        break;
                    }
                }
            }

            getline(file, line);
            lucro = stod(line);
        }
        Estafeta* novoEstafeta = new Estafeta(nome,nif,idade,idno,posicao,transporte,encomendasEstafeta,lucro);
        estafetas.push_back(novoEstafeta);

        getline(file,line);
        if (line == "") break;
    }
    file.close();
}

map<string, Transporte *> Empresa::readTransportes() {
    map<string, Transporte*> result;

    ifstream file;
    file.open("../ficheiros_texto/transportes.txt");

    string line;

    while (!file.eof())
    {
        string matricula;
        float velocidade;
        unsigned int capacidade;

        getline(file,matricula);
        getline(file,line);
        velocidade = stof(line);
        getline(file,line);
        capacidade = stoi(line);

        Transporte* novoTransporte = new Transporte(matricula,velocidade,capacidade);

        result.insert(pair<string,Transporte*>(matricula,novoTransporte));

        getline(file,line);
        if (line == "") break;
    }
    file.close();

    return result;
}

void Empresa::readClientes() {
    ifstream file;
    file.open("../ficheiros_texto/clientes.txt");

    string line;

    while (!file.eof())
    {
        string nome;
        long int nif, idno;
        int idade;
        vector<Encomenda*> encomendasCliente;
        double totalGasto;

        getline(file,nome);
        getline(file,line);
        nif = stol(line);
        getline(file,line);
        idade = stoi(line);
        getline(file,line);
        idno = stol(line);
        Posicao posicao = grafo.getTfromId(idno);
        getline(file,line);
        auto ids = string_split(line,',');
        if(ids.size() == 1 && ids.at(0) == "-"){
            encomendasCliente = {};
        }
        else{
            for (string id : ids)
            {
                for (auto encomenda : encomendas)
                {
                    if (encomenda->getId() == stol(id))
                    {
                        encomendasCliente.push_back(encomenda);
                        break;
                    }
                }
            }
        }

        getline(file,line);
        totalGasto = stod(line);

        Cliente* novoCliente = new Cliente(nome,nif,idade,idno,posicao,encomendasCliente,totalGasto);

        clientes.push_back(novoCliente);

        getline(file,line);
        if (line == "") break;
    }
    file.close();
}

Estafeta *Empresa::escolherEstafeta(int capacidade, Restaurante *restaurante) {
    vector<Estafeta *> aux;
    Estafeta *result;
    for (Estafeta *e : estafetas) {
        if (e->getTransporte()->getCapacidade() >= capacidade)
            aux.push_back(e);
    }
    result = aux.at(0);
    for (int i = 1; i < aux.size(); i++) {
        if (aux.at(i)->getPosicao().calcDist(restaurante->getPosicao()) <
            result->getPosicao().calcDist(restaurante->getPosicao()))
            result = aux.at(i);
    }
    return result;
}

void Empresa::updateClientes(Empresa empresa){
    ofstream file;
    string encomstr;
    bool first = true;
    file.open("../ficheiros_texto/clientes.txt");
    if (file.is_open()) {
        for (auto cliente: empresa.getClientes()) {
            if(!first){
                file << endl << "::::::::::" << endl;
            }
            first = false;
            file << cliente->getNome() << endl;
            file << cliente->getNif() << endl;
            file << cliente->getIdade() << endl;
            file << cliente->getIdNo() << endl;
            encomstr = "";
            if(cliente->getEncomendasFeitas().empty()){
                file << "-" << endl;
                file << 0;
            }
            else{
                for (size_t i = 0; i<cliente->getEncomendasFeitas().size(); i++){
                    encomstr += to_string(cliente->getEncomendasFeitas().at(i)->getId());
                    if(i!=cliente->getEncomendasFeitas().size()-1) encomstr += ", ";
                }
                file << encomstr << endl;
                file << cliente->getTotalGasto();
            }
        }
        file.close();
        cout << "Ficheiro dos clientes atualizado!" << endl;
    }
    else{
        cout << "Erro ao aceder ao ficheiro dos clientes" << endl;
    }
}

void Empresa::updateEncomendas(Empresa empresa) {
    ofstream file;
    string pratostr;
    bool first = true;
    file.open("../ficheiros_texto/encomendas.txt");
    if (file.is_open()) {
        for (auto encomenda: empresa.getEncomendas()) {
            if(!first){
                file << endl << "::::::::::" << endl;
            }
            first = false;
            file << encomenda->getId() << endl;
            file << encomenda->getRestaurante()->getNome() << endl;
            pratostr = "";
            for (size_t i = 0; i<encomenda->getPratos().size(); i++){
                    pratostr += encomenda->getPratos().at(i).first->getNome() + " - " + to_string(encomenda->getPratos().at(i).second);
                    if(i!=encomenda->getPratos().size()-1) pratostr += ", ";
            }
            file << pratostr << endl;
            file << *(encomenda->getHoraPedido()) << endl;
            file << *(encomenda->getHoraEntrega()) << endl;
            file << encomenda->getCusto();
        }
        file.close();
        cout << "Ficheiro das encomendas atualizado!" << endl;
    }
    else{
        cout << "Erro ao aceder ao ficheiro dos clientes" << endl;
    }
}

void Empresa::updateEstafetas(Empresa empresa) {
    ofstream file, fileT;
    string encomstr;
    bool first = true;
    file.open("../ficheiros_texto/estafetas.txt");
    fileT.open("../ficheiros_texto/transportes.txt");
    if (file.is_open() && fileT.is_open()) {
        for (auto estafeta: empresa.getEstafeta()) {
            if(!first){
                file << endl << "::::::::::" << endl;
                fileT <<endl<< "::::::::::" << endl;
            }
            first = false;
            file << estafeta->getNome() << endl;
            file << estafeta->getNif() << endl;
            file << estafeta->getIdade() << endl;
            file << estafeta->getIdNo() << endl;
            file << estafeta->getTransporte()->getMatricula() << endl;
            encomstr = "";
            if(estafeta->getEntregasFeitas().empty()){
                file << "-" << endl;
                file << 0 << endl;
            }
            else{
                for (size_t i = 0; i<estafeta->getEntregasFeitas().size(); i++){
                    encomstr += to_string(estafeta->getEntregasFeitas().at(i)->getId());
                    if(i!=estafeta->getEntregasFeitas().size()-1) encomstr += ", ";
                }
                file << encomstr << endl;
                file << estafeta->getLucroTotal();
            }
            fileT << estafeta->getTransporte()->getMatricula() << endl;
            fileT << estafeta->getTransporte()->getVelocidade() << endl;
            fileT << estafeta->getTransporte()->getCapacidade();

        }
        file.close();
        cout << "Ficheiros dos estafetas e respetivos transportes atualizados!" << endl;
    }
    else{
        cout << "Erro ao aceder ao ficheiro dos estafetas ou dos transportes" << endl;
    }
}

void Empresa::mostrarCaminho() {
    /*long int idEncomenda;
    string input;
    cout<<"Indique o id da encomenda em causa:\n";
    getline(cin,input);
    idEncomenda = stol(input);

    deque<Posicao> caminho;
    for (auto encomenda : encomendas)
    {
        if (encomenda->getId() == idEncomenda)
        {
            caminho = encomenda->getCaminho();
            break;
        }
    }*/

    int width = 1280;
    int height = 720;

    GraphViewer *gv = new GraphViewer(width, height, false);
    gv->createWindow(width, height);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    gv->defineEdgeCurved(false);
    gv->defineVertexSize(1);

    auto caminhoVerts = grafo.getVertexSet();
    for (auto vertex : caminhoVerts)
    {
        double yPercent, xPercent;
        xPercent = (vertex->getInfo().getLatitude() - grafo.getMinX())/(grafo.getMaxX() - grafo.getMinX()) * 0.9 + 0.05;
        yPercent = (vertex->getInfo().getLongitude() - grafo.getMinY())/(grafo.getMaxY() - grafo.getMinY()) * 0.9 + 0.05;

        gv->addNode(vertex->getInfo().getId(),(int) (xPercent*width),(int)(yPercent*height));
        gv->setVertexSize(vertex->getInfo().getId(),3);
        gv->rearrange();
    }
    int id = 0;
    for (auto vertex : caminhoVerts)
    {
        auto adjacent = vertex->getAdj();
        for (auto edge : adjacent)
        {
            gv->addEdge(id,edge.getOrig()->getInfo().getId(),edge.getDest()->getInfo().getId(),EdgeType::UNDIRECTED);
            gv->rearrange();
            id++;
        }
    }
}








