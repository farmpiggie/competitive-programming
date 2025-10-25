#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	// ifstream cin("allmultiples.in");
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> p(n);
		p[0] = x; p[n - 1] = 1;
		// we can use anythign in place of 1
		// if we start at the back, make sure that ()
		// cannot fill this one (?)
		// 
		unordered_set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		s.erase(1);
		s.erase(x);
		int must_fill = -1;
		for (int i = n - 2; i >= 1; i--) {
			if (s.count(i + 1)) { // simply use it
				p[i] = i + 1;
				s.erase(i + 1);
			} else { // try to find something else to use
				must_fill = i; // 
			}
		}
		if (s.size() == 0) {
			for (int i = 0; i < n; i++) cout << p[i] << " ";
			cout << endl;
		} else {
			int left = *s.begin();
			// cout << "leftover: " << left << endl;
			if (left % (must_fill + 1) == 0) {
				p[must_fill] = left;
				int curr_swap_index = must_fill;
				int i = curr_swap_index + 1;
				while (i < n) {
					if (p[curr_swap_index] > p[i] && p[curr_swap_index] % (i + 1) == 0 && p[i] % (curr_swap_index + 1) == 0) {
						swap(p[curr_swap_index], p[i]);
						curr_swap_index = i;
					}
					i++;
				}
				for (int i = 0; i < n; i++) cout << p[i] << " ";
				cout << endl;
			} else {
				cout << "-1" << endl;
			}
				// iterate backwards and see if swap is possible
			
		}
		
	}
	return 0;
}
// 1 2 3 4 5 6 7 8
// 2 8 3 4 5 6 7 1