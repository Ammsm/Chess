#ifndef TAB_H
#define TAB_H

#include <iostream>
#include "Sistema.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Tab
{
    public:
        Tab();
        int CcoordsX(int c);
        int LcoordsY(int l);
        Peca * getPeca(int c, int l);
        void PromovePeao(Peca * peca, int c, int l);
        bool Move(Peca * peca, int c, int l);
        void fazOTrabalho();

    protected:

    private:
        Sistema *Jogo = nullptr;
        int lado = 110;

        // Ajuda a fazer a promocao
        bool promocao = false;

        // Ainda não está feito, mas será para fazer o delizamento das peças
        bool peca_move = false;
        Peca * peca_movendo = nullptr;
};

#endif // TAB_H
