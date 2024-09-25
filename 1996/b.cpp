#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<vector<char>> a(n, vector<char>(n));
		for (auto& x : a) {
			for (char& y : x) {
				cin >> y;
			}
		}
		vector<vector<char>> b(n / k, vector<char>(n / k));
		for (int i = 0; i < n / k; i++) {
			for (int j = 0; j < n / k; j++) {
				b[i][j] = a[i * k][j * k];
			}
		}
		for (auto& x : b) {
			for (char& y : x) {
				cout << y;
			}
			cout << '\n';
		}
	}
	return 0;
}

