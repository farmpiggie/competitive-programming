H, M = map(int, input().split())

M += 60*H

cost = 0

N = int(input())
for i in range(N):
    X, Y = map(int, input().split())
    if M >= X:
        cost += X*Y
        M -= X
    else:
        cost += M*Y
        M -= M
    if M == 0:
        break

print(cost)