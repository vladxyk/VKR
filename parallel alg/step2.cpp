#include <iostream>
#include "header.hpp"
#include <omp.h>

using namespace std;

void step2(double *matrix, int n){ //min_value_col
   
    int min;
    double min_value_col[n];
    //omp_set_num_threads(n);
    #pragma omp parallel for private(min, min_value_col)
    for(int j = 0; j < n; j++){
        min = matrix[j];
        //#pragma omp critical
        for(int i = 0; i < n; i++){
            if(matrix[i * n + j] < min){
               min = matrix[i * n + j];
            }
            min_value_col[j] = min;
        }
    }
    
    #pragma omp parallel for private(min, min_value_col)
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            matrix[i * n + j] -= min_value_col[j];
        }
    }

}