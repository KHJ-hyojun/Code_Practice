import sys
input = sys.stdin.readline

dp = [0,1,1,1,2,2] + [0]*95

for i in range(6,101):
    dp[i] = dp[i-1] + dp[i-5]

for _ in range(int(input())):
    print(dp[int(input())])