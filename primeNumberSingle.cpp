#include<iostream>
#include<chrono>

#define MAX 1000000

// find prime numbers from 1 to 100000
int main()
{
    int count = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 2; i <= MAX; i++)
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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nElapsed time: " << elapsed.count() << "s\n";

    std::cout << "\nTotal prime numbers: " << count << std::endl;


    return 0;
}