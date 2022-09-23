#include "../helpers/matrix/matrix_2d_pointer_generator.hpp" 
#include <iostream>
#include <math.h>

void matrix__rotation_NxN_clockwise(int **&M,int N){
    for(int i=1,k=0;i<N+1;i++,k++){
       for(int j=N-i;j>-1;j--)
            std::swap(*(*(M+j)+(N-i)),*(*(M+k)+j));
    }
    for(int i=1;i<ceil(N/2.0);i++){
        for(int j=i;j<N-i;j++)
            std::swap(*(*(M+j)+(i-1)),*(*(M+N-i)+j));
    }
}

void matrix__rotation_NxN_counterclockwise(int **&M,int N){
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++)
            std::swap(*(*(M+i)+j),*(*(M+N-j-1)+i));
    }
    for(int i=1;i<ceil(N/2.0);i++){
        for(int j=i;j<N-i;j++)
            std::swap(*(*(M+N-i)+j),*(*(M+N-j-1)+(N-i)));
    }
}

int main(){
    int **M;
    int N;
    std::cout<<"Matrix size: ";
    std::cin>>N;
    int op=1;
    matrix_2d_ptr__create_and_fill__random_values(M,N,N,1,5);
    std::cout<<"Matrix:\n";
    matrix_2d_ptr__print(M,N,N);
    while(true){
        std::cout<<"Entry:\n1 -> Clockwise rotation\n2 -> Counterclockwise rotation\nEntry: ";
        std::cin>>op;
        if(op==1){
            matrix__rotation_NxN_clockwise(M,N);
        }
        else if(op==2){
            matrix__rotation_NxN_counterclockwise(M,N);
        }
        else {
            break;
        }
        std::cout<<"Rotation:\n";
        matrix_2d_ptr__print(M,N,N);
    }
}