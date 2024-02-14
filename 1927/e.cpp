#include <bits/stdc++.h>
using namespace std;

// DEFINITIONS

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int t, n, k;

void solve() {
	cin >> n >> k;
	vector<int> arr(k);
	int cnt = n % k;
	arr[0] = 1;
	arr[1] = n;
	int times = n / k;
	for (int i = 2; i < k; i++) {
		if (i % 2 == 0) { // up
			if (i - 2 < cnt) {
				arr[i] = arr[i - 2] + times + 1; // extra repetition
			} else {
				arr[i] = arr[i - 2] + times;
			}
		} else {
			if (i - 2 < cnt) {
				arr[i] = arr[i - 2] - times - 1; // extra repetition
			} else {
				arr[i] = arr[i - 2] - times;
			}
		}
		
	}

	for (int i = 0; i < k; i++) {
		cout << arr[i] << ' ';
	}
	for (int i = k; i < n; i++) {
		if (i % 2 == 0) arr[i % k]++;
		else arr[i % k]--;

		cout << arr[i % k] << ' ';
		
	}
	cout << '\n';
}

int main() {
	send help
	cin >> t;
	while (t--) solve();
	return 0;
}