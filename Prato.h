#ifndef CAL_PRATO_H
#define CAL_PRATO_H

#include <string>
#include <vector>

using namespace std;

class Prato {
private:
    string nome;
    vector<string> ingredientes;
    float preco;
public:
    Prato(const string &nome, const vector<string> &ingredientes, float preco);

    const string &getNome() const;

    void setNome(const string &nome);

    const vector<string> &getIngredientes() const;

    void setIngredientes(const vector<string> &ingredientes);

    float getPreco() const;

    void setPreco(float preco);
};


#endif //CAL_PRATO_H
