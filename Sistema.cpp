#include "Sistema.h"

Sistema::Sistema()
{
    White = new Equipa("White");
    Black = new Equipa("Black");
    int i; int j; int k; int l;
    for(i=0; i<8; i++){
        tabuleiro[1][i] = White->getPecas()[i];
    }
    for(j=0; j<8; j++){
        tabuleiro[6][j] = Black->getPecas()[j];
    }
    for(k=8; k<16; k++){
        tabuleiro[0][k-8] = White->getPecas()[k];
    }
    for(l=8; l<16; l++){
        tabuleiro[7][l-8] = Black->getPecas()[l];
    }
}

Peca* Sistema::getPeca(int c, int l){  // Pode ser útil (é - está a ser)
    return tabuleiro[l][c];
}

bool Sistema::verificaColisoes(Peca *a, int c, int l){
    int x = a->getColuna() - 1; int y = a->getLinha() - 1;  //Casa da peca a ser verificada
    if(a->getNome()[1] == 'T' && a->verificadorMove(c+1, l+1)){
        if(x == c){ // Verificar caso x = c
            if(y > l){
                for(int i = y-1; i>l; i--){
                    if(tabuleiro[i][x] != nullptr){
                        return false;
                    }
                }
            }
            else if(y < l){
                for(int j = y+1; j<l; j++){
                    if(tabuleiro[j][x] != nullptr){
                        return false;
                    }
                }
            }
            else{
                return true;
            }
        }
        else if(y == l){ // Verificar caso y = l
            if(x > c){
                for(int k = x-1; k>c; k--){
                    if(tabuleiro[y][k] != nullptr){
                        return false;
                    }
                }
            }
            else if(x < c){
                for(int m = x+1; m<c; m++){
                    if(tabuleiro[y][m] != nullptr){
                        return false;
                    }
                }
            }
            else{
                return true;
            }
        }
    }
    else if(a->getNome()[1] == 'B' && a->verificadorMove(c+1, l+1)){
        for(int f = 1; f < abs(x-c); f++){
            if(x < c && y < l){
                if(tabuleiro[y+f][x+f] != nullptr){
                    return false;
                }
            }
            else if(x > c && y > l){
                if(tabuleiro[y-f][x-f] != nullptr){
                    return false;
                }
            }
            else if(x > c && y < l){
                if(tabuleiro[y+f][x-f] != nullptr){
                    return false;
                }
            }
            else if(x < c && y > l){
                if(tabuleiro[y-f][x+f] != nullptr){
                    return false;
                }
            }
        }
        return true;
    }
    else if(a->getNome()[1] == 'Q' && a->verificadorMove(c+1, l+1)){
        if(x == c){ // Verificar caso x = c
            if(y > l){
                for(int i = y-1; i>l; i--){
                    if(tabuleiro[i][x] != nullptr){
                        return false;
                    }
                }
            }
            else if(y < l){
                for(int j = y+1; j<l; j++){
                    if(tabuleiro[j][x] != nullptr){
                        return false;
                    }
                }
            }
            else{
                return true;
            }
        }
        else if(y == l){ // Verificar caso y = l
            if(x > c){
                for(int k = x-1; k>c; k--){
                    if(tabuleiro[y][k] != nullptr){
                        return false;
                    }
                }
            }
            else if(x < c){
                for(int m = x+1; m<c; m++){
                    if(tabuleiro[y][m] != nullptr){
                        return false;
                    }
                }
            }
            else{
                return true;
            }
        }
        for(int f = 1; f < abs(x-c); f++){
            if(x < c && y < l){
                if(tabuleiro[y+f][x+f] != nullptr){
                    return false;
                }
            }
            else if(x > c && y > l){
                if(tabuleiro[y-f][x-f] != nullptr){
                    return false;
                }
            }
            else if(x > c && y < l){
                if(tabuleiro[y+f][x-f] != nullptr){
                    return false;
                }
            }
            else if(x < c && y > l){
                if(tabuleiro[y-f][x+f] != nullptr){
                    return false;
                }
            }
        }
        return true;
    }
    else if(a->getNome()[1] == 'P' && a->verificadorMove(c+1, l+1) && a->getLinha() == 2 && l == 3 && tabuleiro[2][c] != nullptr){
        return false;
    }
    return true;
}

