#include "Incendio.hpp"

Incendio::Incendio(int posicaoX, int posicaoY)

{
    this->posicao.push_back(make_pair(posicaoX, posicaoY));
}
void Incendio::propagarIncendio(vector<vector<int>> &matriz, bool sul, bool norte, bool leste, bool oeste)
{
    if (ultPosicao.size() != 0)
    {
        for (int i = 0; i < ultPosicao.size(); i++)
        {
            matriz[ultPosicao[i].first][ultPosicao[i].second] = 3;
        }
    }
}