#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define altura 5
#define largura 10

typedef struct {
    int dia, mes, ano;
} data;

typedef struct{
    int X, Y, intensidade;
    data d;
} raio;

int main(){
    raio r;
    char cidade[altura][largura];
    char *p = &cidade;
    int op = 0, contaRaios = 0, SemRaio = altura * largura;
    //cidade sem nenhum raio
    for(int i = 0; i < altura; i++){
        printf("\n");
        for(int j = 0; j < largura; j++){
            *(p + i * largura + j) = 'O';
        }
    }
    do{
        system("CLS");
        printf("\nMENU\n\n(1) Marcar Raio\n(2) Quantos raios ja cairam\n(3) Quantas areas nao foram afetadas por raio\n(4) Imprimir Matriz\n(5) Sair\n\nDigite uma das opcoes: ");
        scanf("%d", &op);
        system("CLS");

        switch(op){
            case 1:
                printf("\nMARCAR RAIO\n\nDigite a coordenada X onde caiu o raio: "); scanf("%d", &r.X);
                printf("Digite a coordenada Y onde caiu o raio: "); scanf("%d", &r.Y);
                printf("Digite a data da queda do raio no formato dd/mm/aaaa: "); scanf("%d/%d/%d", &r.d.dia, &r.d.mes, &r.d.ano);
                printf("Digite a intensidade do raio: "); scanf("%d", &r.intensidade);
                //conferir se ja caiu raio na regiao
                if(cidade[r.X][r.Y] == 'X'){
                    system("CLS");
                    printf("Dois raios cairam no mesmo lugar!!");
                    exit(1);
                }
                //Marcar com X onde caiu raio
                cidade[r.X][r.Y] = 'X';
                system("CLS");
                printf("Raio marcado com sucesso!");
                contaRaios++;
                SemRaio--;
                sleep(3);
                break;
            case 2:
                system("CLS");
                printf("Cairam %d raios na cidade!", contaRaios);
                sleep(3);
                break;
            case 3:
                system("CLS");
                printf("%d areas nao foram afetadas por raios!", SemRaio);
                sleep(3);
                break;
            case 4:
                system("CLS");
                printf("Mapa de areas afetadas:\n");
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        printf("%c ", *(p + i * largura + j));
                    }
                    printf("\n");
                }
                system("pause");
                getchar();
                break;
            case 5:
                system("CLS");
                printf("Saindo...");
                sleep(3);
                break;
            default:
                printf("Opcao Invalida!");
                sleep(3);
                break;
        }
    }while(op !=5);
}
