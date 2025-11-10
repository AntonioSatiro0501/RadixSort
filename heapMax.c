// Nome: Antonio Costa Satiro de Souza Ra: 10723636

#include <stdio.h>

void troca(int *x, int *y){
    int troc = *x;
    *x = *y;
    *y = troc;
}

void avaliaArvore (int lista[], int tamanho, int maior){

    int aux = maior;
    int galhoEsq = maior*2 + 1;
    int galhoDir = maior*2 + 2; 

    if(galhoEsq < tamanho){

        if(lista[aux] < lista[galhoEsq]){
            aux = galhoEsq;
        }

        if(galhoDir < tamanho && lista[aux] < lista[galhoDir]){
            aux = galhoDir;
        }

        if(aux != maior){
            troca(&lista[maior], &lista[aux]);
            avaliaArvore(lista, tamanho, aux);
        }
    }
}

void heapMax(int tamanho, int lista[]) {

    for(int f = (tamanho -1)/2; f >= 0; f-- ){
        avaliaArvore(lista, tamanho, f);
    }
}

