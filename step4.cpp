#include <iostream>
#include "header.hpp"

using namespace std;

void step4(double *matrix, int *lines, int n){

    double min;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lines[i * n + j] == 0){
                min = matrix[i * n + j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lines[i * n + j] == 0){
                if(matrix[i * n + j] < min){
                    min = matrix[i * n + j];
                }
            }
        }
    }

    cout << min << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(lines[i * n + j] == 0){
                for(int k = 0; k < n; k++){
                    matrix[i * n + k] = matrix[i * n + k] - min;
                }
                break;
            }
        }
    }
    
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout.width(2);
            cout << matrix[i * n + j] << " ";
        }
        cout << endl;
    }
/*
    for(int j = 0; j < n; j++){
        if((lines[j] == 1) && (lines[j + n] == 1)){
            for(int k = j; k < n * n; k += n){
                matrix[k] = matrix[k] + min;
            }
        }
    }
*/
    int checkCol[n];
    for(int i = 0; i < n; i++){
        checkCol[i] = 0;
        for(int j = 0; j < n; j++){
            if(lines[j * n + i] == 1){
                checkCol[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(checkCol[i] == n){
                matrix[j * n + i] = matrix[j * n + i] + min;
            }
        }
    }
}