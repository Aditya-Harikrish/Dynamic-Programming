N = int(input())
height = list(map(int, input().split()))

min_cost = [None] * N
min_cost[0] = 0
min_cost[1] = abs(height[1] - height[0])
for i in range(2, N):
    min_cost[i] = min(min_cost[i-1] + abs(height[i] - height[i-1]),
                      min_cost[i-2] + abs(height[i] - height[i-2]))

print("Minimum cost is", min_cost[N - 1])
