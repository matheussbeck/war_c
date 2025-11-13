# 🗺️ Desafio WAR Estruturado – Conquista de Territórios

Bem-vindo ao **Desafio WAR Estruturado!** Inspirado no famoso jogo de estratégia, este desafio convida você a programar diferentes versões do jogo WAR, evoluindo seus conhecimentos em **C** à medida que avança pelos níveis **Novato**, **Aventureiro** e **Mestre**.

A empresa **MateCheck** contratou você para criar uma versão estruturada do WAR. Cada nível propõe novas funcionalidades, conceitos e desafios de programação. **Você escolhe por onde começar!**

---

## 📁 Estrutura do Projeto

```
war_c/
├── territorios.c      # Nível Novato: Cadastro básico de territórios
├── war.c             # Nível Mestre: Sistema completo com missões
├── README.md         # Documentação do projeto
└── .gitignore       # Arquivos a serem ignorados pelo Git
```

---

## 🧩 Nível Novato: Cadastro Inicial dos Territórios

### 🎯 Objetivo

- Criar uma `struct` chamada `Territorio`.
- Usar um **vetor estático de 5 elementos** para armazenar os territórios.
- Cadastrar os dados de cada território: **Nome**, **Cor do Exército**, e **Número de Tropas**.
- Exibir o estado atual do mapa.

### ⚙️ Funcionalidades

- Leitura de dados pelo terminal (`fgets` e `scanf`)
- Impressão organizada dos dados de todos os territórios

### 💡 Conceitos abordados

- `struct`
- Vetor estático
- Entrada/saída com `scanf`, `fgets`, e `printf`

### 🚀 Como usar

```bash
# Compilar
gcc -o territorios territorios.c -Wall -Wextra

# Executar
./territorios
```

### 📥 Entrada

O usuário digita o nome do território, a cor do exército dominante e o número de tropas para **cada um dos 5 territórios**.

### 📤 Saída

Exibição formatada de todos os territórios cadastrados.

---

## 🧗‍♂️ Nível Aventureiro: Batalhas Estratégicas

### 🎯 Objetivo

- Substituir o vetor estático por **alocação dinâmica com `calloc`**
- Criar uma função para **simular ataques entre dois territórios**
- Utilizar números aleatórios para representar dados de batalha

### 🆕 Novidades em relação ao Nível Novato

- Alocação dinâmica de memória com `calloc`
- Uso de **ponteiros**
- Laço interativo para o jogador escolher **territórios para atacar e defender**
- Simulação de dados de ataque e defesa com `rand()`

### ⚙️ Funcionalidades

- Cadastro dos territórios (como no Nível Novato)
- Fase de ataque com:
  - Escolha de atacante e defensor
  - Dados de ataque/defesa
  - Lógica:
    - Se atacante vence → defensor perde 1 tropa
    - Se defensor perde todas → território é conquistado
    - Empates favorecem o defensor

### 💡 Conceitos abordados

- Ponteiros
- `calloc` / `free`
- Aleatoriedade com `rand()` / `srand()`
- Funções para modularização

---

## 🧠 Nível Mestre: Missões e Modularização Total ⭐

### 🎯 Objetivo

- Dividir o código em funções bem definidas
- Implementar um **sistema de missões**
- Verificar cumprimento da missão
- Aplicar **boas práticas** (uso de `const`, modularização, etc.)

### 🆕 Diferenças em relação ao Nível Aventureiro

- **Modularização total em funções**
- **Missões aleatórias** atribuídas:
  1. 🎯 **Destruir o exército Verde** (conquistar todos os territórios verdes)
  2. 🎯 **Conquistar 3 territórios** para o exército Azul
- **Menu interativo** com opções
- **Inicialização automática** dos territórios (sem necessidade de cadastro manual)

### ⚙️ Funcionalidades Implementadas

#### 1. Sistema de Territórios
- 5 territórios predefinidos:
  - 🇧🇷 **Brasil** (Verde, 5 tropas)
  - 🇦🇷 **Argentina** (Azul, 3 tropas)
  - 🇵🇪 **Peru** (Vermelho, 4 tropas)
  - 🇨🇴 **Colômbia** (Amarelo, 3 tropas)
  - 🇨🇱 **Chile** (Verde, 2 tropas)

