#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Animal
{
private:
    pair<int, int> posicao;
    // ultima posição do animal para evitar que ele volte para a mesma posição
    pair<int, int> ultPosicao;
    int tempoAreaSegura;
    int passos;
    int encontrouAgua;
    // direções de movimento
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    // se morte != 0, o animal morreu e o numero representa a interação que ele morreu
    int morte = 0;

public:
    Animal(int posicaoX, int posicaoY);
    Animal();
    ~Animal();
    pair<int, int> getPosicao() const;
    int getTempoAreaSegura() const;
    int getPassos() const;
    int getEncontrouAgua() const;
    void setPosicao(int posicaoX, int posicaoY);
    void setMorte(int morreu);
    int getMorte();

    // move o animal para uma nova posição com prioridades
    void mover(vector<vector<int>> &matriz, int coluna, int linha);
    // verifica se o animal tem uma segunda chance ou se esta cercado pelo fogo
    bool segundaChance(vector<vector<int>> &matriz, int coluna, int linha);
};
;
