#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Incendio
{
private:
    vector<pair<int, int>> posicao;
    vector<pair<int, int>> ultPosicao;
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

public:
    Incendio(int posicaoX, int posicaoY);
    void propagarIncendio(vector<vector<int>> &matriz, bool sul, bool norte, bool leste, bool oeste);
    bool verificarPosicaoValida(const vector<vector<int>> &matriz, int x, int y);
    void queimarPosicao(vector<vector<int>> &matriz, int x, int y);
};