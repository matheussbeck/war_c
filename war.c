// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        Nível Mestre: Missões e Modularização Total
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 5
#define NUM_MISSOES 2
#define MAX_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[MAX_STRING];
    char cor[MAX_STRING];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.

// Funções de setup e gerenciamento de memória:
Territorio* alocarMapa(void);
void inicializarTerritorios(Territorio *mapa);
void liberarMemoria(Territorio *mapa);

// Funções de interface com o usuário:
void exibirMenuPrincipal(void);
void exibirMapa(const Territorio *mapa);
void exibirMissao(int missaoId);

// Funções de lógica principal do jogo:
void faseDeAtaque(Territorio *mapa, const char *corJogador);
void simularAtaque(Territorio *mapa, int idxAtacante, int idxDefensor, const char *corJogador);
int sortearMissao(void);
int verificarVitoria(const Territorio *mapa, int missaoId, const char *corJogador);

// Função utilitária:
void limparBufferEntrada(void);

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    srand((unsigned int)time(NULL));

    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    Territorio *mapaDoMundo = alocarMapa();
    if (mapaDoMundo == NULL) {
        printf("\n❌ ERRO: Falha ao alocar memória para o mapa!\n");
        return 1;
    }

    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    inicializarTerritorios(mapaDoMundo);

    // - Define a cor do jogador e sorteia sua missão secreta.
    char corJogador[MAX_STRING] = "Azul";
    int missaoAtual = sortearMissao();

    // Exibir cabeçalho do jogo
    printf("\n");
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                  🎲  PROJETO WAR ESTRUTURADO  🎲                      ║\n");
    printf("║                      Nível Mestre - v1.0                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("\n🎯 Bem-vindo, Comandante do Exército %s!\n", corJogador);

    // 2. Laço Principal do Jogo (Game Loop):
    int opcao;
    int jogoAtivo = 1;

    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    do {
        // - A cada iteração, exibe o mapa, a missão e o menu de ações.
        printf("\n");
        printf("═══════════════════════════════════════════════════════════════════════\n");
        exibirMapa(mapaDoMundo);
        printf("\n");
        exibirMissao(missaoAtual);
        printf("\n");
        exibirMenuPrincipal();

        // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
        printf("\n➤ Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("\n❌ Entrada inválida! Digite um número.\n");
            limparBufferEntrada();
            opcao = -1;
            continue;
        }
        limparBufferEntrada();

        switch (opcao) {
            //   - Opção 1: Inicia a fase de ataque.
            case 1:
                printf("\n🗡️  FASE DE ATAQUE\n");
                printf("═══════════════════════════════════════════════════════════════════════\n");
                faseDeAtaque(mapaDoMundo, corJogador);
                break;

            //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
            case 2:
                printf("\n🔍 VERIFICANDO MISSÃO...\n");
                printf("═══════════════════════════════════════════════════════════════════════\n");
                if (verificarVitoria(mapaDoMundo, missaoAtual, corJogador)) {
                    printf("\n");
                    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
                    printf("║                    🏆  VITÓRIA CONQUISTADA!  🏆                      ║\n");
                    printf("║                                                                       ║\n");
                    printf("║          Parabéns, Comandante! Você cumpriu sua missão!              ║\n");
                    printf("║                O mundo está sob seu domínio!                         ║\n");
                    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
                    jogoAtivo = 0;
                } else {
                    printf("\n⚠️  Sua missão ainda não foi cumprida. Continue lutando!\n");
                }
                break;

            //   - Opção 0: Encerra o jogo.
            case 0:
                printf("\n👋 Encerrando o jogo... Até a próxima batalha, Comandante!\n\n");
                jogoAtivo = 0;
                break;

            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
                break;
        }

        // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.
        if (jogoAtivo && opcao >= 0 && opcao <= 2) {
            printf("\n[Pressione ENTER para continuar...]");
            getchar();
        }

    } while (jogoAtivo);

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.
    liberarMemoria(mapaDoMundo);

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.
Territorio* alocarMapa(void) {
    // calloc aloca e inicializa a memória com zeros
    Territorio *mapa = (Territorio*)calloc(NUM_TERRITORIOS, sizeof(Territorio));

    if (mapa == NULL) {
        fprintf(stderr, "ERRO: Falha na alocação de memória com calloc.\n");
    }

    return mapa;
}

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).
void inicializarTerritorios(Territorio *mapa) {
    // Território 0: Brasil
    strcpy(mapa[0].nome, "Brasil");
    strcpy(mapa[0].cor, "Verde");
    mapa[0].tropas = 5;

    // Território 1: Argentina
    strcpy(mapa[1].nome, "Argentina");
    strcpy(mapa[1].cor, "Azul");
    mapa[1].tropas = 3;

    // Território 2: Peru
    strcpy(mapa[2].nome, "Peru");
    strcpy(mapa[2].cor, "Vermelho");
    mapa[2].tropas = 4;

    // Território 3: Colômbia
    strcpy(mapa[3].nome, "Colombia");
    strcpy(mapa[3].cor, "Amarelo");
    mapa[3].tropas = 3;

    // Território 4: Chile
    strcpy(mapa[4].nome, "Chile");
    strcpy(mapa[4].cor, "Verde");
    mapa[4].tropas = 2;
}

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.
void liberarMemoria(Territorio *mapa) {
    if (mapa != NULL) {
        free(mapa);
        mapa = NULL;
    }
}

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.
void exibirMenuPrincipal(void) {
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          MENU PRINCIPAL                               ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");
    printf("║  [1] 🗡️  Atacar um Território                                         ║\n");
    printf("║  [2] 🔍 Verificar Missão                                              ║\n");
    printf("║  [0] 🚪 Sair do Jogo                                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
}

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.
void exibirMapa(const Territorio *mapa) {
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        🗺️  MAPA DO MUNDO  🗺️                          ║\n");
    printf("╠════╦═══════════════════╦═══════════════════╦═══════════════════════╣\n");
    printf("║ ID ║    Território     ║  Exército (Cor)   ║   Tropas Estacionadas ║\n");
    printf("╠════╬═══════════════════╬═══════════════════╬═══════════════════════╣\n");

    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("║ %2d ║ %-17s ║ %-17s ║          %2d       ║\n",
               i + 1,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }

    printf("╚════╩═══════════════════╩═══════════════════╩═══════════════════════╝\n");
}

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.
void exibirMissao(int missaoId) {
    printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                       🎯 SUA MISSÃO SECRETA 🎯                        ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════╣\n");

    switch (missaoId) {
        case 0:
            printf("║  Destruir completamente o Exército VERDE                          ║\n");
            printf("║  (Conquiste todos os territórios de cor Verde)                    ║\n");
            break;
        case 1:
            printf("║  Conquistar pelo menos 3 territórios para o Exército AZUL         ║\n");
            printf("║  (Expanda seu domínio pelo mundo)                                 ║\n");
            break;
        default:
            printf("║  Missão desconhecida                                               ║\n");
            break;
    }

    printf("╚═══════════════════════════════════════════════════════════════════════╝\n");
}

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.
void faseDeAtaque(Territorio *mapa, const char *corJogador) {
    int idxAtacante, idxDefensor;

    // Solicita o território atacante
    printf("\n🎯 Escolha o território ATACANTE (1 a %d): ", NUM_TERRITORIOS);
    if (scanf("%d", &idxAtacante) != 1) {
        printf("❌ Entrada inválida!\n");
        limparBufferEntrada();
        return;
    }
    limparBufferEntrada();

    // Valida o índice do atacante
    idxAtacante--; // Converte para índice do array (0-4)
    if (idxAtacante < 0 || idxAtacante >= NUM_TERRITORIOS) {
        printf("❌ Território inválido!\n");
        return;
    }

    // Verifica se o território pertence ao jogador
    if (strcmp(mapa[idxAtacante].cor, corJogador) != 0) {
        printf("❌ Este território não pertence ao seu exército (%s)!\n", corJogador);
        return;
    }

    // Verifica se há tropas suficientes
    if (mapa[idxAtacante].tropas < 2) {
        printf("❌ Você precisa de pelo menos 2 tropas para atacar! (Território tem %d)\n",
               mapa[idxAtacante].tropas);
        return;
    }

    // Solicita o território defensor
    printf("🛡️  Escolha o território DEFENSOR (1 a %d): ", NUM_TERRITORIOS);
    if (scanf("%d", &idxDefensor) != 1) {
        printf("❌ Entrada inválida!\n");
        limparBufferEntrada();
        return;
    }
    limparBufferEntrada();

    // Valida o índice do defensor
    idxDefensor--; // Converte para índice do array (0-4)
    if (idxDefensor < 0 || idxDefensor >= NUM_TERRITORIOS) {
        printf("❌ Território inválido!\n");
        return;
    }

    // Verifica se não está atacando a si mesmo
    if (idxAtacante == idxDefensor) {
        printf("❌ Você não pode atacar seu próprio território!\n");
        return;
    }

    // Verifica se o defensor é de outro exército
    if (strcmp(mapa[idxDefensor].cor, corJogador) == 0) {
        printf("❌ Você não pode atacar um território do seu próprio exército!\n");
        return;
    }

    // Executa a simulação do ataque
    simularAtaque(mapa, idxAtacante, idxDefensor, corJogador);
}

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.
void simularAtaque(Territorio *mapa, int idxAtacante, int idxDefensor, const char *corJogador) {
    printf("\n⚔️  BATALHA INICIADA!\n");
    printf("───────────────────────────────────────────────────────────────────────\n");
    printf("🗡️  ATACANTE: %s (%s) com %d tropas\n",
           mapa[idxAtacante].nome, mapa[idxAtacante].cor, mapa[idxAtacante].tropas);
    printf("🛡️  DEFENSOR: %s (%s) com %d tropas\n",
           mapa[idxDefensor].nome, mapa[idxDefensor].cor, mapa[idxDefensor].tropas);
    printf("───────────────────────────────────────────────────────────────────────\n");

    // Rolagem dos dados (1-6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n🎲 ROLANDO OS DADOS...\n");
    printf("   Atacante rolou: %d\n", dadoAtacante);
    printf("   Defensor rolou: %d\n", dadoDefensor);
    printf("\n");

    // Determina o vencedor da batalha
    if (dadoAtacante > dadoDefensor) {
        // Atacante vence
        printf("💥 RESULTADO: Vitória do ATACANTE!\n");
        mapa[idxDefensor].tropas--;

        // Verifica se o território foi conquistado
        if (mapa[idxDefensor].tropas <= 0) {
            printf("\n🏆 TERRITÓRIO CONQUISTADO!\n");
            printf("   %s agora pertence ao exército %s!\n", mapa[idxDefensor].nome, corJogador);

            // Transfere o território para o atacante
            strcpy(mapa[idxDefensor].cor, corJogador);
            mapa[idxDefensor].tropas = 1; // Move 1 tropa para o território conquistado
            mapa[idxAtacante].tropas--; // Remove 1 tropa do atacante
        } else {
            printf("   O defensor perdeu 1 tropa. Restam %d tropas.\n", mapa[idxDefensor].tropas);
        }
    } else {
        // Defensor vence (empates também favorecem o defensor conforme regras do War)
        printf("🛡️  RESULTADO: Vitória do DEFENSOR!\n");
        printf("   O ataque foi repelido! Nenhuma tropa foi perdida.\n");
    }

    printf("───────────────────────────────────────────────────────────────────────\n");
}

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.
int sortearMissao(void) {
    return rand() % NUM_MISSOES;
}

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.
int verificarVitoria(const Territorio *mapa, int missaoId, const char *corJogador) {
    switch (missaoId) {
        case 0: {
            // Missão: Destruir o exército Verde
            // Verifica se ainda existe algum território verde
            int existeVerde = 0;
            for (int i = 0; i < NUM_TERRITORIOS; i++) {
                if (strcmp(mapa[i].cor, "Verde") == 0) {
                    existeVerde = 1;
                    break;
                }
            }

            if (!existeVerde) {
                return 1; // Missão cumprida: não há mais territórios verdes
            }

            printf("   Status: Ainda existem territórios verdes no mapa.\n");
            return 0;
        }

        case 1: {
            // Missão: Conquistar pelo menos 3 territórios
            int territoriosAzuis = 0;
            for (int i = 0; i < NUM_TERRITORIOS; i++) {
                if (strcmp(mapa[i].cor, corJogador) == 0) {
                    territoriosAzuis++;
                }
            }

            printf("   Status: Você controla %d território(s). Precisa de 3.\n", territoriosAzuis);

            if (territoriosAzuis >= 3) {
                return 1; // Missão cumprida: 3 ou mais territórios azuis
            }

            return 0;
        }

        default:
            return 0;
    }
}

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
