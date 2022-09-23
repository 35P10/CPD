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

int main(){
    int **M;
    int N;
    std::cout<<"Matrix size: ";
    std::cin>>N;
    int op=1;
    matrix_2d_ptr__create_and_fill__random_values(M,N,N,1,5);
    std::cout<<"Matrix:\n";
    matrix_2d_ptr__print(M,N,N);
    while(op==1){
        std::cout<<"Rotation:\n";
        matrix__rotation_NxN_clockwise(M,N);
        matrix_2d_ptr__print(M,N,N);
        std::cout<<"Entry = 1 -> Clockwise rotation:\nEntry: ";
        std::cin>>op;
    }
}