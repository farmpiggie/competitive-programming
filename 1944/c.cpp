#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

void run() {
	int n; cin >> n;
	vector<int> occ(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		occ[x]++;
	}

	for (int i = 0; i < n + 1; i++) {
		if (occ[i] == 1) {
			occ[i]++;
			break;
		}
	}

	for (int i = 0; i < n + 1; i++) {
		if (occ[i] <= 1) {
			cout << i << '\n';
			break;
		}
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
}