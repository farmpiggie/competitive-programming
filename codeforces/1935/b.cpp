import collections


def solve():
    n = int(input())
    if n <= 1:
        return print(-1)
    arr = list(map(int, input().split()))
    indL = collections.defaultdict(lambda: n)
    indR = collections.defaultdict(lambda: 0)
    for i in range(n):
        v = arr[i]
        indL[v] = min(indL[v], i)
        indR[v] = max(indR[v], i)
    m = 0
    l = 0
    r = n-1
    while 1:
        if m not in indL:
            break
        if indL[m]==indR[m]:
            return -1
        l = max(l,indL[m])
        r = min(r,indR[m])
        if l>=r:
            return -1
        m+=1
    
    print(2)
    # print(*arr[:l+1])
    # print(*arr[l+1:])
    print(1,l+1)
    print(l+2,n)


for _ in range(int(input())):
    a = solve()
    if(a==-1):
        print(-1)
