extern "C"
{
    #ifdef _WIN32
    __declspec(dllexport)
    #endif
    extern void tsne_run_float(float* X, int N, int D, float* Y,
                                int no_dims = 2, float perplexity = 30, float theta = .5,
                                int num_threads = 1, int max_iter = 1000, int n_iter_early_exag = 250,
                                int random_state = -1, bool init_from_Y = false, int verbose = 0,
                                float early_exaggeration = 12, float learning_rate = 200,
                                float *final_error = NULL, int distance = 1);
}
