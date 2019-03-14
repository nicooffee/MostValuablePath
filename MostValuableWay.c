#include <stdio.h>
#include <stdlib.h>
#include "matrixInteger.h"

int **values;
int **ways;
void setWayValues(int n,int m);
int **bestWay(int n,int m);
void printWay(int n,int m,int **W);

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int **W=NULL;
    createMatrix(&ways,n,m);
    createRandomMatrix(&values,n,m,10);
    if(m<=59 && n<=59){
        printMatrix(values,n,m);
        printf("\n");
        printMatrix(ways,n,m);
        setWayValues(n,m);
        printf("\nResultados: \n");
        W=bestWay(n,m);
        printf("\n");
        printWay(n,m,W);
    }
    else{
        setWayValues(n,m);
        printf("\nResultados: \n");
        W=bestWay(n,m);
        printf("\n");
        printf("Valor mayor: %d\n",ways[n-1][m-1]);
    }
    freeMatrix(ways,n,m);
    freeMatrix(values,n,m);
    freeMatrix(W,n,m);
    printf("\E[00m");
    return 0;
}

void setWayValues(int n,int m){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(i==0 && j==0)    ways[i][j]=values[i][j];
            else if(i==0)    ways[i][j]=values[i][j]+ways[i][j-1];
            else if(j==0)   ways[i][j]=values[i][j]+ways[i-1][j];
            else    ways[i][j]=values[i][j]+(ways[i-1][j]>ways[i][j-1]?ways[i-1][j]:ways[i][j-1]);
    return;
}

int **bestWay(int n,int m){
    int **wayFlag;
    int i=n-1,j=m-1;
    createMatrix(&wayFlag,n,m);
    wayFlag[i][j]=1;
    wayFlag[0][0]=1;
    while(i!=0 || j!=0){
        if(i!=0 && j!=0){
            ways[i][j]==(ways[i-1][j]+values[i][j])?i--:j--;
            wayFlag[i][j]=1;
        }
        else if(i==0)   wayFlag[i][--j]=1;
        else if(j==0)   wayFlag[--i][j]=1;
    }
    return wayFlag;
}

void printWay(int n,int m,int **W){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(W[i][j])   printf("\E[42m%3d ",ways[i][j]);
            else    printf("\E[00m%3d ",ways[i][j]);
        printf("\n");
    }
    return;
}