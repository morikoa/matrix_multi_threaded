#include<iostream>
#include<thread>

#define MAX 1000000
#define MAX_THREADS 8
int step_i = 0;
int count = 0;
// find prime numbers from 1 to 100000 using thread

void* find(void* arg)
{
    int core = step_i++;
    for (int i = core * MAX / MAX_THREADS; i < (core + 1) * MAX / MAX_THREADS; i++)
    {
        bool isPrime = true;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            std::cout << i << " ";
            count++;
        }
    }
    return NULL;

}

int main()
{
    int count = 0;

    auto start = std::chrono::high_resolution_clock::now();

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i<MAX_THREADS; i++)
    {
        int* p;
        pthread_create(&threads[i], NULL, find, (void*)(p));
    }

    for (int i = 0; i<MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nElapsed time: " << elapsed.count() << "s\n";
}