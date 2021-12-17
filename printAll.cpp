#include <iostream>

using namespace std;

void print_matrix(double *matrix, int n){
    
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout.width(2);
            cout << matrix[i * n + j] << " ";
        }
        cout << endl;
    }
}
