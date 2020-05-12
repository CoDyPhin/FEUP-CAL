#ifndef CAL_PRATO_H
#define CAL_PRATO_H

#include <string>
#include <vector>

using namespace std;

class Prato {
private:
    string nome;
    vector<string> ingredientes;
    float volume;
    float preco;
public:
    const string &getNome() const;
    void setNome(const string &nome);
    const vector<string> &getIngredientes() const;
    void setIngredientes(const vector<string> &ingredientes);
    float getVolume() const;
    void setVolume(float volume);

    float getPreco() const;

    void setPreco(float preco);

    Prato(string nome, vector<string> ingredientes, float volume);

};


#endif //CAL_PRATO_H
