#include <iostream>
#include "Nulidade.h"


Nulidade::Nulidade(string name, int column, int line, string team)
{
    setNome(name);
    setPosicao(column, line);
    setEquipa(team);
}

bool Nulidade::verificadorMove(int x, int y){
    return true;
}

void Nulidade::Move(int x, int y){
    setPosicao(x, y);
}

Nulidade::~Nulidade(){

}
