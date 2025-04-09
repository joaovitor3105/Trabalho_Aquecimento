#include "Ler_e_Escrever_arquivo.hpp"
#include "Animal.hpp"
#include "Floresta.hpp"
#include "Incendio.hpp"
#include "Config.hpp"
#include <iostream>
using namespace std;

int main()
{
    Floresta floresta = lerArquivo();

    cout << "Linhas: " << floresta.num_linhas << ", Colunas: " << floresta.num_colunas << endl;
    cout << "Incêndio inicial: (" << floresta.incendio_inicial_X << ", " << floresta.incendio_inicial_Y << ")" << endl;

    for (size_t i = 0; i < floresta.matriz.size(); i++)
    {
        for (size_t j = 0; j < floresta.matriz[i].size(); j++)
        {
            cout << floresta.matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
