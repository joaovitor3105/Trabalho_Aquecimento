#pragma once
#include <vector>
using namespace std;

struct Floresta
{
    vector<vector<int>> matriz;
    int num_linhas;
    int num_colunas;
    int incendio_inicial_X;
    int incendio_inicial_Y;

    Floresta() : num_linhas(0), num_colunas(0), incendio_inicial_X(0), incendio_inicial_Y(0) {}

    Floresta(vector<vector<int>> matriz, int num_linhas, int num_colunas, int incendio_inicial_X, int incendio_inicial_Y)
        : matriz(matriz), num_linhas(num_linhas), num_colunas(num_colunas), incendio_inicial_X(incendio_inicial_X), incendio_inicial_Y(incendio_inicial_Y) {}
};