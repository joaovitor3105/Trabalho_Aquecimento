#include "Ler_e_Escrever_arquivo.hpp"
#include "Config.hpp"

Floresta lerArquivo()
{
    ifstream arquivo("input.dat");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo " << "input.dat" << endl;
        return Floresta();
    }

    int num_linhas = 0;
    int num_colunas = 0;
    int incendio_inicial_X = 0;
    int incendio_inicial_Y = 0;
    arquivo >> num_linhas;
    arquivo >> num_colunas;
    arquivo >> incendio_inicial_X;
    arquivo >> incendio_inicial_Y;
    arquivo.ignore();

    vector<vector<int>> matriz = vector<vector<int>>(num_linhas, vector<int>(num_colunas));

    for (int i = 0; i < num_linhas; i++)
    {
        string linha;
        getline(arquivo, linha);
        istringstream stream(linha);
        for (int j = 0; j < num_colunas; j++)
        {
            stream >> matriz[i][j];
        }
    }
    Floresta floresta(matriz, num_linhas, num_colunas, incendio_inicial_X, incendio_inicial_Y);
    return floresta;
}

void escreverArquivo(vector<vector<int>> matriz)
{
    ofstream arquivo("output.dat");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo " << "output.dat" << endl;
        return;
    }

    for (size_t i = 0; i < matriz.size(); i++)
    {
        for (size_t j = 0; j < matriz[i].size(); j++)
        {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << endl;
    }
}
