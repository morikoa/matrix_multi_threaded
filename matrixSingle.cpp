#include<iostream>
#include<chrono>

#define MAX 4
int matA[MAX][MAX];
int matB[MAX][MAX];
int result[MAX][MAX];
int step_i = 0;

void multiply(int i)
{
    int j, k;
    for (j = 0; j < MAX; j++)
        for (k = 0; k < MAX; k++)
            result[i][j] += matA[i][k] * matB[k][j];
}

int main()
{
    for (int i =0; i<MAX; i++)
    {
        for (int j = 0; j<MAX; j++)
        {
            matA[i][j] = rand() % 10;
        }
    }

    for (int i =0; i<MAX; i++)
    {
        for (int j = 0; j<MAX; j++)
        {
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

    std::cout << "Result: " << std::endl;
    for (int i = 0; i<MAX; i++)
    {
        multiply(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;

    
    std:: cout << "Matrix A * Matrix B = " << std::endl;
    for (int i = 0; i<MAX; i++)
    {
        for (int j = 0; j<MAX; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Time taken: " << duration.count() << "seconds" << std::endl;

    return 0;
}