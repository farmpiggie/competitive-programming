#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	// ifstream cin("diversesubstrings.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			arr[i] = (c - '0');
		}

		int start = 0;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			unordered_map<int, int> mp;
			int mx = 0;
			for (int i = j; i < min(j + 100, n); i++) {
				if (mp.find(arr[i]) == mp.end()) mp[arr[i]] = 1;
				else mp[arr[i]]++;
				mx = max(mx, mp[arr[i]]);
				if (mx <= mp.size()) ans++;
			}
			start++;
		} 
		cout << ans << endl;
	}


	return 0;
}