#ifndef BISPO_H
#define BISPO_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Peca.h"

using namespace std;

class Bispo: public Peca
{
    public:
        Bispo(string name, int column, int line, string team);
        bool verificadorMove(int x, int y);
        void Move(int x, int y);
        string getTextura();
        void criaSprite(int lado);
        sf::Sprite getSprite();
        void setPosRep(int lado, int c, int l);

    protected:

    private:
        sf::Texture textura;
        sf::Sprite sprite;

};

#endif // BISPO_H
