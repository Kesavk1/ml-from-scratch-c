#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

Matrix* create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
Matrix* multiply_matrix(Matrix *a, Matrix *b);
void print_matrix(Matrix *m);

#endif
