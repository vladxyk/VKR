#include <iostream>
#include "header.hpp"

using namespace std;


void min_lines(double *matrix, int *lines, int n){
    
    int assigned[n];
    int test;
    int zerosRow[n];
    int zerosCol[n];
    int zerosRowAssigned[n];
    int arrAssigned[n * n];

    for(int i = 0; i < n; i++){
        zerosRow[i] = 0;
        zerosCol[i] = 0;
        for(int j = 0; j < n; j++){
            if(matrix[i * n + j] == 0){
                zerosRow[i]++;
            }
            if(matrix[j * n + i] == 0){
                zerosCol[i]++;
            }
        }
    }

    int arrRowIndex[n + 1];
    arrRowIndex[0] = 0;
    int counter = 0;
    for(int k = 1; k < n; ){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i *n + j] == 0){
                    counter++;
                }
                arrRowIndex[k] = counter;
            }
            k++;
        }
    }

    for(int i = 0; i < n; i++){
        assigned[i] = 9;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((zerosRow[i] == 1) && (matrix[i * n + j] == 0)){
                assigned[i] = i * n + j;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arrAssigned[i * n + j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((assigned[i] != 9) && (zerosCol[assigned[i] - i * n] == 1) && (zerosRow[i] == 1)){ 
                arrAssigned[assigned[i]] = 1;
            }
            else if((matrix[i * n + j] == 0) && (zerosCol[j] == 1)){
                arrAssigned[i * n + j] = 1;
            }
        }
    }
/*
    for(int i = 0; i < n; i++){
        cout << assigned[i] << endl;
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arrAssigned[i * n + j] << " ";
        }
        cout << endl;
    }
*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            lines[i * n + j] = 0;
        }
    }

    for(int i = 0; i < n; i++){;
        zerosRowAssigned[i] = 0;
        for(int j = 0; j < n; j++){
            if(arrAssigned[i * n + j] == 1){
                zerosRowAssigned[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arrAssigned[i * n + j] == 1){
                break;
            }
            if(matrix[i * n + j] == 0){
                for(int k = 0; k < n; k++){
                    lines[k * n + j] = 1;
                    if((arrAssigned[k * n + j] != 1) && (zerosRowAssigned[k] != 0)){
                        for(int t = 0; t < n; t++){
                            lines[k * n + t] = 1;
                        }
                    }
                }
            }
        }
    }
    
    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << lines[i * n + j] << " ";
        }
        cout << endl;
    }


}