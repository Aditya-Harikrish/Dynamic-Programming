/* https://stackoverflow.com/a/2631810/14956511 */
#include <iostream>
#include <vector>

#include "Random.h"
#include "Timer.h"

namespace LIS {

/* O(n^2) */
int lengthOfLIS_v1(const std::vector<int>& a);

/* O(n log n) */
int lengthOfLIS_v2(const std::vector<int>& a);

}  // namespace LIS

signed main() {
    std::vector<int> nArray{10, 100, 1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};

    for (auto& n : nArray) {
        std::cout << "\nn = " << n << std::endl;
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(Random::Int(-1000, 1000));
        }
        std::cout << "a: ";
        for (auto& it : a) {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        {
            std::cout << "\nO(n^2)" << std::endl;
            Timer timer;
            int ans = LIS::lengthOfLIS_v1(a);
            auto timeTaken = timer.StopMicroseconds();
            std::cout << "Length = ";
            std::cout << ans << "\n";
            std::cout << "Time taken: " << timeTaken << " us\n";
        }

        {
            std::cout << "\nO(n log n)" << std::endl;
            Timer timer;
            int ans = LIS::lengthOfLIS_v2(a);
            auto timeTaken = timer.StopMicroseconds();
            std::cout << "Length = ";
            std::cout << ans << "\n";
            std::cout << "Time taken: " << timeTaken << " us\n";
        }
    }
    return 0;
}

int LIS::lengthOfLIS_v1(const std::vector<int>& a) {
    if (a.size() < 1) return 0;
    std::vector<int> dp(a.size(), 1);    /* DP[i] = length of the LIS ending with a[i] */
    std::vector<int> prev(a.size(), -1); /* Only needed to find the LIS itself in addition to its length */
    int max_length = 1;
    int last_index_of_LIS = -1;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_length) {
            max_length = dp[i];
            last_index_of_LIS = i;
        }
    }

    /* Print the LIS */
    std::vector<int> LIS_in_reverse;
    for (auto i = last_index_of_LIS; i >= 0;) {
        LIS_in_reverse.push_back(a[i]);
        i = prev[i];
    }
    std::cout << "LIS: ";
    for (auto it = LIS_in_reverse.rbegin(); it != LIS_in_reverse.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return max_length;  // Length of the LIS
}

int LIS::lengthOfLIS_v2(const std::vector<int>& a) {
    if (a.size() < 1) return 0;
    std::vector<int> s; /* s[i] = index of the smallest integer that ends an increasing sequence of length i */
    s.push_back(0);
    std::vector<int> parent(a.size(), -1);
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] > a[s.back()]) {
            parent[i] = s.back();
            s.push_back(i);
        } else {
            /* Binary search in s for the smallest integer >= a[i] */
            int l = 0, r = s.size() - 1;
            int mid = l + (r - l) / 2;
            int index = r; /* Index of the target in s */
            while (l <= r) {
                mid = l + (r - l) / 2;
                if (a[s[mid]] >= a[i]) {
                    index = std::min(index, mid);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (index - 1 >= 0)
                parent[i] = s[index - 1];
            else
                parent[i] = -1;
            s[index] = i;
        }
    }

    /* Print the LIS */
    std::vector<int> LIS_in_reverse;
    for (int i = s.back(); i >= 0;) {
        LIS_in_reverse.push_back(a[i]);
        i = parent[i];
    }
    std::cout << "LIS: ";
    for (auto it = LIS_in_reverse.rbegin(); it != LIS_in_reverse.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return s.size();  // Length of the LIS
}