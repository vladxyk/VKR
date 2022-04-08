#include <iostream>
#include "header.hpp"

using namespace std;

/*
1) Находим в каждой строке наименьшее значение, вычитаем его из всех значений в этой строке
2) Находим в каждом столбце наименьшее значение, вычитаем его из всех значений в этом столбце
3) Проводим линии через строки и столбцы, содержащие нули, минимальным количеством линий
если количесвто линий = n, то алгоритм завершен. Иначе шаг 4
4) Из оставшихся строк находим наименьшее значение и вычитаем его из каждой незачеркнутой строки, прибавляем его к каждому зачеркнутому столбцу
повторяем пункт 3.
*/

void step4(double *matrix, int *rowAssigned, int *colAssigned, int n){

    double min;
    for(int i = 0; i < n; i++){
        if((rowAssigned[i] == -1) && (colAssigned[i]) != -1){
            min = matrix[i * n + i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((rowAssigned[i] == -1) && (colAssigned[j]) != -1){
                if(matrix[i * n + j] < min){
                    min = matrix[i * n + j];
                }
            }
        }
    }
    
    
/*    
    
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
*/
    //cout << min << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(rowAssigned[i] == -1){
                matrix[i * n + j] -= min;
            }
            if(colAssigned[i] == -1){
                matrix[j * n + i] += min;
            }
        }
    }
    /*
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

    for(int j = 0; j < n; j++){
        if((lines[j] == 1) && (lines[j + n] == 1)){
            for(int k = j; k < n * n; k += n){
                matrix[k] = matrix[k] + min;
            }
        }
    }

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
*/


}