#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 10

int lista[tamanho] = {3, 1, 8, 7, 20, 21, 31, 40, 30, 0};
int ordenado[tamanho];
int opt=-1;
int qtd, res;

void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
int lista_limpar(void);
void lista_mostrar_ordenado(int qtd);

int bubbleSort(int vec[]);
int selectionSort(int vec[], int tam);
int insertionSort(int vec[], int tam);
void troca(int *a, int *b);


int main(){
    srand(time(NULL));
    for(int i = 0; i< tamanho; i++){
        ordenado[i] = lista [i];
    }
    do{
        system("cls");
        lista_mostrar();
        lista_mostrar_ordenado(res);
        menu_mostrar();
        scanf("%d", &opt);
        fflush(stdin);
        switch(opt){
            case 1:
                lista_gerar();
            break;
            case 2:
                lista_ler();
            break;
            case 3:
                res = lista_limpar();
                lista_mostrar_ordenado(res);
                //system("cls");
            break;
            case 4:
                res = bubbleSort(ordenado);
            break;
            case 5:
                res = selectionSort(ordenado, tamanho);
            break;
            case 6:
                res = insertionSort(ordenado, tamanho);
            break;
        }

    }while(opt != 0 );
    system("pause");

    return 0;
}

void lista_mostrar(void){
    printf("[ ");
    for(int i=0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
    printf(" ]");
}

void menu_mostrar(void){
 printf("1 - Gerar lista aleatoriamente\n");
 printf("2 - Criar lista manualmente\n");
 printf("3 - desfazer ordenacao\n");
 printf("4 - Ordenar lista com bubbleSort\n");
 printf("5 - Ordenar lista com selectionSort\n");
 printf("6 - Ordenar lista com insertionSort\n");
 printf("0 - Sair...\n\n");
}

void lista_gerar(void){
    for(int i=0; i< tamanho; i++){
        ordenado[i] = rand()%50;
    }
}

void lista_ler(void){
    for(int i=0; i < tamanho; i++){
        system("cls");
        lista_mostrar();
        printf("\nDigite o valor para a posicao %d ", i);
        scanf("%d", &lista[i]);
        fflush(stdin);
    }
}

int lista_limpar(void){
    for(int i=0; i<tamanho; i++){
        ordenado[i] = lista[i];
    }
    int qtd = 0;
    return qtd;
}

void lista_mostrar_ordenado(int qtd){
    printf("[ ");
    for (int i = 0; i < tamanho; i++ ){
        printf("%d ",ordenado[i]);
    }
    printf("] Tempo = %d iteracoes\n\n", qtd);
}

int bubbleSort(int vec[]){
    int qtd, i, j, tmp;
    qtd = 0;

    for(i = 0; i < tamanho -1; i++){
        for(j =i+1; j < tamanho; j++){
            if(vec[i] > vec[j]){
                troca(&vec[i], &vec[j]);
                qtd++;
            }
        }
    }
    return qtd;
}

int selectionSort(int vec[], int tam){
    int i, j, min, qtd;
    qtd = 0;

    for(i=0; i < tam-1;i++){
        min = i;

        for(j=i+1; j < tam; j++){
            if(vec[min] > vec[j]){
                min = j;
            }
            qtd++;
        }

        if(i != min){
            troca(&vec[i], &vec[min]);
        }
    }
    return qtd;

}

int insertionSort(int vec[], int tam){
    int i, j, qtd=0;

    for(i=1; i<tam; i++){
        j = i;
        while((vec[j] < vec[j-1]) && (j!=0)){
            troca(&vec[j], &vec[j-1]);
            j--;
            qtd++;
        }
    }
    return qtd;
}

void troca(int* a, int* b){
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

}
