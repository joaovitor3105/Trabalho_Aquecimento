#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Floresta.hpp"
#include "Animal.hpp"

using namespace std;

// limpa o arquivo de saida de outras simulações
void limparSaida();
// ler arquivo de entrada e extrai os dados
Floresta lerArquivo();
// escreve a interação e a matriz no arquivo de saida
void escreverArquivoMatriz(vector<vector<int>> matriz, int interacao);
// escreve o relatorio final no arquivo de saida
void gerarRelatorio(Animal animal);
// registra o erro no arquivo de log
void registrarErro(string mensagem);
