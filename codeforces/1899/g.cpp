// segtree.cpp
// Eric K. Zhang; Nov. 22, 2017

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> st[4 * N];

void build(const vector<int>& a) {
	vector<pair<int, int>> b;
}

void update(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) { st[node] += x; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return query(s, e, lo, mid, 2 * node + 1) + 
			query(s, e, mid + 1, hi, 2 * node + 2);
}
