#!/usr/bin/python3

""" Copy and Paste the H characters in the file """
def minOperations(n):

    if n <= 1:
        return 0

    dp = [0] * (n + 1)

    for i in range(2, n + 1):
        dp[i] = i

        for j in range(2, int(i ** 0.5) + 1):
            if i % j == 0:
                dp[i] = min(dp[i], dp[j] + i // j)

    return dp[n]
