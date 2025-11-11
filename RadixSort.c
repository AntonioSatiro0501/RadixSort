// Nome: Antonio Costa Satiro de Souza Ra: 10723636

#include <stdio.h>
#define TAM_MAX_VETOR 100000
int AuxiliarMerge[TAM_MAX_VETOR];

void merge(int vetor[], int esquerda, int meio, int direita, int casaDecimal){
    int i, j, k;

    for(i = meio + 1; i > esquerda; i-- ) AuxiliarMerge[i - 1] = vetor[i - 1];
    for(j = meio; j < direita; j++) AuxiliarMerge[direita + meio - j] = vetor[j + 1];
    for(k = esquerda; k <= direita; k++){

        int ajusteJ = (AuxiliarMerge[j] / casaDecimal) % 10;
        int ajusteI = (AuxiliarMerge[i] / casaDecimal) % 10;

        if(ajusteJ < ajusteI){
            vetor[k] = AuxiliarMerge[j--];
        }else vetor[k] = AuxiliarMerge[i++];
    }
}

void mergeSort(int vetor[],int esquerda, int direita, int casaDecimal){
    int meio = (direita + esquerda) / 2;
    if (esquerda >= direita) return;
    mergeSort(vetor, esquerda, meio, casaDecimal);
    mergeSort(vetor, meio + 1, direita, casaDecimal);
    merge(vetor, esquerda, meio, direita, casaDecimal);
}

int maior(int vetor[], int tam){

    int aux = vetor[0];
    for(int i=0; i < tam; i++){
        if(vetor[i] > aux){
            aux = vetor[i];
        }
    }

    return aux;

}

void radixSort(int vetor[], int tamanho){

    int m = maior(vetor, tamanho);

    for (int casa = 1; m / casa > 0; casa *= 10){
        mergeSort(vetor, 0, tamanho - 1, casa);
    }
}

int main(void) {
    int array [] = {14, 2, 6, 8, 5, 4, 3, 1, 7, 9, 6, 10, 17, 20, 12, 19};
    int n = sizeof(array) / sizeof(array[0]);
    radixSort(array, n);

    printf("[");
    for(int i =0; i < n ; i++ ){
        printf("%d", array[i]);
        if(i < n-1){
            printf(", ");
        }
    }
    printf("]");
}