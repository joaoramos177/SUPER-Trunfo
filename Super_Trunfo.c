#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARROS 8
#define MAX_ATRIBUTOS 6

// Estrutura para representar um carro no Super Trunfo
typedef struct {
    char nome[50];
    char estado[20];
    char codigo[10];
    int velocidade;
    int potencia;
    int cilindradas;
    int ano;
    float peso;
    int consumo;
} Carro;

// Array de carros pré-definidos
Carro carros[MAX_CARROS] = {
    {"Ferrari F8", "SP", "SP001", 340, 720, 3902, 2019, 1435, 8},
    {"Porsche 911", "SC", "SC002", 330, 450, 2981, 2020, 1495, 9},
    {"Lamborghini", "RJ", "RJ003", 350, 770, 6498, 2021, 1570, 7},
    {"McLaren 720S", "MG", "MG004", 341, 720, 3994, 2020, 1419, 8},
    {"Audi R8", "RS", "RS005", 330, 570, 5204, 2019, 1595, 10},
    {"Corvette", "PR", "PR006", 312, 495, 6162, 2020, 1534, 11},
    {"Mustang GT", "BA", "BA007", 290, 460, 5038, 2021, 1725, 12},
    {"BMW M8", "DF", "DF008", 305, 625, 4395, 2020, 1895, 9}
};

// Função para exibir os atributos de um carro
void exibirCarro(Carro carro) {
    printf("\n=== %s ===\n", carro.nome);
    printf("Estado: %s\n", carro.estado);
    printf("Código: %s\n", carro.codigo);
    printf("Velocidade: %d km/h\n", carro.velocidade);
    printf("Potência: %d cv\n", carro.potencia);
    printf("Cilindradas: %d cc\n", carro.cilindradas);
    printf("Ano: %d\n", carro.ano);
    printf("Peso: %.1f kg\n", carro.peso);
    printf("Consumo: %d km/l\n", carro.consumo);
}

// Função para comparar dois carros baseado no atributo escolhido
int compararCarros(Carro carro1, Carro carro2, int atributo) {
    switch(atributo) {
        case 1: // Velocidade (maior é melhor)
            return carro1.velocidade - carro2.velocidade;
        case 2: // Potência (maior é melhor)
            return carro1.potencia - carro2.potencia;
        case 3: // Cilindradas (maior é melhor)
            return carro1.cilindradas - carro2.cilindradas;
        case 4: // Ano (maior é melhor)
            return carro1.ano - carro2.ano;
        case 5: // Peso (menor é melhor)
            return (carro2.peso - carro1.peso) > 0 ? 1 : -1;
        case 6: // Consumo (maior é melhor)
            return carro1.consumo - carro2.consumo;
        default:
            return 0;
    }
}

// Função para obter nome do atributo
char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "Velocidade";
        case 2: return "Potência";
        case 3: return "Cilindradas";
        case 4: return "Ano";
        case 5: return "Peso";
        case 6: return "Consumo";
        default: return "Desconhecido";
    }
}

// Função para embaralhar os carros
void embaralharCarros(Carro cartas[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carro temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }
}

