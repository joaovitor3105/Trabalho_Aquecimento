#include "Incendio.hpp"

Incendio::Incendio(int posicaoX, int posicaoY)

{
    this->proxPosicao.push_back(make_pair(posicaoX, posicaoY));
}
bool Incendio::propagarIncendio(vector<vector<int>> &matriz)
{
    if (!ultPosicao.empty())
    {
        for (auto &pos : ultPosicao)
        {
            matriz[pos.first][pos.second] = 3;
        }
    }

    ultPosicao.clear();
    for (auto &pos : proxPosicao)
    {
        ultPosicao.push_back(pos);
    }
    proxPosicao.clear();

    for (auto &pos : ultPosicao)
    {
        if (SUL)
        {
            int novoX = pos.first + 1;
            int novoY = pos.second;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (NORTE)
        {
            int novoX = pos.first - 1;
            int novoY = pos.second;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (LESTE)
        {
            int novoX = pos.first;
            int novoY = pos.second + 1;
            queimarPosicao(matriz, novoX, novoY);
        }
        if (OESTE)
        {
            int novoX = pos.first;
            int novoY = pos.second - 1;
            queimarPosicao(matriz, novoX, novoY);
        }
    }
    cout << "\ntamanho do vetor:" << proxPosicao.size() << endl;
    if (ultPosicao.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Incendio::verificarPosicaoValida(const vector<vector<int>> &matriz, int x, int y)
{
    if (x < 0 || x >= static_cast<int>(matriz.size()) || y < 0 || y >= static_cast<int>(matriz[0].size()))
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
        proxPosicao.push_back(make_pair(x, y));
    }
}
