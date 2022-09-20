#include <iostream>
#include "../helpers/matrix/matrix_2d_pointer_generator.hpp"

int **A, **B, **C;

int main(){
    int N;
    std::cin>>N;

    matrix_2d_ptr__create_and_fill__random_values(A,N,N,1,5);
    matrix_2d_ptr__create_and_fill__random_values(B,N,N,1,5);
    matrix_2d_ptr__create_and_fill__0s(C,N,N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
    
    matrix_2d_ptr__print(C,N,N);
}