#### 2. Menu Principal
```
[1] 🗡️  Atacar um Território
[2] 🔍 Verificar Missão
[0] 🚪 Sair do Jogo
```

#### 3. Sistema de Batalha
- **Escolha de territórios**: atacante e defensor
- **Rolagem de dados** (1-6) para atacante e defensor
- **Regras de combate**:
  - Atacante vence se rolar número maior
  - Defensor perde 1 tropa ao perder
  - Território conquistado quando tropas chegam a 0
  - Empates favorecem o defensor

#### 4. Sistema de Missões
- Missão sorteada aleatoriamente no início
- Duas missões disponíveis:
  - **Missão 0**: Destruir completamente o exército Verde
  - **Missão 1**: Conquistar pelo menos 3 territórios

#### 5. Verificação de Vitória
- Função dedicada para verificar se missão foi cumprida
- Mensagem de vitória ao completar objetivo

### 💡 Conceitos Avançados Abordados

- ✅ **Modularização**: código dividido em funções especializadas
- ✅ **Const Correctness**: uso de `const` para funções que apenas leem dados
- ✅ **Ponteiros**: passagem por referência para modificar dados
- ✅ **Alocação Dinâmica**: `calloc` e `free` para gerenciamento de memória
- ✅ **Aleatoriedade**: `srand()` e `rand()` para sorteio de missões e dados
- ✅ **Validação de Entrada**: verificações robustas de todas as entradas do usuário
- ✅ **Design de Software**: arquitetura limpa e organizada

### 🚀 Como Compilar e Executar

```bash
# Compilar o programa
gcc -o war war.c -Wall -Wextra

# Executar
./war
```

### 🎮 Como Jogar

1. **Inicie o jogo**: Execute o programa
2. **Veja sua missão**: Uma missão secreta será atribuída
3. **Visualize o mapa**: Veja o estado atual de todos os territórios
4. **Escolha uma ação**:
   - Atacar um território inimigo
   - Verificar se sua missão foi cumprida
   - Sair do jogo

#### Exemplo de Ataque

```
➤ Escolha uma opção: 1
🎯 Escolha o território ATACANTE (1 a 5): 2
🛡️  Escolha o território DEFENSOR (1 a 5): 1

⚔️  BATALHA INICIADA!
🗡️  ATACANTE: Argentina (Azul) com 3 tropas
🛡️  DEFENSOR: Brasil (Verde) com 5 tropas

🎲 ROLANDO OS DADOS...
   Atacante rolou: 5
   Defensor rolou: 3

💥 RESULTADO: Vitória do ATACANTE!
   O defensor perdeu 1 tropa. Restam 4 tropas.
```

### 📋 Estrutura de Dados

```c
typedef struct {
    char nome[MAX_STRING];      // Nome do território
    char cor[MAX_STRING];       // Cor do exército dominante
    int tropas;                 // Número de tropas estacionadas
} Territorio;
```

### 📚 Funções Principais

#### Setup e Gerenciamento de Memória
- `Territorio* alocarMapa(void)` - Aloca memória dinamicamente
- `void inicializarTerritorios(Territorio *mapa)` - Inicializa territórios
- `void liberarMemoria(Territorio *mapa)` - Libera memória alocada

#### Interface com Usuário
- `void exibirMenuPrincipal(void)` - Mostra menu de opções
- `void exibirMapa(const Territorio *mapa)` - Exibe estado do mapa
- `void exibirMissao(int missaoId)` - Mostra missão atual

#### Lógica do Jogo
- `void faseDeAtaque(Territorio *mapa, const char *corJogador)` - Gerencia ataques
- `void simularAtaque(...)` - Executa lógica de batalha
- `int sortearMissao(void)` - Sorteia missão aleatória
- `int verificarVitoria(...)` - Verifica se missão foi cumprida

#### Utilitários
- `void limparBufferEntrada(void)` - Limpa buffer de entrada

### 🎯 Regras de Validação

