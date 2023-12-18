#include<iostream>
#include<thread>

#define MAX 1000
#define MAX_THREADS 8
int matA[MAX][MAX];
int matB[MAX][MAX];
int result[MAX][MAX];

int step_i = 0;

void* multiply(void* arg)
{
    int core = step_i++;
    for (int i = core * MAX / MAX_THREADS; i < (core + 1) * MAX / MAX_THREADS; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                result[i][j] += matA[i][k] * matB[k][j];
    return NULL;
}

int main()
{
    for (int i = 0; i<MAX; i++) 
    {
        for (int j = 0; j<MAX; j++) 
        {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Matrix A" << std::endl;
    for (int i = 0; i<MAX; i++) 
    {
        for (int j = 0; j<MAX; j++) 
        {
            std::cout << matA[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix B" << std::endl;
    for (int i = 0; i<MAX; i++) 
    {
        for (int j = 0; j<MAX; j++) 
        {
            std::cout << matB[i][j] << " ";
        }
        std::cout << std::endl;
    }

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i<MAX_THREADS; i++) 
    {
        int* p;
        pthread_create(&threads[i], NULL, multiply , (void*)(p));
    }

    for (int i = 0; i<MAX_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;

    std::cout << "Matrix Result" << std::endl;
    for (int i = 0; i<MAX; i++) 
    {
        for (int j = 0; j<MAX; j++) 
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;

}