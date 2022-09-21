#include <iostream>
#include "../helpers/matrix/matrix_2d_pointer_generator.hpp"
#include "../helpers/my_classes/timer.hpp"

int **A, **B, **C;

int main(int argc, char**argv){
    int N=std::atoi(argv[1]);
    Timer timer01; 
    int blocksize=N/2;

    matrix_2d_ptr__create_and_fill__random_values(A,N,N,1,5);
    matrix_2d_ptr__create_and_fill__random_values(B,N,N,1,5);
    matrix_2d_ptr__create_and_fill__0s(C,N,N);
    
    timer01.start();
    for (int ii = 0; ii < N; ii+=blocksize)
        for (int jj = 0; jj < N; jj+=blocksize)
            for (int kk = 0; kk < N; kk+=blocksize)
                for (int i = ii; i < ii+blocksize; i++)
                    for (int j = jj; j < jj+blocksize; j++)
                        for (int k = kk; k < kk+blocksize; k++)
                            *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
    timer01.stop();
}