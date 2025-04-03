#include "Ler_e_Escrever_arquivo.hpp"
#include "Config.hpp"

class Floresta
{
private:
    vector<vector<unsigned short int>> matriz;
    unsigned int num_linhas;
    unsigned int num_colunas;
    unsigned int incendio_inicial_X;
    unsigned int incendio_inicial_Y;

public:
    Floresta();
    ~Floresta();
};