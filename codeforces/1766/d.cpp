#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool v[10000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;

	for (int i = 2; i <= 1e7; i++) {
		if (v[i]) continue;
		primes.push_back(i);
		for (int j = i; j <= 1e7; j += i) v[j] = 1;
		
	}

	while (t--) {
		int x, y; cin >> x >> y;
		if (y - x == 1) {cout << "-1\n";  continue;} 
		int temp = y - x, dist = 2e9;

		for (auto k : primes) {
			if (k * k > temp) break;
			if (temp % k) continue;
			// dist = min(dist, k - (idx % k));
			while(temp%k == 0) temp /= k;
			dist = min(dist, (k - x % k) % k);
			
		}

		if (temp > 1) {
			dist = min(dist, (temp - x % temp) % temp);
		}
		cout << dist << "\n";
	}
	return 0;
}