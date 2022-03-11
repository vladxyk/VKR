#include <iostream>
#include "header.hpp"

using namespace std;

int step2(double *matrix, int n, int *arrRowIndex, double *arrValue, int *arrCol, int NZ){ //min_value_col

    int max[n];
    int min;
    for(int i = 0; i < n; i++){
        max[i] = 0;
        for(int j = 0; j < NZ; j++){
            if(i == arrCol[j]){
                max[i]++;
            }
        }
        if(max[i] == n){
            min = arrValue[arrCol[i]];
            for(int k = 0; k < n; k++){
                if(matrix[k * n + i] < min){
                    min = matrix[k * n + i];
                }
            }
            //cout << "\nmin = " << min << endl;
            for(int matI = 0; matI < n; matI++){
                matrix[matI * n + i] -= min;
            }

            CSR_arr_row_index(arrRowIndex, matrix, n);
            NZ = arrRowIndex[n];
            CSR_arr_value(arrValue, matrix, n);
            CSR_arr_col(arrCol, matrix, n, NZ);
        }   
    }

    return NZ;

/*    
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
*/
}