#ifndef EQUIPA_H
#define EQUIPA_H

#include <string>
#include <vector>
#include "Peca.h"

using namespace std;

class Equipa
{
    public:
        Equipa(string nome);
        void setNome(string n);
        string getNome();
        void WcriaPecas(string nome);
        void BcriaPecas(string nome);
        void NcriaPecas(string nome);
        Peca * Busca(string peca);
        vector<Peca*> getPecas();
        Peca* criaNulidade(int x, int y);
        int numPecas(char peca);
        Peca * promovePiao(string tipo, int x, int y, Peca * peca);

    protected:
        string nome;
        vector<Peca*> pecas;

    private:
};

#endif // EQUIPA_H
