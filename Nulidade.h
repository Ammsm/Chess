#ifndef NULIDADE_H
#define NULIDADE_H

#include <string>
#include "Peca.h"

using namespace std;

class Nulidade: public Peca
{
    public:
        Nulidade(string name, int column, int line, string team);
        bool verificadorMove(int x, int y);
        void Move(int x, int y);
        ~Nulidade();

    protected:

    private:

};

#endif // NULIDADE_H
