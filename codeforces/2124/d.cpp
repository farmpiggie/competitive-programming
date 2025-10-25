#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<int> b(a);
		sort(b.begin(), b.end());
		int target = b[k - 1];

		vector<int> c;
		for (int x : a) {
			if (x <= target) c.push_back(x);
		}

		int rem = (int) c.size();

		int l = 0, r = rem - 1;
		bool works = true;
		while (l <= r) {
			if (c[l] != c[r]) {
				if (c[l] == target) {
					rem--;
					l++;
				} else if (c[r] == target) {
					rem--;
					r--;
				} else {
					works = false;
					break;
				}
			} else {
				l++;
				r--;
			}
		}
		cout << ((works && rem >= k - 1) ? "YES" : "NO") << '\n';
	}
}


