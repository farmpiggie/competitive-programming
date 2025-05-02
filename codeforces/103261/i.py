from math import gcd
import random

# print(int(1e9 + 7)**10, 998244353**20)

def miller_rabin(n):
    if n < 2 or n % 6 % 4 != 1:
        return (n | 1) == 3
     
    a = [2, 325, 9375, 28178, 450775, 9780504, 1795265022] + [random.randint(2, n-1)] * 100
    
    s = 0
    cv = n - 1
    while cv % 2 == 0:
        cv //= 2
        s += 1
    d = n >> s
    for elt in a:
        p = pow(elt%n, d, n) 
        i = s
        while p != 1 and p != n - 1 and elt % n and i > 0:
            p = p * p % n
            i -= 1
        if p != n - 1 and i != s:
            return False
    
    return True

def binpow (a, b):
    res = 1
    while b > 0:
        if b % 2:
            res = res * a
            b -= 1
        a = a * a
        b //= 2
    return res

d,k = [int(x) for x in input().split()]

#check if k is a prime power

small_primes = []
max_small = 500

for i in range(2, max_small):
    ok = 1
    for j in range(2, i):
        if i % j == 0:
            ok = 0
            break
    if ok:
        small_primes.append(i)


for pr in small_primes:
    ck = k
    while ck % pr == 0:
        ck /= pr
    if ck == 1:
        print(gcd(pr, d) * d)
        exit()

for n in range(60):
    #check if k is an nth power of a prime
    l = max_small
    r = k
    # print(n)
    while l < r:
        cm = (l + r)//2
        if binpow(cm, n) >= k:
            r = cm
        else:
            l = cm + 1
    # print(l, miller_rabin(l))
    if binpow(l, n) == k and miller_rabin(l):
        print(gcd(l,d) * d)
        exit()
    
print(d)