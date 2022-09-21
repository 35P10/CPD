#include <iostream>
#include "../helpers/matrix/matrix_2d_pointer_generator.hpp"
#include "../helpers/my_classes/timer.hpp" 

int **A, **B, **C;

int main(int argc, char**argv){
    int N=std::atoi(argv[1]);
    Timer timer01;

    matrix_2d_ptr__create_and_fill__random_values(A,N,N,1,5);
    matrix_2d_ptr__create_and_fill__random_values(B,N,N,1,5);
    matrix_2d_ptr__create_and_fill__0s(C,N,N);

    timer01.start();
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
    timer01.stop();
}