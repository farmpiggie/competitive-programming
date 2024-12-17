
	n = int(input())
	a = [int(x) for x in input().split()]

	mp = {} # OrderedDict()
	mp[0] = -1

	prev = -2
	sum = 0
	ans = 0
	for i in range(n):
		sum += a[i]
		if sum in mp and mp[sum] >= prev:
			ans += 1
			prev = i
		mp[sum] = i
	
	print(ans)

t = int(input())

for _ in range(t):
	solve()
