#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Floresta.hpp"
#include "Animal.hpp"

using namespace std;

Floresta lerArquivo();
void escreverArquivo(vector<vector<int>> matriz, Animal animal);
