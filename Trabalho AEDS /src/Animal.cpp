#include "Animal.hpp"

Animal::Animal(int posicaoX, int posicaoY)
{
    this->posicao = make_pair(posicaoX, posicaoY);
    this->tempoAreaSegura = 0;
    this->passos = 0;
    this->encontrouAgua = 0;
}

Animal::~Animal()
{
}

Animal::Animal()
{
    this->posicao = make_pair(-1, -1);
    this->tempoAreaSegura = 0;
    this->passos = 0;
    this->encontrouAgua = 0;
}

pair<int, int> Animal::getPosicao() const
{
    return posicao;
}

void Animal::setPosicao(int posicaoX, int posicaoY)
{
    this->posicao = make_pair(posicaoX, posicaoY);
}

void Animal::mover(vector<vector<int>> &matriz, int coluna, int linha)

{
    int posicaoX = this->posicao.first;
    int posicaoY = this->posicao.second;

    pair<int, int> melhorMovimento = {-1, -1};
    vector<pair<int, int>> movimentosIntermediarios;
    vector<pair<int, int>> movimentosRuins;

    for (int i = 0; i < 4; i++)
    {
        int novoX = posicaoX + dx[i];
        int novoY = posicaoY + dy[i];
        if (novoX >= 0 && novoX < linha && novoY >= 0 && novoY < coluna)
        {
            if (make_pair(novoX, novoY) == ultPosicao)
            {
                continue;
            }
            if (matriz[novoX][novoY] == 4)
            {
                melhorMovimento = make_pair(novoX, novoY);
                break;
            }
            else if (matriz[novoX][novoY] == 1 || matriz[novoX][novoY] == 0)
            {
                movimentosIntermediarios.push_back(make_pair(novoX, novoY));
            }
            else
            {
                movimentosRuins.push_back(make_pair(novoX, novoY));
            }
        }
    }
    if (matriz[posicaoX][posicaoY] == 0)
    {
        if (tempoAreaSegura < 3)
        {
            tempoAreaSegura++;
            return;
        }
        else
        {
            tempoAreaSegura = 0;
        }
    }

    if (melhorMovimento.first != -1)

    {
        ultPosicao = posicao;
        setPosicao(melhorMovimento.first, melhorMovimento.second);
        encontrouAgua++;
        passos++;
        matriz[melhorMovimento.first][melhorMovimento.second] = 0;
        for (int i = 0; i < 4; i++)
        {
            int novoX = melhorMovimento.first + dx[i];
            int novoY = melhorMovimento.second + dy[i];
            if (novoX >= 0 && novoX < linha && novoY >= 0 && novoY < coluna && matriz[novoX][novoY] != 0)
            {
                matriz[novoX][novoY] = 1;
            }
        }
        tempoAreaSegura++;
        return;
    }

    else if (movimentosIntermediarios.size() > 0)
    {
        ultPosicao = posicao;
        pair<int, int> movimento = movimentosIntermediarios[rand() % movimentosIntermediarios.size()];
        setPosicao(movimento.first, movimento.second);
        if (matriz[movimento.first][movimento.second] == 0)
        {
            tempoAreaSegura++;
        }
        passos++;
        return;
    }

    else if (movimentosRuins.size() > 0)
    {
        ultPosicao = posicao;
        pair<int, int> movimento = movimentosRuins[rand() % movimentosRuins.size()];
        setPosicao(movimento.first, movimento.second);
        passos++;
        return;
    }

    else
    {
        cout << "Animal sem movimento possivel" << endl;
        return;
    }
}

int Animal::getTempoAreaSegura() const
{
    return tempoAreaSegura;
}

int Animal::getPassos() const
{
    return passos;
}

int Animal::getEncontrouAgua() const
{
    return encontrouAgua;
}
