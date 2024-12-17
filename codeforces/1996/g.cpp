/*
let us say a < b
for a path to exist from a to b, there must exist:
roads linking a, a + 1, ..., b
OR
roads linking a, a - 1, ..., b + 1, b

observation: if we remove edge (a, a + 1), this dictates which path we must use
we can anchor this via sweepline!
this means that for any edge (x, y) where x <= a && a + 1 <= y, we should not be using the x -> y path.
therefore, we can toggle to the y -> x path when we encounter x, then toggle back.
ans = max # of zeros in the seg tree

NOTES: we can use seg tree for min count!
*/
#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
    struct Node {
        int min_val;
        int count;
        int lazy;
    };

    std::vector<Node> tree;
    int n;

    void buildTree(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {0, 1, 0};
        } else {
            int tm = (tl + tr) / 2;
            buildTree(v*2, tl, tm);
            buildTree(v*2+1, tm+1, tr);
            merge(v);
        }
    }

    void apply(int v, int tl, int tr, int val) {
        tree[v].min_val += val;
        tree[v].lazy += val;
    }

    void push(int v, int tl, int tr) {
        if (tree[v].lazy != 0) {
            int tm = (tl + tr) / 2;
            apply(v*2, tl, tm, tree[v].lazy);
            apply(v*2+1, tm+1, tr, tree[v].lazy);
            tree[v].lazy = 0;
        }
    }

    void merge(int v) {
        if (tree[v*2].min_val < tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count;
        } else if (tree[v*2].min_val > tree[v*2+1].min_val) {
            tree[v].min_val = tree[v*2+1].min_val;
            tree[v].count = tree[v*2+1].count;
        } else {
            tree[v].min_val = tree[v*2].min_val;
            tree[v].count = tree[v*2].count + tree[v*2+1].count;
        }
    }

    void updateRange(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) return;
        if (l == tl && r == tr) {
            apply(v, tl, tr, addend);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateRange(v*2, tl, tm, l, std::min(r, tm), addend);
            updateRange(v*2+1, tm+1, tr, std::max(l, tm+1), r, addend);
            merge(v);
        }
    }

    std::pair<int, int> queryRange(int v, int tl, int tr, int l, int r) {
        if (l > r) return {INT_MAX, 0};
        if (l <= tl && tr <= r) {
            return {tree[v].min_val, tree[v].count};
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        auto left = queryRange(v*2, tl, tm, l, std::min(r, tm));
        auto right = queryRange(v*2+1, tm+1, tr, std::max(l, tm+1), r);
        if (left.first < right.first) {
            return left;
        } else if (left.first > right.first) {
            return right;
        } else {
            return {left.first, left.second + right.second};
        }
    }

public:
    LazySegmentTree(int _n) {
    	n = _n;
        tree.resize(4*n);
        buildTree(1, 0, n-1);
    }

    void updateRange(int l, int r, int addend) {
        updateRange(1, 0, n-1, l, r, addend);
    }

    std::pair<int, int> queryRange(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
    
    int get_maintained(){
    	pair<int, int> res = queryRange(0, n-1);
    	return n - (res.first == 0 ? res.second : 0);
    };
};

#define pii pair<int, int>
#define f first
#define s second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<pii> a(m);
		for (pii& p : a) {
			cin >> p.f >> p.s;
			--p.f; --p.s;
		}

		LazySegmentTree st(n);
		for (const pii& p : a) st.updateRange(p.f, p.s - 1, 1);
		vector<vector<int>> start(n), end(n);
		for (int i = 0; i < m; i++) {
			start[a[i].f].push_back(i);
			end[a[i].s].push_back(i);
		}
		int ans = st.get_maintained();
		for (int i = 0; i < n; i++) {
			for (int j : start[i]) { // remove edges from a...b, add edges b -> a
				st.updateRange(a[j].f, a[j].s - 1, -1);
				st.updateRange(0, a[j].f - 1, 1);
				st.updateRange(a[j].second, n - 1, 1);
			}
			for (int j : end[i]) { // 
				st.updateRange(a[j].f, a[j].s - 1, 1);
				st.updateRange(0, a[j].f - 1, -1);
				st.updateRange(a[j].s, n - 1, -1);
			}
			ans = min(ans, st.get_maintained());
		}
		cout << ans << endl;
	}
	return 0;
}
