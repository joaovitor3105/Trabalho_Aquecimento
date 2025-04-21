#include "Ler_e_Escrever_arquivo.hpp"
#include "Animal.hpp"
#include "Floresta.hpp"
#include "Incendio.hpp"
#include "Config.hpp"
#include <iostream>

using namespace std;

void executarSimulacao()
{
    // limpa arquivo de saida
    limparSaida();

    // lê arquivo de entrada e inicializa variaveis
    Floresta floresta = lerArquivo();
    Incendio incendio(floresta.incendio_inicial_X, floresta.incendio_inicial_Y);
    vector<vector<int>> matriz = floresta.matriz;
    Animal animal;

    // coloca animal na primeira posição segura
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

    // se nao encontrar colocar no log****************************************

    // variavel de controle para o loop
    bool matrizQueimada = false;

    // escreve matriz inicial no arquivo
    escreverArquivoMatriz(matriz, 0);

    // loop de iterações(para em caso de queimar a matriz ou atingir o maximo de iterações)
    for (int i = 1; i < interacoes && !matrizQueimada; i++)
    {
        // movimento do animal se não estiver morto
        if (animal.getMorte() == 0)
        {
            animal.mover(matriz, floresta.num_colunas, floresta.num_linhas);
        }

        // propagação do incendio
        matrizQueimada = incendio.propagarIncendio(matriz);

        // se o animal estiver na posição do incendio ganha uma segunda chance
        // se não conseguir escapar morre
        if (matriz[animal.getPosicao().first][animal.getPosicao().second] == 2)
        {
            bool morreu = !animal.segundaChance(matriz, floresta.num_colunas, floresta.num_linhas);
            if (morreu)
            {
                animal.setMorte(i);
            }
        }

        // escreve matriz no arquivo
        escreverArquivoMatriz(matriz, i);
    }

    // relatorio final da simulação
    gerarRelatorio(animal);
}