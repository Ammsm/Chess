#include <iostream>
#include "Torre.h"


Torre::Torre(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
    criaSprite(110);  // Aqui depois vejo se mudo
}

bool Torre::verificadorMove(int x, int y){
    if((x == getColuna() && y != getLinha() || x != getColuna() && y == getLinha()) && 1 <= y && y <= 8 && 1 <= x && x <= 8){
        return true;
    }
    else{
        return false;
    }
}

void Torre::Move(int x, int y){
    setPosicao(x, y);
}

string Torre::getTextura(){
    if(equipa == "White"){
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Torre_branca.png";
    }
    else{
        return "C:\\Users\\afons\\OneDrive\\Ambiente de Trabalho\\C++\\Teste\\Nova pasta (2)\\Torre_preta.png";
    }
}

void Torre::criaSprite(int lado){
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

sf::Sprite Torre::getSprite(){
    return sprite;
}

void Torre::setPosRep(int lado, int c, int l){
    int x = lado/2 + c*lado;
    int y = lado/2 - (l-7)*lado + lado/25;
    sprite.setPosition(x, y);
}
