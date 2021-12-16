#include <iostream>
#include <vector>

#include "Timer.h"

#define int int64_t

namespace Knapsack {
namespace WithoutRepetition {
int v1(int N, int W, const std::vector<int>& w, const std::vector<int>& v);

// if the maximum possible value is known (here: 10**6)
// O((10 ** 6) * N)
int v2(int N, int W, const std::vector<int>& w, const std::vector<int>& v);
}  // namespace WithoutRepetition

int WithRepetition(int N, int W, const std::vector<int>& w, const std::vector<int>& v) {
    std::vector<int> m(N, 0);
    m[0] = 0;
    for (int capacity = 1; capacity <= W; ++capacity) {
        for (int i = 0; i < w.size(); ++i) {
            if (w[i] <= capacity) {
                m[capacity] = std::max(m[capacity], m[capacity - w[i] + v[i]]);
            }
        }
    }
}

}  // namespace Knapsack

signed main(void) {
    int N, W;
    std::cin >> N >> W;
    std::vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> w[i] >> v[i];
    }

    {
        std::cout << "Without Repetition: ";
        std::cout << Knapsack::WithoutRepetition::v1(N, W, w, v) << "\n";
    }

    {
        std::cout << "With Repetition: ";
        std::cout << Knapsack::WithRepetition(N, W, w, v) << "\n";
    }

    return 0;
}

int Knapsack::WithoutRepetition::v1(int N, int W, const std::vector<int>& w, const std::vector<int>& v) {
    std::vector<std::vector<int>> m(N + 1, std::vector<int>(W + 1));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else if (j >= w[i - 1]) {
                m[i][j] = std::max(m[i - 1][j - w[i - 1]] + v[i - 1], m[i - 1][j]);
            } else {
                m[i][j] = m[i - 1][j];
            }
        }
    }
    return m[N][W];
}

int Knapsack::WithoutRepetition::v2(int N, int W, const std::vector<int>& w, const std::vector<int>& v) {
    std::vector<int> dp(100001, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 100000; j >= 0; --j) {
            if (dp[j] != INT_MAX && dp[j] + w[i] <= W) {
                dp[j + v[i]] = std::min(dp[j + v[i]], dp[j] + w[i]);
            }
        }
    }
    for (int i = 100000; i >= 1; --i) {
        if (dp[i] != INT_MAX) {
            return i;
        }
    }
    return -1;
}
