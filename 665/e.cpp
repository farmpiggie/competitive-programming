#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

struct node {
	int cnt = 0;
	node *zero = nullptr, *one = nullptr; // next bit is zero, one
	
	node() {}
};

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	node* mp = new node;
	gp_hash_table<int, int, chash> cnt; 
				       
	// init
	cnt[0] = 1;

	node* t = mp;	
	for (int i = 0; i < 31; i++) {
		t->zero = new node;
		t = t->zero;
		t->cnt++;
	}

	auto find = [&](int cur) {
		int y = k ^ cur;
		ll res = 0;
		node* t = mp;
		// for every position that is a zero, flip the bit in y and then try to add to tally
		for (int i = 30; i >= 0; i--) {
			int bit = (y >> i) & 1;
			int kbit = (k >> i) & 1;
			// if corresponding bit in k is zero, flip it and check answer in trie
			if (kbit == 0) {
				if (bit && t->zero) {
					res += t->zero->cnt;
				} else if (!bit && t->one) {
					res += t->one->cnt;
				}
			}
			if (bit == 0) {
				// add the value of flipping to one
				if (!t->zero) break; // cannot continue
				t = t->zero;
			} else {
				if (!t->one) break; // cannot continue
				t = t->one;
			}
		}
		return res;
	};



	ll ans = 0;
	int cur = 0;
	for (int x : a) {
		cur ^= x;

		ans += find(cur);

		if (cnt.find(k ^ cur) != cnt.end()) {
			ans += cnt[k ^ cur];
		}
		
		// update
		cnt[cur]++;
		t = mp;
		for (int i = 30; i >= 0; i--) {
			int bit = (cur >> i) & 1;
			if (bit) {
				if (!t->one) t->one = new node;
				t = t->one;
			} else {
				if (!t->zero) t->zero = new node;
				t = t->zero;
			}
			t->cnt++;
		}
	}

	cout << ans << '\n';
	return 0;
}

