#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "../include/neuralnet.h"

// Helper function to apply sigmoid
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

NeuralNet* create_network(int input, int hidden, int output) {
    NeuralNet *nn = malloc(sizeof(NeuralNet));
    nn->input_size = input;
    nn->hidden_size = hidden;
    nn->output_size = output;

    nn->W1 = create_matrix(input, hidden);
    nn->W2 = create_matrix(hidden, output);
    nn->A1 = create_matrix(1, hidden);
    nn->A2 = create_matrix(1, output);

    // Random init (small values)
    for (int i = 0; i < input; i++)
        for (int j = 0; j < hidden; j++)
            nn->W1->data[i][j] = ((double) rand() / RAND_MAX - 0.5);

    for (int i = 0; i < hidden; i++)
        for (int j = 0; j < output; j++)
            nn->W2->data[i][j] = ((double) rand() / RAND_MAX - 0.5);

    return nn;
}

void free_network(NeuralNet *nn) {
    free_matrix(nn->W1);
    free_matrix(nn->W2);
    free_matrix(nn->A1);
    free_matrix(nn->A2);
    free(nn);
}

Matrix* forward(NeuralNet *nn, Matrix *X) {
    Matrix *Z1 = multiply_matrix(X, nn->W1);
    for (int i = 0; i < Z1->rows; i++)
        for (int j = 0; j < Z1->cols; j++)
            Z1->data[i][j] = sigmoid(Z1->data[i][j]);

    free_matrix(nn->A1);
    nn->A1 = Z1;

    Matrix *Z2 = multiply_matrix(nn->A1, nn->W2);
    for (int i = 0; i < Z2->rows; i++)
        for (int j = 0; j < Z2->cols; j++)
            Z2->data[i][j] = sigmoid(Z2->data[i][j]);

    free_matrix(nn->A2);
    nn->A2 = Z2;

    return Z2;
}

// Minimalistic XOR training (no backprop for now, just a placeholder)
void train(NeuralNet *nn, Matrix *X, Matrix *Y, double lr, int epochs) {
    for (int e = 0; e < epochs; e++) {
        Matrix *output = forward(nn, X);
        // TODO: Add backprop here for real learning
        free_matrix(output);
    }
}
