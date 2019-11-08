#include <cstdio>
#include <cstdlib>

#include "tsne_lib.h"

static inline float randD() {
    return (float)rand() / (float)((unsigned)RAND_MAX + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <N> <D> <no_dims> <num_threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int D = atoi(argv[2]);
    int no_dims = atoi(argv[3]);
    int num_threads = atoi(argv[4]);

    float *X = (float *)malloc(N * D * sizeof(float));
    if (!X) {
        printf("Could not allocate memory for X");
        return 1;
    }

    float *Y = (float *)malloc(N * no_dims * sizeof(float));
    if (!X) {
        printf("Could not allocate memory for Y");
        return 1;
    }

    // Initialize X
    srand(0x1337);
    for (int i = 0; i < N * D; i++)
        X[i] = randD();

    float perplexity = 30.0;
    float theta = .5;
    int max_iter = 1000;
    int n_iter_early_exag = 250;
    int init_from_Y = false;
    int verbose = 0;
    float early_exaggeration = 12;
    float learning_rate = 200;
    float *final_error = NULL;
    int distance = 1;

    tsne_run_float(
        X, N, D, Y, no_dims, perplexity, theta, num_threads, max_iter, n_iter_early_exag,
        -1, init_from_Y, verbose, early_exaggeration, learning_rate, final_error, distance
    );

    return 0;
}
