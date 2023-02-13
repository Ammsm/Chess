#ifndef PECA_H
#define PECA_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Peca.h"

using namespace std;

class Peca
{
    public:
        Peca();
        void setNome(string n);
        void setColuna(int c);
        void setLinha(int l);
        void setPosicao(int c, int l);
        void setEquipa(string e);
        string getNome();
        string getEquipa();
        int getColuna();
        int getLinha();
        virtual bool verificadorMove(int x, int y);
        virtual void Move(int x, int y);
        virtual bool verificadorCome(int x, int y);
        bool getCastle();
        virtual string getTextura(string equipa);
        virtual void criaSprite(int lado);
        virtual sf::Sprite getSprite();
        virtual void setPosRep(int lado, int c, int l);

    protected:
        string nome;
        string equipa;
        int coluna;
        int linha;
        bool castle = true;

    private:

};

#endif // PECA_H
