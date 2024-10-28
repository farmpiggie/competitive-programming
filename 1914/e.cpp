/*
alice and bob each have marbles of n different colors
each player, starting with alice, chooses a color i s.t. both players have marbles of said color
lets say A = 0, B = 0
if alice chose i, then (A - B) changes by a[i] - 1
if bob chose i, then (A - B) changes by -(b[i] - 1)

// opportunity cost of alice is (a[i] - 1) - (b[i] - 1) = a[i] - b[i]
//

NOT OPTIMAL to take the biggest at each time step; need to consider opportunity cost


*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		ll one = 0, two = 0;
		vector<int> arr(n);
		iota(arr.begin(), arr.end(), 0);
		sort(arr.begin(), arr.end(), [&](int x, int y) {
			return a[x] + b[x] > a[y] + b[y];
		});
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) one += a[arr[i]] - 1;
			else two += b[arr[i]] - 1;
		}
		cout << one - two << endl;
	}
}
