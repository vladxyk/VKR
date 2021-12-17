#ifndef CSR_H
#define CSR_H


void init_matrix(double *matrix, int n);

void min_value_row(double *matrix, int n);
void min_value_col(double *matrix, int n);
void min_lines(double *matrix, int *lines, int n);

void print_matrix(double *matrix, int n);

#endif