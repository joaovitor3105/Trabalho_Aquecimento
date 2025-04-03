#include "Ler_e_Escrever_arquivo.hpp"
#include "Animal.hpp"
#include "Floresta.hpp"
#include "Config.hpp"
#include <iostream>
using namespace std;

int main()
{
    Animal animal(3, 0);
    vector<vector<int>> matriz = lerArquivo();
    for (size_t i = 0; i < matriz.size(); i++)
    {
        for (size_t j = 0; j < matriz[i].size(); j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    for (int i; i < 50; i++)
    {
        animal.mover(matriz, matriz[0].size(), matriz.size());
        cout << "Posicao do animal: " << animal.getPosicao().first << ", " << animal.getPosicao().second << endl;
        cout << "Passos: " << animal.getPassos() << endl;
        cout << "Tempo na area segura: " << animal.getTempoAreaSegura() << endl;
        cout << "Encontrou agua: " << animal.getEncontrouAgua() << endl;
        cout << "----------------------------------------" << endl;
        cout << "Matriz atualizada: " << endl;
        for (size_t i = 0; i < matriz.size(); i++)
        {
            for (size_t j = 0; j < matriz[i].size(); j++)
            {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    escreverArquivo(matriz);
    return 0;
}