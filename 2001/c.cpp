#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited;
vector<bool> visited2;
vector<pair<int, int>> edges;


int get_ans(int a, int b) {
	int ans; cin >> ans;
	return ans;
}

int ask(int a, int b) {
	cout << "? " << a << " " << b << '\n';
	cout << flush;
	return get_ans(a, b);
}

void visit(int a, int b, unordered_set<int>& boop) {
	if (a == b) return;
	if (a > b) swap(a, b);
	if (visited[a][b] || (visited2[a] && visited2[b])) return; // already computed
	visited[a][b] = true;
	int mid = ask(a, b);
	if (mid == -1) {
		exit(0);
	}
	if (mid == a) edges.push_back({a, b});
	else {
		visit(a, mid, boop);
		visit(mid, b, boop);
	}
	boop.insert(a);
	boop.insert(b);
}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		edges = {};
		visited = vector<vector<bool>>(n + 1, vector<bool>(n + 1, 0));
		visited2 = vector<bool>(n + 1, 0);

		for (int i = 2; i <= n; i++) {
			unordered_set<int> boop;
			visit(1, i, boop);
			for (int num : boop) visited2[num] = true;
		}
		cout << "! ";
		for (auto& p : edges) cout << p.first << " " << p.second << " ";
		cout << '\n' << flush;

	}
	
	return 0;
}