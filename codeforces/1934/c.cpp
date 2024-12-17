#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

int query(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int d; cin >> d;
	return d;
}

void run() {
	int n, m; cin >> n >> m;
	int a, b, c;
	a = query(1, 1) + 2; // (x + y)
	b = n + m - query(n, m); // (x + y)
	c = query(1, m) + 1 - m; // (x - y)

	int x1 = max(min((a + c) / 2, n), 1), y1 = max(min((a - c) / 2, m), 1);
	int x2 = max(min((b + c) / 2, n), 1), y2 = max(min((b - c) / 2, m), 1);

	if (query(x1, y1)) cout << "! " << x2 << " " << y2 << endl;
	else cout << "! " << x1 << ' ' << y1 << '\n';
}

int main() {
	int t; cin >> t; while (t--) run();
	return 0;
}