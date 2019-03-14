#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixInteger.h"

void createMatrix(int ***M,int n,int m){
    int i;
    (*M)=(int**) calloc(n,sizeof(int *));
    for(i=0;i<n;i++)
        (*M)[i]=(int*) calloc(m,sizeof(int));
    return;
}

void createRandomMatrix(int ***M,int n,int m,int rMax){
    int i,j;
    srand(time(NULL));
    (*M)=(int**) calloc(n,sizeof(int *));
    for(i=0;i<n;i++){
        (*M)[i]=(int*) calloc(m,sizeof(int));
        for(j=0;j<m;j++)
            (*M)[i][j]=rand()%rMax;
    }
    return;
}
void printMatrix(int **M,int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%3d ",M[i][j]);
        printf("\n");
    }
    return;
}

void freeMatrix(int **M,int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        free(M[i]);
    }
    free(M);
    return;
}