#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Floresta.hpp"

using namespace std;

Floresta lerArquivo();
void escreverArquivo(vector<vector<int>> matriz);
