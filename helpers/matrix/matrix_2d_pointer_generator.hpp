#include <iostream>
#include <stdlib.h>
#include <time.h>       

void matrix_2d_ptr__create(int **&M, int rows, int cols){
    M = new int *[rows];
    for(int i=0 ; i < rows ; i++)
        *(M+i)= new int [cols];
}

void matrix_2d_ptr__create_and_fill__0s(int **&M, int rows, int cols){
    M = new int *[rows];
    for(int i=0 ; i < rows ; i++)
        *(M+i)= new int [cols]();
}

void matrix_2d_ptr__print(int **&M, int rows, int cols){
    for(int i=0 ; i < rows ; i++){
        for(int j=0 ; j < cols ; j++)
            std::cout <<"\t"<< *(*(M+i)+j);
        std::cout << std::endl;
    }
}

void matrix_2d_ptr__fill__input(int **&M, int rows, int cols){
    for(int i=0 ; i < rows ; i++){
        for(int j=0 ; j < cols ; j++){
            std::cin>>*(*(M+i)+j);
        }
    }
}

void matrix_2d_ptr__fill__random_values(int **&M, int rows, int cols, int rand_range_floor, int rand_range_ceil){
    srand (time(NULL));
    int rand_range_lenght = rand_range_ceil-rand_range_floor+1;
    for(int i=0 ; i < rows ; i++){
        for(int j=0 ; j < cols ; j++){
            *(*(M+i)+j) = rand() % rand_range_lenght + rand_range_floor;
        }
    }
}

void matrix_2d_ptr__create_and_fill__random_values(int **&M, int rows, int cols, int rand_range_floor, int rand_range_ceil){
    srand (time(NULL));
    int rand_range_lenght = rand_range_ceil-rand_range_floor+1;
    M = new int *[rows];
    for(int i = 0; i < rows ; i++){ 
        *(M+i)= new int [cols]();
        for(int j=0 ; j < cols ; j++)  
            *(*(M+i)+j) = rand() % rand_range_lenght + rand_range_floor;
    }
}
