# Sistema de Cadastro de Territórios - WAR GAME

## 📋 Descrição

Este projeto implementa um sistema de cadastro de territórios utilizando estruturas de dados compostas (structs) em linguagem C. O programa permite cadastrar informações de 5 territórios e exibir seus dados de forma organizada.

## 🎯 Objetivos

O objetivo deste desafio é praticar:
- Criação e uso de structs em C
- Manipulação de vetores de estruturas
- Entrada e saída de dados
- Boas práticas de documentação de código

## 🚀 Funcionalidades

- **Cadastro de Territórios**: Permite cadastrar 5 territórios com as seguintes informações:
  - Nome do território (até 30 caracteres)
  - Cor do exército (até 10 caracteres)
  - Número de tropas (valor inteiro positivo)

- **Exibição de Dados**: Exibe todos os territórios cadastrados de forma formatada e organizada

## 📁 Estrutura do Projeto

```
war_c/
├── territorios.c          # Código-fonte principal
├── README.md              # Documentação do projeto
└── teste_entrada.txt      # Arquivo de teste (opcional)
```

## 🔧 Compilação

Para compilar o programa, execute:

```bash
gcc -o territorios territorios.c -Wall -Wextra
```

## ▶️ Execução

Para executar o programa:

```bash
./territorios
```

### Exemplo de Uso

```
=========================================================================
           SISTEMA DE CADASTRO DE TERRITORIOS - WAR GAME
=========================================================================

>>> CADASTRO DE TERRITORIOS <<<
Por favor, cadastre 5 territorios.

-------------------------
Territorio 1 de 5
-------------------------
Nome do territorio: Brasil
Cor do exercito: Verde
Numero de tropas: 15

[... continua para os demais territórios ...]
```

## 📊 Estrutura de Dados

### Struct Territorio

```c
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Número de tropas
} Territorio;
```

## 🛠️ Requisitos Técnicos

### Funcionais
- ✅ Definição da struct Territorio com os campos especificados
- ✅ Cadastro de 5 territórios
- ✅ Exibição dos dados após cadastro

### Não Funcionais
- ✅ **Usabilidade**: Interface clara com mensagens orientativas
- ✅ **Desempenho**: Resposta inferior a 2 segundos
- ✅ **Documentação**: Código extensivamente comentado
- ✅ **Manutenibilidade**: Nomes claros e representativos

## 📚 Bibliotecas Utilizadas

- `stdio.h`: Entrada e saída de dados
- `string.h`: Manipulação de strings

## 🔍 Funções Principais

### `main()`
Função principal que coordena a execução do programa.

### `cadastrarTerritorios()`
Realiza o cadastro dos territórios solicitando informações ao usuário.

### `exibirTerritorios()`
Exibe os dados dos territórios cadastrados de forma formatada.

### `limparBuffer()`
Limpa o buffer de entrada para evitar problemas com leituras subsequentes.

## ⚠️ Validações

- O programa valida se o número de tropas é um valor inteiro positivo
- Tratamento seguro de strings usando `fgets` ao invés de `scanf`
- Remoção de caracteres de nova linha das strings lidas

## 📝 Notas de Desenvolvimento

- O código utiliza `fgets` para leitura de strings, que é mais seguro que `scanf`
- Buffer de entrada é limpo após cada operação para evitar comportamentos inesperados
- Todas as funções possuem documentação detalhada
- O código segue boas práticas de indentação e nomenclatura

## 👨‍💻 Autor

Desenvolvido como parte do desafio de estruturas de dados compostas.

## 📄 Licença

Este projeto foi desenvolvido para fins educacionais.
