#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
#include <map>
using namespace std; 

#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pii> a(n);
		map<int, int> mp1, mp2; //x + y, x

		for (auto &[x, y] : a) {
			cin >> x >> y;
			mp1[x + y]++;
			mp2[x]++;
		}

		int s = -1, c = -1; // c = x + y
		for (auto [x, cnt] : mp2) {
			if (cnt & 1) {
				s = x;
				break;
			}
		}

		for (auto [b, cnt] : mp1) {
			if (cnt & 1) {
				c = b;
				break;
			}
		}

		cout << s << " " << c - s << '\n';
	}
}


   

    
