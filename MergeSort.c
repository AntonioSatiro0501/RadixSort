// Nome: Antonio Costa Satiro de Souza Ra: 10723636

#include <stdio.h>
#define TAM_MAX_VETOR = 100000
int AuxiliarMerge[];


void mergeSort(int vetor[],int esquerda, int direita){

    int meio = (direita + esquerda) / 2;
    if (esquerda >= direita) return;
    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio + 1, direita);
    merge(vetor, esquerda, meio, direita);
}

void merge(char vetor[], int esquerda, int meio, int direita){
    
    int i, j, k;

    for(i = meio + 1; i > esquerda; i-- ) AuxiliarMerge[i - 1] = vetor[i - 1];
    for(j = meio; j < direita; j++) AuxiliarMerge[direita + meio - j] = vetor[j + 1];
    for(k = esquerda; k <= direita; k++){
        if(AuxiliarMerge[j] < AuxiliarMerge[i]){
            vetor[k] = AuxiliarMerge[j--];
        }else vetor[k] = AuxiliarMerge[i++];
    }
}

int maior(int vetor[]){

    int aux = vetor[0];
    for(int i=0; i < tamanho(vetor); i++){
        if(vetor[i] > aux){
            aux = vetor[i];
        }
    }

    return aux;

}

int tamanho(int vetor[]){

    int tam = (sizeof(vetor) / sizeof(vetor[0]));
    return tam;
}