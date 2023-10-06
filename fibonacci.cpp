/**
 * @file fibonacci.cpp
 * @brief Fibonacci sequence implementation performance comparison
 * @details Implementation of the Fibonacci sequence using both recursion and iteration
 * https://oeis.org/A000045
*/

#include <iostream>
#include <vector>
#include <chrono>

/**
 * @brief Fibonacci sequence implementation using recursion
 * @param n The nth number in the Fibonacci sequence to calculate
 * @return The nth number in the Fibonacci sequence
*/
uint64_t fibonacci_recursion(uint64_t n)
{
    if (n <= 1) {
        return n;
    }

    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}

/**
 * @brief Fibonacci sequence implementation using iteration
 * @param n The nth number in the Fibonacci sequence to calculate
 * @return The nth number in the Fibonacci sequence
*/
uint64_t fibonacci_iteration(int n)
{
    std::vector<uint64_t> fib(n + 1);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n < 0) {
        std::cerr << "n must be a positive integer" << std::endl;
        return 1;
    }

    // Use chrono to time the execution of each function
    auto start = std::chrono::high_resolution_clock::now();
    auto result = fibonacci_recursion(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Fibonacci recursion: " << result << " (" << duration.count() << " microseconds)" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    result = fibonacci_iteration(n);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Fibonacci iteration: " << result << " (" << duration.count() << " microseconds)" << std::endl;

    return 0;
}
