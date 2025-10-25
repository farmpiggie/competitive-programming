#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		int start = 0;
		while (start < n && s[start] == 'B') {
			start++;
		}

		if (start == n) {
			cout << "0\n";
			continue;
		}

		vector<string> a; // groups of PP, PB
		int groups = 0;
		string cur = "";
		ll ans = 0;
		int pp_cnt = 0; // total
		vector<pair<int, int>> pb_prevs; // index, # of pps before
		set<int> deleted;

		for (int i = start; i < n; i++) {
			char c = s[i];
			if (c == 'P') {
				cur += c;
				if (cur == "PP") {
					a.push_back(cur); // always PP
					groups++;
					cur = "";
					pp_cnt++;
				} 
			} else { // c == 'B'
				if (cur == "P") {
					cur += c;
					a.push_back(cur);
					groups++;
					cur = "";
					pb_prevs.push_back({a.size() - 1, pp_cnt});
				} else if (cur == "B") {
					ans += a.size() * 2;
					cur = "";
				} else { // empty
					if (pb_prevs.size() == 0) { // just move it down
						ans += pp_cnt;
					} else { // combine with some PB from before
						pair<int, int> entry = pb_prevs.back();
						deleted.insert(entry.first);
						//cout << "deleted: " << entry.first << '\n';
						pb_prevs.pop_back();
						//cout << "adding first: " << pp_cnt - entry.second << '\n';
						//cout << "adding second: " << (entry.second) * 2 + pb_prevs.size() + 1 << '\n';
						ans += (pp_cnt - entry.second); // hopping over PPs
						ans += (entry.second) * 2 + pb_prevs.size() + 1; // all PP, PBs before as well as leftover P
						cur = "P"; // leftover P propagated up
					}
				}
			}
		}
		
		//cout << "ans: " << ans << '\n';

		vector<string> b;
		for (int i = 0; i < a.size(); i++) {
			if (deleted.find(i) != deleted.end()) continue;
			b.push_back(a[i]);
		}

		// leftover [PB], [PP] blocks

		pp_cnt = 0;
		int pb_cnt = 0;
		for (string block : b) {
			//cout << "block: " << block << '\n';
			if (block == "PP") pp_cnt++;
			else {
				ans += pp_cnt;
				pb_cnt++;
			}
		}
		
		//cout << "ans: " << ans << '\n';

		// pb cnt??
		int p_cnt = 0;
		//cout << "pb_cnt: " << pb_cnt << '\n';
		while (pb_cnt > 1) {
			ans += 2 + p_cnt;
			p_cnt += 2;
			pb_cnt -= 2;
		}
		if (pb_cnt == 1) {
			ans += p_cnt / 2 + 1;
		}
		cout << ans << '\n';
	}
}

		
