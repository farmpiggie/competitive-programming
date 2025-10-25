#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	// ifstream fin("doremypaint.in");
	int t; cin >> t;
	// simply choose l and r s.t we minimize l - r and contain all 
	while (t--) {
		int n; cin >> n;
		unordered_set<int> s;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			s.insert(a);
		}
		cout << 1 << " " << n << endl;
	}
	return 0;
}