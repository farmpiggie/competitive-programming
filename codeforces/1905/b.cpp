#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t, n;

void solve (){
	cin >> n;
	vector<int> vert(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		vert[a]++;
		vert[b]++;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vert[i] == 1) cnt++;
	}

	cout << (cnt + 1) / 2 << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}