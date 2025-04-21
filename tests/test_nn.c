#include <stdio.h>
#include "../include/matrix.h"
#include "../include/neuralnet.h"

int main() {
    Matrix *X = create_matrix(4, 2);
    Matrix *Y = create_matrix(4, 1);

    // XOR input
    X->data[0][0] = 0; X->data[0][1] = 0; Y->data[0][0] = 0;
    X->data[1][0] = 0; X->data[1][1] = 1; Y->data[1][0] = 1;
    X->data[2][0] = 1; X->data[2][1] = 0; Y->data[2][0] = 1;
    X->data[3][0] = 1; X->data[3][1] = 1; Y->data[3][0] = 0;

    NeuralNet *nn = create_network(2, 4, 1);
    train(nn, X, Y, 0.1, 1000);

    Matrix *out = forward(nn, X);
    printf("Output after training:\n");
    print_matrix(out);

    free_matrix(X);
    free_matrix(Y);
    free_matrix(out);
    free_network(nn);

    return 0;
}
