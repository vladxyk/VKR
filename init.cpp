#include <iostream>

using namespace std;

void init_matrix(double *matrix, int n){
    
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i * n + j] = rand()%15;
        }
    }  
}


