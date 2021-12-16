#include <iostream>
#include <vector>
int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> h(n), dp(std::max(n, 2));
    for (auto &it : h) std::cin >> it;

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; ++i) {
        dp[i] = std::min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    std::cout << dp[n - 1] << "\n";

    return 0;
}