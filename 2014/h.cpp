#include <bits/stdc++.h>
using namespace std;

// given a range 0...n - 1, sort elements in the range
// answer is a[1] + a[3] + ....
// sherrif will never actually win, but the best he can do is tie
// so it must be that a[0] == a[1], a[2] == a[3], etc?
// (count of each # in the range) % 2 == 0
// we can compute this with mo's algo?

vector<bool> cnt(1e6 + 1); // count occ of #
vector<int> a;
int parity = 0;

void remove(int idx) {
	if (cnt[a[idx]]) parity--;
	else parity++;
	cnt[a[idx]] = !cnt[a[idx]];
}  

void add(int idx) {
	remove(idx);	
}     

int get_answer() {
	return parity == 0;
} 

int block_size = 450; // floor(sqrt(2e5))

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    // clear data structure
    while (cur_l <= cur_r) {
	remove(cur_l);
	cur_l++;
    }

    return answers;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		a.resize(n);
		for (int& x : a) cin >> x;
		vector<Query> queries;
		for (int i = 0; i < q; i++) {
			int l, r; cin >> l >> r;
			--l; --r;
			queries.push_back({l, r, i});
		}
		for (int val : mo_s_algorithm(queries)) {
			if (val) cout << "YES\n";
			else cout << "NO\n";
		}	
	}
	return 0;
}