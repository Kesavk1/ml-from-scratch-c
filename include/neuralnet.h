#ifndef NEURALNET_H
#define NEURALNET_H

#include "matrix.h"

typedef struct {
    int input_size;
    int hidden_size;
    int output_size;
    Matrix *W1;
    Matrix *W2;
    Matrix *A1;
    Matrix *A2;
} NeuralNet;

NeuralNet* create_network(int input, int hidden, int output);
void free_network(NeuralNet *nn);

Matrix* forward(NeuralNet *nn, Matrix *X);
void train(NeuralNet *nn, Matrix *X, Matrix *Y, double lr, int epochs);

#endif
