#include <iostream>
#include "Equipa.h"
#include "Piao.h"
#include "Torre.h"
#include "Cavalo.h"
#include "Bispo.h"
#include "Rainha.h"
#include "Rei.h"

Equipa::Equipa(string nome)
{
    setNome(nome);
    if(nome == "White"){
        WcriaPecas(nome);
    }
    else if(nome == "Black"){
        BcriaPecas(nome);
    }
}

void Equipa::setNome(string n){
    nome = n;
}


string Equipa::getNome(){
    return nome;
}

vector<Peca*> Equipa::getPecas(){
    return pecas;
}

void Equipa::WcriaPecas(string nome){
    Peca *WP1; WP1 = new Piao("WP1", 1, 2, nome); pecas.push_back(WP1);
    Peca *WP2; WP2 = new Piao("WP2", 2, 2, nome); pecas.push_back(WP2);
    Peca *WP3; WP3 = new Piao("WP3", 3, 2, nome); pecas.push_back(WP3);
    Peca *WP4; WP4 = new Piao("WP4", 4, 2, nome); pecas.push_back(WP4);
    Peca *WP5; WP5 = new Piao("WP5", 5, 2, nome); pecas.push_back(WP5);
    Peca *WP6; WP6 = new Piao("WP6", 6, 2, nome); pecas.push_back(WP6);
    Peca *WP7; WP7 = new Piao("WP7", 7, 2, nome); pecas.push_back(WP7);
    Peca *WP8; WP8 = new Piao("WP8", 8, 2, nome); pecas.push_back(WP8);
    Peca *WT1; WT1 = new Torre("WT1", 1, 1, nome); pecas.push_back(WT1);
    Peca *WC1; WC1 = new Cavalo("WC1", 2, 1, nome); pecas.push_back(WC1);
    Peca *WB1; WB1 = new Bispo("WB1", 3, 1, nome); pecas.push_back(WB1);
    Peca *WQ; WQ = new Rainha("WQ1", 4, 1, nome); pecas.push_back(WQ);
    Peca *WK; WK = new Rei("WKg", 5, 1, nome); pecas.push_back(WK);
    Peca *WB2; WB2 = new Bispo("WB2", 6, 1, nome); pecas.push_back(WB2);
    Peca *WC2; WC2 = new Cavalo("WC2", 7, 1, nome); pecas.push_back(WC2);
    Peca *WT2; WT2 = new Torre("WT2", 8, 1, nome); pecas.push_back(WT2);
}

void Equipa::BcriaPecas(string nome){
    Peca *BP1; BP1 = new Piao("BP1", 1, 7, nome); pecas.push_back(BP1);
    Peca *BP2; BP2 = new Piao("BP2", 2, 7, nome); pecas.push_back(BP2);
    Peca *BP3; BP3 = new Piao("BP3", 3, 7, nome); pecas.push_back(BP3);
    Peca *BP4; BP4 = new Piao("BP4", 4, 7, nome); pecas.push_back(BP4);
    Peca *BP5; BP5 = new Piao("BP5", 5, 7, nome); pecas.push_back(BP5);
    Peca *BP6; BP6 = new Piao("BP6", 6, 7, nome); pecas.push_back(BP6);
    Peca *BP7; BP7 = new Piao("BP7", 7, 7, nome); pecas.push_back(BP7);
    Peca *BP8; BP8 = new Piao("BP8", 8, 7, nome); pecas.push_back(BP8);
    Peca *BT1; BT1 = new Torre("BT1", 1, 8, nome); pecas.push_back(BT1);
    Peca *BC1; BC1 = new Cavalo("BC1", 2, 8, nome); pecas.push_back(BC1);
    Peca *BB1; BB1 = new Bispo("BB1", 3, 8, nome); pecas.push_back(BB1);
    Peca *BQ; BQ = new Rainha("BQ1", 4, 8, nome); pecas.push_back(BQ);
    Peca *BK; BK = new Rei("BKg", 5, 8, nome); pecas.push_back(BK);
    Peca *BB2; BB2 = new Bispo("BB2", 6, 8, nome); pecas.push_back(BB2);
    Peca *BC2; BC2 = new Cavalo("BC2", 7, 8, nome); pecas.push_back(BC2);
    Peca *BT2; BT2 = new Torre("BT2", 8, 8, nome); pecas.push_back(BT2);
}

Peca * Equipa::Busca(string peca){
    for(int i=0; i<pecas.size(); i++){
        Peca * a = getPecas()[i];
        if(a->getNome()[1] == peca[1] && a->getNome()[2] == peca[2]){
            return a;
        }
    }
    return nullptr;
}

int Equipa::numPecas(char peca){
    int conta = 1;
    if(peca == 'R'){
        peca = 'Q';
    }
    for(int i=0; i<pecas.size(); i++){
        string nome = pecas[i]->getNome();
        if(nome[1] == peca){
            conta++;
        }
    }
    return conta;
}

Peca * Equipa::promovePiao(string tipo, int x, int y, Peca * peca){  // Recebe x, y pertencentes [1, 8]
    int num = numPecas(tipo[0]);
    string indice = to_string(num);
    string team = getNome().substr(0, 1);
    if(tipo[0] == 'C'){
        peca->setPosicao(100, 100);
        string nome = team + "C" + indice;
        Peca *C; C = new Cavalo(nome, x, y, getNome()); pecas.push_back(C);
        return C;
    }
    else if(tipo[0] == 'T'){
        peca->setPosicao(100, 100);
        string nome = team + "T" + indice;
        Peca *T; T = new Torre(nome, x, y, getNome()); pecas.push_back(T);
        return T;
    }
    else if(tipo[0] == 'B'){
        peca->setPosicao(100, 100);
        string nome = team + "B" + indice;
        Peca *B; B = new Bispo(nome, x, y, getNome()); pecas.push_back(B);
        return B;
    }
    else if(tipo[0] == 'R'){
        peca->setPosicao(100, 100);
        string nome = team + "Q" + indice;
        Peca *Q; Q = new Rainha(nome, x, y, getNome()); pecas.push_back(Q);
        return Q;
    }
}
