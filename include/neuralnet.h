#ifndef NEURALNET_H
#define NEURALNET_H

#include "matrix.h"  // ✅ This is the missing link

typedef struct {
    int input_size;
    int hidden_size;
    int output_size;
    Matrix *W1;
    Matrix *W2;
    Matrix *A1;
    Matrix *A2;
} NeuralNet;

NeuralNet* create_nn(int input, int hidden, int output);
void free_nn(NeuralNet *nn);
Matrix* forward(NeuralNet *nn, Matrix *X);
void train(NeuralNet *nn, Matrix *X, Matrix *Y, double lr, int epochs);

#endif
