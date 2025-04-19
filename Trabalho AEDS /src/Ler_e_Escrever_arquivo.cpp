#include "Ler_e_Escrever_arquivo.hpp"
#include "Config.hpp"

Floresta lerArquivo()
{ // abre o arquivo de entrada
    ifstream arquivo("input.dat");
    // verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    { // escrever no log****************************
        cout << "Erro ao abrir o arquivo " << "input.dat" << endl;
        return Floresta();
    }
    // lê os dados do arquivo e armazenar na estrutura Floresta
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

void escreverArquivoMatriz(vector<vector<int>> matriz, int interacao)
{ // abre o arquivo de saida
    ofstream arquivo("output.dat", ios::app);
    if (!arquivo.is_open())
    { // escrever no log****************************
        cout << "Erro ao abrir o arquivo " << "output.dat" << endl;
        return;
    }
    // escreve a interação e a matriz no arquivo de saida
    arquivo << "interação: " << interacao << endl;

    for (size_t i = 0; i < matriz.size(); i++)
    {
        for (size_t j = 0; j < matriz[i].size(); j++)
        {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << endl;
    }
    arquivo << "----------------------------------------" << endl;
    arquivo.close();
}

void gerarRelatorio(Animal animal)
{ // abre o arquivo de saida
    ofstream arquivo("output.dat", ios::app);
    if (!arquivo.is_open())
    { // escrever no log****************************
        cout << "Erro ao abrir o arquivo " << "output.dat" << endl;
        return;
    }
    // escreve o relatorio do animal
    if (animal.getMorte() == 0)
    {
        arquivo << "Animal sobreviveu" << endl;
    }
    else
    {
        arquivo << "Animal morreu na interção: " << animal.getMorte() << endl;
    }
    arquivo << "Animal na posição: (" << animal.getPosicao().first << ", " << animal.getPosicao().second << ")" << endl;
    arquivo << "Passos: " << animal.getPassos() << ", Encontrou água: " << animal.getEncontrouAgua() << endl;

    // escreve se o vento estava ativo e suas direções
    if (VENTO)
    {
        arquivo << "O vento estava ativo nas direções:" << endl;
        if (SUL)
        {
            arquivo << " Sul" << endl;
        }
        if (NORTE)
        {
            arquivo << " Norte" << endl;
        }
        if (LESTE)
        {
            arquivo << " Leste" << endl;
        }
        if (OESTE)
        {
            arquivo << " Oeste" << endl;
        }
        arquivo << endl;
    }
    else
    {
        arquivo << "O vento estava inativo" << endl;
    }
    arquivo << "----------------------------------------" << endl;

    arquivo.close();
}

void limparSaida()
{
    ofstream arquivo("output.dat", ios::trunc);
    if (!arquivo.is_open())
    { // escrever no log****************************
        cout << "Erro ao abrir o arquivo " << "output.dat" << endl;
        return;
    }
    arquivo.close();
}
