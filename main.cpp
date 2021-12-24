#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "mkl.h"
#include "mkl_spblas.h"
#include <time.h>
#include "header.hpp"

using namespace std;

int main(int argc, char *argv[]){

    int N;
    double solution = 0;
    cout << "fuu" << endl;
    cout << "Enter size of matrix: ";
    cin >> N;
   
    double *original_matrix = new double[N * N];
    double *mat = new double[N * N];

    init_matrix(original_matrix, N);
    print_matrix(original_matrix, N);
    
    memcpy(mat, original_matrix, sizeof(original_matrix) * N * N);
    
    step1(mat, N);
    print_matrix(mat, N);

    step2(mat, N);
    print_matrix(mat, N);

    int *lines = new int[N * N];
    bool end = false;

    int *zerosRow = new int[N];
    int *zerosCol = new int[N];

    int LinesRow[N];
    int LinesCol[N];
    int numLines;

    while(!end){
        step3(mat, lines, zerosRow, zerosCol, N);
        numLines = 0;
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

        cout << "min number of lines = " << numLines << endl;

        if((numLines == N) || (numLines == 0) || (numLines == N * 2)){
            end = true;
            for(int i = 0; i < N; i++){
                if(zerosRow[i] == 1){
                    for(int t = 0; t < N; t++){
                        if(mat[i * N + t] == 0){
                            solution = solution + original_matrix[i * N + t];
                            //break;
                        }
                    }
                }
                for(int j = 0; j < N; j++){
                    if(zerosCol[j] == 1){
                        for(int t = j; t < N * N; t += N){
                            if(mat[t] == 0){
                                solution = solution + original_matrix[t];
                                mat[t] = 1.7E+308;
                            }
                            //break;
                        }
                    }/*
                    else if(mat[i * N + j] == 0 && zerosCol[j] == 1){
                        solution = solution + original_matrix[i * N + j];
                        break;
                    }
                    
                    else if(mat[i * N + j] == 0){
                        solution = solution + original_matrix[i * N + j];
                        for(int k = j; k < N * N; k += N){
                            mat[k] = 1.7E+308;
                        }
                        break;
                    }
                    */
                }
            }
            cout << "Optimal solution = " << solution << endl;
        }
        else{
            step4(mat, lines, N);
            print_matrix(mat, N);
        }
    
    }

    delete []original_matrix;
    delete []mat;
    delete []lines;

    return 0;
}