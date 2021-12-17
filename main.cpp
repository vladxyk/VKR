#include <iostream>
#include <fstream>
#include <algorithm>
#include "mkl.h"
#include "mkl_spblas.h"
#include <time.h>
#include "header.hpp"

#define BILLION 1000000000;

using namespace std;

int main(int argc, char *argv[]){

    int N;
    cout << "fuu" << endl;
    cout << "Enter size of matrix: ";
    cin >> N;
   
    double *mat = new double[N * N];
    init_matrix(mat, N);
    print_matrix(mat, N);

    min_value_row(mat, N);
    print_matrix(mat, N);

    min_value_col(mat, N);
    print_matrix(mat, N);

    int lines[N * N];
    min_lines(mat, lines, N);

    int LinesRow[N];
    int LinesCol[N];
    int numLines = 0;

    for(int i = 0; i < N; i++){
        LinesRow[i] = 0;
        LinesCol[i] = 0;
    }

    for(int i = 0; i < N; i++){
        LinesRow[i] = 0;
        LinesCol[i] = 0;
        for(int j = 0; j < N; j++){
            if(lines[i * N + j] == 1){
                LinesRow[i]++;
            }
            if(lines[j * N + i] == 1){
                LinesCol[i]++;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(LinesRow[i] == N){
            numLines++;
        }
        if(LinesCol[i] == N){
            numLines++;
        }
    }

    if((numLines == N) || (numLines == 0)){
        cout << "Optimal solution" << endl;
    }


    
    delete []mat;

    return 0;
}