#include <iostream>
#include "../helpers/my_classes/timer.hpp" 

const int n=7500;
int A[n][n],x[n], y[n];

int main(){
    Timer timer01;
    int op;

    std::cin>>op;
    //inicializar matrices
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            A[i][j]=0;
    }
    for(int i=0;i<n;i++)
        x[i]=0;

    timer01.start();
    if(op==1){
        //bucle 1: recorrido por filas
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                y[i]+=A[i][j]*x[j];
        }
    }
    else if(op==2){
        //bucle 2: recorrido por columnas
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++)
                y[i]+=A[i][j]*x[j];
        }
    }
    timer01.stop();
}