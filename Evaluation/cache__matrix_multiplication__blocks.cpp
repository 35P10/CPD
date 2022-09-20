#include <iostream>
#include "../helpers/matrix/matrix_2d_pointer_generator.hpp"

int **A, **B, **C;

int main(){
    int N;
    std::cin>>N;    

    matrix_2d_ptr__create_and_fill__random_values(A,N,N,1,5);
    matrix_2d_ptr__create_and_fill__random_values(B,N,N,1,5);
    matrix_2d_ptr__create_and_fill__0s(C,N,N);

    int blocksize=N/2;
    for (int ii = 0; ii < N; ii+=blocksize)
        for (int jj = 0; jj < N; jj+=blocksize)
            for (int kk = 0; kk < N; kk+=blocksize)
                for (int i = ii; i < ii+blocksize; i++)
                    for (int j = jj; j < jj+blocksize; j++)
                        for (int k = kk; k < kk+blocksize; k++)
                            *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);

    matrix_2d_ptr__print(C,N,N);
}