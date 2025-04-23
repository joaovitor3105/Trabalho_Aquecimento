#pragma once
#include <iostream>
#include <vector>
#include "Config.hpp"
using namespace std;

class Incendio
{
private:
    vector<pair<int, int>> proxPosicao;
    vector<pair<int, int>> ultPosicao;
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

public:
    // Construtor
    Incendio(int posicaoX, int posicaoY);
    // propaga o incêndio na matriz
    bool propagarIncendio(vector<vector<int>> &matriz);
    // verifica se a posição é válida dentro da matriz
    bool verificarPosicaoValida(const vector<vector<int>> &matriz, int x, int y);
    // transforma a posição da matriz em fogo
    void queimarPosicao(vector<vector<int>> &matriz, int x, int y);
};