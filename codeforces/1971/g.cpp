// a_i XOR a_j < 4 means all bits except the last two match
// swaps are commutative
// find which values can swap, sort them
#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		unordered_map<int, vector<int>, custom_hash> mp; // numbers
		unordered_map<int, vector<int>, custom_hash> mp2; // indices

		for (int i = 0; i < n; i++) {
			mp[a[i] >> 2].push_back(a[i]);
			mp2[a[i] >> 2].push_back(i);
		}
		for (auto& p : mp) {
			sort(p.second.begin(), p.second.end());
		}
		vector<int> ans(n);
		for (auto& p : mp2) {
			for (int i = 0; i < (int) p.second.size(); i++) {
				ans[p.second[i]] = mp[p.first][i];
			}
		}
		for (int& x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
