from math import log2


def solve():
    A, B, M = map(int, input().split())

    dp = {}

    def rec(n) -> int:
        # print(n)
        if n < 0:
            n = -n
        if n == 0:
            return 2
        if n == 1:
            return A
        if n in dp:
            return dp[n]
        # find largest power of 2
        # print(n)
        l = log2(n)
        if int(l) == l: # perfect power
            n1 = rec(n//2)
            dp[n] = (n1*n1 - 2) % M
        else:
            l = int(l)
            a = 2**l
            # print(n, a)
            n1 = rec(a)
            n2 = rec(n-a)
            n3 = rec(n-a-a)
            dp[n] = (n1*n2-n3) % M
        return dp[n]

    print(rec(B))


solve()

