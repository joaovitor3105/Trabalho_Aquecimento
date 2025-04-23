# Simulador de Propagação de Incêndios em Florestas

Este repositório contém a implementação de um simulador de propagação de incêndios em florestas, desenvolvido como parte de um trabalho acadêmico. O objetivo principal é modelar a propagação do fogo em uma matriz que representa a floresta, utilizando a linguagem de programação C++. Adicionalmente, o simulador é capaz de identificar rotas de fuga para um animal presente na floresta, conforme especificações descritas no enunciado do trabalho.

## Índice

- [Descrição do Problema](#descrição-do-problema)
- [Especificação do Trabalho](#especificação-do-trabalho)
- [Configuração do Ambiente](#configuração-do-ambiente)
- [Compilação e Execução](#compilação-e-execução)
- [Entrada e Saída de Dados](#entrada-e-saída-de-dados)
- [Estratégias de Propagação do Incêndio](#estratégias-de-propagação-do-incêndio)
- [Movimentação do Animal](#movimentação-do-animal)
- [Padrões de Propagação e Análise](#padrões-de-propagação-e-análise)
- [Possíveis Melhorias e Algoritmos Emergentes](#possíveis-melhorias-e-algoritmos-emergentes)
- [Estrutura do Repositório](#estrutura-do-repositório)
- [Licença](#licença)

## Descrição do Problema

O simulador utiliza uma matriz dinâmica para representar a floresta. Cada célula da matriz pode conter os seguintes valores, que indicam o estado correspondente:
- **0**: Área vazia (não queima)
- **1**: Árvore saudável
- **2**: Árvore em chamas
- **3**: Árvore queimada (não propaga mais fogo)
- **4**: Presença de água

A simulação consiste em iterar sobre a matriz para propagar o incêndio e deslocar um animal até que o fogo se extinga ou o número máximo de iterações seja alcançado.

## Especificação do Trabalho

### Requisitos

- Implementação em C ou C++.
- Modularização do código com headers (`.h` ou `.hpp`) e arquivos de implementação (`.c` ou `.cpp`).
- Configuração global através de um arquivo `config.h` ou `config.hpp`.
- Entrada de dados a partir de `input.dat` e saída escrita em `output.dat`.
- Simulação iterativa e visual, exibindo o estado da floresta em cada iteração.
- Compatibilidade com sistemas operacionais Linux e compilação com `make`.

### Funcionalidades

1. Representação da floresta como matriz dinâmica.
2. Propagação do fogo com e sem influência do vento.
3. Movimentação de um animal buscando rotas de fuga.
4. Relatório de desempenho e análise ao final da simulação.

## Configuração do Ambiente

Certifique-se de que o ambiente Linux possui os seguintes requisitos:
- GCC ou outro compilador C/C++ compatível.
- `make` instalado para automação da compilação.
- Editor de texto ou IDE para visualizar e editar os arquivos.

## Compilação e Execução

Utilize os seguintes comandos no terminal para compilar e executar o simulador:

1. Limpar arquivos antigos:
   ```bash
   make clean
   ```
2. Compilar o código:
   ```bash
   make
   ```
3. Executar o simulador:
   ```bash
   make run
   ```

## Entrada e Saída de Dados

### Arquivo de Entrada (`input.dat`)

O arquivo `input.dat` deve conter:
- Dimensões da matriz (N x M).
- Coordenadas iniciais do incêndio.
- Matriz da floresta, linha por linha.

#### Exemplo:
```
5 5 1 1
1 1 1 1 4
1 2 1 1 1
1 1 1 1 4
0 0 1 1 1
1 4 1 0 4
```

### Arquivo de Saída (`output.dat`)

A cada iteração, o estado atualizado da matriz será escrito no arquivo `output.dat`.

#### Exemplo:
Após a 1ª iteração:
```
1 2 1 1 4
2 2 2 1 1
1 2 1 1 4
0 0 1 1 1
1 4 1 0 4
```

## Estratégias de Propagação do Incêndio

1. **Sem influência do vento**: O fogo se propaga linearmente em todas as direções ortogonais.
2. **Com influência do vento**: O fogo se propaga apenas em direções configuradas no arquivo `config.h`.

### Regras de Propagação

1. Árvore saudável (1) entra em chamas (2) se houver uma árvore vizinha em chamas.
2. Árvore em chamas (2) se torna queimada (3) após um ciclo.
3. O processo continua até não haver mais árvores em chamas ou o limite de iterações ser atingido.

## Movimentação do Animal

O animal busca rotas de fuga em direções ortogonais com a seguinte prioridade:
1. Melhor opção: célula com água (4).
2. Opções intermediárias: célula vazia (0) ou árvore saudável (1).
3. Pior opção: célula com árvore queimada (3).

### Regras Específicas

- O animal executa sua movimentação antes da propagação do fogo.
- Se o animal encontrar água, a célula é atualizada para 0, e as células adjacentes são convertidas para 1.
- Caso o fogo alcance a posição do animal, ele recebe uma segunda chance para escapar.

## Padrões de Propagação e Análise

### Sem Vento
O fogo se propaga em todas as direções ortogonais, resultando em uma expansão simétrica quando não há obstáculos.

### Com Vento
A propagação é direcionada, resultando em padrões assimétricos que dependem da configuração do vento.

Exemplo visual:
- Sem vento:
  ```
  Centro -> Todas as direções
  ```
- Com vento:
  ```
  Centro -> Apenas direções específicas configuradas
  ```

### Análise
O simulador permite prever o potencial de destruição do incêndio ao observar o número de iterações e a área afetada.

## Possíveis Melhorias e Algoritmos Emergentes

### Melhorias Sugeridas
- Implementação de algoritmos de busca heurística (e.g., A* ou Dijkstra) para a movimentação do animal.
- Adição de variáveis ambientais, como umidade e topografia.
- Paralelização do cálculo de propagação utilizando OpenMP ou MPI.

### Algoritmos Emergentes
- **Percolação Estocástica**: Modelagem probabilística da propagação do fogo.
- **Autômatos Celulares Avançados**: Inclusão de regras complexas e interações locais para maior realismo.

## Estrutura do Repositório

```
Algoritmos/
├── src/
│   ├── main.cpp
│   ├── config.hpp
│   ├── animal.cpp
│   ├── fire.cpp
│   ├── matrix.cpp
│   └── ...
├── input.dat
├── output.dat
├── Makefile
└── README.md
```

## Licença

Este projeto foi desenvolvido para fins acadêmicos e está disponível sob a licença MIT.
