#include <iostream>
#include <string.h>
#include "header.hpp"

using namespace std;

bool bpm(int *mat, int *seen, int *matchR, int *colAssigned, int n, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (mat[i * n + j] == 1 && seen[j] != 1)
        {
            seen[j] = 1;
            if (matchR[j] < 0 || bpm(mat, seen, matchR, colAssigned, n, matchR[j]))
            {
                matchR[j] = i;
                colAssigned[matchR[j]] = j;
                return true;
            }

        }
    }
    return false;
}
 
int maxBPM(int *mat, int *matchR, int *rowAssigned, int *colAssigned, int n){

    int seen[n];
    for(int i = 0; i < n; i++){
        matchR[i] = -1;
        rowAssigned[i] = i;
    }

    int result = 0;
    for(int i = 0; i < n; i++){
    
        memset(seen, 0, sizeof(seen));

        if(bpm(mat, seen, matchR, colAssigned, n, i)){
            result++;
        }
        else{
            rowAssigned[i] = -1;
        }
    }

    return result;
}

void step3(double *matrix, int *lines, int *arrAssigned, int n){ //min_lines

    int *matchR = new int[n];
    
    int mat[n * n];
    
    int *rowAssigned = new int[n];
    int *colAssigned = new int[n];
    
    int rowX[n];
    int colX[n];
    int zerosRowAssigned[n];
    int zerosColAssigned[n];

    for(int i = 0; i < n * n; i++){
        arrAssigned[i] = 0;
    }


    for(int i = 0; i < n; i++){
        rowX[i] = -1;
        colX[i] = -1;
        rowAssigned[i] = 0;
        colAssigned[i] = 0;
    }

    for(int i = 0; i < n * n; i++){
        if(matrix[i] == 0){
            mat[i] = 1;
        }
        else{
            mat[i] = 0;
        }
    }

    int max = maxBPM(mat, matchR, rowAssigned, colAssigned, n);

    cout << "max = " << max << endl;

    for(int i = 0; i < n; i++){
        if(rowAssigned[i] != -1){
            arrAssigned[rowAssigned[i] * n + colAssigned[i]] = 1;
        }
    }

    cout << "i" << endl;
    for(int i = 0; i < n; i++){
        cout << rowAssigned[i] << " ";
    }
    cout << "\nj" << endl;
    for(int i = 0; i < n; i++){
        cout << colAssigned[i] << " ";
    }
    cout << endl;

    //for(int i = 0; i < n; i++){
    //    arrAssigned[rowAssigned[i] * n + colAssigned[i]] = 1;
    //}
        cout << "\nARRASS" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arrAssigned[i * n + j] << " ";
        }
        cout << endl;
    }
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            lines[i * n + j] = 0;
            if(matrix[i * n + j] == 0){
                lines[i * n + j] = 1;
            }
        }
    }

    cout << endl;
    cout << "lines" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << lines[i * n + j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){;
        zerosRowAssigned[i] = 0;
        zerosColAssigned[i] = 0;
        for(int j = 0; j < n; j++){
            if(arrAssigned[i * n + j] == 1){
                zerosRowAssigned[i]++;
            }
            if(arrAssigned[j * n + i] == 1){
                zerosColAssigned[i]++;
            }
        }
    }
    int it = -1;
    int checkX = 0; //while(checkX > max)
    while(checkX > it){ 
        it = checkX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(zerosRowAssigned[i] == 0){
                    rowX[i] = i;
                    if((matrix[i * n + j] == 0) && (colX[j] != j)){
                        colX[j] = j;
                        checkX++;
                        for(int t = 0; t < n; t++){
                            if(arrAssigned[t * n + j] == 1){
                                rowX[t] = t;
                                zerosRowAssigned[t] = 0;
                                checkX++;
                            }
                        }
                    }
                }
            }
        zerosRowAssigned[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(rowX[i] == -1){
                lines[i * n + j] = 1;
            }
            if(colX[i] != -1){
                lines[j * n + i] = 1;
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
    cout << "\nzerorow" << endl;
    for(int i = 0; i < n; i++){
        cout << zerosRowAssigned[i] << " ";
    }
    cout << "\nzerocol" << endl;
    for(int i = 0; i < n; i++){
        cout << zerosColAssigned[i] << " ";
    }
    cout << endl;

}
