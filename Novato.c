#include <stdio.h>
#include <string.h>

int main() {
    // Dados do jogador
    char Nome[50];
    int Idade, Nascimento;
    char Tutorial[10];

    // Carta 1
    char Estado1, Codigo1[4], NomeCidade1[50];
    unsigned long int Populacao1;
    float Area1, PIB1;
    int PontosTuristicos1;
    float Densidade1, PIBPerCapita1, SuperPoder1;

    // Carta 2
    char Estado2, Codigo2[4], NomeCidade2[50];
    unsigned long int Populacao2;
    float Area2, PIB2;
    int PontosTuristicos2;
    float Densidade2, PIBPerCapita2, SuperPoder2;

    // Entrada do jogador
    printf("\n    ===== SUPER TRUNFO =====\n");
    printf("Olá novo jogador. Qual é o seu nome? ");
    scanf(" %[^\n]", Nome);

    printf("Nome bonito o seu! Qual é a sua idade? ");
    scanf("%d", &Idade);

    printf("Quando você nasceu? ");
    scanf("%d", &Nascimento);

    while (getchar() != '\n'); // Limpa o buffer

    printf("Deseja receber o tutorial? (Sim ou Não) ");
    scanf(" %[^\n]", Tutorial);

    if (strcmp(Tutorial, "Sim") == 0) {
        printf("\n===== TUTORIAL =====\n");
        printf("No jogo Super Trunfo - Cidades, cada jogador recebe cartas com atributos.\n");
        printf("Você compara os valores e quem tiver o melhor vence o atributo.\n");
        printf("No nível mestre, usamos até o Super Poder para decidir a melhor carta!\n\n");
    } else {
        printf("Ok! Vamos prosseguir então.\n\n");
    }

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Informe o estado (letra de A a H): ");
    scanf(" %c", &Estado1);

    printf("Informe o código da carta (ex: A01): ");
    scanf(" %s", Codigo1);

    while (getchar() != '\n');
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", NomeCidade1);

    printf("Informe a população: ");
    scanf("%lu", &Populacao1);

    printf("Informe a área em km²: ");
    scanf("%f", &Area1);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &PIB1);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &PontosTuristicos1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Informe o estado (letra de A a H): ");
    scanf(" %c", &Estado2);

    printf("Informe o código da carta (ex: B01): ");
    scanf(" %s", Codigo2);

    while (getchar() != '\n');
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", NomeCidade2);

    printf("Informe a população: ");
    scanf("%lu", &Populacao2);

    printf("Informe a área em km²: ");
    scanf("%f", &Area2);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &PIB2);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &PontosTuristicos2);

    // Cálculos
    Densidade1 = Populacao1 / Area1;
    PIBPerCapita1 = (PIB1 * 1000000000) / Populacao1;

    Densidade2 = Populacao2 / Area2;
    PIBPerCapita2 = (PIB2 * 1000000000) / Populacao2;

    SuperPoder1 = Populacao1 + Area1 + PIB1 + PontosTuristicos1 + PIBPerCapita1 + (1.0 / Densidade1);
    SuperPoder2 = Populacao2 + Area2 + PIB2 + PontosTuristicos2 + PIBPerCapita2 + (1.0 / Densidade2);

    // Exibição das cartas
    printf("\n==============================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", Estado1);
    printf("Código: %s\n", Codigo1);
    printf("Cidade: %s\n", NomeCidade1);
    printf("População: %lu\n", Populacao1);
    printf("Área: %.2f km²\n", Area1);
    printf("PIB: %.2f bilhões\n", PIB1);
    printf("Pontos Turísticos: %d\n", PontosTuristicos1);
    printf("Densidade: %.2f hab/km²\n", Densidade1);
    printf("PIB per Capita: %.2f reais\n", PIBPerCapita1);
    printf("Super Poder: %.2f\n", SuperPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Estado2);
    printf("Código: %s\n", Codigo2);
    printf("Cidade: %s\n", NomeCidade2);
    printf("População: %lu\n", Populacao2);
    printf("Área: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões\n", PIB2);
    printf("Pontos Turísticos: %d\n", PontosTuristicos2);
    printf("Densidade: %.2f hab/km²\n", Densidade2);
    printf("PIB per Capita: %.2f reais\n", PIBPerCapita2);
    printf("Super Poder: %.2f\n", SuperPoder2);

    // Comparação Final
    printf("\n===== RESULTADO FINAL =====\n");
    if (SuperPoder1 > SuperPoder2) {
        printf("VENCEDORA: Carta 1 (%s)\n", NomeCidade1);
    } else if (SuperPoder2 > SuperPoder1) {
        printf("VENCEDORA: Carta 2 (%s)\n", NomeCidade2);
    } else {
        printf("EMPATE entre %s e %s!\n", NomeCidade1, NomeCidade2);
    }

    return 0;
}
