/*
 * =========================================================================
 * PROGRAMA: Sistema de Cadastro de Territórios
 * =========================================================================
 * Descrição:
 *   Este programa implementa um sistema simples de cadastro de territórios
 *   utilizando estruturas de dados compostas (structs). O sistema permite
 *   cadastrar informações de 5 territórios e exibir seus dados.
 *
 * Autor: Sistema de Gerenciamento de Territórios
 * Data: 2025-11-13
 * =========================================================================
 */

#include <stdio.h>   // Biblioteca para entrada e saída de dados
#include <string.h>  // Biblioteca para manipulação de strings

/*
 * =========================================================================
 * DEFINIÇÃO DA ESTRUTURA DE DADOS
 * =========================================================================
 * A struct Territorio agrupa informações relacionadas a um território:
 * - nome: nome do território (até 30 caracteres)
 * - cor: cor do exército que ocupa o território (até 10 caracteres)
 * - tropas: quantidade de tropas presentes no território
 * =========================================================================
 */
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Número de tropas
} Territorio;

/*
 * =========================================================================
 * CONSTANTES DO PROGRAMA
 * =========================================================================
 */
#define NUM_TERRITORIOS 5  // Número de territórios a serem cadastrados

/*
 * =========================================================================
 * PROTÓTIPOS DE FUNÇÕES
 * =========================================================================
 */
void cadastrarTerritorios(Territorio territorios[], int quantidade);
void exibirTerritorios(Territorio territorios[], int quantidade);
void limparBuffer(void);

/*
 * =========================================================================
 * FUNÇÃO PRINCIPAL
 * =========================================================================
 * A função main coordena a execução do programa:
 * 1. Declara um vetor de structs para armazenar os territórios
 * 2. Chama a função de cadastro
 * 3. Chama a função de exibição
 * =========================================================================
 */
int main() {
    // Declaração do vetor de structs para armazenar os territórios
    Territorio territorios[NUM_TERRITORIOS];

    // Exibir cabeçalho do programa
    printf("=========================================================================\n");
    printf("           SISTEMA DE CADASTRO DE TERRITORIOS - WAR GAME\n");
    printf("=========================================================================\n\n");

    // Cadastrar os territórios
    cadastrarTerritorios(territorios, NUM_TERRITORIOS);

    // Exibir os territórios cadastrados
    exibirTerritorios(territorios, NUM_TERRITORIOS);

    return 0;
}

/*
 * =========================================================================
 * FUNÇÃO: cadastrarTerritorios
 * =========================================================================
 * Descrição:
 *   Realiza o cadastro dos territórios solicitando ao usuário que informe
 *   o nome, cor do exército e número de tropas de cada território.
 *
 * Parâmetros:
 *   - territorios[]: vetor de structs onde serão armazenados os dados
 *   - quantidade: número de territórios a cadastrar
 *
 * Retorno: void
 *
 * Observações:
 *   - Utiliza fgets para leitura de strings (mais seguro que scanf)
 *   - Remove o caractere '\n' do final das strings lidas com fgets
 *   - Limpa o buffer de entrada quando necessário
 * =========================================================================
 */
void cadastrarTerritorios(Territorio territorios[], int quantidade) {
    printf(">>> CADASTRO DE TERRITORIOS <<<\n");
    printf("Por favor, cadastre %d territorios.\n\n", quantidade);

    // Laço para cadastrar cada território
    for (int i = 0; i < quantidade; i++) {
        printf("-------------------------\n");
        printf("Territorio %d de %d\n", i + 1, quantidade);
        printf("-------------------------\n");

        // Leitura do nome do território
        printf("Nome do territorio: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);

        // Remove o caractere '\n' do final da string, se existir
        size_t len = strlen(territorios[i].nome);
        if (len > 0 && territorios[i].nome[len - 1] == '\n') {
            territorios[i].nome[len - 1] = '\0';
        }

        // Leitura da cor do exército
        printf("Cor do exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);

        // Remove o caractere '\n' do final da string, se existir
        len = strlen(territorios[i].cor);
        if (len > 0 && territorios[i].cor[len - 1] == '\n') {
            territorios[i].cor[len - 1] = '\0';
        }

        // Leitura do número de tropas
        printf("Numero de tropas: ");

        // Lê o número de tropas e valida a entrada
        while (scanf("%d", &territorios[i].tropas) != 1 || territorios[i].tropas < 0) {
            printf("Entrada invalida! Digite um numero inteiro positivo: ");
            limparBuffer();
        }

        // Limpa o buffer para a próxima iteração
        limparBuffer();

        printf("\n");
    }
}

/*
 * =========================================================================
 * FUNÇÃO: exibirTerritorios
 * =========================================================================
 * Descrição:
 *   Exibe na tela todos os dados dos territórios cadastrados de forma
 *   formatada e organizada.
 *
 * Parâmetros:
 *   - territorios[]: vetor de structs com os dados a serem exibidos
 *   - quantidade: número de territórios a exibir
 *
 * Retorno: void
 *
 * Observações:
 *   - Utiliza formatação de saída para apresentação clara dos dados
 *   - Exibe um cabeçalho e linhas separadoras para melhor legibilidade
 * =========================================================================
 */
void exibirTerritorios(Territorio territorios[], int quantidade) {
    printf("\n=========================================================================\n");
    printf("                    TERRITORIOS CADASTRADOS\n");
    printf("=========================================================================\n\n");

    // Laço para percorrer e exibir cada território
    for (int i = 0; i < quantidade; i++) {
        printf("-------------------------------------------------------------------------\n");
        printf("Territorio #%d\n", i + 1);
        printf("-------------------------------------------------------------------------\n");
        printf("  Nome do Territorio:  %s\n", territorios[i].nome);
        printf("  Cor do Exercito:     %s\n", territorios[i].cor);
        printf("  Numero de Tropas:    %d\n", territorios[i].tropas);
        printf("-------------------------------------------------------------------------\n\n");
    }

    // Resumo final
    printf("=========================================================================\n");
    printf("Total de territorios cadastrados: %d\n", quantidade);
    printf("=========================================================================\n");
}

/*
 * =========================================================================
 * FUNÇÃO: limparBuffer
 * =========================================================================
 * Descrição:
 *   Limpa o buffer de entrada (stdin) para evitar problemas com leituras
 *   subsequentes, especialmente após usar scanf.
 *
 * Parâmetros: void
 *
 * Retorno: void
 *
 * Observações:
 *   - Lê e descarta todos os caracteres até encontrar '\n' ou EOF
 *   - Essencial para evitar comportamentos inesperados na entrada de dados
 * =========================================================================
 */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
