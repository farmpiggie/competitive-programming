#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; 
		cin >> s;
		int l_cnt = 0, i_cnt = 0, t_cnt = 0;
		for (char c : s) {
			if (c == 'L') l_cnt++;
			else if (c == 'I') i_cnt++;
			else t_cnt++;
		}
		
		if (l_cnt == i_cnt && i_cnt == t_cnt) {
			cout << "0\n";
			continue;
		}

		int moves = 0;
		bool need = false;
		bool works = true;
		vector<int> ans;
		while (moves < 2 * n) {
			int i = 1;
			if (l_cnt == i_cnt && i_cnt == t_cnt) break;
			int options = 0;
			int moved = 0;
			while (i < s.size() && moves < 2 * n) {
				int biggest = max({l_cnt, i_cnt, t_cnt});
				vector<char> temp = {s[i - 1], s[i]};
				sort(temp.begin(), temp.end());
				if (temp[0] != temp[1]) options++;
				if (temp[0] == 'I' && temp[1] == 'T' && (l_cnt != biggest || need)) {
					s.insert(i, "L");
					ans.push_back(i);
					i = max(i - 1, 1);
					moved++;
					l_cnt++;
					moves++;
					need = false;
					continue;
				}
				if (temp[0] == 'L' && temp[1] == 'T' && (i_cnt != biggest || need)) {
					s.insert(i, "I");
					ans.push_back(i);
					i = max(i - 1, 1);
					moved++;
					i_cnt++;
					moves++;
					need = false;
					continue;
				}
				if (temp[0] == 'I' && temp[1] == 'L' && (t_cnt != biggest || need)) {
					s.insert(i, "T");
					ans.push_back(i);
					i = max(i - 1, 1);
					moved++;
					t_cnt++;
					moves++;
					need = false;
					continue;
				}
				i++;
			}
			if (options == 0) {
				works = false;
				break;
			}
			if (moved == 0) {
				need = true;
			}
		}
		if (works) {
			cout << ans.size() << '\n';
			for (int x : ans) cout << x << '\n';
		} else {
			cout << "-1\n";
		}
	}
}
				








	