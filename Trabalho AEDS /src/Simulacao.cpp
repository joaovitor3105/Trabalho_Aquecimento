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

    for (int i = 0; i < 50; i++)
    {
        animal.mover(matriz, floresta.num_colunas, floresta.num_linhas);
        cout << "Animal na posicao: (" << animal.getPosicao().first << ", " << animal.getPosicao().second << ")" << endl;
        cout << "Passos: " << animal.getPassos() << ", Tempo na area segura: " << animal.getTempoAreaSegura() << ", Encontrou agua: " << animal.getEncontrouAgua() << endl;
        incendio.propagarIncendio(matriz);
        cout << "Matriz atual:" << endl;
        for (size_t i = 0; i < matriz.size(); i++)
        {
            for (size_t j = 0; j < matriz[i].size(); j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}