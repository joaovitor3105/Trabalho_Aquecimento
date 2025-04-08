#include "Incendio.hpp"

Incendio::Incendio(int posicaoX, int posicaoY)

{
    this->posicao.push_back(make_pair(posicaoX, posicaoY));
}
void Incendio::propagarIncendio(vector<vector<int>> &matriz, bool sul, bool norte, bool leste, bool oeste)
{
    if (!ultPosicao.empty())
    {
        for (auto &pos : ultPosicao)
        {
            matriz[pos.first][pos.second] = 3;
        }
    }

    ultPosicao.clear();
    for (auto &pos : posicao)
    {
        ultPosicao.push_back(pos);
    }
    posicao.clear();

    for (auto &pos : ultPosicao)
    {
        if (sul)
        {
            int novoX = pos.first + 1;
            int novoY = pos.second;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (norte)
        {
            int novoX = pos.first - 1;
            int novoY = pos.second;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (leste)
        {
            int novoX = pos.first;
            int novoY = pos.second + 1;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (oeste)
        {
            int novoX = pos.first;
            int novoY = pos.second - 1;
            queimarPosicao(matriz, novoX, novoY);
        }
    }
}

bool Incendio::verificarPosicaoValida(const vector<vector<int>> &matriz, int x, int y)
{
    if (x < 0 || x >= matriz.size() || y < 0 || y >= matriz[0].size())
    {
        return false;
    }
    return true;
}

void Incendio::queimarPosicao(vector<vector<int>> &matriz, int x, int y)
{
    if (verificarPosicaoValida(matriz, x, y) && matriz[x][y] == 1)
    {
        matriz[x][y] = 2;
        posicao.push_back(make_pair(x, y));
    }
}
