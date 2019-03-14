#include <stdio.h>
#include <stdlib.h>
#include "matrixInteger.h"

int **values;
int **paths;
void setWayValues(int n,int m);
int **bestPath(int n,int m);
void printPath(int n,int m,int **W);

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int **W=NULL;
    createMatrix(&paths,n,m);
    createRandomMatrix(&values,n,m,10);
    if(m<=59 && n<=59){
        printMatrix(values,n,m);
        printf("\n");
        printMatrix(paths,n,m);
        setWayValues(n,m);
        printf("\nResultados: \n");
        W=bestPath(n,m);
        printf("\n");
        printPath(n,m,W);
    }
    else{
        setWayValues(n,m);
        printf("\nResultados: \n");
        W=bestPath(n,m);
        printf("\n");
        printf("Valor mayor: %d\n",paths[n-1][m-1]);
    }
    freeMatrix(paths,n,m);
    freeMatrix(values,n,m);
    freeMatrix(W,n,m);
    printf("\E[00m");
    return 0;
}

void setWayValues(int n,int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(i==0 && j==0)    paths[i][j]=values[i][j];
            else if(i==0)    paths[i][j]=values[i][j]+paths[i][j-1];
            else if(j==0)   paths[i][j]=values[i][j]+paths[i-1][j];
            else    paths[i][j]=values[i][j]+(paths[i-1][j]>paths[i][j-1]?paths[i-1][j]:paths[i][j-1]);
    return;
}

int **bestPath(int n,int m){
    int **wayFlag;
    int i=n-1,j=m-1;
    createMatrix(&wayFlag,n,m);
    wayFlag[i][j]=1;
    wayFlag[0][0]=1;
    while(i!=0 || j!=0){
        if(i!=0 && j!=0){
            paths[i][j]==(paths[i-1][j]+values[i][j])?i--:j--;
            wayFlag[i][j]=1;
        }
        else if(i==0)   wayFlag[i][--j]=1;
        else if(j==0)   wayFlag[--i][j]=1;
    }
    return wayFlag;
}

void printPath(int n,int m,int **W){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(W[i][j])   printf("\E[42m%3d ",paths[i][j]);
            else    printf("\E[00m%3d ",paths[i][j]);
        printf("\n");
    }
    return;
}