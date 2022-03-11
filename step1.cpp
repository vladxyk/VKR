#include <iostream>
#include "header.hpp"

using namespace std;

int step1(double *matrix, int n, int *arrRowIndex, double *arrValue, int *arrCol, int NZ){ //min_value_row

    int minValue;
    for(int i = n; i > 0; i--){
        if((arrRowIndex[i] - arrRowIndex[i - 1]) == n){
            minValue = arrValue[arrRowIndex[i - 1]]; 
            for(int j = 0; j < n; j++){
                if(arrValue[arrRowIndex[i - 1] + j] < minValue){
                    minValue = arrValue[arrRowIndex[i - 1] + j];
                }
            }
            for(int k = 0; k < n; k++){
                arrValue[(i - 1) + k] -= minValue; 
                matrix[(i - 1) * n + k] -= minValue;
            }
            minValue = 0;
            CSR_arr_row_index(arrRowIndex, matrix, n);
            NZ = arrRowIndex[n];
            CSR_arr_value(arrValue, matrix, n);
            CSR_arr_col(arrCol, matrix, n, NZ);

        }
    }
    return NZ;

/*
    int min;
    double min_value_row[n];
    for(int i = 0; i < n; i++){
        min = matrix[i * n];
        for(int j = 0; j < n; j++){
            if(matrix[i * n + j] < min){
                min = matrix[i * n + j];
            }
            min_value_row[i] = min;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i * n + j] -= min_value_row[i];
        }
    }
*/

}