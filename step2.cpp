#include <iostream>

using namespace std;

void min_value_col(double *matrix, int n){
    
    int min;
    double min_value_col[n];
    for(int j = 0; j < n; j++){
        min = matrix[j];
        for(int i = 0; i < n; i++){
            if(matrix[i * n + j] < min){
               min = matrix[i * n + j];
            }
            min_value_col[j] = min;
        }
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            matrix[i * n + j] -= min_value_col[j];
        }
    }

}