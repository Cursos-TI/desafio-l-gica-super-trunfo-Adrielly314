#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis do jogador 1
    char Nome1[60];
    int Idade1, Nascimento1;
    char Tutorial[20];

    printf("\n    ===== SUPER TRUNFO =====\n");

    // Jogador 1 - Cadastro
    printf("Olá novo jogador. Qual é o seu nome? ");
    if (scanf(" %[^\n]", Nome1) != 1) return 1;

    printf("Nome bonito o seu! Qual é a sua idade? ");
    if (scanf("%d", &Idade1) != 1) return 1;

    printf("Quando você nasceu? (Digite apenas o ano, ex: 2013) ");
    if (scanf("%d", &Nascimento1) != 1) return 1;

    while (getchar() != '\n');

    printf("Deseja receber o tutorial? (Sim ou Não) ");
    if (scanf(" %[^\n]", Tutorial) != 1) return 1;

    if (strcmp(Tutorial, "Sim") == 0) {
        printf("\n===== TUTORIAL =====\n");
        printf("No jogo Super Trunfo - Países, cada jogador recebe cartas de cidades com informações como população, área, PIB e pontos turísticos.\n");
        printf("A cada rodada, um jogador escolhe uma característica de sua carta e compara com a do adversário.\n");
        printf("Quem tiver o maior valor vence e fica com a carta do outro jogador.\n");
        printf("O jogo continua até que um dos jogadores tenha todas as cartas.\n");
        printf("Dica: escolha bem suas jogadas e tente adivinhar a estratégia do adversário!\n\n");
    } else {
        printf("Ok! Vamos prosseguir então.\n\n");
    }

    if (Idade1 >= 18)
        printf("\nBem-vindo(a), %s! Prepare-se para uma disputa intensa e estratégica.\n\n", Nome1);
    else
        printf("\nOi %s! Vamos nos divertir muito, jogando de forma leve e divertida!\n\n", Nome1);

    int continuar = 1;
    while (continuar) {
        // Escolha de oponente
        int modoJogo;
        printf("Você deseja jogar contra:\n");
        printf("1 - Computador\n2 - Outra pessoa\nEscolha: ");
        scanf("%d", &modoJogo);

        // Variáveis do jogador 2
        char Nome2[60];
        int Idade2, Nascimento2;

        if (modoJogo == 1) {
            strcpy(Nome2, "Computador");
            printf("\nVocê enfrentará um Robô!\n");
        } else {
            printf("\nJogador 2, qual é o seu nome? ");
            if (scanf(" %[^\n]", Nome2) != 1) return 1;

            printf("Qual a sua idade, %s? ", Nome2);
            if (scanf("%d", &Idade2) != 1) return 1;

            printf("Quando você nasceu, %s? (Digite apenas o ano, ex: 2010) ", Nome2);
            if (scanf("%d", &Nascimento2) != 1) return 1;

            if (Idade2 >= 18)
                printf("\nBem-vindo(a), %s! Prepare-se para uma disputa intensa e estratégica.\n", Nome2);
            else
                printf("\nOi %s! Vamos nos divertir muito nessa rodada!\n", Nome2);
        }

        printf("\n%s e %s, boa sorte para vocês!\n", Nome1, Nome2);

        // Cidades
        char *Cidades[] = {"Petrópolis", "Caucaia", "São Paulo", "Paris", "Tóquio", "Cidade do Cabo", "Toronto", "Barcelona"};
        char *Paises[] = {"Brasil", "Brasil", "Brasil", "França", "Japão", "África do Sul", "Canadá", "Espanha"};
        int Populacoes[] = {278881, 355679, 11451999, 2104154, 8970000, 4600000, 2790000, 1600000};
        float Areas[] = {795.798, 1223.246, 1521.202, 105.0, 2194.07, 2461.0, 630.2, 101.9};
        float PIBs[] = {51.003, 28.229, 66.872, 5.150, 2000.0, 335.0, 400.0, 177.0};
        int PontosTuristicos[] = {15, 12, 60, 100, 90, 70, 85, 75};
        float Densidades[8];
        for (int i = 0; i < 8; i++) {
            Densidades[i] = Populacoes[i] / Areas[i];
        }

        // Mostrar cidades
        printf("\nAs cidades disponíveis são:\n");
        for (int i = 0; i < 8; i++) {
            printf("%d - %s\n", i + 1, Cidades[i]);
        }

        // Jogador 1 escolhe
        int Escolha1;
        printf("\n%s, escolha sua cidade: ", Nome1);
        if (scanf("%d", &Escolha1) != 1 || Escolha1 < 1 || Escolha1 > 8) {
            printf("Opção inválida!\n");
            return 1;
        }
        Escolha1--;

        printf("\n===== CARTA ESCOLHIDA - %s =====\n", Nome1);
        printf("País: %s\n", Paises[Escolha1]);
        printf("Cidade: %s\n", Cidades[Escolha1]);

        // Jogador 2 escolhe
        int Escolha2;
        if (modoJogo == 1) {
            srand(time(NULL));
            Escolha2 = rand() % 8;
            printf("\nRobô está escolhendo sua cidade...\n");
            printf("Cidade selecionada!\n");
        } else {
            printf("\n%s, escolha sua cidade: ", Nome2);
            if (scanf("%d", &Escolha2) != 1 || Escolha2 < 1 || Escolha2 > 8) {
                printf("Opção inválida!\n");
                return 1;
            }
            Escolha2--;
        }

        printf("\n===== CARTA ESCOLHIDA - %s =====\n", Nome2);
        printf("País: %s\n", Paises[Escolha2]);
        printf("Cidade: %s\n", Cidades[Escolha2]);

        // Escolha do critério
        int Criterio;
        printf("\n%s, escolha o critério para comparar:\n", Nome1);
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica (quanto MENOR, melhor)\n");
        printf("Digite sua escolha: ");
        if (scanf("%d", &Criterio) != 1 || Criterio < 1 || Criterio > 5) {
            printf("Critério inválido!\n");
            return 1;
        }

        float Valor1 = 0, Valor2 = 0;
        char NomeCriterio[30];

        switch (Criterio) {
            case 1:
                Valor1 = Populacoes[Escolha1];
                Valor2 = Populacoes[Escolha2];
                strcpy(NomeCriterio, "População");
                break;
            case 2:
                Valor1 = Areas[Escolha1];
                Valor2 = Areas[Escolha2];
                strcpy(NomeCriterio, "Área");
                break;
            case 3:
                Valor1 = PIBs[Escolha1];
                Valor2 = PIBs[Escolha2];
                strcpy(NomeCriterio, "PIB");
                break;
            case 4:
                Valor1 = PontosTuristicos[Escolha1];
                Valor2 = PontosTuristicos[Escolha2];
                strcpy(NomeCriterio, "Pontos Turísticos");
                break;
            case 5:
                Valor1 = Densidades[Escolha1];
                Valor2 = Densidades[Escolha2];
                strcpy(NomeCriterio, "Densidade Demográfica");
                break;
        }

        // Resultado
        printf("\n================== RESULTADO ==================\n");
        printf("Atributo escolhido: %s\n", NomeCriterio);
        printf("Valor de %s: %.2f\n", Nome1, Valor1);
        printf("Valor de %s: %.2f\n", Nome2, Valor2);

        if (Criterio == 5) {
            if (Valor1 < Valor2)
                printf("\n%s venceu (menor densidade)!\n", Nome1);
            else if (Valor2 < Valor1)
                printf("\n%s venceu (menor densidade)!\n", Nome2);
            else
                printf("\nEmpate!\n");
        } else {
            if (Valor1 > Valor2)
                printf("\n%s venceu!\n", Nome1);
            else if (Valor2 > Valor1)
                printf("\n%s venceu!\n", Nome2);
            else
                printf("\nEmpate!\n");
        }

        // Continuar jogando?
        char resposta[10];
        printf("\nDeseja continuar jogando? (Sim ou Não) ");
        scanf(" %s", resposta);
        if (strcmp(resposta, "Não") == 0 || strcmp(resposta, "nao") == 0)
            continuar = 0;
    }

    printf("\nObrigado por jogar Super Trunfo! Até a próxima!\n");
    return 0;
}