// Verifica se é feito um autocheck e reverte a jogada - devolve true se algo for feito, devolve false se estiver tudo em ordem
bool Sistema::verificaAutoCheck(Peca *a, Peca *v, int c, int l){
    int x = a->getColuna() - 1; int y = a->getLinha() - 1;
    if(a->getEquipa() == "White" && verificaCheckW()){
        tabuleiro[l][c] = a;
        tabuleiro[y][x] = v;
        if(v != nullptr) v->Move(c+1, l+1);
        a->Move(x+1, y+1);
        return true;
    }
    else if(a->getEquipa() == "Black" && verificaCheckB()){
        tabuleiro[l][c] = a;
        tabuleiro[y][x] = v;
        if(v != nullptr) v->Move(c+1, l+1);
        a->Move(x+1, y+1);
        return true;
    }
    return false;
}

// Devolve verdadeiro se o Rei PRETO estiver em check
bool Sistema::verificaCheckB(){  //Verifica se o Rei PRETO está em check
    Peca *k = Black->Busca("BKg");
    int x = k->getColuna() - 1;
    int y = k->getLinha() - 1;
    for(int i=0; i<White->getPecas().size(); i++){
        Peca *a = White->getPecas()[i];
        if(a->getNome()[1] != 'K' && a->getNome()[1] != 'P' && a->getColuna() <= 8 && a->verificadorMove(x+1, y+1) && verificaColisoes(a, x, y)){
            return true;  //Outra ideia é alterar um atributo do sistema
        }
        if(a->getNome()[1] == 'P' && a->getColuna() != 100 && a->verificadorCome(x+1, y+1)){  // NO futuro, não esquecer de verificar colisões, caso ponha
            return true;  //Outra ideia é alterar um atributo do sistema
        }
    }
    return false;
}

// Devolve verdadeiro se o Rei BRANCO estiver em check
bool Sistema::verificaCheckW(){  //Verifica se o Rei BRANCO está em check
    Peca *k = White->Busca("WKg");
    int x = k->getColuna() - 1;
    int y = k->getLinha() - 1;
    for(int i=0; i<Black->getPecas().size(); i++){
        Peca *a = Black->getPecas()[i];
        if(a->getNome()[1] != 'K' && a->getNome()[1] != 'P' && a->getColuna() <= 8 && a->verificadorMove(x+1, y+1) && verificaColisoes(a, x, y)){
            return true;  //Outra ideia é alterar um atributo do sistema
        }
        if(a->getNome()[1] == 'P' && a->getColuna() != 100 && a->verificadorCome(x+1, y+1)){  // NO futuro, não esquecer de verificar colisões, caso ponha
            return true;  //Outra ideia é alterar um atributo do sistema
        }
    }
    return false;
}

// Move um peça
void Sistema::Move(Peca *a, int c, int l){
    int x = a->getColuna() - 1; int y = a->getLinha() - 1;
    Peca *v = tabuleiro[l][c];
    if(a->getNome()[1] == 'K' && a->getCastle() && abs(c-x) >= 2){
        if(c > x && tabuleiro[y][x+1]->getNome() == "   " && tabuleiro[y][x+2]->getNome() == "   " && tabuleiro[y][x+3]->getNome()[1] == 'T'){
            Peca * b = tabuleiro[y][x+1];  //Peça nulidade
            tabuleiro[y][x] = tabuleiro[y][x+2];
            tabuleiro[y][x+1] = tabuleiro[y][x+3];
            tabuleiro[y][x+2] = a;
            tabuleiro[y][x+3] = b;
        }
        if(c < x && tabuleiro[y][x-1]->getNome() == "   " && tabuleiro[y][x-2]->getNome() == "   " && tabuleiro[y][x-3]->getNome() == "   " && tabuleiro[y][x-4 ]->getNome()[1] == 'T'){
            Peca * b = tabuleiro[y][x-1];  //Peça nulidade
            tabuleiro[y][x] = tabuleiro[y][x-2];
            tabuleiro[y][x-1] = tabuleiro[y][x-4];
            tabuleiro[y][x-2] = a;
            tabuleiro[y][x-4] = b;
        }
    }
    if(v->getNome() == "   " && a->verificadorMove(c+1, l+1) && verificaColisoes(a, c, l)){
        a->Move(c+1, l+1);  //Faz o mov. de uma peça de casa para casa
        tabuleiro[l][c] = a;
        tabuleiro[y][x] = v;
    }
    else if(v->getNome() != "   " && a->getNome()[1] != 'P' && a->verificadorMove(c+1, l+1) && v->getEquipa() != a->getEquipa() && verificaColisoes(a, c, l)){
        a->Move(c+1, l+1);  //Cobre peças a comer - excluindo o pião
        tabuleiro[l][c] = a;
        v->setPosicao(100, 100);
    }
    else if(v->getNome() != "   " && a->getNome()[1] == 'P' && a->verificadorCome(c+1, l+1) && v->getEquipa() != a->getEquipa()){
        a->Move(c+1, l+1);  //Caso do pião
        tabuleiro[l][c] = a;
        v->setPosicao(100, 100);
    }
    if(a->getNome()[1] == 'P' && (a->getLinha() == 8 || a->getLinha() == 1)){  // Promover o pião (falta verificar quando chega)
        string escolha;
        cout << "Promova(Torre, Cavalo, Bispo, Rainha ou Piao): ";
        cin >> escolha;
        cout << "\n";
        if(a->getEquipa() == "White"){
            tabuleiro[l][c] = White->promovePiao(escolha, c+1, l+1, a);
        }
        else if(a->getEquipa() == "Black"){
            tabuleiro[l][c] = Black->promovePiao(escolha, c+1, l+1, a);
        }
    }
}

