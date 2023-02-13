#include <iostream>
#include "Rainha.h"


Rainha::Rainha(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
    criaSprite(110);  // Aqui depois vejo se mudo
}

bool Rainha::verificadorMove(int x, int y){
    if(((x != getColuna() && y != getLinha() && abs(getColuna() - x) == abs(getLinha() - y)) ||
        (x == getColuna() && y != getLinha() || y == getLinha() && x != getColuna())) && 1 <= y && y <= 8 && 1 <= x && x <= 8){
        return true;
    }
    else{
        return false;
    }
}

void Rainha::Move(int x, int y){
    setPosicao(x, y);
}

string Rainha::getTextura(){
    if(equipa == "White"){
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Rainha_branca.png";
    }
    else{
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Rainha_preta.png";
    }
}

void Rainha::criaSprite(int lado){
    int x = coluna - 1;
    int y = linha - 1;
    int c = lado/2 + x*lado;
    int l = lado/2 - (y-7)*lado + lado/25;
    textura.loadFromFile(getTextura());
    sf::Sprite sprt(textura);
    sprt.setOrigin(50, 50);
    sprt.setPosition(c, l);
    sprite = sprt;
}

sf::Sprite Rainha::getSprite(){
    return sprite;
}

void Rainha::setPosRep(int lado, int c, int l){
    int x = lado/2 + c*lado;
    int y = lado/2 - (l-7)*lado + lado/25;
    sprite.setPosition(x, y);
}
