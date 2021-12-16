// Given d denominations denom[0] through denom[d-1] and an amount n,
// calculate the least number of notes we would need totally
// of the given denominations to total n

// NEED TO REWRITE
#include <iostream>
#include <vector>

#include "Timer.h"

namespace MinCoins {

// Input: amount n, denominations denom
// Returns: Minimum number of coins needed
int WithoutMemoisation(int n, const std::vector<int>& denom) {
    if (n == 0) return 0;
    int min = INT_MAX;
    for (auto& denomination : denom) {
        if (n - denomination >= 0) {
            min = std::min(min, 1 + WithoutMemoisation(n - denomination, denom));
        }
    }
    return min;
}

int WithMemoisationHelper(int n, const std::vector<int>& denom, std::vector<int>& CoinMemo) {
    if (CoinMemo[n] != -1) return CoinMemo[n];
    int min = INT_MAX;
    for (auto& denomination : denom) {
        if (n - denomination >= 0) {
            min = std::min(min, 1 + WithMemoisationHelper(n - denomination, denom, CoinMemo));
        }
    }
    CoinMemo[n] = min;
    return min;
}

int WithMemoisation(int n, const std::vector<int>& denom) {
    std::vector<int> CoinMemo(n + 1, -1);
    CoinMemo[0] = 0;
    return WithMemoisationHelper(n, denom, CoinMemo);
}

}  // namespace MinCoins

int main() {
    int d;  // number of denominations
    std::cout << "Enter the number of denominations: ";
    std::cin >> d;
    std::vector<int> denom(d);  // the values of the denominations
    std::cout << "1 has to be one of the denominations.\n";

    for (int i = 0; i < d; ++i) {
        std::cout << "Enter denomination " << i + 1 << ": ";
        std::cin >> denom[i];
    }

    std::vector<uint64_t> nArray;  // the amounts
    for (uint64_t i = 1; i <= 60; ++i) nArray.push_back(i);
    for (auto& n : nArray) {
        std::cout << "amount = " << n << ",";
        std::cout.flush();
        {
            // Without Memoisation
            // printf("%-19s : ", "Without Memoisation");

            Timer timer;
            int minCoins = MinCoins::WithoutMemoisation(n, denom);
            int timeTaken = timer.StopMicroseconds();
            std::cout << timeTaken << " us,";
            std::cout.flush();
        }

        {
            // With Memoisation
            // printf("%-19s : ", "With Memoisation");

            Timer timer;
            int minCoins = MinCoins::WithMemoisation(n, denom);
            int timeTaken = timer.StopMicroseconds();
            std::cout << timeTaken << " us" << std::endl;
        }

        // std::cout << std::endl;
    }
    return 0;
}