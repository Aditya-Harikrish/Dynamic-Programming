#include <iostream>
#include <vector>

namespace FrogJump {

int MinCostDP(std::vector<int> h, int k) {
    int n = h.size();
    std::vector<int> dp(n);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        int curr_min = dp[i - 1] + abs(h[i] - h[i - 1]);

        for (int j = i - 2; j >= i - k && j >= 0; --j) {
            curr_min = std::min(curr_min, dp[j] + abs(h[i] - h[j]));
        }

        dp[i] = curr_min;
    }

    return dp[n - 1];
}

}  // namespace FrogJump

int main(void) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    for (auto &it : h) std::cin >> it;

    std::cout << FrogJump::MinCostDP(h, k) << '\n';

    return 0;
}