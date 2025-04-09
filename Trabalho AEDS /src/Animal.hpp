#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal
{
private:
    pair<int, int> posicao;
    pair<int, int> ultPosicao;
    int tempoAreaSegura;
    int passos;
    int encontrouAgua;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    Animal(int posicaoX, int posicaoY);
    Animal();
    ~Animal();
    pair<int, int> getPosicao() const;
    int getTempoAreaSegura() const;
    int getPassos() const;
    int getEncontrouAgua() const;
    void setPosicao(int posicaoX, int posicaoY);
    void mover(vector<vector<int>> &matriz, int coluna, int linha);
};
;
