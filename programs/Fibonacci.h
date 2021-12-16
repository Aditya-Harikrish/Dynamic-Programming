#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <cstdint>
#include <iostream>
#include <vector>

// Both of the functions below populate FibArray with Fibonacci
// numbers from F_0 till F_n (including both). Thus, it calculates
// the first (n+1) Fibonacci numbers. Here, F_0 = 0 and F_1 = 1.
namespace Fibonacci {
uint64_t Without_Memoisation(std::vector<uint64_t>& FibArray, uint64_t n) {
    if (n <= 1)
        FibArray[n] = n;
    else
        FibArray[n] = Without_Memoisation(FibArray, n - 1) + Without_Memoisation(FibArray, n - 2);
    return FibArray[n];
}

uint64_t With_Memoisation(std::vector<uint64_t>& FibArray, uint64_t n) {
    // The default value to fill the array is 4, because 4 is not a Fibonacci number
    // Checking if the value is present in the memo
    if (FibArray[n] != 4) return FibArray[n];

    // Value not present in memo at this point
    if (n <= 1)
        FibArray[n] = n;
    else
        FibArray[n] = With_Memoisation(FibArray, n - 1) + With_Memoisation(FibArray, n - 2);
    return FibArray[n];
}

}  // namespace Fibonacci

#endif