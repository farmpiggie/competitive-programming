Q = int(input())


def calc(s):
    # number of palindromes less than s, given as string
    N = len(s)
    sub = False
    ret = 0
    for i in range((N+1)//2):
        ret *= 10
        ret += ord(s[i])-ord('0')
        if s[i] > s[N-i-1]:
            sub = True
        elif s[i] < s[N-i-1]:
            sub = False
        if i == 0:
            ret -= 1
    if sub:
        ret -= 1
    # print(s, ret, sub, N, "yeet")
    if N == 1:
        # print(s, ret, sub)
        return ret+1
    else:
        ss = ""
        # print(s, ret, sub, N)
        for i in range(N-1):
            ss += "9"
        return ret + 1 + calc(ss)



def solve():
    L, R = input().split()
    L = str(int(L)-1)
    # number of palindromes length N less than L
    print(calc(R)-calc(L))



for q in range(Q):
    solve()