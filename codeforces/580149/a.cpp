#include <bits/stdc++.h>
using namespace std;

struct bit {
	int n; 
	vector<int> tree;

	bit() {}
	
	bit(int _n) {
		n = _n;
		tree = vector<int>(n + 1, 0);
	}

	void update(int x, int val) {
		++x;
		while (x <= n) {
			tree[x] += val;
			x += (x & -x);
		}
	}

	int query(int x) {
		++x;
		int res = 0;
		while (x > 0) {
			res += tree[x];
			x -= (x & -x);
		}
		return res;
	}
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
	int n; cin >> n;
	vector<array<int, 3>> queries(n);
	unordered_map<int, vector<int>> mp; // mp[value] = times it appears in queries
	for (auto& [x, y, z] : queries) {
		cin >> x >> y >> z;
		mp[z].push_back(y); 
	}

	unordered_map<int, int> mp2; // mp2[time] = corresponding time in BIT
	for (auto& [_, timestamps] : mp) {
		sort(timestamps.begin(), timestamps.end());
		for (int i = 0; i < (int) timestamps.size(); i++) {
			mp2[timestamps[i]] = i;
		}
	}

	unordered_map<int, bit> mp3; // mp3[value] = corresponding BIT
	for (auto& [x, y] : mp) {
		mp3[x] = bit((int) y.size()); // construct empty BIT
	}	

	for (auto [a, t, x] : queries) {
		t = mp2[t];
		if (a == 1) {
			mp3[x].update(t, 1);
		} else if (a == 2) {
			mp3[x].update(t, -1);
		} else { // a == 3
			cout << mp3[x].query(t) << '\n';
		}
	}
	return 0;
}


		
	
	



