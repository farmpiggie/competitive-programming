#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

#define pii pair<int, int>

#define f first
#define s second

int n, q;
map<pii, set<int>> mp;
pii pos[MAXN];
char a[MAXN];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	mp[{0, 0}].insert(0);
	pos[0] = {0, 0};

	for (int i = 1; i <= n; i++) {
		pos[i] = pos[i - 1];
		if (a[i] == 'U') {
			pos[i].s++;
		} else if (a[i] == 'D') {
			pos[i].s--;
		} else if (a[i] == 'L') {
			pos[i].f--;
		} else { // R
			pos[i].f++;
		}
		mp[pos[i]].insert(i);
	}

	for (int i = 0; i < q; i++) {
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		pii dest = {x, y};
		bool works = false;
		if (mp[dest].size() > 0) {
			auto it = mp[dest].lower_bound(0);
			if (it != mp[dest].end() && *it < l) {
				works = true;
			}
			it = mp[dest].lower_bound(r);
			if (it != mp[dest].end() && *it <= n) {
				works = true;
			}
		}
		pii p;
		p.f = pos[l - 1].f + pos[r].f - x;
		p.s = pos[l - 1].s + pos[r].s - y;
		auto it = mp[p].lower_bound(l);
		if (mp[p].size() > 0 && it != mp[p].end() && *it < r) {
			works = true;
		}
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}






	return 0;
}