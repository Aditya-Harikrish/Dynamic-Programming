import numpy as np

N, K = map(int, input().split())
height = list(map(int, input().split(' ')))

min_cost = [None] * N
min_cost[0] = 0

for i in range(1, N):
    currentMinimum = min_cost[i - 1] + abs(height[i] - height[i - 1])
    for j in range(i - 2, max(0, i - K) - 1, -1):
        currentMinimum = min(
            min_cost[i - 1], min_cost[j] + abs(height[i] - height[j]))
    min_cost[i] = currentMinimum
# print(min_cost)
print("Minimum cost is", min_cost[N - 1])

# int n, k, t, curr_min, i, j;
# cin >> n >> k;
# vector<int> h;
# h.reserve(n);
# for (i = 0; i < n; ++i)
# {
#     cin >> t;
#     h.push_back(t);
# }
# int *dp = (int *)malloc(sizeof(int) * n);
# dp[0] = 0;
# for (i = 1; i < n; ++i)
# {
#     curr_min = dp[i - 1] + abs(h[i] - h[i - 1]);
#     for (j = i - 2; j >= i - k && j >= 0; --j)
#     {
#         curr_min = min(curr_min, dp[j] + abs(h[i] - h[j]));
#     }
#     dp[i] = curr_min;
# }
# cout << dp[n - 1] << '\n';
# free(dp);
