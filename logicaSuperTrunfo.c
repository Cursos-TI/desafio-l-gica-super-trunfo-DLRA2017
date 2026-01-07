#include <stdio.h>
#include <string.h>

/**
 *São Paulo 
*Habitantes:11.900.000 
*PIB: 850.000.000.000.
*km²:1.521 
*Principais pontos turisticos:08
*Farol Santander
*Theatro Municipal
*Beco do Batman
*Catedral da Sé
*Pinacoteca de São Paulo
*Museu do Ipiranga
*Avenida Paulista
*Parque Ibirapuera:

____________________________
*Rio de Janeiro 
*Habitantes: 6.200.000.
*PIB:53.000.000.000.
*km²:43.750
*Principais pontos turisticos:10
*Pedra do Arpoador
*Teatro Municipal
*Maracanã
*Escadaria Selarón
*Parque Lage
*Museu do Amanhã
*Jardim Botânico
*Praias Icônicas
*Bondinho do Pão de Açúcar
*Cristo Redentor

___________________________
 *Belo Horizonte 

*Habitantes:2,4 milhões
*PIB: 51.000.000.000. 
*km²:331,354
*Principais pontos turisticos:4

*Serra do Curral
*Mercado Central
*Praça da Liberdade
*Conjunto Moderno da Pampulha

________________________________

*/

// Estrutura para representar as cartas do Super Trunfo
typedef struct {
    char name[30];
    int population;
    float area;
    float pib;
    int tourist_points;
} Card;

// Função para exibir os dados de uma carta

void displayCard(Card c) {
    printf("\n--- Cidade: %s ---\n", c.name);
    printf("População: %d habitantes\n", c.population);
    printf("Área: %.2f km2\n", c.area);
    printf("PIB: %.2f biliões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.tourist_points);
}

int main() {
    Card cities[3];
    char *city_names[] = {"Rio de Janeiro", "São Paulo", "Belo Horizonte"};

    printf("========================================\n");
    printf("     BEM-VINDO AO SUPER TRUNFO EM C     \n");
    printf("========================================\n");
    printf("Instruções: Digite apenas valores numéricos quando solicitado.\n");

    // Loop para cadastrar as 3 cidades
    for (int i = 0; i < 3; i++) {
        strcpy(cities[i].name, city_names[i]);
        
        printf("\n>>> Configurando dados para: %s <<<\n", cities[i].name);
        
        printf("Digite a População (ex: 12000000): ");
        if (scanf("%d", &cities[i].population) != 1) {
            printf("Erro: Você digitou texto em vez de número. Reinicie o programa.\n");
            return 1;
        }
        
        printf("Digite a Área em km2 (ex: 1521.11): ");
        scanf("%f", &cities[i].area);
        
        printf("Digite o PIB em biliões (ex: 700.50): ");
        scanf("%f", &cities[i].pib);
        
        printf("Digite o número de Pontos Turísticos: ");
        scanf("%d", &cities[i].tourist_points);
        
        // Limpa o buffer do teclado para a próxima iteração
        while (getchar() != '\n'); 
    }

    // --- EXIBIÇÃO DOS DADOS ---
    printf("\n\n========================================");
    printf("\n         RESUMO DAS CARTAS              ");
    printf("\n========================================\n");
    for (int i = 0; i < 3; i++) {
        displayCard(cities[i]);
    }

    // --- LÓGICA DE COMPARAÇÃO (Vencedor por População) ---
    int winner_index = 0;
    for (int i = 1; i < 3; i++) {
        if (cities[i].population > cities[winner_index].population) {
            winner_index = i;
        }
    }

    printf("\n========================================");
    printf("\n       RESULTADO DO DUELO (POP)         ");
    printf("\n========================================\n");
    printf("VENCEDORA: %s!\n", cities[winner_index].name);
    printf("População Recorde: %d habitantes.\n", cities[winner_index].population);
    printf("========================================\n");

    return 0;
}
