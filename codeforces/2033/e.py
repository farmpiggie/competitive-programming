'''
if # in right spot, don't swap it
if a[i] is not in right spot (a[i] != i), we should have it so that a[j] = i and j = a[i]. 
e.g. 1 x 3, 3 x 1 are good.

2 3 1 5 6 7 4
3 2 1 5 6 7 4
3 2 1 7 6 5 4

1
2 1
3 2 1
4 2 3 1 or 4 3 2 1

'''
t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(x) - 1 for x in input().split()]
	vis = [False for _ in range(n)]
	ans = 0
	for i in range(n):
		if not vis[i]:
			cur = a[i]
			vis[i] = True
			sz = 1
			while cur != i:
				sz += 1
				vis[cur] = True
				cur = a[cur]
			
			ans += max(0, (sz - 1) // 2)
	print(ans)
			
