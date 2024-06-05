#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> 

#define tam 20
int *reclamacoes = NULL;

int main() {
    // Declarações de variáveis
    int op, nmr_produtos, nmr_filiais, trimestre = 4, *p, len = 0, n_trimestre;
    char **p1, **p2;

    do {
        system("CLS");
        printf("--------------MENU---------------\n\n");
        printf("(1) - Inicializacao do sistema\n(2) - Catalogo do sistema\n(3) - Catalogo de filiais\n(4) - Inserir venda de um produto/trimestre\n(5) - Inserir venda de um produto/filial\n(6) - Produto mais vendido por filial\n(7) - Filial que mais vende produtos\n(8) - Produto mais vendido\n(9) - Filial que mais vende\n(10) - Melhor trimestre\n(11) - Inserir novo produto\n(12) - Inserir nova filial\n(13) - Remover produto\n(14) - Inserir Reclamacao\n(15) - Contador de Reclamacoes\n(16) - SAIR\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op) {
            // Inicialização do sistema
            case 1: {
                system("CLS");
                printf("Inicializando o sistema...\n");
                Sleep(2);
                printf("Informe o numero de produtos do catalogo da rede Market++: ");
                scanf("%d", &nmr_produtos);
                printf("Informe o numero de filiais da rede de supermercados: ");
                scanf("%d", &nmr_filiais);
                p = (int *)calloc(nmr_produtos * nmr_filiais * trimestre, sizeof(int));
                reclamacoes = (int *)calloc(nmr_produtos * nmr_filiais * trimestre, sizeof(int));
                if (p == NULL || reclamacoes == NULL) {
                    printf("ERRO: Memoria Insuficiente!\n");
                    exit(1);
                }
                printf("Sistema inicializado com sucesso!\n");
                Sleep(1);
                break;
            }

            // Catalogo do sistema
            case 2: {
                system("CLS");
                printf("--------------CATALOGO DO SISTEMA---------------\n");
                if (nmr_produtos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    p1 = (char **)calloc(nmr_produtos, sizeof(char *));
                    if (p1 == NULL) {
                        printf("ERRO: Memoria Insuficiente!\n");
                        exit(1);
                    }

                    for (int i = 0; i < nmr_produtos; i++) {
                        p1[i] = (char *)calloc(tam, sizeof(char));
                        if (p1[i] == NULL) {
                            printf("ERRO: Memoria Insuficiente!");
                            exit(1);
                        }
                        setbuf(stdin, NULL);
                        printf("Informe o nome do produto %d: ", i + 1);
                        fgets(p1[i], tam, stdin);
                        len = strlen(p1[i]);

                        if (p1[i][len - 1] == '\n') {
                            p1[i][len - 1] = '\0';
                        }
                    }
                }
                Sleep(2);
                break;
            }

            // Catalogo de filiais
            case 3: {
                system("CLS");
                printf("--------------CATALOGO DE FILIAIS---------------\n");
                if (nmr_filiais == 0) {
                    printf("Nenhuma filial cadastrada.\n");
                } else {
                    p2 = (char **)calloc(nmr_filiais, sizeof(char *));
                    if (p2 == NULL) {
                        printf("ERRO: Memoria Insuficiente!\n");
                        exit(1);
                    }

                    for (int i = 0; i < nmr_filiais; i++) {
                        p2[i] = (char *)calloc(tam, sizeof(char));
                        if (p2[i] == NULL) {
                            printf("ERRO: Memoria Insuficiente!");
                            exit(1);
                        }
                        setbuf(stdin, NULL);
                        printf("Informe o nome da filial %d: ", i + 1);
                        fgets(p2[i], tam, stdin);
                        len = strlen(p2[i]);

                        if (p2[i][len - 1] == '\n') {
                            p2[i][len - 1] = '\0';
                        }
                    }
                }
                Sleep(2);
                break;
            }

            // Inserir venda de um produto/trimestre
            case 4: {
                system("CLS");
                printf("--------------INSERIR VENDA DE UM PRODUTO/TRIMESTRE---------------\n");
                printf("Informe o numero do trimestre desejado (1 a 4): ");
                scanf(" %d", &n_trimestre);
                if (n_trimestre < 1 || n_trimestre > 4) {
                    printf("Trimestre invalido!\n");
                    Sleep(1);
                    break;
                }

                printf("Informe o nome do produto: ");
                char nome_produto[tam];
                setbuf(stdin, NULL);
                fgets(nome_produto, tam, stdin);

                len = strlen(nome_produto);
                if (nome_produto[len - 1] == '\n') {
                    nome_produto[len - 1] = '\0';
                }

                int existe = 0;
                int indice = -1;
                for (int i = 0; i < nmr_produtos; i++) {
                    if (strcmp(nome_produto, p1[i]) == 0) {
                        existe = 1;
                        indice = i;
                        break;
                    }
                }

                if (!existe) {
                    printf("\nProduto nao esta no catalogo!\n");
                    Sleep(1);
                    break;
                }

                int vendas = 0;
                for (int i = 0; i < nmr_filiais; i++) {
                    printf("\nInforme as vendas para a filial %s no trimestre %d: ", p2[i], n_trimestre);
                    scanf("%d", &vendas);

                    p[(indice * nmr_filiais * trimestre) + (i * trimestre) + n_trimestre - 1] = vendas;
                }

                printf("\nVendas inseridas com sucesso!\n");
                Sleep(1);
                break;
            }

            // Inserir venda de um produto/filial
            case 5: {
                system("CLS");
                printf("--------------INSERIR VENDA DE UM PRODUTO/FILIAL---------------\n");
                printf("Informe o nome da filial: ");
                char nome_filial[tam];
                setbuf(stdin, NULL);
                fgets(nome_filial, tam, stdin);

                len = strlen(nome_filial);
                if (nome_filial[len - 1] == '\n') {
                    nome_filial[len - 1] = '\0';
                }

                printf("Informe o nome do produto: ");
                char nome_produto[tam];
                setbuf(stdin, NULL);
                fgets(nome_produto, tam, stdin);

                len = strlen(nome_produto);
                if (nome_produto[len - 1] == '\n') {
                    nome_produto[len - 1] = '\0';
                }

                int existef = 0;
                int indicef = -1;

                for (int i = 0; i < nmr_filiais; i++) {
                    if (strcmp(nome_filial, p2[i]) == 0) {
                        existef = 1;
                        indicef = i;
                        break;
                    }
                }

                if (!existef) {
                    printf("\nFilial nao esta no catalogo!\n");
                    Sleep(1);
                    break;
                }

                int existe = 0;
                int indice = -1;

                for (int i = 0; i < nmr_produtos; i++) {
                    if (strcmp(nome_produto, p1[i]) == 0) {
                        existe = 1;
                        indice = i;
                        break;
                    }
                }
                if (!existe) {
                    printf("\nProduto nao esta no catalogo!\n");
                    Sleep(1);
                    break;
                }

                int vendas = 0;
                for (int i = 0; i < trimestre; i++) {
                    printf("Informe o numero de vendas do produto %s na filial %s no trimestre %d: ", nome_produto, nome_filial, i + 1);
                    scanf("%d", &vendas);

                    p[(indice * nmr_filiais * trimestre) + (indicef * trimestre) + i] = vendas;
                }

                printf("Vendas inseridas com sucesso!\n");
                Sleep(1);
                break;
            }

            // Produto mais vendido por filial
            case 6: {
                system("CLS");
                printf("--------------PRODUTO MAIS VENDIDO POR FILIAL---------------\n");
                printf("Informe o nome da filial: ");
                char nome_filial[tam];
                setbuf(stdin, NULL);
                fgets(nome_filial, tam, stdin);

                len = strlen(nome_filial);
                if (nome_filial[len - 1] == '\n') {
                    nome_filial[len - 1] = '\0';
                }

                int existef = 0;
                int indicef = -1;

                for (int i = 0; i < nmr_filiais; i++) {
                    if (strcmp(nome_filial, p2[i]) == 0) {
                        existef = 1;
                        indicef = i;
                        break;
                    }
                }

                if (!existef) {
                    printf("\nFilial nao esta no catalogo!\n");
                    system("pause");
                    break;
                }

                int maisVendido = -1, maior = -1, total;

                for (int i = 0; i < nmr_produtos; i++) {
                    total = 0;
                    for (int j = 0; j < trimestre; j++) {
                        total += p[(i * nmr_filiais * trimestre) + (indicef * trimestre) + j];
                    }
                    if (total > maior) {
                        maior = total;
                        maisVendido = i;
                    }
                }

                printf("O produto mais vendido na filial %s e: %s\n", nome_filial, p1[maisVendido]);
                system("pause");
                break;
            }

            // Mais vendido por filial
            // Mais vendido por filial
            case 7: 
            {
                system("CLS");
                printf("--------------FILIAL QUE MAIS VENDE PRODUTOS EM UM TRIMESTRE---------------\n");
                printf("Informe o trimestre desejado (1 a 4): ");
                int tri_desejado;
                scanf("%d", &tri_desejado);

                if (tri_desejado < 1 || tri_desejado > 4) {
                    printf("Trimestre invalido!\n");
                    system("pause");
                    break;
                }

                int maisVendido = -1, maior = -1, total;

                for (int i = 0; i < nmr_filiais; i++) {
                    total = 0;
                    for (int j = 0; j < nmr_produtos; j++) {
                        total += p[(j * nmr_filiais * trimestre) + (i * trimestre) + (tri_desejado - 1)];
                    }
                    if (total > maior) {
                        maior = total;
                        maisVendido = i;
                    }
                }

                printf("A filial que mais vendeu produtos no trimestre %d e: %s\n", tri_desejado, p2[maisVendido]);
                system("pause");
                break;
            }


            // Produto mais vendido
            case 8: {
                system("CLS");
                printf("--------------PRODUTO MAIS VENDIDO---------------\n");
                int maisVendido = -1, maior = -1, total;

                for (int i = 0; i < nmr_produtos; i++) {
                    total = 0;
                    for (int j = 0; j < nmr_filiais; j++) {
                        for (int k = 0; k < trimestre; k++) {
                            total += p[(i * nmr_filiais * trimestre) + (j * trimestre) + k];
                        }
                    }
                    if (total > maior) {
                        maior = total;
                        maisVendido = i;
                    }
                }

                printf("O produto mais vendido e: %s\n", p1[maisVendido]);
                system("pause");
                break;
            }

            // Filial que mais vende
            case 9: {
                system("CLS");
                printf("--------------FILIAL QUE MAIS VENDE---------------\n");
                int maisVendido = -1, maior = -1, total;

                for (int i = 0; i < nmr_filiais; i++) {
                    total = 0;
                    for (int j = 0; j < nmr_produtos; j++) {
                        for (int k = 0; k < trimestre; k++) {
                            total += p[(j * nmr_filiais * trimestre) + (i * trimestre) + k];
                        }
                    }
                    if (total > maior) {
                        maior = total;
                        maisVendido = i;
                    }
                }

                printf("A filial que mais vende e: %s\n", p2[maisVendido]);
                system("pause");
                break;
            }

            // Melhor trimestre
            case 10: {
                system("CLS");
                printf("--------------MELHOR TRIMESTRE---------------\n");
                int melhorTrimestre = -1, maior = -1, total;

                for (int i = 0; i < trimestre; i++) {
                    total = 0;
                    for (int j = 0; j < nmr_produtos; j++) {
                        for (int k = 0; k < nmr_filiais; k++) {
                            total += p[(j * nmr_filiais * trimestre) + (k * trimestre) + i];
                        }
                    }
                    if (total > maior) {
                        maior = total;
                        melhorTrimestre = i + 1; // Trimestres são de 1 a 4
                    }
                }

                printf("O melhor trimestre e: Trimestre %d\n", melhorTrimestre);
                system("pause");
                break;
            }

            // Inserir novo produto
            case 11: {
                system("CLS");
                printf("--------------INSERIR NOVO PRODUTO---------------\n");
                if (nmr_produtos == 0) {
                    printf("ERRO: Inicialize o sistema primeiro!\n");
                    system("pause");
                    break;
                }

                p1 = (char **)realloc(p1, (nmr_produtos + 1) * sizeof(char *));
                if (p1 == NULL) {
                    printf("ERRO: Memoria Insuficiente!\n");
                    exit(1);
                }

                p1[nmr_produtos] = (char *)calloc(tam, sizeof(char));
                if (p1[nmr_produtos] == NULL) {
                    printf("ERRO: Memoria Insuficiente!");
                    exit(1);
                }

                setbuf(stdin, NULL);
                printf("Informe o nome do novo produto: ");
                fgets(p1[nmr_produtos], tam, stdin);
                len = strlen(p1[nmr_produtos]);

                if (p1[nmr_produtos][len - 1] == '\n') {
                    p1[nmr_produtos][len - 1] = '\0';
                }

                nmr_produtos++;
                printf("\nNovo produto inserido com sucesso!\n");
                system("pause");
                break;
            }

            // Inserir nova filial
            case 12: {
                system("CLS");
                printf("--------------INSERIR NOVA FILIAL---------------\n");
                if (nmr_filiais == 0) {
                    printf("ERRO: Inicialize o sistema primeiro!\n");
                    system("pause");
                    break;
                }

                p2 = (char **)realloc(p2, (nmr_filiais + 1) * sizeof(char *));
                if (p2 == NULL) {
                    printf("ERRO: Memoria Insuficiente!\n");
                    exit(1);
                }

                p2[nmr_filiais] = (char *)calloc(tam, sizeof(char));
                if (p2[nmr_filiais] == NULL) {
                    printf("ERRO: Memoria Insuficiente!");
                    exit(1);
                }

                setbuf(stdin, NULL);
                printf("Informe o nome da nova filial: ");
                fgets(p2[nmr_filiais], tam, stdin);
                len = strlen(p2[nmr_filiais]);

                if (p2[nmr_filiais][len - 1] == '\n') {
                    p2[nmr_filiais][len - 1] = '\0';
                }

                nmr_filiais++;
                printf("\nNova filial inserida com sucesso!\n");
                system("pause");
                break;
            }

            // Remover produto
            case 13: {
                system("CLS");
                printf("--------------REMOVER PRODUTO---------------\n");
                if (nmr_produtos == 0) {
                    printf("ERRO: Inicialize o sistema primeiro!\n");
                    system("pause");
                    break;
                }

                printf("Informe o nome do produto a ser removido: ");
                char nome_produto[tam];
                setbuf(stdin, NULL);
                fgets(nome_produto, tam, stdin);

                len = strlen(nome_produto);
                if (nome_produto[len - 1] == '\n') {
                    nome_produto[len - 1] = '\0';
                }

                int indice = -1;
                for (int i = 0; i < nmr_produtos; i++) {
                    if (strcmp(nome_produto, p1[i]) == 0) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    printf("\nProduto nao encontrado!\n");
                    Sleep(1);
                    break;
                }

                // Move os produtos restantes para preencher o espaço do produto removido
                for (int i = indice; i < nmr_produtos - 1; i++) {
                    strcpy(p1[i], p1[i + 1]);
                }

                // Realoca o vetor de produtos para a nova quantidade
                p1 = (char **)realloc(p1, (nmr_produtos - 1) * sizeof(char *));
                if (p1 == NULL) {
                    printf("ERRO: Memoria Insuficiente!\n");
                    exit(1);
                }

                nmr_produtos--;
                printf("\nProduto removido com sucesso!\n");
                system("pause");
                break;
            }

            //Registrar reclamacao
            case 14: 
            {
                system("CLS");
                printf("--------------REGISTRAR RECLAMACAO DO CLIENTE---------------\n");
                
                if (reclamacoes == NULL) {
                    printf("ERRO: Memoria Insuficiente!\n");
                    exit(1);
                }

                printf("Informe o nome do produto: ");
                char nome_produto[tam];
                setbuf(stdin, NULL);
                fgets(nome_produto, tam, stdin);

                len = strlen(nome_produto);
                if (nome_produto[len - 1] == '\n') {
                    nome_produto[len - 1] = '\0';
                }

                int existe_produto = 0;
                int indice = -1;
                for (int i = 0; i < nmr_produtos; i++) {
                    if (strcmp(nome_produto, p1[i]) == 0) {
                        existe_produto = 1;
                        indice = i;
                break;
                    }
                }

                if (!existe_produto) {
                printf("\nProduto nao encontrado!\n");
                system("pause");
                break;
                }

            printf("Informe o nome da filial: ");
            char nome_filial[tam];
            setbuf(stdin, NULL);
            fgets(nome_filial, tam, stdin);

                len = strlen(nome_filial);
                if (nome_filial[len - 1] == '\n') {
                nome_filial[len - 1] = '\0';
                }

                int existe_filial = 0;
                int indicef = -1;
                for (int i = 0; i < nmr_filiais; i++) {
                    if (strcmp(nome_filial, p2[i]) == 0) {
                    existe_filial = 1;
                    indicef = i;
                    break;
                    }
                }

                if (!existe_filial) {
                    printf("\nFilial nao encontrada!\n");
                    system("pause");
                    break;
                }

            printf("Informe o trimestre (1 a 4) em que ocorreu a reclamacao: ");
            int trimestre_reclamacao;
            scanf("%d", &trimestre_reclamacao);

                if (trimestre_reclamacao < 1 || trimestre_reclamacao > 4) {
                printf("Trimestre invalido!\n");
                system("pause");
                break;
                }

            reclamacoes[(indice * nmr_filiais * trimestre) + (indicef * trimestre) + (trimestre_reclamacao - 1)]++;

                printf("\nReclamacao registrada com sucesso!\n");
                system("pause");
                break;
            }

         //Conta as reclamações e informa em quais filiais e trimestres isso ocorreu
            case 15: 
            {
                system("CLS");
                printf("----------Numero de Reclamacoes Registradas----------\n");

                int totalReclamacoes = 0;

                for (int i = 0; i < nmr_produtos; i++) {
                    for (int j = 0; j < nmr_filiais; j++) {
                        for (int k = 0; k < trimestre; k++) {
                            int indice = (i * nmr_filiais * trimestre) + (j * trimestre) + k;
                            int reclamacao = reclamacoes[indice];

                            if (reclamacao > 0) {
                                printf("Reclamacao registrada para o produto '%s', na filial '%s', trimestre '%d'.\n", p1[i], p2[j], k + 1);
                                totalReclamacoes += reclamacao;
                            }
                        }
                    }
                }

                if (totalReclamacoes == 0) {
                    printf("Nenhuma reclamacao registrada.\n");
                } else {
                    printf("Total de reclamacoes registradas: %d\n", totalReclamacoes);
                }

                system("pause");
                break;
            }

            // SAIR
            case 16: 
            {
                system("CLS");
                printf("Saindo do sistema...\n");
                Sleep(2);
                break;
            }

            default: {
                printf("Opcao invalida! Tente novamente.\n");
                system("pause");
            }
        }
    } while (op != 16);

    // Liberar a memória alocada
    if(reclamacoes != NULL) {
        free(reclamacoes);
    }

    if (p1 != NULL) {
        for (int i = 0; i < nmr_produtos; i++) {
            free(p1[i]);
        }
        free(p1);
    }

    if (p2 != NULL) {
        for (int i = 0; i < nmr_filiais; i++) {
            free(p2[i]);
        }
        free(p2);
    }

    if (p != NULL) {
        free(p);
    }

    return 0;
}
