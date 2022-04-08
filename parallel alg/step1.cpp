#include <iostream>
#include "header.hpp"
#include <omp.h>

using namespace std;

void step1(double *matrix, int n){ //min_value_row

    int min;
    double min_value_row[n];
    //omp_set_num_threads(n);
    #pragma omp parallel for private(min, min_value_row)
        for(int i = 0; i < n; i++){
            min = matrix[i * n];
            //#pragma omp critical
            for(int j = 0; j < n; j++){
                if(matrix[i * n + j] < min){
                    min = matrix[i * n + j];
                }
                min_value_row[i] = min;
            }
        }

    #pragma omp parallel for private(min, min_value_row)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i * n + j] -= min_value_row[i];
        }
    }


}