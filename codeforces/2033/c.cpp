t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(x) for x in input().split()] 
	for i in range(1, n // 2):
#		print(i, i - 1, n - 1 - i, n - i)
		yes = (a[i] == a[i - 1]) + (a[n - 1 - i] == a[n - i])
		no = (a[n - 1 - i] == a[i - 1]) + (a[i] == a[n - i])
		if no < yes:
			a[i], a[n - 1 - i] = a[n - 1 - i], a[i]

	ans = 0
	for i in range(1, n):
		ans += (a[i] == a[i - 1])

	print(ans)
