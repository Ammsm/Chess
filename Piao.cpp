#include <iostream>
#include "Piao.h"


Piao::Piao(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
    criaSprite(110);  // Aqui depois vejo se mudo
}

bool Piao::verificadorMove(int x, int y){
    if(((getEquipa() == "White" && (getLinha() == 2 && y - getLinha() <= 2 || getLinha() != 2 && y - getLinha() == 1)) ||
        (getEquipa() == "Black" && (getLinha() == 7 && getLinha() - y <= 2 || getLinha() != 7 && getLinha() - y == 1))) &&
        y != getLinha() && 1 <= y && y <= 8 && x == getColuna()){
        return true;
    }
    else{
        return false;
    }
}

bool Piao::verificadorCome(int x,  int y){
    if((getEquipa() == "White" && abs(getColuna() - x) == 1 && y - getLinha() == 1) || (getEquipa() == "Black" && abs(getColuna() - x) == 1 && getLinha() - y == 1)){
        return true;
    }
    else{
        return false;
    }
}

void Piao::Move(int x, int y){
    setPosicao(x, y);
}

string Piao::getTextura(){
    if(equipa == "White"){
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Peao_branco.png";
    }
    else{
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Peao_preto.png";
    }
}

void Piao::criaSprite(int lado){
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

sf::Sprite Piao::getSprite(){
    return sprite;
}

void Piao::setPosRep(int lado, int c, int l){
    int x = lado/2 + c*lado;
    int y = lado/2 - (l-7)*lado + lado/25;
    sprite.setPosition(x, y);
}
