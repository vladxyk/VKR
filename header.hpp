#ifndef CSR_H
#define CSR_H


void init_matrix(double *matrix, int n);

int step1(double *matrix, int n, int *arrRowIndex, double *arrValue, int *arrCol, int NZ);
int step2(double *matrix, int n, int *arrRowIndex, double *arrValue, int *arrCol, int NZ);
void step3(double *matrix, int *lines, int *arrAssigned, int n);
void step4(double *matrix, int *lines, int n);

void CSR_arr_value(double *arrValue, double *mat, int n);
void CSR_arr_col(int *arrCol, double *mat, int n, int NZ);
void CSR_arr_row_index(int *arrRowIndex, double *mat, int n);

void print_arr_value(double *arrValue, int NZ);
void print_arr_col(int *arrCol, int NZ);
void print_arr_row_index(int *arrRowIndex, int n);

void print_matrix(double *matrix, int n);

#endif