// Função principal do jogo
void jogarSuperTrunfo() {
    Carro baralho[MAX_CARROS];
    memcpy(baralho, carros, sizeof(carros));
    
    // Embaralhar o baralho
    embaralharCarros(baralho, MAX_CARROS);
    
    // Distribuir cartas (4 para cada jogador)
    Carro jogador[4];
    Carro computador[4];
    
    for (int i = 0; i < 4; i++) {
        jogador[i] = baralho[i];
        computador[i] = baralho[i + 4];
    }
    
    int pontosJogador = 0;
    int pontosComputador = 0;
    int rodada = 1;
    
    printf("=== SUPER TRUNFO DE CARROS ===\n");
    printf("Bem-vindo ao jogo! Você tem 4 carros.\n");
    
    while (rodada <= 4) {
        printf("\n--- Rodada %d ---\n", rodada);
        
        // Exibir carta atual do jogador
        printf("\nSua carta atual:\n");
        exibirCarro(jogador[rodada-1]);
        
        // Jogador escolhe atributo
        int atributo;
        printf("\nEscolha um atributo para comparar:\n");
        printf("1 - Velocidade\n");
        printf("2 - Potência\n");
        printf("3 - Cilindradas\n");
        printf("4 - Ano\n");
        printf("5 - Peso\n");
        printf("6 - Consumo\n");
        printf("Digite sua escolha (1-6): ");
        scanf("%d", &atributo);
        
        if (atributo < 1 || atributo > 6) {
            printf("Atributo inválido! Escolha 1-6.\n");
            continue;
        }
        
        // Comparar cartas
        Carro cartaJogador = jogador[rodada-1];
        Carro cartaComputador = computador[rodada-1];
        
        printf("\nSua carta: %s\n", cartaJogador.nome);
        printf("Carta do computador: %s\n", cartaComputador.nome);
        printf("Atributo escolhido: %s\n", nomeAtributo(atributo));
        
        int resultado = compararCarros(cartaJogador, cartaComputador, atributo);
        
        // Exibir valores comparados
        switch(atributo) {
            case 1:
                printf("Sua velocidade: %d vs Computador: %d\n", 
                       cartaJogador.velocidade, cartaComputador.velocidade);
                break;
            case 2:
                printf("Sua potência: %d vs Computador: %d\n", 
                       cartaJogador.potencia, cartaComputador.potencia);
                break;
            case 3:
                printf("Suas cilindradas: %d vs Computador: %d\n", 
                       cartaJogador.cilindradas, cartaComputador.cilindradas);
                break;
            case 4:
                printf("Seu ano: %d vs Computador: %d\n", 
                       cartaJogador.ano, cartaComputador.ano);
                break;
            case 5:
                printf("Seu peso: %.1f vs Computador: %.1f\n", 
                       cartaJogador.peso, cartaComputador.peso);
                break;
            case 6:
                printf("Seu consumo: %d vs Computador: %d\n", 
                       cartaJogador.consumo, cartaComputador.consumo);
                break;
        }
        
        // Determinar vencedor da rodada
        if (resultado > 0) {
            printf("\n Você venceu esta rodada!\n");
            pontosJogador++;
        } else if (resultado < 0) {
            printf("\n💻 Computador venceu esta rodada!\n");
            pontosComputador++;
        } else {
            printf("\n Empate!\n");
        }
        
        printf("Placar: Você %d x %d Computador\n", pontosJogador, pontosComputador);
        
        rodada++;
        
        if (rodada <= 4) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Limpar buffer
            getchar(); // Aguardar Enter
        }
    }
    
    // Resultado final
    printf("\n=== FIM DO JOGO ===\n");
    printf("Placar Final: Você %d x %d Computador\n", pontosJogador, pontosComputador);
    
    if (pontosJogador > pontosComputador) {
        printf(" PARABÉNS! VOCÊ VENCEU O JOGO! \n");
    } else if (pontosComputador > pontosJogador) {
        printf(" O computador venceu. Tente novamente!\n");
    } else {
        printf(" EMPATE! Foi um jogo equilibrado!\n");
    }
    
    // Exibir todas as cartas usadas
    printf("\n--- Todas as cartas usadas no jogo ---\n");
    printf("\nSUAS CARTAS:\n");
    for (int i = 0; i < 4; i++) {
        exibirCarro(jogador[i]);
    }
    
    printf("\nCARTAS DO COMPUTADOR:\n");
    for (int i = 0; i < 4; i++) {
        exibirCarro(computador[i]);
    }
}

// Menu principal
int main() {
    int opcao;
    
    do {
        printf("\n=== SUPER TRUNFO - MENU PRINCIPAL ===\n");
        printf("1 - Jogar\n");
        printf("2 - Regras do Jogo\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                jogarSuperTrunfo();
                break;
            case 2:
                printf("\n=== REGRAS DO SUPER TRUNFO ===\n");
                printf("- Cada jogador recebe 4 cartas de carros\n");
                printf("- Em cada rodada, você escolhe um atributo\n");
                printf("- Atributos: Velocidade, Potência, Cilindradas, Ano, Peso, Consumo\n");
                printf("- Para maioria: maior valor vence (Velocidade, Potência, etc)\n");
                printf("- Para Peso: menor valor vence\n");
                printf("- Vence quem ganhar mais rodadas\n");
                break;
            case 3:
                printf("Obrigado por jogar! Até mais! \n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
    
    return 0;
}
