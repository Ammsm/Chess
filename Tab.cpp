#include "Tab.h"

Tab::Tab()
{
    Jogo = new Sistema();
}

// Transforma a coluna em coordenadas da janela
int Tab::CcoordsX(int c){
    int x = lado/2 + c*lado;
    return x;
}

// Transforma a linha em coordenadas da janela
int Tab::LcoordsY(int l){
    int y =  lado/2 - (l-7)*lado;
    return y;
}

Peca * Tab::getPeca(int c, int l){
    return Jogo->getPeca(c, l);
}

void Tab::PromovePeao(Peca * peca, int c, int l){
    if(Jogo->PromovePeao(peca, c, l)){promocao = true;}
}

// Executa o movimento no tabuleiro
bool Tab::Move(Peca * peca, int c, int l){
    int x = peca->getColuna() - 1; int y = peca->getLinha() - 1;
    Peca * v = Jogo->getPeca(c, l);
    if(peca->getNome()[1] == 'K' && peca->getCastle() && abs(c-x) >= 2){
        Jogo->Castle(peca, c, l);
        return true;
    }
    if(v == nullptr && peca->verificadorMove(c+1, l+1) && Jogo->verificaColisoes(peca, c, l)){
        Jogo->Movimento(peca, c, l);
        if(!Jogo->verificaAutoCheck(peca, v, x, y)){
            PromovePeao(peca, c, l);
            peca->setPosRep(110, c, l); //Acho que está tudo
            return true;
        }
        return false;
    }
    else if(v != nullptr && peca->getNome()[1] != 'P' && peca->verificadorMove(c+1, l+1) && v->getEquipa() != peca->getEquipa() && Jogo->verificaColisoes(peca, c, l)){
        Jogo->Movimento(peca, c, l);
        if(!Jogo->verificaAutoCheck(peca, v, x, y)){
            peca->setPosRep(110, c, l); //Acho que está tudo
            return true;
        }
        return false;
    }
    else if(v != nullptr && peca->getNome()[1] == 'P' && peca->verificadorCome(c+1, l+1) && v->getEquipa() != peca->getEquipa()){
        Jogo->Movimento(peca, c, l);
        if(!Jogo->verificaAutoCheck(peca, v, x, y)){
            PromovePeao(peca, c, l);
            peca->setPosRep(110, c, l); //Acho que está tudo
            return true;
        }
        return false;
    }
    return false;
}



// Faz o trabalho
void Tab::fazOTrabalho(){
    sf::RenderWindow window(sf::VideoMode(lado*12, lado*8), "Xadrez");
    window.setFramerateLimit(24);  //Cria janela "window"

    sf::Color claro(235, 235, 235, 255);  // Cria as cores do tabuleiro
    sf::Color escuro(100, 100, 100, 255);

    int x = 0;  //Def do quadrado branco
    int y = 0;
    sf::RectangleShape rect;
    sf::Vector2f posicao(x, y);
    rect.setPosition(posicao);  // Quadrado branco
    rect.setSize(sf::Vector2f(8*lado, 8*lado));
    rect.setFillColor(claro);

    sf::Font open_sans;
    open_sans.loadFromFile("C:\\Users\\afons\\Downloads\\my_type_of_font");

    //Valores do primeiro input
    int x_1 = 0;
    int y_1 = 0;
    int a = 99;
    int b = 99;

    //Valores do segundo input
    int x_2 = 0;
    int y_2 = 0;
    int c = 99;
    int d = 99;

    Peca * peca = nullptr;
    Peca * anterior = Jogo->getPeca(7, 7);

    //Quadrado da seleção
    sf::RectangleShape sel;
    sel.setSize(sf::Vector2f(lado, lado));
    sf::Color amarelo(190, 190, 0, 120);
    sel.setFillColor(amarelo);
    sel.setOrigin(55, 55);



    // O que se faz na janela
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && x_1 == 0 && peca == nullptr){
                x_1 = sf::Mouse::getPosition(window).x;
                y_1 = sf::Mouse::getPosition(window).y;
                a = floor((x_1 - x) / lado);
                b = -(floor((y_1 - y) / lado) - 7);
                peca = getPeca(a, b);
                if(x_1 >= x && x_1 <= x+(8*lado) && y_1 >= y && y_1 <= y+(8*lado) && peca != nullptr && peca->getEquipa() != anterior->getEquipa()){
                }
                else{
                    x_1 = 0;
                    y_1 = 0;
                    a = 99;
                    b = 99;
                    peca = nullptr;
                }
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && x_1 != 0){
                x_2 = sf::Mouse::getPosition(window).x;
                y_2 = sf::Mouse::getPosition(window).y;
                c = floor((x_2 - x) / lado);
                d = -(floor((y_2 - y) / lado) - 7);
                if(x_2 >= x && x_2 <= x+(8*lado) && y_2 >= y && y_2 <= y+(8*lado) && ((a == c && b != d) || (a != c && b == d) || (a != c && b != d)) && peca->getNome() != "   "){
                    if(Move(peca, c, d)){anterior = peca;}
                }
                x_1 = 0;
                y_1 = 0;
                a = 99;
                b = 99;
                peca = nullptr;
            }
        }
        window.clear(sf::Color(27,49,49));
        window.draw(rect);
        cout << promocao;
        for(int k=0; k<8; k++){
            sf::RectangleShape quad;
            quad.setSize(sf::Vector2f(lado, lado));
            quad.setFillColor(escuro);
            int Ypos = posicao.y;
            Ypos += k*lado;
            for(int i=0; i<4; i++){
                int Xpos = posicao.x;
                if(k % 2 == 0){
                    Xpos += (2*i+1)*lado;
                    quad.setPosition(Xpos, Ypos);
                    window.draw(quad);
                }
                else if(k % 2 == 1){;
                    Xpos += (2*i)*lado;
                    quad.setPosition(Xpos, Ypos);
                    window.draw(quad);
                }
            }
        }
        sel.setPosition(CcoordsX(a), LcoordsY(b));
        window.draw(sel);
        for(int i=0; i<Jogo->getWhite().getPecas().size(); i++){
            Peca *a = Jogo->getWhite().getPecas()[i];
            if(a->getColuna() < 9){
                window.draw(a->getSprite());
            }
        }
        for(int i=0; i<Jogo->getBlack().getPecas().size(); i++){
            Peca *a = Jogo->getBlack().getPecas()[i];
            if(a->getColuna() < 9){
                window.draw(a->getSprite());
            }
        }
        window.display();
    }
}




