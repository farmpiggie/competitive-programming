/*
next[i][j] = first index of character j occurring after index i, or -1 if DNE
cnt[i] = # of characters required 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
		int n, k; cin >> n >> k;
		string s; cin >> s;
		
		vector<vector<int>> next(n, vector<int>(k, -1));
		
		for (int j = 0; j < k; j++) {
			int idx = -1;
			for (int i = n - 1; i >= 0; i--) {
				next[i][j] = idx;
				if (s[i] == (j + 'a')) idx = i;
			}
		}

		vector<int> last(n, 0);
		map<int, int> mp; 
		for (int i = n - 1; i >= 0; i--) {
			if (mp.size() < k) {
				last[i] = 1;
			} else {
				int mn = INT_MAX;
				for (auto p : mp) mn = min(mn, p.second);
				last[i] = mn + 1;
			}
			mp[(s[i] - 'a')] = last[i];
		}
		
		int q; cin >> q;
		while (q--) {
			string t; cin >> t;
			int index = t[0] == s[0] ? 0 : next[0][(t[0] - 'a')];
			int i;
			for (i = 1; i < (int) t.size() && index != -1; i++) {
				index = next[index][(t[i] - 'a')];
			}
			cout << (index == -1 ? 0 : last[index]) << '\n';	
		}
}
			
				
				

		
		
