#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <time.h>
#include "header.hpp"

#define BILLION 1000000000


/*
1) Находим в каждой строке наименьшее значение, вычитаем его из всех значений в этой строке
2) Находим в каждом столбце наименьшее значение, вычитаем его из всех значений в этом столбце
3) Проводим линии через строки и столбцы, содержащие нули, минимальным количеством линий
если количесвто линий = n, то алгоритм завершен. Иначе шаг 4
4) Из оставшихся строк находим наименьшее значение и вычитаем его из каждой незачеркнутой строки, прибавляем его к каждому зачеркнутому столбцу
повторяем пункт 3.
*/

using namespace std;

int main(int argc, char *argv[]){

    int N = 3534;
    double solution;
    int minmax;
    double max = 0;
    cout << "fuu" << endl;
    //cout << "Enter size of matrix: ";
    //cin >> N;

    //cout << "min or max? Enter 1 or 2" << endl;
    //cin >> minmax;
/*    
    ifstream fin(argv[1]);

    int M, N, L;

    while (fin.peek() == '%'){
        fin.ignore(2048, '\n');
    }

    fin >> M >> N >> L;


    double *original_matrix = new double[M * N];	    

    for (int l = 0; l < L; l++){
	    int m, n;
	    double data;
	    fin >> m >> n >> data;
	    original_matrix[(m - 1) + (n - 1) * M] = data;
    }

    fin.close();
*/   

    double *original_matrix = new double[N * N];
    FILE* fp;
    fp = fopen("3534.txt", "rt");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){       
            fscanf(fp, "%lf ", &original_matrix[i * N + j]);
        }
    }

    double *mat = new double[N * N];
    int *arrAssigned = new int[N * N];

    //init_matrix(original_matrix, N);
    //print_matrix(original_matrix, N);
    int threadsNum = 4;
    memcpy(mat, original_matrix, sizeof(original_matrix) * N * N);

    cout << "step1" << endl;

    struct timespec startMyTimeMul, endMyTimeMul;
    clock_gettime(CLOCK_REALTIME, &startMyTimeMul);

    step1(mat, N);
    
    cout << "step2" << endl;
    step2(mat, N);

    clock_gettime(CLOCK_REALTIME, &endMyTimeMul);
    double resMyTime = (endMyTimeMul.tv_sec - startMyTimeMul.tv_sec) + (double)(endMyTimeMul.tv_nsec - startMyTimeMul.tv_nsec) / BILLION;
    cout << "my Time dense new hungarian alg: \t" << resMyTime << " sec" << endl;
    //print_matrix(mat, N);
    
    //clock_gettime(CLOCK_REALTIME, &endMyTimeMul);
    //double resMyTime = (endMyTimeMul.tv_sec - startMyTimeMul.tv_sec) + (double)(endMyTimeMul.tv_nsec - startMyTimeMul.tv_nsec) / BILLION;
    //cout << "my Time sparse hungarian alg: \t" << resMyTime << " sec" << endl;
    

/*
    if(minmax == 2){
        for(int i = 0; i < NZ; i++){
            if(arrValue[i] > max){
                max = arrValue[i];
            }
        }
        for(int i = 0; i < N * N; i++){
            mat[i] = (mat[i] - max) * -1;
        }
        print_matrix(mat, N);
    
        step1(mat, N);
        print_matrix(mat, N);

        step2(mat, N);
        print_matrix(mat, N);
    }
    else if(minmax = 1){
        //print_matrix(mat, N);
    
        step1(mat, N);
        print_matrix(mat, N);

        step2(mat, N);
        print_matrix(mat, N);
    }
*/

    int *lines = new int[N * N];
    bool end = false;

    //int zerosRow[N];
    //int zerosCol[N];
    //int indexmaxZerosRow = 0;
    //int indexmaxZerosCol = 0;

    //int LinesRow[N];
    //int LinesCol[N];
    int numLines = 0;
    int arrZerosRow[N];

    int *rowAssigned = new int[N];
    int *colAssigned = new int[N];
    //step3(mat, lines, arrAssigned, N);

    while(!end){
        numLines = step3(mat, lines, arrAssigned, rowAssigned, colAssigned, N);
/*
        for(int i = 0; i < N; i++){
            zerosRow[i] = 0;
            zerosCol[i] = 0;
            for(int j = 0; j < N; j++){
                if(mat[i * N + j] == 0){
                    zerosRow[i]++;
                }
                if(mat[j * N + i] == 0){
                    zerosCol[i]++;
                }
            }
        }

        numLines = 0;
        for(int i = 0; i < N; i++){
            LinesRow[i] = 0;
            LinesCol[i] = 0;
            arrZerosRow[i] = -1;
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
        if(numLines == N * 2){
            numLines = N;
        }
*/
        //cout << "min number of lines = " << numLines << endl;

        if(numLines == N){
            end = true;
            solution = 0;
            for(int i = 0; i < N; i++){
                //for(int j = 0; j < N; j++){
                    //if(arrAssigned[i * N + j] == 1){
                        solution = solution + original_matrix[rowAssigned[i] * N + colAssigned[i]];
                        arrZerosRow[i] = colAssigned[i];
                    //}
                //}
            }
            for(int i = 0; i < N; i++){
                //cout << arrZerosRow[i] << " ";
                if(arrZerosRow[i] == -1){
                    cout << "za sho" << endl;
                }
            }
            cout << "\nOptimal solution = " << solution << endl;          
        }
        else{
            step4(mat, rowAssigned, colAssigned, N);
            //print_matrix(mat, N);
        }
    
    }

    // clock_gettime(CLOCK_REALTIME, &endMyTimeMul);
    // double resMyTime = (endMyTimeMul.tv_sec - startMyTimeMul.tv_sec) + (double)(endMyTimeMul.tv_nsec - startMyTimeMul.tv_nsec) / BILLION;
    // cout << "my Time dense new hungarian alg: \t" << resMyTime << " sec" << endl;
    

    delete []original_matrix;
    delete []mat;
    delete []lines;

    return 0;
}
