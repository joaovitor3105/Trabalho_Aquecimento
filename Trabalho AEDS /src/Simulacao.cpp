#include "Ler_e_Escrever_arquivo.hpp"
#include "Animal.hpp"
#include "Floresta.hpp"
#include "Incendio.hpp"
#include "Config.hpp"
#include <iostream>

using namespace std;

void executarSimulacao()
{
    Floresta floresta = lerArquivo();
    Incendio incendio(floresta.incendio_inicial_X, floresta.incendio_inicial_Y);
    vector<vector<int>> matriz = floresta.matriz;
    Animal animal;
    bool encontrou = false;
    for (int i = 0; i < floresta.num_linhas && !encontrou; i++)
    {
        for (int j = 0; j < floresta.num_colunas; j++)
        {
            if (matriz[i][j] == 0)
            {
                animal.setPosicao(i, j);
                encontrou = true;
                break;
            }
        }
    }
}