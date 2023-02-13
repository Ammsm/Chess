#include <iostream>
#include "Bispo.h"


Bispo::Bispo(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
    criaSprite(110);  // Aqui depois vejo se mudo
}

bool Bispo::verificadorMove(int x, int y){
    if(x != getColuna() && y != getLinha() && abs(getColuna() - x) == abs(getLinha() - y) && 1 <= y && y <= 8 && 1 <= x && x <= 8){
        return true;
    }
    else{
        return false;
    }
}

void Bispo::Move(int x, int y){
    setPosicao(x, y);
}

string Bispo::getTextura(){
    if(equipa == "White"){
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Bispo_branco.png";
    }
    else{
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Bispo_preto.png";
    }
}

void Bispo::criaSprite(int lado){
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

sf::Sprite Bispo::getSprite(){
    return sprite;
}

void Bispo::setPosRep(int lado, int c, int l){
    int x = lado/2 + c*lado;
    int y = lado/2 - (l-7)*lado + lado/25;
    sprite.setPosition(x, y);
}
