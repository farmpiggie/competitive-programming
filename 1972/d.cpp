#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2000005;

vector<int> spf(MAXN, 1);

vector<int> factors(int x) {
	vector<int> ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

int main() {

	spf[0] = 0;
	for (int i = 2; i < MAXN; i++) {
		if (spf[i] == 1) {
			for (int j = i; j < MAXN; j += i) {
				if (spf[j] == 1)
					spf[j] = i;
			}
		}
	}

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			
		}
	}
	return 0;
}
