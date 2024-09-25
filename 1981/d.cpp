#include <bits/stdc++.h>
using namespace std;

vector<int> path(int x, int y) {
	if (x == y) return {x * 2};
	bool swapped = false;
	if (x > y) {
		swapped = true;
		swap(x, y);
	}

	vector<int> xs, ys; 
	while (x > 0) {
		xs.push_back(x);
		x /= 2;
	}
	while (y > 0) {
		ys.push_back(y);
		y /= 2;
	}
	reverse(xs.begin(), xs.end());
	reverse(ys.begin(), ys.end());
	int i = 0;
	for (;i < min(xs.size(), ys.size()); i++) {
		if (xs[i] != ys[i]) break;
	}
	--i; 
	vector<int> path;
	for (int j = xs.size() - 2; j >= i; j--) {
		path.push_back(xs[j]);
	}
	for (int j = i + 1; j < ys.size(); j++) {
		path.push_back(ys[j]);
	}
	path.pop_back();

	if (swapped) reverse(path.begin(), path.end());
	return path;

}

int main() {
//	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		vector<int> pos;
		for (int i = 0; i < n; i++) if (a[i] != -1) pos.push_back(i);
		
		if (pos.size() == 0) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) cout << 1 << ' ';
				else cout << 2 << ' ';
			}
			cout << '\n';
			continue;
		}

		bool ok = true;

		for (int i = pos[0] - 1; i >= 0; i--) {
			a[i] = ((pos[0] - i) % 2 == 0) ? a[pos[0]] : 2 * a[pos[0]];
		}
		for (int i = pos[pos.size() - 1] + 1; i < n; i++) {
			a[i] = ((i - pos[pos.size() - 1]) % 2 == 0) ? a[pos[pos.size() - 1]] : 2 * a[pos[pos.size() - 1]];
		}
		for (int i = 1; i < pos.size(); i++) {
			int l = a[pos[i - 1]], r = a[pos[i]];
//			cout << "left and right: " << l << " " << r << '\n';
			vector<int> p = path(l, r);
			
//			for (int& x : p) cout << x << " ";
//			cout << '\n';
		
//			cout << "transition: " << l << " ";
//			for (int& x : p) cout << x << " ";
//			cout << r << '\n';

			int gap = pos[i] - pos[i - 1] - 1;
			if (p.size() > gap || gap % 2 != p.size() % 2) {
				
				ok = false;
				break;
			} else {
//				cout << "yay\n";
				for (int j = 0; j < p.size(); j++) {
					a[pos[i - 1] + j + 1] = p[j];
				}
				for (int j = p.size(); j < gap; j++) {
					if ((j - p.size()) % 2 == 0) a[pos[i - 1] + j + 1] = r;
					else a[pos[i - 1] + j + 1] = r * 2;
				}
			}
		}
		if (!ok) cout << "-1\n";
		else {
			for (int& x : a) cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}
