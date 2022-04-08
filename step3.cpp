#include <iostream>
#include <string.h>
#include "header.hpp"

using namespace std;

bool bpm(double *matrix, int *seen, int *matchR, int *colAssigned, int n, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (matrix[i * n + j] == 0 && seen[j] != 1)
        {
            seen[j] = 1;
            if (matchR[j] < 0 || bpm(matrix, seen, matchR, colAssigned, n, matchR[j]))
            {
                matchR[j] = i;
                colAssigned[matchR[j]] = j;
                return true;
            }

        }
    }
    return false;
}
 
int maxBPM(double *matrix, int *matchR, int *rowAssigned, int *colAssigned, int n){

    int seen[n];
    for(int i = 0; i < n; i++){
        matchR[i] = -1;
        rowAssigned[i] = i;
    }

    int result = 0;
    for(int i = 0; i < n; i++){
    
        memset(seen, 0, sizeof(seen));

        if(bpm(matrix, seen, matchR, colAssigned, n, i)){
            result++;
        }
        else{
            rowAssigned[i] = -1;
        }
    }

    return result;
}

int step3(double *matrix, int *lines, int *arrAssigned, int *rowAssigned, int *colAssigned, int n){ //min_lines

    int *matchR = new int[n];
    
    //int mat[n * n];
    //memset(lines, 0, sizeof(lines) * n * n);
    for(int i = 0; i < n*n; i++){
       lines[i] = 0;
    }
    
    int rowX[n];
    int colX[n];
    /*
    int zerosRowAssigned[n];
    int zerosColAssigned[n];
    */


    for(int i = 0; i < n; i++){
        rowX[i] = -1;
        colX[i] = -1;
        colAssigned[i] = 0;
    }

    int numLines = maxBPM(matrix, matchR, rowAssigned, colAssigned, n);
/*
    cout << "match" << endl;
    for(int i = 0; i < n; i++){
        cout << matchR[i] << "  ";
    }
*/


    //cout << "max = " << numLines << endl;
/*
    cout << "i" << endl;
    for(int i = 0; i < n; i++){
        cout << rowAssigned[i] << " ";
    }
    cout << "\nj" << endl;
    for(int i = 0; i < n; i++){
        cout << colAssigned[i] << " ";
    }
    cout << endl;
*/
    for(int i = 0; i < n * n; i++){
        arrAssigned[i] = 0;
    }
    for(int i = 0; i < n; i++){
        if(rowAssigned[i] != -1){
            arrAssigned[rowAssigned[i] * n + colAssigned[i]] = 1;
        }
    }

    if(numLines == n){
        return numLines;
    }

/*ne nado
    cout << "\nARRASS" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arrAssigned[i * n + j] << " ";
        }
        cout << endl;
    }
*/

/*
    cout << endl;
    cout << "lines" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << lines[i * n + j] << " ";
        }
        cout << endl;
    }
*/
    int it = -1;
    int checkX = 0; //while(checkX > max)
    while(checkX > it){ 
        it = checkX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //if(zerosRowAssigned[i] == 0){
                if(rowAssigned[i] == -1){
                    rowX[i] = i;
                    //cout << "i = " << i << endl;
                    if((matrix[i * n + j] == 0.0) && (colX[j] != j)){
                        colX[j] = j;
                        checkX++;
                        //cout << "check " << checkX << endl;
                        for(int t = 0; t < n; t++){
                            if(arrAssigned[t * n + j] == 1){
                            //if(colAssigned[t] == j && rowAssigned[t] != -1){
                                rowX[t] = t;
                                rowAssigned[t] = -1;
                                //cout << "rowas[" << t << "] = " << rowAssigned[t] << endl;
                                checkX++;
                                colAssigned[j] = -1;
                            }
                        }
                        colAssigned[j] = -1;
                    }
                }
            }
        //rowAssigned[i] = 1;
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
/*    
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << lines[i * n + j] << " ";
        }
        cout << endl;
    }

    cout << "\nzerorow" << endl;
    for(int i = 0; i < n; i++){
        cout << rowAssigned[i] << " ";
    }
    cout << "\nzerocol" << endl;
    for(int i = 0; i < n; i++){
        cout << colAssigned[i] << " ";
    }
    cout << endl;
*/
    return numLines;
}
