#include <iostream>
#include "Cavalo.h"


Cavalo::Cavalo(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
    criaSprite(110);  // Aqui depois vejo se mudo
}

bool Cavalo::verificadorMove(int x, int y){
    if(x != getColuna() && y != getLinha() && (abs(x - getColuna()) == 2 && abs(y - getLinha()) == 1 || abs(x - getColuna()) == 1 && abs(y - getLinha()) == 2) && 1 <= y && y <= 8 && 1 <= x && x <= 8){
        return true;
    }
    else{
        return false;
    }
}

void Cavalo::Move(int x, int y){
    setPosicao(x, y);
}

string Cavalo::getTextura(){
    if(equipa == "White"){
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Cavalo_branco.png";
    }
    else{
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Cavalo_preto.png";
    }
}

void Cavalo::criaSprite(int lado){
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

sf::Sprite Cavalo::getSprite(){
    return sprite;
}

void Cavalo::setPosRep(int lado, int c, int l){
    int x = lado/2 + c*lado;
    int y = lado/2 - (l-7)*lado + lado/25;
    sprite.setPosition(x, y);
}
