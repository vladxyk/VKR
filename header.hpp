#ifndef CSR_H
#define CSR_H


void init_matrix(double *matrix, int n);

void step1(double *matrix, int n);
void step2(double *matrix, int n);
void step3(double *matrix, int *lines, int *arrAssigned, int n);
void step4(double *matrix, int *lines, int n);

void print_matrix(double *matrix, int n);

#endif