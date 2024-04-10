#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> divisors;
		for (int i = 1; i <= (int) sqrt(n); i++) {
			if (n % i == 0) {
				divisors.push_back(i);
				divisors.push_back(n / i);
			}
		}
		sort(divisors.begin(), divisors.end());
		for (int len : divisors) {
			map<string, int> mp;
			for (int i = 0; i < n; i += len) {
				mp[s.substr(i, len)]++;
			}
			bool works = false;	
			if (mp.size() == 1) {
				works = true;
			} else if (mp.size() == 2) {
				auto it = mp.begin();
				string s1 = it->first;
				string s2 = (++it)->first;
				int dif = 0;
				for (int i = 0; i < len; i++) {
					if (s1[i] != s2[i]) {
						dif++;
					}
				}
				if (dif == 1 && (mp[s1] == 1 || mp[s2] == 1)) works = true;
			}	
			if (works) {
				cout << len << '\n';
				break;
			}
		}
		
	}
	return 0;
}
