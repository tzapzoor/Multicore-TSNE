### Benchmark history

##### Serial

$ time ./benchmark 1000 500 3 1
real    0m39.296s
user    0m39.265s
sys     0m0.021s

#### TBB

##### Iteration 1

$ time ./benchmark 1000 500 3 1
real    0m39.523s
user    0m39.500s
sys     0m0.018s

$ time ./benchmark 1000 500 3 2
real    0m27.795s
user    0m42.290s
sys     0m0.078s

$ time ./benchmark 1000 500 3 4
real    0m23.657s
user    0m54.271s
sys     0m0.191s

$ time ./benchmark 1000 500 3 8
real    0m21.289s
user    1m12.125s
sys     0m0.662s

$ time ./benchmark 1000 500 3 16
real    0m20.451s
user    1m29.709s
sys     0m1.843s