O programa implementa validações robustas:

- ✅ Verifica se território atacante pertence ao jogador
- ✅ Valida se há tropas suficientes para atacar (mínimo 2)
- ✅ Impede ataque ao próprio território
- ✅ Impede ataque a territórios da mesma cor
- ✅ Valida entrada de números e índices de territórios

### 🏆 Condições de Vitória

#### Missão 0: Destruir Exército Verde
- Conquistar **todos** os territórios verdes
- Não pode existir nenhum território de cor Verde no mapa

#### Missão 1: Conquistar Territórios
- Controlar **pelo menos 3 territórios** com o exército Azul
- Territórios podem ser conquistados através de ataques bem-sucedidos

---

## 🏁 Conclusão

Com este **Desafio WAR Estruturado**, você praticará fundamentos essenciais da linguagem **C** de forma **divertida e progressiva**.

Cada nível foca em um conjunto de habilidades:

- 🟢 **Novato**: `struct`, vetor, entrada/saída
- 🔵 **Aventureiro**: ponteiros, memória dinâmica, lógica de jogo
- 🟣 **Mestre**: modularização, design limpo, sistema de missões

---

## 📝 Requisitos Técnicos

### Bibliotecas Utilizadas
```c
#include <stdio.h>      // Entrada e saída
#include <stdlib.h>     // Alocação dinâmica, rand/srand
#include <string.h>     // Manipulação de strings
#include <time.h>       // Geração de seed para random
#include <locale.h>     // Suporte a caracteres UTF-8
```

### Compilação
```bash
gcc -o war war.c -Wall -Wextra -std=c11
```

### Compatibilidade
- Sistema Operacional: Linux, macOS, Windows (MinGW)
- Compilador: GCC 7.0+, Clang 10.0+
- Padrão C: C99 ou superior

---

## 🎓 Conceitos de Programação Aplicados

### Design de Software
- **Separação de Responsabilidades**: Cada função tem uma única responsabilidade
- **Interface Limpa**: Funções com nomes descritivos e parâmetros claros
- **Código Autodocumentado**: Comentários explicativos em todo o código

### Boas Práticas em C
- **Const Correctness**: Uso de `const` para parâmetros somente-leitura
- **Gerenciamento de Memória**: Sempre liberar memória alocada
- **Validação de Entrada**: Verificar todas as entradas do usuário
- **Tratamento de Erros**: Verificar retornos de funções críticas

### Arquitetura do Código
```
main()
├── Setup (Alocação, Inicialização, Configuração)
├── Game Loop
│   ├── Exibir Estado do Jogo
│   ├── Ler Ação do Jogador
│   ├── Executar Ação
│   └── Verificar Condição de Vitória
└── Cleanup (Liberação de Memória)
```

---

## 🐛 Solução de Problemas

### Erro de Compilação
```bash
# Se houver erro de compilação, verifique:
gcc --version  # Versão do compilador
gcc -o war war.c -Wall -Wextra -v  # Compilação verbose
```

### Caracteres Não Aparecem Corretamente
```bash
# Configure o locale do terminal:
export LC_ALL=pt_BR.UTF-8
export LANG=pt_BR.UTF-8
```

### Memória Não Liberada
```bash
# Use valgrind para verificar vazamentos de memória:
valgrind --leak-check=full ./war
```

---

## 📚 Referências e Recursos

- [The C Programming Language (K&R)](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)
- [C Standard Library Documentation](https://en.cppreference.com/w/c)
- [WAR Board Game Rules](https://www.grow.com.br/war)

---

## 👨‍💻 Desenvolvimento

Este projeto foi desenvolvido como parte do desafio educacional da **MateCheck** para ensino de programação estruturada em C.

### Histórico de Versões
- **v1.0** - Implementação completa do Nível Mestre
  - Sistema de missões
  - Combate com dados
  - Modularização total
  - Interface visual melhorada

---

## 📜 Licença

Este projeto foi desenvolvido para fins educacionais.

---

🚀 **Boa sorte! Avance nos níveis e torne-se um mestre da programação estratégica!**

> Equipe de Ensino – MateCheck
