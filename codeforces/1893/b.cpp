#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, m, a[N], b[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(b, b + m);
	reverse(b, b + m);

	vector<int> ans;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] > b[j]) {
			ans.push_back(a[i]);
			i++;
		} else {
			ans.push_back(b[j]);
			j++;
		}
	}

	while (i < n) {
		ans.push_back(a[i]);
		i++;
	}

	while (j < m) {
		ans.push_back(b[j]);
		j++;
	}

	for (int num : ans) 
		cout << num << ' ';
	cout << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}