//a -> Peca a Mover (Rei)
void Sistema::Castle(Peca *a, int c, int l){
    int x = a->getColuna() - 1; int y = a->getLinha() - 1;
    if(c > x && tabuleiro[y][x+1] == nullptr && tabuleiro[y][x+2] == nullptr && tabuleiro[y][x+3]->getNome()[1] == 'T'){
        Peca * b = tabuleiro[y][x+1];  //Peça nulidade
        tabuleiro[y][x] = tabuleiro[y][x+2];
        tabuleiro[y][x+1] = tabuleiro[y][x+3];
        tabuleiro[y][x+2] = a;
        tabuleiro[y][x+3] = b;
        a->Move(c, l);
        tabuleiro[y][x+1]->Move(c, l+1);
        a->setPosRep(110, c , l);
        tabuleiro[y][x+1]->setPosRep(110, c-1, l);
    }
    if(c < x && tabuleiro[y][x-1] == nullptr && tabuleiro[y][x-2] == nullptr && tabuleiro[y][x-3] == nullptr && tabuleiro[y][x-4 ]->getNome()[1] == 'T'){
        Peca * b = tabuleiro[y][x-1];  //Peça nulidade
        tabuleiro[y][x] = tabuleiro[y][x-2];
        tabuleiro[y][x-1] = tabuleiro[y][x-4];
        tabuleiro[y][x-2] = a;
        tabuleiro[y][x-4] = b;
        a->Move(c+1, l);
        tabuleiro[y][x-1]->Move(c+2, l+1);
        a->setPosRep(110, c, l);
        tabuleiro[y][x-1]->setPosRep(110, c+1, l);
    }
}

//Faz o movimento natural das peças
void Sistema::Movimento(Peca *a, int c, int l){
    int x = a->getColuna() - 1; int y = a->getLinha() - 1;
    Peca *v = tabuleiro[l][c];
    a->Move(c+1, l+1);  //Faz o mov. de uma peça de casa para casa
    tabuleiro[l][c] = a;
    tabuleiro[y][x] = nullptr;
    if(v != nullptr) v->setPosicao(100, 100);
}

bool Sistema::PromovePeao(Peca *a, int c, int l){
    if(a->getNome()[1] == 'P' && (a->getLinha() == 8 || a->getLinha() == 1)){
        a->Move(c+1, l+1);
        string escolha;
        cout << "Promova(Torre, Cavalo, Bispo ou Rainha): ";
        cin >> escolha;
        cout << "\n";
        if(a->getEquipa() == "White"){
            tabuleiro[l][c] = White->promovePiao(escolha, c+1, l+1, a);
            return true;
        }
        else if(a->getEquipa() == "Black"){
            tabuleiro[l][c] = Black->promovePiao(escolha, c+1, l+1, a);
            return true;
        }
        return false;
    }
    return false;
}

Equipa Sistema::getWhite(){
    return *White;
}

Equipa Sistema::getBlack(){
    return *Black;
}
